// WARN: %的运算: 防止出现负数, %MOD前+MOD

#include <bits/stdc++.h>

using namespace std;

const long MOD = 10000;

long t, x, y, n = 0, c[1000008], qx[1001], qy[1001];

inline void add(long pos, long v){
  while(pos <= n){
    c[pos] += v % MOD;
    c[pos] %= MOD;
    pos += pos & -pos;
  }
  return;
}

inline long sum(long pos){
  // [1, pos]
  long cnt = 0;
  while(pos){
    cnt += c[pos] % MOD;
    cnt %= MOD;
    pos -= pos & -pos;
  }
  return cnt;
}

inline long query(long pos){
  // pos
  return (sum(pos) - sum(pos - 1) + MOD) % MOD; // 注意负数
}

int main(){
  freopen("fibonacci.in", "r", stdin);
  freopen("fibonacci.out", "w", stdout);

  scanf("%ld", &t);
  for(long i = 1; i <= t; i++){
    scanf("%ld%ld", &qx[i], &qy[i]);
    n = max(n, qy[i]);
  }

  add(1, 1); add(2, 1);
  for(long i = 3; i <= n; i++){
    add(i, (query(i - 1) + query(i - 2)) % MOD);
    // printf("%ld=[%ld, %ld, %ld]\n", i, (query(i - 1) + query(i - 2)) % MOD, query(i), c[i]);
  }

  for(long i = 1; i <= t; i++){
     printf("%ld\n", (sum(qy[i]) - sum(qx[i] - 1) + MOD) % MOD);
  }

  return 0;
}
