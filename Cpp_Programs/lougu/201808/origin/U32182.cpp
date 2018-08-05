#include <bits/stdc++.h>

/*
     xm=4 0 1 2 3
yn=5
0
1
2
3
4
(0 0) (1 0) (2 0) (3 0)

(0 4)(1 4)(2 4)(3 4)
(x, y)
(m, n)
[m][n]
[行][列]
*/

using namespace std;

long n, m, ans = 0/*, debug = 0*/;
const long MOD = 998244353;
vector<vector <bool> > t;

bool check(){
  long cnt = 0;
  for(long j = 0; j < m; j++){
    cnt = 0;
    for(long i = 0; i < n; i++){
      if(t[i][j]) cnt++;
    }
    if(cnt > 2) return false;
  }
  return true;
}

void dfs(long x){

  // (nowX)
  // 即将放置t[x]
  // nowX == m 时check
  if(x == m){
    ans %= MOD;
    if(check()) ans++;
    ans %= MOD;
    return;
  }
  for(long a = 0; a < n; a++){
    t[x][a] = true;
    for(long b = a + 1; b < n; b++){
      t[x][b] = true;
/*
      if(debug <= 5){
      for(long i = 0; i < n; i++){
        for(long j = 0; j < m; j++){
          if(t[i][j])printf("1");else printf("0");
        }printf("\n");
      }printf("\n\n");
      debug++;
      }
*/
      dfs(x + 1);
      t[x][b] = false;
    }
    t[x][a] = false;
  }
}

int main(){

  scanf("%ld %ld", &n, &m);
  t.resize(m + 1);
  for(long i = 0; i < m; i++){
    t[i].resize(n + 1);
  }
  dfs(0);
  printf("%ld", ans);

  return 0;

}
