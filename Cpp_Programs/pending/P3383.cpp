// P3383 【模板】线性筛素数
// https://www.luogu.org/problemnew/show/P3383

// Status: 4ms-800ms, AC

// WARN: 0, 1 不是素数 (#15)

#include <bits/stdc++.h>

using namespace std;

vector<long> prime;
vector<bool> vis;
long n, m, t, cnt = 0;

int main(){

  scanf("%ld%ld", &n, &m);
  prime.resize(n + 1);
  vis.resize(n + 1);
  for(long i = 2; i <= n; i++){
    if(!vis[i]) prime[cnt++] = i; //不是目前找到的素数的倍数, 即找到素数
    for(long j = 0; j < cnt && i * prime[j] <= n; j++){
      vis[i * prime[j]] = true; //找到的素数的倍数不再访问
      if(i % prime[j] == 0) break; // http://www.cnblogs.com/A-S-KirigiriKyoko/articles/6034572.html
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld", &t);
    if((t == 0) && (t == 1)) printf("No\n");
    if(binary_search(prime.begin(), prime.begin() + cnt, t))
      printf("Yes\n");
    else
      printf("No\n");
  }


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
