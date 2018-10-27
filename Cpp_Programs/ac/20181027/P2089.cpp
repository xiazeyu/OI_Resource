// P2089 烤鸡
// https://www.luogu.org/problemnew/show/P2089

// Status: AC

// WARN: DFS终止条件: 到达结果/越界 (#33)

#include <bits/stdc++.h>

using namespace std;

long n, cnt = 0, ans[60000][10], t[10];

void DFS(long s, long u){
  // s: 第s种配料
  // r: 已用u克
  if((s == 10) && (u == n)){
    for(long i = 0; i < 10; i++) ans[cnt][i] = t[i];
    cnt++;
    return;
  }
  if((u >= n) || (s >= 10)) return;
  for(long i = 1; i <= 3; i++){
    t[s] = i;
    DFS(s + 1, u + i);
  }
  return;
}

int main(){

  scanf("%ld", &n);
  DFS(0, 0);
  printf("%ld\n", cnt);
  for(long i = 0; i < cnt; i++){
    for(long j = 0; j < 10; j++)
      printf("%ld ", ans[i][j]);
    printf("\n");
  }

  return 0;

}
