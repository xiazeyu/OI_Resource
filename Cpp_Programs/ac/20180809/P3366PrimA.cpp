// P3366 【模板】最小生成树
// https://www.luogu.org/problemnew/show/P3366

// Prim 邻接表

// Status: AC

// Question: 该图不连通 这样写对吗

#include <limits.h>
#include <bits/stdc++.h>

const long maxL = 0x3f3f3f3f;

using namespace std;

struct Node{
  long v, w;
  Node(long a = 0, long b = 0){
    v = a; w = b;
  }
};

vector<bool> vis;
vector<long> dist;
vector<vector<Node> > Edge;
long n, m, x, y, z, ans = 0;

int main(){

  scanf("%ld%ld", &n, &m);
  vis.resize(n + 1);
  dist.resize(n + 1, maxL);
  Edge.resize(n + 1);
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &z);
    Edge[x].push_back(Node(y, z));
    Edge[y].push_back(Node(x, z));
  }
  dist[1] = 0;
  for(long i = 1; i <= n; i++){
    long pos = 0; // 找到v集合的最近点
    for(long j = 1; j <= n; j++){
      if((!vis[j])&&(dist[j] < dist[pos])) pos = j;
    }
    if(pos == 0){ // 未找到与v连通的点
      printf("orz\n");
      return 0;
    }
    vis[pos] = true; // pos 涂色
    ans += dist[pos];

    for(long j = 0; j < Edge[pos].size(); j++){ // 松弛 v
      long v = Edge[pos][j].v;
      if((!vis[v]) && (dist[v] > Edge[pos][j].w)){
        dist[v] = Edge[pos][j].w;
      }
    }
  }

  printf("%ld\n", ans);

  return 0;

}
