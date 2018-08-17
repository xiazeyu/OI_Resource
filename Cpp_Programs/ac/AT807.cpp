// AT807 素数、コンテスト、素数
// https://www.luogu.org/problemnew/show/AT807

// Status:

#include <bits/stdc++.h>

using namespace std;

vector<long> prime;
vector<bool> vis;
long n, t, cnt = 0;

int main(){

  n = 1000000;
  prime.resize(n + 1);
  vis.resize(n + 1);
  for(long i = 2; i <= n / 2; i++){ // 枚举合数最大因子, i <= n / 2时 Prime[] 不全, i <= n 时 Prime[]全
    if(!vis[i]) prime[cnt++] = i; //不是目前找到的素数的倍数, 即找到素数
    for(long j = 0; j < cnt && i * prime[j] <= n; j++){// 最小因子与最大因子乘积必为合数, 筛去此数
      vis[i * prime[j]] = true; //找到的素数的倍数不再访问
      if(i % prime[j] == 0) break; // http://www.cnblogs.com/A-S-KirigiriKyoko/articles/6034572.html
    }
  }
  scanf("%ld", &t);
  if(!vis[t])
    printf("YES\n");
  else
    printf("NO\n");

  /* // 埃拉托斯特尼筛法 O(nlglgn)
  for(long i = 2; i <= n; i++){
    if(!pri[i]) continue;
    for(long j = 0; j <)

    for(long j = 2; i * j <= n; j++){
      pri[i * j] = false;
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld", &t);
    if(pri[t])
      printf("Yes\n");
    else
      printf("No\n");
  }*/
  return 0;

}
