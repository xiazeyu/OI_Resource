// 跳石头
// https://www.luogu.org/problemnew/show/P2678

// TIP: 找出题目变化规律, 不变量 而不是简单模拟(#T1),
// WARN: while 及 for 内部所有推出量均要考虑 是否溢出/越界(#2)
//  用 for 而非 while(#3)
// WARN: 区间左闭右开(#1)

/*

bool check(int dist)
｛
        int pre=0,cnt=0;
        for(ini i=1;i<=n+1;i++)
        {
                 if(d[i]-pre<dist)cnt++;
                 else pre=d[i];
        }
        if(cnt>m)return false;
        else return true;
｝
d[n+1]存右岸的坐标，即L
当前考察区间为[pre，d[i]]

*/
#include <bits/stdc++.h>

using namespace std;

long long l ,le, ri, mid, ans = 0;
long n, m;
vector<long long> d;

bool check(long long dist){
  long long now = 0, nxt = 1;
  // now: 当前的位置, 0<=index<=n + 1, n 是最后一块可以移除的石头
  // nxt: 下一个位置
  long cnt = 0;
  // cnt: 移走的石头数
  // 移走nxt石头
  while(nxt <= n){ // 因为nxt是实际操作的石头, 受[1, n]的限制
    if(d[nxt] - d[now] < dist){
      nxt++;cnt++;
      // 移走石头
    }else{
      now = nxt; // 跳到nxt上
      nxt++;
    }
  }
  return (cnt <= m);
}

int main(){

  scanf("%lld%ld%ld", &l, &n, &m);
  d.resize(n + 4);
  d[0] = 0;
  d[n + 1] = l;
  for(int i = 1; i <= n; i++){
    scanf("%lld", &d[i]);
  }
  le = 0;
  ri = l + 1;
  while(le < ri){
    mid = (le + ri) / 2;
    if(check(mid)){
      ans = mid;
      le = mid + 1;
    }else{
      ri = mid;
    }
  }

  printf("%lld", ans);

  return 0;

}
