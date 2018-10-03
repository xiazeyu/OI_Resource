// P1880 [NOI1995]ʯ�Ӻϲ�
// https://www.luogu.org/problemnew/show/P1880

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, a[101], dpmin[202][202], dpmax[202][202], sum[202], ansMin = 0x3f3f3f3f, ansMax;
// dpmin[i][j] [i, j]�ϲ�����С�÷�
// dpmax[i][j] [i, j]�ϲ������÷�

int main(){

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  for(long i = n + 1; i <= 2 * n; i++){
    sum[i] = sum[i - 1] + a[i - n]; // �ƻ����
  }
  memset(dpmin, 0x3f, sizeof(dpmin));
  for(long i = 1; i <= 2 * n; i++){
    dpmin[i][i] = 0;
  }
  for(long len = 2; len < 2 * n; len++){
    // len: ���䳤��
    for(long i = 1; i <= 2 * n - len; i++){
      // i: ��ʼλ��
      long j = i + len - 1; // j: ��ֹλ��
      for(long k = i; k < j; k++){
        dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k+1][j] + sum[j] - sum[i - 1]);
        dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k+1][j] + sum[j] - sum[i - 1]);
      }
    }
  }

  for(long i = 1; i <= n; i++){ // ��
    ansMax = max(ansMax, dpmax[i][i + n - 1]);
    ansMin = min(ansMin, dpmin[i][i + n - 1]);
  }

  printf("%ld\n%ld\n", ansMin, ansMax);


  return 0;

}
