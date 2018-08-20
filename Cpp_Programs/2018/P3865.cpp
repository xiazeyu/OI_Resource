// P3865 ��ģ�塿ST��
// https://www.luogu.org/problemnew/show/P3865

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, m, st[100008][20], x, y;
// st[i][j] ��¼�ӵ�iλ��ʼ2^j��Ԫ���е����ֵ
// st[i][j] ��¼[i, i + 2^j - 1]�����ֵ

long log2(long inp){
  long ans = 0;
  while(inp){
    ans++;
    inp >>= 1;
  }
  return ans;
}

void stInit(){
  for(long j = 1; j <= log2(n); j++){
    for(long i = 0; i < n; i++){
      // ��[i, j]������Ϊ2��������[i, i + 2^(j-1) - 1], [i + 2^(j - 1), j]
      st[i][j] = st[i][j - 1];
      if(i + (1<<(j - 1)) < n)
        st[i][j] = max(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
    }
  }
  return;
}

long rmq(long i, long j){
  long m = log2(j - i + 1);
  return max(st[i][m], st[j - (1<<m) + 1][m]);
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 0; i < n; i++){
    scanf("%ld", &st[i][0]);
  }
  stInit();
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld", &x, &y);
    printf("%ld\n", rmq(x, y));
  }

  return 0;

}
