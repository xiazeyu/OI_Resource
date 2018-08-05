//ÌøÊ¯Í·
#include<bits/stdc++.h>
using namespace std;
int d[50010],N,M,L;
bool check(int x){
	int pre=0,cnt=0;
	for(int i=1;i<=N;i++){
		if(d[i]-d[pre]<x)
			cnt++;
		else
			pre=i;
	}
	if(d[N+1]-d[pre]<x) cnt++;
	if(cnt<=M) return true;
	else return false;
}
int main(){
	cin>>L>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>d[i];
	d[0]=0;
	d[N+1]=L;
	int l=1,r=L+1,mid,ans;
	while(l<r){
		mid=(l+r)/2;
		if(check(mid)==true){
			ans=mid;
			l=mid+1;
		}
		else
			r=mid;
	}
	cout<<ans<<endl;
	return 0;
}
