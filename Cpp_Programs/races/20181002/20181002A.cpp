#include <bits/stdc++.h>

using namespace std;

long n, a[5001], b[5001], cnt, ans;

int main(){

  while(scanf("%ld", &n) != EOF){
    cnt = 0; ans = 0x3f3f3f3f;
    for(long i = 0; i < n; i++){
      scanf("%ld", &a[i]);
      b[i] = a[i];
    }
    sort(b, b + n);
    for(long i = 0; i < n; i++)
      for(long j = 0; j < i; j++)
        if(a[j] > a[i]) cnt++;
    ans = cnt;
    for(long i = 0; i < n; i++){
      long smaller = lower_bound(b, b + n, a[i]) - b,
      larger = n - (upper_bound(b, b + n, a[i]) - b);
      cnt -= smaller;
      cnt += larger;
      ans = min(ans, cnt);
    }
    printf("%ld\n", ans);
  }


  return 0;

}
