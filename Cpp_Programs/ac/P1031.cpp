// P1031 均分纸牌
// https://www.luogu.org/problemnew/show/P1031

#include <bits/stdc++.h>

using namespace std;

long n, ans = 0, aver;
vector<long> a;

int main(){

  scanf("%ld", &n);
  a.resize(n + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &a[i]);
    aver += a[i];
  }
  aver /= n;
  for(int i = 0; i < n; i++){
    a[i] -= aver;
  }
  for(int i = 0; i < n; i++){
    if(a[i] != 0){
      a[i + 1] += a[i];
      a[i] = 0;
      ans++;
    }
  }

  printf("%ld", ans);

  return 0;

}
