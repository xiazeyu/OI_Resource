// P3865 【模板】ST表
// https://www.luogu.org/problemnew/show/P3865
// http://www.cnblogs.com/zwfymqz/p/8581995.html

// Status: AC

// Problem: log2函数中, 注意最终求得为log(_n, 2)还是log(_n, 2) + 1 (while条件为 _n - 1)

#include <bits/stdc++.h>

using namespace std;

long n, m, st[100008][20], l, r;
// st[i][j]: [i, i+(1<<j)-1]
// [i, i+(1<<(j-1))-1], [i+(1<<(j-1)), j]

long Log2(long _n){
  long cnt = 0;
  while(_n - 1){ // here, _n - 1
    cnt++; _n >>= 1;
  }
  return cnt;
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &st[i][0]);
  }
  for(long j = 1; j <= Log2(n) + 1; j++){
    for(long i = 1; i+(1<<(j-1))<=n; i++){
      st[i][j] = max(st[i][j - 1], st[i+(1<<(j-1))][j - 1]);
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld", &l, &r);
    long m = Log2(r - l + 1);
    printf("%ld\n", max(st[l][m], st[r - (1 << m) + 1][m]));
  }

  return 0;

}
