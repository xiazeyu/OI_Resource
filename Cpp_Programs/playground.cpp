#include <bits/stdc++.h>

#define getd(n, w) ((n&(1<<w))>>w)

using namespace std;

vector<long> Hash[2333];

bool inHash(long n){
  long d = n % 2321;
  if(Hash[d].empty()) return false;
  bool flag = false;
  for(long i = 0; i < Hash[d].size(); i++){
    if(Hash[d][i] == n){
      flag = true; break;
    }
  }
  return flag;
}

void putHash(long n){
  long d = n % 2321;
  if(inHash(n)) return;
  Hash[d].push_back(n);
  return;
}


int main(){

  for(long i = 1; i <= 100; i++) cout<<i<<" "<<(i + 1) / 2<<" "<<i / 2 + 1<<endl;

  return 0;
}
