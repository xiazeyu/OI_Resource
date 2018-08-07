// 收入计划
// http://www.joyoi.cn/problem/tyvj-1359

// WARN: 二分范围必须位于合法区间内(#5)

#include <bits/stdc++.h>

using namespace std;

long n, m, ans, l = 0, r = 8, mid;
vector<long> a;

bool check(long mon){
  long cnt = 0, tot = 0; // tot 是过去攒的钱
  for(long i = 1; i <= n; i++){
    if(tot + a[i] > mon){ // 假设 今天(i)还是攒着
      tot = a[i]; // 太多了, 先取钱再存
      cnt++;
    }else{
      tot += a[i]; // 存着
    }
  }
  if(tot > 0) cnt++; // 最后一天还有没取的钱 取出来
  return (cnt <= m);
}

int main(){

  scanf("%ld%ld", &n, &m);
  a.resize(n + 4);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
    l = max(l, a[i]); // l from max, not from 0
    r += a[i];
  }

  while(l < r){
    mid = (l + r) / 2;
    // printf("c%ld=%d\n", mid, check(mid));
    if(check(mid)){
      r = mid;
      ans = mid;
    }else{
      l = mid + 1;
    }
  }

  printf("%ld", ans);

  return 0;

}
