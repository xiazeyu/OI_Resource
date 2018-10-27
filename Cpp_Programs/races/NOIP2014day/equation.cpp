#include <bits/stdc++.h>

using namespace std;

const long MOD = 1e9+7;

long n, m, a[108];
vector<long> ans;

long long Pow(long d, long e){
  long long t = 1;
  for(long i = 1; i <= e; i++)
    t *= d;
  return t;
}

int main(){

  // freopen("equation.in", "r", stdin);
  // freopen("equation.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 0; i <= n; i++)
    scanf("%ld", &a[i]);
  for(long i = 1; i <= m; i++){
    long long l = 0;
    for(long j = 0; j <= n; j++)
      l += a[j] * Pow(i, j);
    if(l == 0) ans.push_back(i);
  }

  printf("%ld\n", ans.size());
  for(unsigned long i = 0; i < ans.size(); i++){
    printf("%ld\n", ans[i]);
  }

  return 0;

}
