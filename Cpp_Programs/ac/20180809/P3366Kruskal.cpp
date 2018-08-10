// P3366 【模板】最小生成树
// https://www.luogu.org/problemnew/show/P3366

// Status: AC

// Kruskal 边集数组

#include <bits/stdc++.h>

using namespace std;


struct Edge{
  long a, b, w;
  Edge(long nodeA = 0, long nodeB = 0, long weight = 0){
    a = nodeA; b = nodeB; w = weight;
  }
  bool operator< (const Edge &b) const {
    return w < b.w;
  }
};

long m, n, x, y, z, ans = 0, cnt = 0;
vector<Edge> p;
vector<long> par;

long Find(long a){
  if(par[a] == a) return a;
  return par[a] = Find(par[a]);
}

void Join(long a, long b){
  par[Find(a)] = par[Find(b)];
  return;
}

int main(){

  scanf("%ld%ld", &n, &m);
  par.resize(n + 1);
  for(long i = 1; i <= n; i++){
    par[i] = i;
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &z);
    if(x != y){
      p.push_back(Edge(x, y, z));
    }
  }
  sort(p.begin(), p.end());
  for(long i = 0; i < m; i++){
    if(cnt == n - 1) break;
    if(Find(p[i].a) != Find(p[i].b)){
      Join(p[i].a, p[i].b);
      cnt++; ans += p[i].w;
    }
  }

  printf("%ld", ans);

  return 0;

}
