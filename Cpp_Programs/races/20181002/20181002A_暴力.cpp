#include <bits/stdc++.h>

using namespace std;

long n, a[10000], ans = 0x3f3f3f3f;

long largerCount(long l, long e, long nu){
  long cnt = 0;
  for(long i = l; i <= e; i++){
    if(a[i % n] > nu) cnt++;
  }
  return cnt;
}

int main(){

  while(scanf("%ld", &n) != EOF){
    for(long i = 0; i < n; i++){
      scanf("%ld", &a[i]);
      a[i + n] = a[i];
    }
    for(long i = 0; i < 2 * n; i++){
      long t = 0;
      for(long j = 0; j < n; j++){
        t += largerCount(i, i + j, a[i + j]);
      }
      ans = min(ans, t);
    }

    printf("%ld\n", ans);
  }

  return 0;

}
