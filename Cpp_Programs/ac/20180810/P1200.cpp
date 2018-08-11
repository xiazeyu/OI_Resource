// P1200 [USACO1.1]ÄãµÄ·ÉµúÔÚÕâ¶ùYour Ride Is He¡­
// https://www.luogu.org/problemnew/show/P1200

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

const int MOD = 47;

long aM = 1, bM = 1;
string a, b;

int main(){

  cin>>a>>b;
  for(long i = 0; i < a.size(); i++){ // HERE
    aM *= a[i] - 'A' + 1;
    aM %= 47;
  }
  for(long i = 0; i < b.size(); i++){ // HERE
    bM *= b[i] - 'A' + 1;
    bM %= 47;
  }
  if(aM == bM){
    printf("GO");
  }else{
    printf("STAY");
  }

  return 0;

}
