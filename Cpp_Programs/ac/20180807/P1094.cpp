// P1094 纪念品分组
// https://www.luogu.org/problemnew/show/P1094

#include <bits/stdc++.h>

using namespace std;

long w, n, ans = 0, a = 0, b;
vector<long> p;

int main(){

  scanf("%ld", &w);
  scanf("%ld", &n);
  p.resize(n + 4);
  b = n - 1;
  for(int i = 0; i < n; i++){
    scanf("%ld", &p[i]);
  }
  sort(p.begin(), p.begin() + n);

  while(a <= b){/*
    if(a == b){
      a++;b--;
      ans++;
    }*/
    if(p[a] + p[b] <= w){
      a++;b--;
      ans++;
    }else{
      b--;
      ans++;
    }
  }

  printf("%ld\n", ans);

  return 0;

}
