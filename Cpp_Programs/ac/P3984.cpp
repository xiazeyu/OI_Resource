// P3984 ¸ßÐËµÄ½ò½ò
// https://www.luogu.org/problemnew/show/P3984

#include <bits/stdc++.h>

using namespace std;

long n, t, prev, tu, ans = 0;

int main(){

  scanf("%ld%ld", &n, &t);
  if(n >= 1) scanf("%ld", &prev);
  ans = t;
  for(long i = 1; i <= n - 1; i++){
    scanf("%ld", &tu);
    if(tu - prev <= t){
      ans += tu - prev;
      prev = tu;
    }else{
      prev = tu;
      ans += t;
    }
  }

  printf("%ld", ans);

  return 0;

}
