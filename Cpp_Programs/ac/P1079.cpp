// P1079 Vigen®®re √‹¬Î
// https://www.luogu.org/problemnew/show/P1079
// NOIP 2012 D1T1

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

string _k, _c;

char Dec(char c, char k){
  long _c, _k;
  bool cap = false;
  k = ((k >= 'a') && (k <= 'z')) ? (k + 'A' - 'a') : (k);
  if((c >= 'A') && (c <= 'Z')) cap = true;
  c = ((c >= 'a') && (c <= 'z')) ? (c + 'A' - 'a') : (c);
  _c = c - 'A';
  _k = k - 'A';
  _c -= _k;
  _c = (_c + 26) % 26;
  if(cap)
    return 'A' + _c;
  else
    return 'a' + _c;
}

int main(){

  long p = 0;
  cin>>_k>>_c;
  for(unsigned long i = 0; i < _c.length(); i++){
    cout<<Dec(_c[i], _k[p++]);
    p %= _k.length();
  }
  cout<<endl;

  return 0;

}
