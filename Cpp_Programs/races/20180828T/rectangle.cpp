#include <bits/stdc++.h>

using namespace std;

long dp[50][50][2500], n, m, k;

int main(){
  // freopen("rectangle.in", "r", stdin);
  // freopen("rectangle.out", "w", stdout);

  scanf("%ld%ld%ld", &n, &m, &k);
  dp[2][2][4] = 1;
  for(long i = 3; i <= n; i++)
    for(long j = 3; j <= m; j++)
      for(long l = 4; l <= k, l++)

  return 0;
}
