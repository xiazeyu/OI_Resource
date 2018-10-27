#include <bits/stdc++.h>

using namespace std;

long n, dist[20][20], dp[20][1<<20];
// dp[i][j] 当前到达i点, 状态为j(0 - unreached)

int main(){
  scanf("%ld", &n);
  for(long i = 0; i < n; i++)
    for(long j = 0; j < n; j++)
      scanf("%ld", &dist[i][j]);
  memset(dp, 0x3f, sizeof(dp));
  dp[0][1] = 0;
  for(long j = 1; j < (1<<n); j++)
  	for(long i = 0; i < n; i++)
  	  for(long k = 0;k < n; k++)
        // k为枚举的可行解, k -> i
        if(((j >> k) & 1) && (dp[i][j] > dp[k][j ^ (1 << i)] + dist[k][i]))
          dp[i][j] = dp[k][j ^ (1 << i)] + dist[k][i];
  printf("%ld\n", dp[n - 1][(1<<n) - 1]);
  return 0;
}
