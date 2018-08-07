// P1177 ¡¾Ä£°å¡¿¿ìËÙÅÅÐò
// https://www.luogu.org/problemnew/show/P1177

#include <bits/stdc++.h>

using namespace std;

long n;
vector<long> a;

int main(){

  scanf("%ld", &n);
  a.resize(n);
  for(long i = 0; i < n; i++){
    scanf("%ld", &a[i]);
  }
  sort(a.begin(), a.begin() + n);
  for(long i = 0; i < n - 1; i++){
    printf("%ld ", a[i]);
  }
  printf("%ld\n", a[n - 1]);

  return 0;

}
