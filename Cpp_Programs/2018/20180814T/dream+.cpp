#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x7fffffff;

struct Node{
  long v, w;
  Node(long no = 0, long weight = maxL){
    v = no; w = weight;
  }
  bool operator< (const Node &b) const {
    return w > b.w;
  }
};

long n, m, x, y, c, s, t, qust, u, v, deans;
vector<bool> vis;
vector<long> dist;
vector<vector <Node> > Edge;
vector<long> pre;
priority_queue<Node, vector<Node> > q;

long dijkstra(){
  // Init
  while(!q.empty()) q.pop();
  vis.resize(0); vis.resize(n + 1);
  dist.resize(0); dist.resize(n + 1, maxL);

  dist[s] = 0;
  q.push(Node(s, 0));
  for(long i = 1; i <= n; i++){
    if(q.empty()) continue;
    // Ñ°ÕÒpos
    long pos;
    do{
      pos = q.top().v;
      q.pop();
    }while((vis[pos]) && (!q.empty()));
    // È¾É«
    vis[pos] = true;
    // ËÉ³Ú
    for(long j = 0; j < Edge[pos].size(); j++){
      long v = Edge[pos][j].v, w = Edge[pos][j].w;
      if((!vis[v]) && ((long long)dist[v] > (long long)w + (long long)dist[pos])){
        dist[v] = w + dist[pos];
        q.push(Node(v, dist[v]));
      }
    }
  }
  return dist[t];
}

int main(){

  freopen("dream.in", "r", stdin);
  freopen("dream.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  Edge.resize(n + 1);
  pre.resize(n + 1);
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &c);
    if(x != y){
      Edge[x].push_back(Node(y, c));
      Edge[y].push_back(Node(x, c));
    }
  }
  scanf("%ld%ld%ld", &s, &t, &qust);

  // -- Running MST
  while(!q.empty()) q.pop();
  vis.resize(0); vis.resize(n + 1);
  dist.resize(0); dist.resize(n + 1, maxL);

  dist[s] = 0;
  q.push(Node(s, 0));
  for(long i = 1; i <= n; i++){
    if(q.empty()) continue;
    // Ñ°ÕÒpos
    long pos;
    do{
      pos = q.top().v;
      q.pop();
    }while((vis[pos]) && (!q.empty()));
    // È¾É«
    vis[pos] = true;
    // ËÉ³Ú
    for(long j = 0; j < Edge[pos].size(); j++){
      long v = Edge[pos][j].v, w = Edge[pos][j].w;
      if((!vis[v]) && ((long long)dist[v] > (long long)w + (long long)dist[pos])){
        dist[v] = w + dist[pos];
        q.push(Node(v, dist[v]));
        pre[v] = pos;
      }
    }
  }
    deans = dist[t];
  // -- End running MST

  // printf("\n%ld\n\n\n", deans);
  // for(long i = 1; i <= n; i++) printf("%ld-%ld\n", i, pre[i]);

  for(long i = 1; i <= qust; i++){
    scanf("%ld%ld", &u, &v);
    if(!((pre[u] == v) || (pre[v] == u))){
      printf("%ld\n", deans);
      continue;
    }
    long ow = -1, pInU = -1, pInV = -1;
    for(long j = 0; j <= Edge[u].size(); j++){
      if(Edge[u][j].v == v){
        ow = Edge[u][j].w;// cout<<"ow"<<ow<<endl;
        pInU = j;// cout<<"foundU"<<pInU<<" "<<Edge[u][pInU].w<<endl;
        Edge[u][pInU].w = maxL;// cout<<"setU"<<Edge[u][pInU].w<<endl;
        break;
      }
    }
    for(long j = 0; j <= Edge[v].size(); j++){
      if(Edge[v][j].v == u){
        pInV = j;// cout<<"foundV"<<pInV<<" "<<Edge[v][pInV].w<<endl;
        Edge[v][pInV].w = maxL;// cout<<"setU"<<Edge[v][pInV].w<<endl;
        break;
      }
    }
    long ans = dijkstra();
    if (pInU != -1) Edge[u][pInU].w = ow;// cout<<"reSetU"<<Edge[u][pInU].w<<endl;
    if (pInV != -1) Edge[v][pInV].w = ow;// cout<<"reSetU"<<Edge[u][pInU].w<<endl;
    if(ans == maxL){
      printf("Infinity\n");
    }else{
      printf("%ld\n", ans);
    }
  }

  fclose(stdin);
  fclose(stdout);
  return 0;

}
