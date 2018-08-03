#include <bits/stdc++.h>

using namespace std;

long n;
vector<long> a;

int main(){

  scanf("%ld", &n);
  a.resize(n + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &a[i]);
  }
  for(long i = 0; i < n; i += 2){
    sort(a.begin(), a.begin() + i + 1);
    printf("%ld\n", a[i / 2]);
  }

  return 0;

}
