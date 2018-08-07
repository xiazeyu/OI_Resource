// P1106 删数问题
// https://www.luogu.org/problemnew/show/P1106

#include <bits/stdc++.h>

using namespace std;

string ans, n;
long s;

void dfs(string str, int i){
  if(i == 0){
    if(str < ans){
      ans = str;
    }
    return;
  }
  for(int j = 0; j < str.length(); j++){
    dfs(str.substr(0, j) + str.substr(j + 1), i - 1);
  }
}

int main(){

  cin>>n;
  cin>>s;
  ans = n;

  dfs(n, s);

  while(ans[0] == '0'){
    ans = ans.substr(1);
  }
  if(ans.length() == 0){
    cout<<0<<endl;
  }
  cout<<ans<<endl;

  return 0;

}
