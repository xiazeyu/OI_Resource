// P1055 ISBNºÅÂë
// https://www.luogu.org/problemnew/show/P1055

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

const string out = "0123456789X";

string ISBN;
int cnt = 0, ide = 0;

int main(){

  cin>>ISBN;
  for(long i = 0; i < 11; i++){
    if(ISBN[i] != '-'){
      cnt++;
      ide += (ISBN[i] - '0') * cnt;
    }
  }

  ide %= 11;

  if(out[ide] == ISBN[12]){
    cout<<"Right"<<endl;
  }else{
    ISBN.erase(12, 1);
    cout<<ISBN<<out[ide]<<endl;
  }

  return 0;

}
