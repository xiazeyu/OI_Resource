// P1962 ì³²¨ÄÇÆõÊýÁÐ
// https://www.luogu.org/problemnew/show/P1962

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;
const long MOD = 1e9+7;
long long n;
struct Mat{
  long long data[3][3];
  Mat(){
    memset(data, 0, sizeof(data));
  }
  void init(){
    data[1][1] = data[2][2] = 1;
    return;
  }
};

Mat operator* (const Mat &a, const Mat &b){
  Mat tans;
  for(long i = 1; i <= 2; i++)
    for(long j = 1; j <= 2; j++)
      for(long k = 1; k <= 2; k++)
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

Mat opt, ans;

int main(){

  scanf("%lld", &n);
  if(n <= 2){
    printf("1\n");
    return 0;
  }
  opt.data[1][1] = 1; opt.data[1][2] = 1;
  opt.data[2][1] = 1; opt.data[2][2] = 0;
  ans = opt ^ (n - 1);
  printf("%lld", ans.data[1][1]);

  return 0;

}
