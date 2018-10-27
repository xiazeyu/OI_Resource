#include <bits/stdc++.h>

using namespace std;

long n, al;

long dfs(long row, long ld, long rd){
  if(row == al) return 1;
  // 状态中: 1 - 不能放
  long possible = al & (~(row | ld | rd)),
       i,
       cnt = 0;
  while(possible != 0){
    i = possible & -possible;
    possible -= i;
    cnt += dfs(row|i, (ld|i)<<1, (rd|i)>>1);
  }
  return cnt;

}

int main(){

  scanf("%ld", &n);
  al = (1<<n) - 1;
  printf("%ld\n", dfs(0, 0, 0));

  return 0;
}
