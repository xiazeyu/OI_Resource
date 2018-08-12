// P2384 ���·
// https://www.luogu.org/problemnew/show/P2384

// Status: REx10, ��������������, ������

// Problem: ��������pre����

// WARN: Dijkstra �ɳ�ʱ (!vis[v]) ���� (#16)
// WARN: �ڽӱ��¼pre�������ұ� (#17)

#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3f, MOD = 9987;

struct Node{
  long v, w;
  Node(long no = 0, long weight = 0){
    v = no; w = weight;
  }
  bool operator< (const Node &b) const {
    return w > b.w;
  }
};

long n, m, x, y, z, ans = 1;
vector<vector<Node> > Edge;
vector<bool> vis;
vector<long> dist, pre;
priority_queue<Node, vector<Node> > q;

int main(){

  scanf("%ld%ld", &n, &m);
  Edge.resize(n + 8);
  vis.resize(n + 8);
  pre.resize(n + 8);
  dist.resize(n + 8, maxL);
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &z);
    if((x != y) && (x >= 0) && (x <= n) && (y >= 0) && (y <- n))
      Edge[x].push_back(Node(y, z));
  }
  dist[1] = 0;
  q.push(Node(1, 0));
  for(long i = 1; i <= n; i++){
    if(q.empty()) continue;
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
      if((!vis[v]) && (dist[v] > dist[pos] + w)){ // Dijkstra �ɳ�ʱ (!vis[v])
        dist[v] = dist[pos] + w;
        q.push(Node(v, dist[v]));
        pre[v] = pos;
      }
    }
  }

  // for(long i = 1; i <= n; i++) cout<<"pre["<<i<<"]="<<pre[i]<<endl;
  long point = n;
  do{
    long i;
    for(long i = 0; i < Edge[pre[point]].size(); i++){ // �ڽӱ��¼pre�������ұ�
      if(Edge[pre[point]][i].v == point) break;
    }
    ans *= (Edge[pre[point]][i].w % MOD);
    ans %= MOD;
    point = pre[point];
  }while(point != 1);

  printf("%ld\n", ans);

  return 0;

}
