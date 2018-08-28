#include <bits/stdc++.h>

using namespace std;

long st[4000008], ans[1000001], a[1000001], n;

void create(long rt, long l, long r){
  if(l == r){
    st[rt] = 1;
    return;
  }
  long mid = (l + r)>>1;
  create(rt<<1, l, mid);
  create(rt<<1|1, mid + 1, r);
  st[rt] = st[rt<<1] + st[rt<<1|1];
  return;
}

void del(long rt, long l, long r, long pos){
  if(l == r){
    st[rt] = 0;
    return;
  }
  long mid = (l + r)>>1;
  if(pos <= mid) del(rt<<1, l, mid, pos);
  if(mid + 1 <= pos) del(rt<<1|1, mid + 1, r, pos);
  st[rt] = st[rt<<1] + st[rt<<1|1];
  return;
}

long query(long rt, long l, long r, long v){
  long mid = (l + r)>>1;
  if(l == r) return l;
  if(st[rt<<1] >= v)
    return query(rt<<1, l, mid, v);
  else
    return query(rt<<1|1, mid + 1, r, v - st[rt<<1]);
}

int main(){

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
    a[i]++;
  }
  create(1, 1, n);
  for(long i = n; i >= 1; i--){
    long pos = query(1, 1, n, a[i]);
    ans[pos] = i;
    del(1, 1, n, pos);
  }

  for(long i = 1; i <= n; i++){
    printf("%ld ", ans[i]);
  }


  return 0;
}
