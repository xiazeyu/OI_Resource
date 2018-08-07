#include <bits/stdc++.h>

using namespace std;

long n;
vector<string> a;
vector<string>::iterator it;

int main(){

  cin>>n;
  a.resize(n + 4);
  for(long i = 0; i < n; i++){
    cin>>a[i];
  }
  sort(a.begin(), a.begin() + n);
  for(it = a.begin(); it != a.end(); it++){
    cout<<*it<<endl;
  }

  return 0;

}
