// P1036 选数
// https://www.luogu.org/problemnew/show/P1036

// Status: AC

// Problem: 全组合求法

#include <bits/stdc++.h>

using namespace std;

long n, k, x[20], ans = 0;

bool isPrime(long _n){
  for(long i = 2; i <= sqrt(_n); i++)
    if(!(_n % i)){
      return false;
    }
  return true;
}

void DFS(long _k, long cnt, long s){
  if(_k == 0){
    if(isPrime(cnt)) ans++;
    return;
  }
  for(long i = s; i < n; i++){
    DFS(_k - 1, cnt + x[i], i + 1);
  }
  return;
}

int main(){

  scanf("%ld%ld", &n, &k);
  for(long i = 0; i < n; i++){
    scanf("%ld", &x[i]);
  }
  DFS(k, 0, 0);

  printf("%ld\n", ans);

  return 0;

}
