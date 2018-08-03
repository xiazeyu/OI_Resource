#include <bits/stdc++.h>

using namespace std;

long long l ,le, ri, mid;
long n, m;
vector<long long> d;

bool check(long long dist){
  long long lastDist = 0;
  long cnt = 0;
  for(long i = 1; i < n + 1; i++){
    lastDist += d[i] - d[i - 1];
    if(lastDist < dist){
      cnt++;
    }else{
      cnt = 0;
    }
  }
  return cnt <= m;
}

int main(){

  scanf("%lld %ld %ld", &l, &n, &m);
  d.resize(n + 1);
  d[n + 1] = l;
  for(int i = 1; i <= n; i++){
    scanf("%lld", &d[i]);
  }
  while(1){
    scanf("%lld", &mid);
    printf("%d\n", check(mid));
  }

  return 0;

}
