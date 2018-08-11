// P3371 【模板】单源最短路径（弱化版）
// https://www.luogu.org/problemnew/show/P3371

// Status: ACx3, TLEx2

// SPFA 邻接表 + 优先队列优化

#include <bits/stdc++.h>

using namespace std;

const long maxL = 2147483647;

struct Node {
  long v, w;
  Node(long no, long weight) {
    v = no;
    w = weight;
  }
  bool operator< (const Node &b) const {
  	return w > b.w;
  }
};

long n, m, s, f, g, w;
vector<vector <Node> > Edge;
vector<long> dist;
priority_queue<Node, vector<Node> > q; // 优先用距离起点距离最近的点去松弛其他点

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
  q.push(Node(s, 0));
  while(!q.empty()) {
    long pos = q.top().v;
    q.pop();
    for(long i = 0; i < Edge[pos].size(); i++) {
      long v = Edge[pos][i].v, w = Edge[pos][i].w;
      if(dist[v] > dist[pos] + w) {
        dist[v] = dist[pos] + w;
          q.push(Node(v, dist[v]));
      }
    }
  }

  for(long i = 1; i < n; i++) {
    printf("%ld ", dist[i]);
  }
  printf("%ld\n", dist[n]);

  return 0;

}
