// P3371 ��ģ�塿��Դ���·���������棩
// https://www.luogu.org/problemnew/show/P3371

// Status: AC

// Dijkstra �ڽӱ�

// WARN: spfaÿ���ɳ����·���ϵ�һ����, ȷ��һ��������: while(!q.empty()); dijkstraÿ����һ����: while(!q.empty()) > for(long i = 1; i <= n; i++)
// WARN: ���ȶ�������ͨ��(�����Ƿ�Ϊ�� if(q.empty()) continue; ) (#10)

#include <bits/stdc++.h>

using namespace std;

const long maxN = 2147483647;

struct Node{
  long v, w;
  Node(long no = 0, long weight = 0){
    v = no; w = weight;
  }
  bool operator< (const Node &b) const {
    return w > b.w;
  }
};

long n, m, s, f, g, w;
vector<vector <Node> > Edge;
vector<long> dist;
vector<bool> vis;
priority_queue<Node, vector<Node> > q;

int main(){

  scanf("%ld%ld%ld", &n, &m, &s);
  Edge.resize(n + 1);
  dist.resize(n + 1, maxN);
  vis.resize(n + 1);
  for(long i = 1; i <= m; i++){ // ������
    // �ڽӱ�洢
    scanf("%ld%ld%ld", &f, &g, &w);
    if(f != g){
      Edge[f].push_back(Node(g, w));
    }
  }

  dist[s] = 0;
  q.push(Node(s, 0));
  // while(!q.empty()){ // ?????????
  for(long i = 1; i <= n; i++){
    if(q.empty()) continue; // ?????
    // Ѱ�� pos
    long pos;
    do{
      pos = q.top().v;
      q.pop();
    }while((vis[pos]) && (!q.empty()));
    // Ⱦɫ
    vis[pos] = true;
    // �ɳ�
    for(long i = 0; i < Edge[pos].size(); i++){
      long v = Edge[pos][i].v, w = Edge[pos][i].w;
      if((!vis[v]) && (dist[v] > w + dist[pos])){
        dist[v] = w + dist[pos];
        q.push(Node(v, dist[v]));
      }
    }
  }

  for(long i = 1; i < n; i++){
    printf("%ld ", dist[i]);
  }
  printf("%ld", dist[n]);

  return 0;

}
