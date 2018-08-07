// P3378 ¡¾Ä£°å¡¿¶Ñ
// https://www.luogu.org/problemnew/show/P3378

#include <bits/stdc++.h>

using namespace std;

long n, a, b;
priority_queue<long, vector<long>, greater<long> > p;

int main(){

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a);
    if(a == 1){
      scanf("%ld", &b);
      p.push(b);
    }
    if(a == 2){
      printf("%ld\n", p.top());
    }
    if(a == 3){
      p.pop();
    }
  }

  return 0;

}
