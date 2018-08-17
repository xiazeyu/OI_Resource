#include <bits/stdc++.h>

using namespace std;

const long maxN = 0x3f3f3f3f;

long n, m, ans, c, x, y;
long mat[201][201], dist[201][201];

void floyd(){
  memcpy(dist, mat, sizeof(mat));
  for(long a = 1; a <= n; a++){
    for(long i = 1; i <= n; i++){
      for(long j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][a] + dist[a][j]){
          dist[i][j] = dist[i][a] + dist[a][j];
        }
      }
    }
  }
  return;
}

void printMat(){
  for(long i = 1; i <= n; i++){
    for(long j = 1; j <= n; j++){
      printf("[%ld][%ld]=%ld(%ld) ", i, j, mat[i][j], dist[i][j]);
    }printf("\n");
  }
}

int main(){
  freopen("journey.in", "r", stdin);
  freopen("journey.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 1; i <= n; i++){
    for(long j = 1; j <= n; j++){
      scanf("%ld", &mat[i][j]);
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &c, &x, &y);
    if(c == 1){
      if(mat[x][y] < maxN){
        mat[x][y] = maxN;
      }
    }else{
      floyd();
      // printMat();
      if(dist[x][y] >= maxN){
        printf("-1\n");
      }else{
        printf("%ld\n", dist[x][y]);
      }
    }
  }

  return 0;

}
