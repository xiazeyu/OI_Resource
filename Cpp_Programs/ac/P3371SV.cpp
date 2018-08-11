// P3371 ��ģ�塿��Դ���·���������棩
// https://www.luogu.org/problemnew/show/P3371

// Status: AC

// SPFA �ڽӱ� + ���ȶ����Ż� + vis�Ż�

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
vector<long> vis;
priority_queue<Node, vector<Node> > q; // �����þ�������������ĵ�ȥ�ɳ�������

int main() {

  scanf("%ld%ld%ld", &n, &m, &s);
  dist.resize(n + 1, maxL);
  Edge.resize(n + 1);
  vis.resize(n + 1);
  for(long i = 1; i <= m; i++) {
    scanf("%ld%ld%ld", &f, &g, &w);
    if(f != g) {
      Edge[f].push_back(Node(g, w));
    }
  }

  dist[s] = 0;
  vis[s] = true;
  q.push(Node(s, 0));
  while(!q.empty()) {
    long pos = q.top().v;
    vis[pos] = false;
    q.pop();
    for(long i = 0; i < Edge[pos].size(); i++) {
      long v = Edge[pos][i].v, w = Edge[pos][i].w;
      if(dist[v] > dist[pos] + w) {
        dist[v] = dist[pos] + w;
        if(!vis[v]){
          q.push(Node(v, dist[v]));
          vis[v] = true;
        }
      }
    }
  }

  for(long i = 1; i < n; i++) {
    printf("%ld ", dist[i]);
  }
  printf("%ld\n", dist[n]);

  return 0;

}
