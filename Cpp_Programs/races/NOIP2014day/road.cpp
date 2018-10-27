#include <bits/stdc++.h>

using namespace std;

const long MAXN = 0x3f3f3f3f;

long n, m, _x, _y, s, t, dist[10004];
vector<long> Edge[10004], rEdge[10004];
bool vis[10004];
priority_queue<long, vector<long> > q;

void rDfs(long n){
  vis[n] = true;
  for(long i = 0; i < rEdge[n].size(); i++){
    long u = rEdge[n][i];
    if(!vis[u]) rDfs(u);
  }
}

int main(){

  // freopen("road.in", "r", stdin);
  // freopen("road.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld", &_x, &_y);
    if(_x == _y) continue;
    Edge[_x].push_back(_y);
    rEdge[_y].push_back(_x);
  }
  scanf("%ld%ld", &s, &t);
  rDfs(t);
  for(long i = 1; i <= n; i++){
    bool flag = false;
    for(long j = 0; j < Edge[i].size(); j++)
    if(vis[Edge[i][j]]){
      flag = true;
      break;
    }
    if(!flag) Edge[i].clear();
  }
  memset(vis, 0, sizeof(vis));
  memset(dist, 0x3f, sizeof(dist));

  dist[s] = 0;
  q.push(s);
  for(long i = 1; i <= n; i++){
    if(q.empty()) continue;
    long pos;
    do{
      pos = q.top();
      q.pop();
    }while((vis[pos]) && (!q.empty()));
    vis[pos] = true;
    for(long j = 0; j < Edge[pos].size(); j++){
      long v = Edge[pos][j];
      if((!vis[v]) && (dist[v] > dist[pos] + 1)){
        dist[v] = dist[pos] + 1;
        q.push(v);
      }
    }
  }

  if(dist[t] == MAXN)
    printf("-1\n");
  else
    printf("%ld\n", dist[t]);

  return 0;

}
