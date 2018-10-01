#include <bits/stdc++.h>

using namespace std;

long long n = 1, m, k;
string t;

long long mod(string a, long long b){
  long long ans = 0;
  for(unsigned long i = 0; i < a.length(); i++){
    ans = (ans * 10 + (a[i] - '0')) % b;
  }
  return ans;
}

int main(){

  cin>>k>>m;
  t += "1";
  while(mod(t, m) != k){
    n++; t += "1";
  }
  cout<<n<<endl;

  return 0;

}
