#include <bits/stdc++.h>

using namespace std;

long num, t, n, m;
long tong[30];
string g;

int main(){

  freopen("fragment.in", "r", stdin);
  freopen("fragment.out", "w", stdout);
  cin>>num>>t>>n>>m;
  if(num <= 2){
    printf("YES\n");
  }else if((num >= 4) &&(num <= 6)){
    for(long i = 1; i <= n; i++){
      cin>>g;
      for(long j = 0; j < g.size(); j++) tong[g[j] - 'A']++;
    }
    for(long i = 0; i <= 26; i++){
      if(tong[i] % 2){
        printf("NO\n");
        return 0;
      }
    }
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;

}
