#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

ull x, y, a, b, MOD;

inline ull qpow(ull a, ull r){
  ull ans = 1, base = a;
  while(r){
    if(r&1)
      ans = ans * base;
    base = base * base;
    r >>= 1;
  }
  return ans;
}

ull gcd(long a, long b){
  return b?gcd(b, a%b):a;
}

int main(){

  cin>>x>>y>>a>>b>>MOD;
  if(a > b) swap(a, b); // a <= b
  if(b % a == 0){
    cout<<(qpow(x, a) - qpow(y, a)) % MOD<<endl;
    return 0;
  }
  cout<<gcd(qpow(x, a)-qpow(y, a), qpow(x, b)-qpow(y, b)) % MOD<<endl;

  return 0;

}
