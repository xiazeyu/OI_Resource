#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
int F[MAXN][MAXN],n;
string str;
int main() {
	cin>>str;
	n=str.length();
	memset(F,0x3f,sizeof(F));
	for(int i=0; i<n; i++)F[i][i]=1; //初始化区间长度为1的消去次数
	for(int len=2; len<=n; len++)
		for(int i=0; i<=n-len; i++) {
                      int j=i+len-1;
			for(int k=i; k<j; k++)
				if(F[i][j]>F[i][k]+F[k+1][j])
					F[i][j]=F[i][k]+F[k+1][j];
			if(str[i]==str[j]) {
				if(len==2)F[i][j]=1;
				else if(len>2&&F[i][j]>F[i+1][j-1])
					F[i][j]=F[i+1][j-1];
			}
		}
	cout<<F[0][n-1];
	return 0;
} //复杂度O(n^3)

