// P1028 数的计算
// https://www.luogu.org/problemnew/show/P1028

// Status: AC

// WARN: 递归, 递推 记忆法优化 (#19)

#include <bits/stdc++.h>

using namespace std;

long n;
long long cache[1024] = {0};

long long cnt(long a){
  if(cache[a]) return cache[a];
  long long tot = 1;
  for(long i = 1; 2 * i <= a; i++){
    tot += cnt(i);
  }
  return cache[a] = tot;
}

int main(){

  scanf("%ld", &n);
  cache[0] = 1;
  cache[1] = 1;
  printf("%Ld\n", cnt(n));

  return 0;

}
