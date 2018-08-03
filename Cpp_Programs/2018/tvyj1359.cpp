// http://www.joyoi.cn/problem/tyvj-1359

#include <bits/stdc++.h>

using namespace std;

long n, m;
long long t, l, r, mid;
vector<long> sal;

bool check(long testM){
  long t = 0;
  long long sum = 0;
  for(int i = 0; i < n; i++){
    sum += sal[i];
    if(sum > testM){
      sum = 0;
      t++;
    }
  }
  printf(" testM:%ld, t:%ld\n", testM, t);
  if(t > m){
    return false;
  }return true;
}

int main(){

  scanf("%ld %ld", &n, &m);
  sal.resize(n + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &sal[i]);
    t = sal[i];
    l = max(l, t);
    r += sal[i];
  }
  while(l < r){
    mid = (l + r) / 2;
    // printf(" l:%lld, r:%lld, mid:%lld, check:%d\n",l, r, mid, check(mid));
    if(check(mid)){
      r = mid;
    }else{
      l = mid + 1;
    }
  }

  printf("%lld", l - 1);


  return 0;

}
