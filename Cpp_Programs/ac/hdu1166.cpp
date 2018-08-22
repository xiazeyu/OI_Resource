// HDU1166 µÐ±ø²¼Õó Ïß¶ÎÊ÷Ä£°å
// http://acm.hdu.edu.cn/showproblem.php?pid=1166

// Status: AC

// WARN: 多组输入时当前的Case Number输出是否正常(不能while(t--)) (#25)

#include <bits/stdc++.h>

using namespace std;

int t, n, a[50001] = {0}, _i, _j, tr[200008] = {0}, tCnt = 0;
char o[20];

int Create(int rt, int l, int r){
  if(l == r)
    return tr[rt] = a[l];
  int mid = (l + r)>>1;
  return tr[rt] = Create(rt<<1, l, mid) + Create(rt<<1|1, mid + 1, r);
}

void Add(int rt, int l, int r, int pos, int v){
  if(l == r){
    tr[rt] += v;
    return;
  }
  int mid = (l + r)>>1;
  if(pos <= mid)
    Add(rt<<1, l, mid, pos, v);
  else
    Add(rt<<1|1, mid + 1, r, pos, v);
  tr[rt] = tr[rt<<1] + tr[rt<<1|1];
  return;
}

int query(int rt, int l, int r, int s, int e){
  if((s <= l) && (r <= e)) return tr[rt];
  int mid = (l + r)>>1,
  cnt = 0;
  if(s <= mid) cnt += query(rt<<1, l, mid, s, e);
  if(mid + 1 <= e) cnt += query(rt<<1|1, mid + 1, r, s, e);
  return cnt;
}

int main(){

  scanf("%d", &t);
  while(t != tCnt){
    printf("Case %d:\n", ++tCnt);
    // printf("Case %d:\n", t + 1);
    scanf("%d", &n);
    for(long i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    Create(1, 1, n);
    while(1){
      scanf("%s", &o[0]);
      if(o[0] == 'E') break;
      scanf("%d%d", &_i, &_j);
      if(o[0] == 'A'){
        Add(1, 1, n, _i, _j);
      }else if(o[0] == 'S'){
        Add(1, 1, n, _i, -1 * _j);
      }else if(o[0] == 'Q'){
        printf("%d\n", query(1, 1, n, _i, _j));
      }
    }
  }

  return 0;

}
