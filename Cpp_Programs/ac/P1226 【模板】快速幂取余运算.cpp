// P1226 【模板】快速幂||取余运算
// https://www.luogu.org/problemnew/show/P1226

// Status: AC

// Problem: 不能篡改a
// Problem: always %

#include <bits/stdc++.h>

using namespace std;

long b, p, k;

long qpow(long a, long r, long MOD){
  long ans = 1, base = a;
  while(r){
    if(r&1)
      ans = ((ans % MOD) * (base % MOD)) % MOD;
    base = ((base % MOD) * (base % MOD)) % MOD;
    r >>= 1;
  }
  return ans % MOD;
}

int main(){

  scanf("%ld%ld%ld", &b, &p, &k);
  printf("%ld^%ld mod %ld=%ld\n", b, p, k, qpow(b, p, k));

  return 0;

}
