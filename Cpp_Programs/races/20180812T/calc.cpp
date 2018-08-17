#include <bits/stdc++.h>

using namespace std;

const long MOD = 1e9 + 9;

long cache[101][101], n, m, num, cnt = 0;

long wha(long n, long k){
  if(cache[n][k]) return cache[n][k];
  return cache[n][k] = ((long long)wha(n % MOD, (k - 1) % MOD) % MOD) * ((long long)wha((n - 1) % MOD, k % MOD) % MOD) % MOD;
}

int main(){

  freopen("calc.in", "r", stdin);
  freopen("calc.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 0; i <= 100; i++){
    cache[0][i] = 1; cache[i][0] = i;
  }
  num = wha(n, m);
  for(long i = 1; i < sqrt(num); i++){
    if(!(num % i)) cnt++;
  }cnt *= 2;
  if(sqrt(num) * sqrt(num) == num) cnt++;
  if(num == 1) cnt = 1;
  /*
  for(long i = 0; i <= 100; i++){
    for(long j = 0; j <= 100; j++){
      printf("%ld, ", cache[i][j]);
    }printf("\n");
  }*/

  printf("%ld\n", cnt);

  fclose(stdin);
  fclose(stdout);

  return 0;

}
