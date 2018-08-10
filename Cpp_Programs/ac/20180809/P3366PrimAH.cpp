// P3366 【模板】最小生成树
// https://www.luogu.org/problemnew/show/P3366

// Status: AC

// Prim 邻接表 堆优化

#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3fL;

struct Node{
  long v, w;
  Node(long node = 0, long weight = 0){
    v = node; w = weight;
  }
  bool operator< (const Node &b) const {
    return w > b.w;
  }
};

long n, m, x, y, z, ans = 0;
vector<bool> vis;
vector<long> dist;
vector<vector<Node> > Edge;
priority_queue<Node, vector<Node> > q;

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

  dist[1] = 0; q.push(Node(1, 0));
  for(long i = 1; i <= n; i++){ // 仅计数
    // 找 pos
    long pos;
    if(q.empty()){
      printf("orz\n");
      return 0;
    }
    do{
      pos = q.top().v;
      q.pop();
    }while(vis[pos]);
    // 涂色
    vis[pos] = true;
    ans += dist[pos];
    // 松弛
    for(long j = 0; j < Edge[pos].size(); j++){ // 枚举 pos 所连边
      long v = Edge[pos][j].v;
      if((!vis[v]) && (dist[v] > Edge[pos][j].w)){
        dist[v] = Edge[pos][j].w;
        q.push(Node(v, dist[v]));
      }
    }
  }

  printf("%ld", ans);

  return 0;

}
