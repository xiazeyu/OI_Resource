#include <bits/stdc++.h>

using namespace std;

long n, ans = 0, t;
bool flag;
vector<long> a;

int main(){

  scanf("%ld", &n);
  for(long i = 0; i < n; i++){
    flag = true;
    scanf("%ld", &t);
    for(long j = 0; j < i; j++){
      if (a[j] == t){
        flag = false;
        break;
      }
    }
    if(flag) a.push_back(t);
  }

  for(long i = 0; i < a.size(); i++){
    printf("el:%ld\n", a[i]);
  }

  for(long i = 0; i < a.size(); i++){
    for(long j = i + 1; j < a.size(); j++){
      for(long k = 0; k < a.size(); k++){
        if((i == k) || (j == k)) continue;
        if(a[i] + a[j] == a[k]) ans++;
      }
    }
  }

  printf("%ld", ans);

  return 0;

}
