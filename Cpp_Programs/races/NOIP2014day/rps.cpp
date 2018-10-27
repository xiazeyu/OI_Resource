// 20:15 - 20:40
#include <bits/stdc++.h>

using namespace std;

long N, NA, NB, a[204], b[204], poA, poB, ansA, ansB;

int pd(long _a, long _b){
  // 1: a得分, 2: b得分, 3: 均不得分
  if(_a == _b) return 3;
  if(((_a == 0) && (_b == 2)) || ((_a == 0) && (_b == 3))
    || ((_a == 1) && (_b == 3)) || ((_a == 2) && (_b == 4))
    || ((_a == 3) && (_b == 4)) || ((_a == 1) && (_b == 0))
    || ((_a == 4) && (_b == 0)) || ((_a == 2) && (_b == 1))
    || ((_a == 4) && (_b == 1)) || ((_a == 3) && (_b == 2))
    ) return 1;
  return 2;
}

int main(){

  freopen("rps.in", "r", stdin);
  freopen("rps.out", "w", stdout);

  scanf("%ld%ld%ld", &N, &NA, &NB);
  for(long i = 0; i < NA; i++)
    scanf("%ld", &a[i]);
  for(long i = 0; i < NB; i++)
    scanf("%ld", &b[i]);
  for(long i = 1; i <= N; i++){
    long t = pd(a[poA], b[poB]);
    if(t == 1)
      ansA++;
    else if(t == 2)
      ansB++;
    poA++; poB++; poA %= NA; poB %= NB;
  }

  printf("%ld %ld\n", ansA, ansB);

  return 0;

}
