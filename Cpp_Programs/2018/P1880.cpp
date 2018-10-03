// P1880 [NOI1995]石子合并
// https://www.luogu.org/problemnew/show/P1880

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, a[101], dpmin[202][202], dpmax[202][202], sum[202], ansMin = 0x3f3f3f3f, ansMax;
// dpmin[i][j] [i, j]合并的最小得分
// dpmax[i][j] [i, j]合并的最大得分

int main(){

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  for(long i = n + 1; i <= 2 * n; i++){
    sum[i] = sum[i - 1] + a[i - n]; // 破环求和
  }
  memset(dpmin, 0x3f, sizeof(dpmin));
  for(long i = 1; i <= 2 * n; i++){
    dpmin[i][i] = 0;
  }
  for(long len = 2; len < 2 * n; len++){
    // len: 区间长度
    for(long i = 1; i <= 2 * n - len; i++){
      // i: 起始位置
      long j = i + len - 1; // j: 终止位置
      for(long k = i; k < j; k++){
        dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k+1][j] + sum[j] - sum[i - 1]);
        dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k+1][j] + sum[j] - sum[i - 1]);
      }
    }
  }

  for(long i = 1; i <= n; i++){ // 环
    ansMax = max(ansMax, dpmax[i][i + n - 1]);
    ansMin = min(ansMin, dpmin[i][i + n - 1]);
  }

  printf("%ld\n%ld\n", ansMin, ansMax);


  return 0;

}
