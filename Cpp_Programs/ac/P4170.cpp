// P4170 [CQOI2007]涂色
// https://www.luogu.org/problemnew/show/P4170

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

string str;
long _dp[51][51], n, MAXN;
// dp[i][j] [i][j]最小的涂色次数

long dp(long i, long j){
  if(_dp[i][j] != MAXN) return _dp[i][j];
  if(str[i] == str[j]){
    // 同时涂色
    _dp[i][j] = min(_dp[i][j], min(dp(i+1, j), dp(i, j-1)));
  }
  // 不同时涂色
  for(long k = i; k < j; k++){
    _dp[i][j] = min(_dp[i][j], dp(i, k) + dp(k+1, j));
  }
  return _dp[i][j];
}

int main(){

  cin>>str;
  n = str.length();
  memset(_dp, 0x3f, sizeof(_dp));
  MAXN = _dp[0][0];
  for(long i = 0; i < n; i++){
    _dp[i][i] = 1;
  }
  cout<<dp(0, n - 1)<<endl;

  return 0;

}
