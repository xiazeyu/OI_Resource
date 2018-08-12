// P3371 【模板】单源最短路径（弱化版）
// https://www.luogu.org/problemnew/show/P3371

// Status: AC

// SPFA 邻接表 + 队列优化 + vis 标记优化

#include <bits/stdc++.h>

using namespace std;

const long maxL = 2147483647;

struct Node {
  long v, w;
  Node(long no, long weight) {
    v = no;
    w = weight;
  }
};

long n, m, s, f, g, w;
vector<vector <Node> > Edge;
vector<long> dist;
vector<bool>vis; // vis含义为当前节点是否在队列中, 避免重复入队
queue<long> q; // 优先用松弛的先后顺序松弛其他点

int main() {

  scanf("%ld%ld%ld", &n, &m, &s);
  dist.resize(n + 1, maxL);
  Edge.resize(n + 1);
  for(long i = 1; i <= m; i++) {
    scanf("%ld%ld%ld", &f, &g, &w);
    if(f != g) {
      Edge[f].push_back(Node(g, w));
    }
  }

  dist[s] = 0;
  q.push(0);
  while(!q.empty()) {
    long pos = q.front();
    q.pop();
    for(long i = 0; i < Edge[pos].size(); i++) {
      long v = Edge[pos][i].v, w = Edge[pos][i].w;
      if(dist[v] > dist[pos] + w) {
        dist[v] = dist[pos] + w;
          q.push(v);
      }
    }
  }

  for(long i = 1; i < n; i++) {
    printf("%ld ", dist[i]);
  }
  printf("%ld\n", dist[n]);

  return 0;

}
