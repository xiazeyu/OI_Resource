// P1706 全排列问题
// https://www.luogu.org/problemnew/show/P1706

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n;
vector<long> v;

int main(){

  scanf("%ld", &n);
  v.resize(n + 1);
  for(long i = 1; i <= n; i++)
    v[i] = i;
  do{
    for(long i = 1; i <= n; i++){
      printf("%5ld", v[i]);
    }printf("\n");
  }while(next_permutation(v.begin() + 1, v.end())); // +1

  return 0;

}
