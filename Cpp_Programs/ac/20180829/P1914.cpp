// P1914 Ğ¡ÊéÍ¯¡ª¡ªÃÜÂë
// https://www.luogu.org/problemnew/show/P1914

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

string s;
long n;

char nextChar(long _c){
  return (_c + n > 'z'? _c + n - 26 : _c + n);
}

int main(){

  cin>>n;
  cin>>s;
  for(long i = 0; i < s.size(); i++){
    s[i] = nextChar(s[i]);
  }
  cout<<s<<endl;

  return 0;

}
