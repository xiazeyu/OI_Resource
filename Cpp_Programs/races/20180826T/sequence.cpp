#include <bits/stdc++.h>

using namespace std;

long n, _o, a[1000000];

int main(){

  // freopen("sequence.in", "r", stdin);
  // freopen("sequence.out", "w", stdout);

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &_o);
    for(long j = i - 1; j >= _o; j--){
      a[j] = a[j - 1];
    }
    a[_o] = i;
  }

  for(long i = 0; i < n; i++){
    printf("%ld ", a[i]);
  }

  return 0;

}
