// P1250 种树
// https://www.luogu.org/problemnew/show/P1250

// Status: AC

// 贪心, 定长数组

// WARN:

#include <bits/stdc++.h>

using namespace std;

struct Need{
  long b, e, n;
  Need(long Begin = 0, long End = 0, long num = 0){
    b = Begin; e = End; n = num;
  }
  bool operator< (const Need &o) const {
    if(e == o.e) // 手误
      return b < o.b;
    return e < o.e;
  }
};

long n, h, b, e, t, ans = 0;
bool plant[30001];
Need work[5000];

int main(){

  scanf("%ld%ld", &n, &h);
  for(long i = 0; i < h; i++){
    scanf("%ld%ld%ld", &work[i].b, &work[i].e, &work[i].n);
  }
  // 结束位置升序排序
  sort(work, work + h);
  // 贪心
  for(long i = 0; i < h; i++){
    // cout<<work[i].b<<" "<<work[i].e<<" "<<work[i].n<<endl;
    // 第 i 个请求
    // 计数已种树棵树
    long cnt = 0;
    for(long j = work[i].b; j <= work[i].e; j++){
      if(plant[j]) cnt++;
    }
    // cout<<"cnt: "<<cnt<<endl;
    if(cnt >= work[i].n) continue;
    // 从尾部开始种树
    for(long j = work[i].e; j >= work[i].b; j--){ // for 循环第二个参数: 循环开始条件
    // cout<<"try to plant: "<<j<<endl;
      if(!plant[j]){
        // cout<<"plant: "<<j<<endl;
        plant[j] = true;
        cnt++; ans++;
        if(cnt == work[i].n) break;
      }
    }
  }

  printf("%ld", ans);


  return 0;

}
