#include <bits/stdc++.h>

using namespace std;

long n, minMoney = 0x7fffffff, nowMoney = 0;
long a, b;

int main(){

  // minMoney

  scanf("%ld", &n);
  for(long i = 1; i <= 3; i++){
    scanf("%ld %ld", &a, &b);
    nowMoney = b * (n / a);
    if(n % a){
      nowMoney += b;
    }
    minMoney = min(nowMoney, minMoney);
  }

  printf("%ld", minMoney);

  return 0;

}
