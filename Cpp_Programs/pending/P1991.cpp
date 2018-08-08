// P1991 无线通讯网
// https://www.luogu.org/problemnew/show/P1991
// http://poj.org/problem?id=2349

// Status: AC on luogu, WA on POJ

// Problem: Heap

#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3f;

struct Node{
  long v;
  long double w;
  Node(long index = 0, long double weight = 0){
    v = index; w = weight;
  }
  bool operator< (const Node &b) const {
    return w > b.w;
  }
};

long s, p;
double output;
vector<bool> vis;
vector<long> mapX, mapY;
vector<long double> dist;
vector<vector<Node> > Edge;
priority_queue<Node, vector<Node> > h;
priority_queue<long double, vector<long double> > MSTEdge;

int main(){

  scanf("%ld%ld", &s, &p);
  vis.resize(p + 1);
  dist.resize(p + 1, maxL);
  Edge.resize(p + 1);
  mapX.resize(p + 1);
  mapY.resize(p + 1);
  for(long i = 1; i <= p; i++){
    scanf("%ld%ld", &mapX[i], &mapY[i]);
    for(long j = i; j >= 1; j--){
      long double tmp = sqrt(pow(abs(mapX[i] - mapX[j]), 2) + pow(abs(mapY[i] - mapY[j]), 2));
      if(i != j){
        // cout<<"!"<<tmp<<endl;
        Edge[i].push_back(Node(j, tmp));
        Edge[j].push_back(Node(i, tmp));
      }
    }
  }

  dist[1] = 0; h.push(Node(1, 0));
  for(long i = 1; i <= p; i++){
    long pos;
    // 寻找pos
    do{
      pos = h.top().v;
      h.pop();
    }while(vis[pos]);
    // 染色
    vis[pos] = true;
    MSTEdge.push(dist[pos]);
    // 松弛
    for(long j = 0; j < Edge[pos].size(); j++){
      long v = Edge[pos][j].v;
      if((!vis[v]) && dist[v] > Edge[pos][j].w){
        dist[v] = Edge[pos][j].w;
        h.push(Node(v, dist[v]));
      }
    }
  }

  for(long i = 1; i < s; i++){
    MSTEdge.pop();
  }

  output = MSTEdge.top();

  printf("%.2f", output);

  return 0;

}
