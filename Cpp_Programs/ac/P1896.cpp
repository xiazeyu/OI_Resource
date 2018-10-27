// P1896 [SCOI2005]互不侵犯
// https://www.luogu.org/problemnew/show/P1896

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, m, pStat[1<<10], pCnt[1<<10], pN = 0;
long long dp[10][1<<10][90], ans;
// 当前第i行状态为j放了k个国王

void preProcess(long _pos,long _status, long kingCnt){
// 当前正在在_pos放置国王kingCnt, 当前状态为_status
  if(_pos >= n){
    pStat[++pN] = _status;
    pCnt[pN] = kingCnt;
    return;
  }
  preProcess(_pos + 1, _status, kingCnt);
  preProcess(_pos + 2, _status | (1 << _pos), kingCnt + 1);
}

int main(){

  scanf("%ld%ld", &n, &m);
  preProcess(0, 0, 0);
  // dp[i][j][k] = sum{dp[i-1][__allStat__(t)][k' - k]}
  dp[0][0][0] = 1;
  for(long i = 1; i <= n; i++)
    for(long j = 1; j <= pN; j++)
      for(long k = m; k >= pCnt[j]; k--)
        for(long t = 1; t <= pN; t++){
          if((pStat[j] & pStat[t])||(pStat[j] & (pStat[t] << 1))||(pStat[j] & (pStat[t] >> 1))) continue;
          dp[i][pStat[j]][k] += dp[i-1][pStat[t]][k-pCnt[j]];
        }

  for(long i = 1; i <= pN; i++)
    ans += dp[n][pStat[i]][m];
  printf("%lld\n", ans);

  return 0;

}
