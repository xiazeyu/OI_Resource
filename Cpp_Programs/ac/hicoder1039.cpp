// 例1、消除回文串
//     给定一个字符串组成的序列,每次可以将连续一段回文序列消去，消去后左右两边会接到一起，求最少消几次能消完整个序列。
// 【输入格式】一行一个字符串（字符串长度<10000）
// 【输出格式】一行一个整数，表示多少次能消完整个序列（
// 说明：单个字符可以看作是回文
// 【样例输入】aabbaacdde
// 【样例输出】4


// Status: 过样例

// Problem:

#include <bits/stdc++.h>

using namespace std;

string str;
long dp[10000][10000];
// dp[i][j] str[i, j]中最少消去的次数

int main(){

  cin>>str;
  memset(dp, 0x3f, sizeof(dp));
  for(long i = 0; i < str.length(); i++) dp[i][i] = 1;
  for(long len = 2; len <= str.length(); len++){
    // len: 字符串长度
    for(long i = 0; i <= str.length() - len; i++){
      // i: 起始位置
      long j = i + len - 1; // j: 终止位置
      for(long k = i; k < j; k++){
        // dp[i][j] = min{dp[i][k] + dp[k + 1][j]}
        if(dp[i][j]>dp[i][k] + dp[k+1][j])
          dp[i][j] = dp[i][k] + dp[k+1][j]; //
      }
      if(str[i] == str[j]){
        // 特判回文
        if(len == 2) dp[i][j] = 1;
        if(len > 2)
          dp[i][j] = min(dp[i][j], dp[i+1][j-1]); // 同时消去
      }
    }
  }

  cout<<dp[0][str.length() - 1]<<endl;


  return 0;

}
