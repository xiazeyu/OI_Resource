#include <bits/stdc++.h>

using namespace std;

long long t = 1, n = 1, m, k;

int main(){

  cin>>k>>m;
  while(t % m != k){
    n++;
    t *= 10; t++;
  }
  cout<<n<<endl;

  return 0;

}
