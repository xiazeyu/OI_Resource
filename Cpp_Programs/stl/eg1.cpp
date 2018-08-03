#include <bits/stdc++.h>

using namespace std;

long n;
vector<long long> a;

int main(){

  scanf("%ld", &n);
  a.resize(n + 4);
  for(long i = 0; i < n; i++){
    scanf("%lld", &a[i]);
  }
  sort(a.begin(), a.begin() + n);
  if(n % 2){
    // ÆæÊý
    printf("%lld\n", a[n / 2]);
  }else{
    // Å¼Êý
    printf("%lld\n", (a[n / 2 - 1] + a[n / 2]) / 2);
  }

  return 0;

}
