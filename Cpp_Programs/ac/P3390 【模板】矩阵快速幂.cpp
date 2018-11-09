// P3390 【模板】矩阵快速幂
// https://www.luogu.org/problemnew/show/P3390

// Status:

// Problem: 结构体初始化

#include <bits/stdc++.h>

using namespace std;

#define MAXN 108
const long long MOD = 1e9 + 7;
long n, _t;
long long k;
struct Mat{
  long long data[MAXN][MAXN];
  Mat(){
    memset(data, 0, sizeof(data)); // 结构体初始化
  }
  void init(){
    for(long i = 1; i <= n; i++)
      data[i][i] = 1;
    return;
  }
};

Mat operator*(const Mat &a, const Mat &b){
  Mat ans;
  for(long i = 1; i <= n; i++)
    for(long j = 1; j <= n; j++)
      for(long k = 1; k <= n; k++)
        ans.data[i][j] = (ans.data[i][j] % MOD + a.data[i][k] * b.data[k][j] % MOD) % MOD;
  return ans;
}

Mat operator^(const Mat &a, long long N){
  Mat cnt, base = a;
  cnt.init();
  while(N){
    if(N & 1)
      cnt = cnt * base;
    base = base * base;
    N >>= 1;
  }
  return cnt;
}

Mat mat, ans;

int main(){

  scanf("%ld%lld", &n, &k);
  for(long i = 1; i <= n; i++)
    for(long j = 1; j <= n; j++){
      scanf("%ld", &_t);
      mat.data[i][j] = _t;
    }
  ans = mat ^ k;
  for(long i = 1; i <= n; i++){
    for(long j = 1; j <= n; j++){
      printf("%lld ", ans.data[i][j]);
    }
    printf("\n");
  }


  return 0;

}
