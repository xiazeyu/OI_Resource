// P3372 【模板】线段树 1
// https://www.luogu.org/problemnew/show/P3372

// Status: AC

#include <bits/stdc++.h>

using namespace std;

struct Node{
  long long sum, lazy;
  Node(long long _sum = 0, long long _lazy = 0){
    sum = _sum; lazy = _lazy;
  }
};

Node t[400008];
long long a[100008];
int n, m, o, x, y, k;

long long Create(long rt, long l, long r){
  if(l == r)
    return t[rt].sum = a[l];
  // pushUp
  long mid = (l + r)>>1;
  return t[rt].sum = Create(rt<<1, l, mid) + Create(rt<<1|1, mid + 1, r);
}

void pushDown(long rt, long l, long r){
  if((t[rt].lazy) && (l != r)){
    long mid = (l + r)>>1,
    lLen = mid - l + 1,
    rLen = r - (mid + 1) + 1;
    t[rt<<1].lazy += t[rt].lazy;
    t[rt<<1|1].lazy += t[rt].lazy;
    t[rt<<1].sum += t[rt].lazy * lLen;
    t[rt<<1|1].sum += t[rt].lazy * rLen;
    t[rt].lazy = 0; // 勿忘
  }
  return;
}

void addV(long rt, long l, long r, long s, long e, long v){
  // 当前结点: rt, [l, r]
  // 待操作: [b, e], v
  if((s <= l) && (r <= e)){
  // 1. 子集
    long len = r - l + 1;
    t[rt].lazy += v;
    t[rt].sum += v * len;
    return;
  }
  // 2. pushDown
  pushDown(rt, l, r);
  long mid = (l + r) >> 1;
  // 3. 交集
  if(s <= mid) addV(rt<<1, l, mid, s, e, v);
  if(mid + 1 <= e) addV(rt<<1|1, mid + 1, r, s, e, v);
  // 4. 更新
  t[rt].sum = t[rt<<1].sum + t[rt<<1|1].sum;
  return;
}

long long query(long rt, long l, long r, long s, long e){
  if((s <= l) && (r <= e)){
    return t[rt].sum;
  }
  pushDown(rt, l, r);
  long mid = (l + r) >> 1;
  long long cnt = 0;
  if(s <= mid) cnt += query(rt<<1, l, mid, s, e);
  if(mid + 1 <= e) cnt += query(rt<<1|1, mid + 1, r, s, e);
  return cnt;
}

int main(){

  scanf("%d%d", &n, &m);
  for(long i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
  }
  Create(1, 1, n);
  for(long i = 1; i <= m; i++){
    scanf("%d%d%d", &o, &x, &y);
    if(o == 1){
      scanf("%d", &k);
      addV(1, 1, n, x, y, k);
    }else{
      printf("%lld\n", query(1, 1, n, x, y));
    }
  }

  return 0;

}
