// P1426 小鱼会有危险吗
// https://www.luogu.org/problemnew/show/P1426

// Status: AC

// TIP: 作图模拟

#include <bits/stdc++.h>

using namespace std;

long s, x;
long double v = 7, l;

int main(){

  cin>>s>>x;
  while(l < s - x){
    l += v;
    v *= 0.98;
  }
  if(v > 2 * x){
    cout<<"n"<<endl;
  }else{
    cout<<"y"<<endl;
  }

  return 0;

}
