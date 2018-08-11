// P1567 统计天数
// https://www.luogu.org/problemnew/show/P1567

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, cnt = 0, ans = 0;
long long prev = -1, t;

int main(){

  scanf("%ld", &n);
  while(n--){
    scanf("%lld", &t);
    if(t > prev){
      cnt++; prev = t; ans = max(ans, cnt);
    } else{ // HERE
      cnt = 1; prev = t;
    }
  }

  printf("%ld\n", ans);

  return 0;

}
