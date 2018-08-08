#include <bits/stdc++.h>

using namespace std;

const long MOD = 1e9 + 7;

long n, m, k;
vector<vector <long> > mat, dp;

int main(){

  freopen("hopscotch.in", "r", stdin);
  freopen("hopscotch.out", "w", stdout);

  scanf("%ld%ld%ld", &n, &m, &k);
  mat.resize(n + 1);
  dp.resize(n + 1);
  for(long i = 0; i <= n; i++){
    mat[i].resize(m + 1);
    dp[i].resize(m + 1);
  }
  for(long x = 1; x <= n; x++){
    for(long y = 1; y <= m; y++){
      scanf("%ld", &mat[x][y]);
    }
  }

  dp[1][1] = 1;
  for(long x = 1; x <= n; x++){
    for(long y = 1; y <= m; y++){
      for(long fx = 1; fx < x; fx++){
        for(long fy = 1; fy < y; fy++){
          if(dp[x][y] != dp[fx][fy]){
            dp[x][y] += dp[fx][fy] + 1;
            dp[x][y] %= MOD;
          }
        }
      }
    }
  }
  /*
  for(long x = 1; x <= n; x++){
    for(long y = 1; y <= m; y++){
      printf("dp[%ld][%ld]=%Ld ", x, y, dp[x][y]);
    }printf("\n");
  }
  */
  printf("%ld", dp[n][m] / 5);

  fclose(stdin);
  fclose(stdout);
  return 0;

}
