// P3368 【模板】树状数组 2
// https://www.luogu.org/problemnew/show/P3368

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, m, x, y, k, o;
long b[500002];

void add(long Begin, long End, long value){
  // b[Begin] += value;
  // b[End + 1] -= value;
  while(Begin <= n){
    b[Begin] += value;
    Begin += Begin & -Begin;
  }
  long t = End + 1;
  while(t <= n){
    b[t] -= value;
    t += t & -t;
  }
  return;
}

long getA(long pos){
  long cnt = 0;
  while(pos){
    cnt += b[pos];
    pos -= pos & -pos;
  }
  return cnt;
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &k);
    add(i, i, k);
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld", &o);
    if(o == 1){
      scanf("%ld%ld%ld", &x, &y, &k);
      add(x, y, k);
    }else{
      scanf("%ld", &x);
      printf("%ld\n", getA(x));
    }
  }

  return 0;

}
