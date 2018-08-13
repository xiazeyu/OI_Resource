// P1706 全排列问题
// https://www.luogu.org/problemnew/show/P1706

// Status: AC

#include <bits/stdc++.h>

using namespace std;

long n;
long pre[11];
bool vis[11];

void dfs(long w){
  if(w > n){
    for(long i = 1; i <= n; i++){
      printf("%5ld", pre[i]);
    }printf("\n");
    return;
  }
  for(long i = 1; i <= n; i++){
    if(!vis[i]){
      vis[i] = true;
      pre[w] = i;
      dfs(w + 1);
      vis[i] = false;
    }
  }
}

int main(){

  scanf("%ld", &n);
  dfs(1);

  return 0;

}
