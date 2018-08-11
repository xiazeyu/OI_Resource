// P2141 珠心算测验
// https://www.luogu.org/problemnew/show/P2141

// Status: AC

// WARN: a.size() = n => a的最后一个元素为a[n - 1] (#9)

#include <bits/stdc++.h>

using namespace std;

long n, cnt = 0;
vector<long> a;
bool flag[10010] = {0};

int main(){

  scanf("%ld", &n);
  a.resize(n);
  for(long i = 0; i < n; i++){
    scanf("%ld", &a[i]);
  }
  sort(a.begin(), a.begin() + n);
  for(long i = 0; i < n; i++){
    for(long j = i + 1; j < n; j++){
      if(a[i] + a[j] <= a[n - 1]){
        flag[a[i] + a[j]] = true;
      }
    }
  }
  for(long i = 0; i < n; i++){
    if(flag[a[i]]) cnt++;
  }

  printf("%ld\n", cnt);


  return 0;

}
