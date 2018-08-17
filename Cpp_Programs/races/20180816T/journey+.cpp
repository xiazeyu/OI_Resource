#include <bits/stdc++.h>

using namespace std;

const long maxN = 0x3f3f3f3f;

struct Edge{
  long b, e;
  Edge(long Begin = 0, long End = 0){
    b = Begin; e = End;
  }
};

long n, m, ans, c, x, y;
long mat[201][201], dist[201][201], pre[201][201];
vector<Edge> changed;
queue<Edge> q;

void floyd(){
  memcpy(dist, mat, sizeof(mat));
  for(long i = 1; i <= n; i++){
    for(long j = 1; j <= n; j++)
      pre[i][j] = i;
  }
  for(long a = 1; a <= n; a++){
    for(long i = 1; i <= n; i++){
      for(long j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][a] + dist[a][j]){
          dist[i][j] = dist[i][a] + dist[a][j];
          pre[i][j] = a;
        }
      }
    }
  }
  return;
}
/*
void printMat(){
  for(long i = 1; i <= n; i++){
    for(long j = 1; j <= n; j++){
      printf("[%ld][%ld]=%ld(%ld, %ld) ", i, j, mat[i][j], dist[i][j], pre[i][j]);
    }printf("\n");
  }
}
*/
bool inMST(Edge sea, Edge ori){
  while(q.size()) q.pop();
  q.push(ori);
  while(!q.empty()){
    if((q.front().b == sea.b) && (q.front().e == sea.e)){
      return true;
    }
    if(q.front().b != pre[q.front().b][q.front().e]){
      q.push(Edge(q.front().b, pre[q.front().b][q.front().e]));
      q.push(Edge(pre[q.front().b][q.front().e], q.front().e));
    }
    q.pop();
  }
  return false;
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
  floyd();
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &c, &x, &y);
    if(c == 1){
      if(mat[x][y] < maxN){
        mat[x][y] = maxN;
        changed.push_back(Edge(x, y));
      }
    }else{
      for(long i = 0; i < changed.size(); i++){
        // printf("test: (%ld, %ld) in (%ld, %ld)\n", changed[i].b, changed[i].e, x, y);
        if(inMST(changed[i], Edge(x, y))){
          floyd();
          changed.clear();
          break;
        }
      }
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
