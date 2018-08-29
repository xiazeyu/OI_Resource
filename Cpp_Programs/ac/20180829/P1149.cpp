// P1149 »ð²ñ°ôµÈÊ½
// https://www.luogu.org/problemnew/show/P1149

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

const long c[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long n, num[2002], ans = 0;

long getN(long nu){
  if(num[nu]) return num[nu];
  long cnt = 0, t = nu;
  do{
    cnt += c[t % 10];
    t /= 10;
  }while(t);
  return num[nu] = cnt;
}

int main(){

  scanf("%ld", &n);

  for(long i = 0; i <= 1000; i++){
    for(long j = 0; j <= 1000; j++){
      if(getN(i) + getN(j) + 4 + getN(i + j) == n) ans++;
    }
  }

  printf("%ld\n", ans);


  return 0;

}
