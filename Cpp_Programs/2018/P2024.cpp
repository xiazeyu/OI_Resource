#include <bits/stdc++.h>

using namespace std;

long n, k, x, y, t, ans = 0;

vector<long> par;

int Find(long a){
  if(a == par[a]) return a;
  return par[a] = Find(par[a]);
}

void Join(long a, long b){
  par[Find(a)] = par[Find(b)];
  return;
}

int main(){

  scanf("%ld%ld", &n, &k);
  par.resize(n + 1);
  for(long i = 1; i <= n; i++){
    par[i] = i;
  }
  for(long i = 1; i <= k; i++){
    scanf("%ld%ld%ld", &t, &x, &y);
    if((x == y)||(x > n)||(y > n)){
      ans++;
      continue;
    }
    if(t == 1){
      if(Find(x) != Find(y)){
        if((Find(x) == x)||(Find(x) == y)){
          Join(x, y);
        }else{
          ans++;
          continue;
        }
      }
    }
  }

  return 0;

}
