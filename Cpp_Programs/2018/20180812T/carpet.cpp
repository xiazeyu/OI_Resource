#include <bits/stdc++.h>

using namespace std;

struct Edge{
  long a, b, w;
  Edge(long fromNo = 0, long toNo = 0, long weight = 0){
    a = fromNo; b = toNo; w = weight;
  }
  bool operator< (const Edge &b) const {
    return w > b.w;
  }
};

long n, m, k, a, b, c, cnt = 0, point = 0;
vector<Edge> pool;
vector<long> par;

long Find(long a){
  if(par[a] == a) return a;
  return par[a] = Find(par[a]);
}

void Join(long a, long b){
  par[Find(a)] = Find(b);
  return;
}

int main(){

  freopen("carpet.in", "r", stdin);
  freopen("carpet.out", "w", stdout);

  scanf("%ld%ld%ld", &n, &m, &k);
  pool.resize(m);
  par.resize(n + 1);
  for(long i = 0; i <= n; i++){
    par[i] = i;
  }
  for(long i = 0; i < m; i++){
    scanf("%ld%ld%ld", &a, &b, &c);
    if(a != b)
      pool[i] = Edge(a, b, c);
  }
  sort(pool.begin(), pool.end());
  while((k) && (point <= m)){
    // cout<<"test: "<<point<<" "<<pool[point].a<<" "<<pool[point].b<<" "<<pool[point].w<<" "<<(Find(pool[point].a) == Find(pool[point].b))<<endl;
    // for(long i = 1; i <= n; i++) cout<<par[i]<<" "; cout<<endl<<endl;
    if(Find(pool[point].a) == Find(pool[point].b)){
      point++;
      continue;
    }
    k--;
    cnt += pool[point].w;
    Join(pool[point].a, pool[point].b);
    point++;
  }

  printf("%ld\n", cnt);

  fclose(stdin);
  fclose(stdout);

  return 0;

}
