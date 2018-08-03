#include <bits/stdc++.h>

using namespace std;

long n, cnt = 0, last = -1;
vector<long> num, ans;

int main(){

  scanf("%ld", &n);
  num.resize(n + 4);
  for(long i = 0; i < n; i++){
    scanf("%ld", &num[i]);
  }
  sort(num.begin(), num.begin() + n);
  for(long i = 0; i < n; i++){
    if(num[i] != last){
      last = num[i];
      ans.push_back(num[i]);
      cnt++;
    }
  }
  printf("%ld\n", cnt);
  for(long i = 0; i < ans.size(); i++){
    printf("%ld ", ans[i]);
  }

  return 0;

}
