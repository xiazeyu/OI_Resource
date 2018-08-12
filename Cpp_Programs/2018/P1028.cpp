// P1028 ÊýµÄ¼ÆËã
// https://www.luogu.org/problemnew/show/P1028

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n;

long cnt(long a){
  if(a <= 1) return 0;
  long tot = 0;
  for(long i = 1; i <= (a / 2); i++){
    tot += cnt(i);
  }
  return tot;
}

int main(){

  scanf("%ld", &n);

  printf("%ld\n", cnt(n));

  return 0;

}
