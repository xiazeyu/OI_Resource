// P1551 亲戚
// https://www.luogu.org/problemnew/show/P1551

#include <bits/stdc++.h>

using namespace std;

long n, m, p, t1, t2;
vector<long> par;

long Find(long a){
  if(par[a] == a) return a;
  return par[a] = Find(par[a]);
}

void Join(long x, long y){
  par[Find(x)] = Find(y);
  return;
}

int main(){

  scanf("%ld%ld%ld", &n, &m, &p);
  par.resize(n + 1);
  for(long i = 1; i <= n; i++) par[i] = i;
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld", &t1, &t2);
    Join(t1, t2);
  }
  for(long i = 1; i <= p; i++){
    scanf("%ld%ld", &t1, &t2);
    if(Find(t1) == Find(t2)){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }

  return 0;

}
