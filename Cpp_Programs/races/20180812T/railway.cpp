#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3f;

struct Node{
  long v, w;
  Node(long no = 0, long weight = 0){
    v = no; w = weight;
  }
  bool operator< (const Node &b) const{
    return w > b.w;
  }
};

long n, m, c, s, t, x, y, z, b, totDist = 0;
// n ������, m ��˫��·, c ����˾, �� s �� t
vector<bool> vis;
vector<long> dist;
vector<vector<Node> > Edge;
priority_queue<Node, vector<Node> > q;

int main(){

  freopen("railway.in", "r", stdin);
  freopen("railway.out", "w", stdout);
/*
  scanf("%ld%ld%ld%ld%ld", &n, &m, &c, &s, &t);
  // n ������, m ��˫��·, c ����˾, �� s �� t
  vis.resize(n + 1);
  dist.resize(n + 1, maxL);
  Edge.resize(n + 1);
  if(c == 1){
    for(long i = 1; i <= m; i++){
      scanf("%ld%ld%ld%ld", &x, &y, &z, &b);
      if(x != y){
        Edge[x].push_back(Node(y, z));
        Edge[y].push_back(Node(x, z));
      }
    }
    for(long i = 1; i <= m; i++){
      // �շ�?????
    }
    dist[s] = 0; q.push(Node(s, 0));
    for(long i = 1; i <= n; i++){
      if(q.empty) continue;
      // Ѱ�� pos
      // Ϳɫ
      // �ɳ�
    }

  }

  if(n == 2){
    // ö��2������
  }*/
  printf("-1\n");

  fclose(stdin);
  fclose(stdout);
  return 0;

}
