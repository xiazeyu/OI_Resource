// ��1���������Ĵ�
//     ����һ���ַ�����ɵ�����,ÿ�ο��Խ�����һ�λ���������ȥ����ȥ���������߻�ӵ�һ���������������������������С�
// �������ʽ��һ��һ���ַ������ַ�������<10000��
// �������ʽ��һ��һ����������ʾ���ٴ��������������У�
// ˵���������ַ����Կ����ǻ���
// ���������롿aabbaacdde
// �����������4


// Status: ������

// Problem:

#include <bits/stdc++.h>

using namespace std;

string str;
long dp[10000][10000];
// dp[i][j] str[i, j]��������ȥ�Ĵ���

int main(){

  cin>>str;
  memset(dp, 0x3f, sizeof(dp));
  for(long i = 0; i < str.length(); i++) dp[i][i] = 1;
  for(long len = 2; len <= str.length(); len++){
    // len: �ַ�������
    for(long i = 0; i <= str.length() - len; i++){
      // i: ��ʼλ��
      long j = i + len - 1; // j: ��ֹλ��
      for(long k = i; k < j; k++){
        // dp[i][j] = min{dp[i][k] + dp[k + 1][j]}
        if(dp[i][j]>dp[i][k] + dp[k+1][j])
          dp[i][j] = dp[i][k] + dp[k+1][j]; //
      }
      if(str[i] == str[j]){
        // ���л���
        if(len == 2) dp[i][j] = 1;
        if(len > 2)
          dp[i][j] = min(dp[i][j], dp[i+1][j-1]); // ͬʱ��ȥ
      }
    }
  }

  cout<<dp[0][str.length() - 1]<<endl;


  return 0;

}
