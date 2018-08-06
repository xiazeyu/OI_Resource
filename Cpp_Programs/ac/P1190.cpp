// P1190 接水问题
// https://www.luogu.org/problemnew/show/P1190

#include <bits/stdc++.h>

using namespace std;

long n, m, minTap;
long long ans = 0, minTime;
vector<long> w;
vector<long long> tap;


int main(){

  scanf("%ld %ld", &n, &m);
  w.resize(n + 4);
  tap.resize(m + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &w[i]);
  }

  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j++){
      if(tap[j] < tap[minTap]) minTap = j;
    }
    tap[minTap] += w[i];
  }
  for(int i = 0; i < m; i++){
    if(tap[i] > ans) ans = tap[i];
  }

  printf("%lld", ans);

  return 0;

}
