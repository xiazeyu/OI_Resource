// P1464 Function
// https://www.luogu.org/problemnew/show/P1464

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long long _a, _b, _c, tmp[21][21][21];

long long w(long long a, long long b, long long c){
  if((a <= 0) || (b <= 0) || (c <= 0)) return 1;
  if((a > 20) || (b > 20) || (c > 20)) return w(20, 20, 20);
  if(tmp[a][b][c]) return tmp[a][b][c];
  if((a < b) && (b < c)) return tmp[a][b][c] = w(a, b, c - 1) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return tmp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(){
  cin>>_a>>_b>>_c;
  while(!((_a == -1) && (_b == -1) && (_c == -1))){ // Here ÖÕÖ¹Ìõ¼þ
    cout<<"w("<<_a<<", "<<_b<<", "<<_c<<") = "<<w(_a, _b, _c)<<endl;
    cin>>_a>>_b>>_c;
  }

  return 0;

}
