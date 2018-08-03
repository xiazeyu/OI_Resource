#include <bits/stdc++.h>

using namespace std;

long n, t;
set<long> num;
set<long>::iterator it;

int main(){

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &t);
    num.insert(t);
  }
  printf("%d\n", num.size());
  for(it = num.begin(); it != num.end(); it++){
    printf("%ld ", *it);
  }

  return 0;

}
