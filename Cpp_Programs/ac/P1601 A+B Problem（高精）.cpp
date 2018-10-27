// P1601 A+B Problem£¨¸ß¾«£©
// https://www.luogu.org/problemnew/show/P1601

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

string a, b;

int cToN(char _c){
  return _c - '0';
}

char nToC(int _n){
  return _n + '0';
}

string hpAdd(string _a, string _b){
  string c = "";
  long sz = max(_a.length(), _b.length()),
       dlta = 0;
  while(_a.length() < (unsigned long)sz)
    _a = '0' + _a;
  while(_b.length() < (unsigned long)sz)
    _b = '0' + _b;
  for(long i = sz - 1; i >= 0; i--){
    dlta += cToN(_a[i]) + cToN(_b[i]);
    if(dlta >= 10){
      dlta %= 10;
      c = nToC(dlta) + c;
      dlta = 1;
    }else{
      c = nToC(dlta) + c;
      dlta = 0;
    }
  }
  if(dlta) c = nToC(dlta) + c;
  if(c.length() == 0) c = "0";
  return c;
}

int main(){

  cin>>a>>b;
  cout<<hpAdd(a, b)<<endl;

  return 0;

}
