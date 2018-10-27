// link
#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

long n, w[200001], _u, _v;
long long Max, Tot;
vector<long> Edge[200001];

int main(){

  // freopen("link.in", "r", stdin);
  // freopen("link.out", "w", stdout);

  scanf("%ld", &n);
  for(long i = 1; i <= n - 1; i++){
    scanf("%ld%ld", &_u, &_v);
    Edge[_u].push_back(_v);
    Edge[_v].push_back(_u);
  }
  for(long i = 1; i <= n; i++)
    scanf("%ld", &w[i]);

  for(long i = 1; i <= n; i++){
    long u = Edge[i][0];
    long long tmax = w[u], ttot = w[u];
    for(unsigned long j = 1; j < Edge[i].size(); j++){
      long v = Edge[i][j];
      Tot += ttot * w[v];
      Max = max(Max, tmax * w[v]);
      ttot += w[v];
      tmax = max(tmax, (long long)w[v]);
    }
  }

  printf("%lld %lld\n", Max, 2 * Tot % MOD);

  return 0;

}
