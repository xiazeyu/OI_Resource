// A4 生成组合

// Status: 样例AC

#include <bits/stdc++.h>

using namespace std;

long n, r;
vector<long> pre;
vector<bool> vis;

void dfs(long w){
  if(w > r){
    for(long i = 1; i <= r; i++){
      printf("%ld ", pre[i]);
    }printf("\n");
    return;
  }
  for(long i = 1; i <= n; i++){
    if((!vis[i]) && (i > pre[w - 1])){
      vis[i] = true;
      pre[w] = i;
      dfs(w + 1);
      vis[i] = false;
    }
  }
}

int main(){

  scanf("%ld%ld", &n, &r);
  pre.resize(n + 1);
  vis.resize(r + 1);
  dfs(1);

  return 0;

}
