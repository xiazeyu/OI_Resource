// P1106 删数问题
// https://www.luogu.org/problemnew/show/P1106

#include <bits/stdc++.h>

using namespace std;

string n;
int k;

int main(){

  cin>>n;
  n.resize(n.length() + 4);
  cin>>k;

  for(int i = 1; i <= k; i++){
    for(int j = 0; j < n.length(); j++){
      if(n[j] > n[j + 1]){
        n.erase(j, 1);
        break;
      }
    }
  }

  while(n[0] == '0'){
    n.erase(0, 1);
  }

  if(n.length() == 0){
    cout<<0<<endl;
  }
  cout<<n<<endl;

  return 0;

}
