// P1939 【模板】矩阵加速（数列）
// https://www.luogu.org/problemnew/show/P1939

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

const long MOD = 1e9+7;

long t, n;
struct Mat{
  long long data[4][4];
  Mat(){
    memset(data, 0, sizeof(data));
  }
  void init(){
    data[1][1] = 1; data[2][2] = 1; data[3][3] = 1;
    return;
  }
};

Mat operator* (const Mat &a, const Mat &b){
  Mat tans;
  for(long i = 1; i <= 3; i++)
    for(long j = 1; j <= 3; j++)
      for(long k = 1; k <= 3; k++)
        tans.data[i][j] = (tans.data[i][j] % MOD + a.data[i][k] * b.data[k][j] % MOD) % MOD;
  return tans;
}

Mat operator^(const Mat &a, long b){
  Mat tans, base = a;
  tans.init();
  while(b){
    if(b & 1)
      tans = tans * base;
    base = base * base;
    b >>= 1;
  }
  return tans;
}
Mat opt, tmp;

int main(){

  scanf("%ld", &t);
  opt.data[1][1] = opt.data[1][3] = opt.data[2][1] = opt.data[3][2] = 1;
  for(long i = 1; i <= t; i++){
    scanf("%ld", &n);
    if(n <= 3){
      printf("1\n");
      continue;
    }
    tmp = opt ^ (n - 1);
    printf("%lld\n", tmp.data[1][1]);
  }

  return 0;

}
