// https://www.luogu.org/problemnew/show/U28036
// TODO: Ò»Öª°ë½â; Q1

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353, calMax = 2018;

int cal[calMax][calMax] = {0}, n, q;
long ans = 0, x, y;
vector<int> a;

void getCal(){
  for(int i = 0; i < calMax; i++){
    cal[i][0] = 1;
  }
  for(int i = 1; i < calMax; i++){
    for(int j = 1; j <= i; j++){
      cal[i][j] = (cal[i - 1][j] % MOD + cal[i - 1][j - 1] % MOD) % MOD;
    }
  }
}

int main(){

  getCal();
  scanf("%d", &n);
  a.resize(n + 4);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  while(q--){
    ans = 0;
    scanf("%ld%ld", &x, &y);
    for(long i = 0, j = y; i <= x; i++){
      ans += ((1l) * cal[x][i] * a[j]) % MOD;
      if (ans>=MOD) ans-=MOD; // Q1
      j++;
      if(j > n) j = 1;
    }
    printf("%ld\n", ans);
  }

  return 0;

}
