#include <bits/stdc++.h>

using namespace std;

#define MAXN 15
struct edge{
  long v, w;
  edge(long node = 0, long weight = 0){
    v = node; w = weight;
  }
};
struct h{
  long no, w, k;
  bool operator<(const h &b) const {
    return w < b.w;
  }
  h(long a = 0, long b = 0, long c = 0){
    no = a; w = b; k = c;
  }
};

long n, m, _x, _y, _v, dist[MAXN][MAXN], done[MAXN], ans = 0x3f3f3f3f;
priority_queue<h, vector<h> > q;
vector<edge> Edge[MAXN];


int main(){
  freopen("treasure.in", "r", stdin);
  freopen("treasure.out", "w", stdout);
  scanf("%ld%ld", &n, &m);
  memset(dist, 0x3f, sizeof(dist));
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &_x, &_y, &_v);
    if(_x == _y) continue;
    if(dist[_x][_y] > _v){
      Edge[_x].push_back(edge(_y, _v));
      Edge[_y].push_back(edge(_x, _v));
      dist[_x][_y] = _v;
      dist[_y][_x] = _v;
    }
    for(long i = 1; i <= n; i++){
      memset(done, 0, sizeof(done));
      long tans = 0;
      while(!q.empty())
        q.pop();
      q.push(h(i, 0, 1));
      while(!q.empty()){
        h tp = q.top();
        if(done[tp.no]){
          q.pop();
          continue;
        }
        done[tp.no] = 1;
        tans += tp.w;
        q.pop();
        for(long j = 0; j < Edge[tp.no].size(); j++){
          if(!done[dist[tp.no][j]])
            q.push(h(Edge[tp.no][j].v, Edge[tp.no][j].w * tp.k, tp.k + 1));
        }
      }
      ans = min(ans, tans);
    }
  }
  printf("%ld\n", ans);

  return 0;
}
