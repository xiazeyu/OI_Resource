// P1014 Cantor±Ì
// https://www.luogu.org/problemnew/show/P1014

// Status: AC

// Problem: …ÛÃ‚

#include <bits/stdc++.h>

using namespace std;

long n, ln = 0, cnt = 0, st;

int main(){

  cin>>n;
  while(cnt < n){
    ln++;
    cnt += ln;
    // cout<<ln<<" "<<cnt<<endl;
  }
  st = ln - (cnt - n);
  if(ln % 2){
    cout<<ln - st + 1<<"/"<<st<<endl;
  }else{
    cout<<st<<"/"<<ln - st + 1<<endl;
  }

  return 0;

}
