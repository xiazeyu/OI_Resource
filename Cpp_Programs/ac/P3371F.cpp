// P3371 【模板】单源最短路径（弱化版）
// https://www.luogu.org/problemnew/show/P3371

// Status: MLEx3, ACx7

// Floyd

// WARN: SPFA: 会dist+dist, 小心溢出 (#14)

#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3f;

vector<vector<long> > dist;
long n, m, s, f, g, w;

long c(long i){
  if(i == 0x3f3f3f3f) return 2147483647;
  return i;
}

int main(){

  scanf("%ld%ld%ld", &n, &m, &s);
  dist.resize(n + 1);
  for(long i = 0; i < n + 1; i++){
    dist[i].resize(n + 1, maxL);
    dist[i][i] = 0;
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &f, &g, &w);
    if(f != g){
      dist[f][g] = min(dist[f][g], w);
    }
  }
  for(long a = 1; a <= n; a++){
    for(long i = 1; i <= n; i++){
      for(long j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][a] + dist[a][j])
          dist[i][j] = dist[i][a] + dist[a][j];
      }
    }
  }

  for(long i = 1; i < n; i++){
    printf("%ld ", c(dist[s][i]));
  }printf("%ld", c(dist[s][n]));

  return 0;

}
