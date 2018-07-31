#include <bits/stdc++.h>

using namespace std;

long n, m;
long long ans = 0;
vector<long> w;
vector<long long> s, tapTime;


int main(){

  scanf("%ld %ld", &n, &m);
  w.resize(n + 4);
  tapTime.resize(m + 4);
  s.resize(m + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &w[i]);
  }
  sort(w.begin(), w.begin() + n);
  for(int i = 0; i < n; i++){
    s[i % m] += w[i];
    tapTime[i % m] += s[i % m];
  }
  for(int i = 0; i < m; i++){
    ans += tapTime[i];
  }

  printf("%lld", ans);

  return 0;

}
