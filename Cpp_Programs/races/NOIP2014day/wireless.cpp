#include <bits/stdc++.h>

using namespace std;

long d, n, _x, _y, _k, k[180][180], cnt, maxQ;

int main(){

  freopen("wireless.in", "r", stdin);
  freopen("wireless.out", "w", stdout);

  scanf("%ld%ld", &d, &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld%ld%ld", &_x, &_y, &_k);
    k[_x + 20][_y + 20] = _k;
  }

  for(long x = 20; x <= 148; x++)
    for(long y = 20; y <= 148; y++){
      long t = 0;
      for(long i = x - d; i <= x + d; i++)
        for(long j = y - d; j <= y + d; j++){
          t+= k[i][j];
        }
      if(t > maxQ){
        maxQ = t;
        cnt = 1;
      } else if(t == maxQ)
        cnt++;
    }

  printf("%ld %ld\n", cnt, maxQ);


  return 0;

}
