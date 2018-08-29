// P1217 [USACO1.5]回文质数 Prime Palindromes
// https://www.luogu.org/problemnew/show/P1217

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

bool isHuiwen(long _x){
  long _a = _x, _b = 0;
  while(_a){
    _b = _b * 10 + _a % 10;
    _a /= 10;
  }
  if(_b == _x) return true;
  return false;
}

long prime[5000000], pn = 0, a, b;
bool isPri[10000000];

int main(){

  scanf("%ld%ld", &a, &b);
  b = min(b, (long)10000000);
  memset(isPri, true, sizeof(isPri));
  for(long i = 2; i <= b / 2; i++){
    if(isPri[i]) prime[pn++] = i;
    for(long j = 0; j < pn && i * prime[j] <= b; j++){
      isPri[i * prime[j]] = false;
      if(i % prime[j] == 0) break;
    }
  }
  for(long i = a; i <= b; i++){
    if(isPri[i] && isHuiwen(i)) printf("%ld\n", i);
  }

  return 0;

}
