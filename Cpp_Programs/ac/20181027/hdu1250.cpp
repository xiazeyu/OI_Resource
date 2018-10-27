// Anniversary party ÷‹ƒÍ«Ï—Á
// http://acm.hdu.edu.cn/showproblem.php?pid=1520

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 6010;

vector<long> Edge[MAXN];
long dp[MAXN][2], n, l, k, rt;

void dfs(long a, long par){
  for(long i = 0; i < Edge[a].size(); i++)
    dfs(Edge[a][i], a);
  dp[par][0] += max(dp[a][0], dp[a][1]);
  dp[par][1] += dp[a][0];
  return;
}

int main(){

  while(~scanf("%ld", &n)){
    for(long i = 1; i <= n; i++)
      scanf("%ld", &dp[i][1]);
    rt = (1 + n) * n / 2;
    while(scanf("%ld%ld", &l, &k), l + k){
      Edge[k].push_back(l);
      rt -= l;
    }
    dfs(rt, 0);
    printf("%ld\n", max(dp[rt][1], dp[rt][0]));
    memset(dp, 0, sizeof(dp));
    for(long i = 1; i <= n; i++)
      Edge[i].clear();
  }

  return 0;

}
