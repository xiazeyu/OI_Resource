#include <bits/stdc++.h>

using namespace std;

long n;
// long long dp[108][2] = {0};
string dp[108][2];

const string ita = "0123456789";

/*
long dfs(long remain, long direction){
  // remain 剩余步数
  // direction 0 - 任意, 1 - 左或右
  if((remain == 1) && (direction == 0))
    return 3;
  if((remain == 1) && (direction == 1))
    return 2;
  if(direction == 0)
    return 2 * dfs(remain - 1, 1) + dfs(remain - 1, 0);
  if(direction == 1)
    return dfs(remain - 1, 1) + dfs(remain - 1, 0);
}
*/

string add(string a, string b){
  long sA = a.size(), sB = b.size(), maxS, dA, dB, t;
  string tA, tB, sum;
  bool over = false;
  maxS = max(a.size(), b.size());
  // 对齐
  for(long i = 1; i <= maxS - sA; i++){
    tA += "0";
  }
  for(long i = 1; i <= maxS - sB; i++){
    tB += "0";
  }
  tA += a; tB += b;
  for(long i = maxS - 1; i >= 0; i--){
    dA = tA[i] - '0';
    dB = tB[i] - '0';
    t = dA + dB;
    if(over){
      t++; over = false;
    }
    if(t >= 10){
      over = true;
      t %= 10;
      sum = ita[t] + sum;
    }else{
      over = false;
      sum = ita[t] + sum;
    }
  }
  if(over) sum = '1' + sum;
  return sum;
}

int main(){
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);

  cin>>n;
  // dp[0][0] = 0; dp[0][1] = 0;
  // dp[1][0] = 3; dp[1][1] = 2;
  dp[0][0] = "0"; dp[0][1] = "0";
  dp[0][2] = "3"; dp[1][1] = "2";
  for(long i = 2; i<= 100; i++){
    dp[i][1] = add(dp[i - 1][1], dp[i - 1][0]);
    dp[i][0] = add(add(dp[i - 1][1], dp[i - 1][1]), dp[i - 1][0]);
  }
  cout<<dp[n][0]<<endl;
  // printf("%ld\n", dfs(n, 0));

  fclose(stdin);
  fclose(stdout);
  return 0;

}
