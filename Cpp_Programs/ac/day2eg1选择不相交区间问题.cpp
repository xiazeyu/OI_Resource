/*
设有n个活动的集合E={1,2,...,n},其中每个活动都要求使用同一资源，如演讲会场等，而在同一时间内只有一个活动等使用这一资源。每个活动i都有一个要求使用该资源的起始时间si和一个结束时间fi且si<fi。如果选择了活动i，则它在时间区间[si,fi]内占用资源。若区间[si,fi]与区间[sj,fj]不相交则称活动i与活动j是相容的。也就是说，当fi≤sj或者fj≤si时。活动i与活动j相容。选择出有互相兼容的活动组成的最大集合。
【输入格式】第一行一个整数n（n≤1000）。接下来的n行每行两个整数si和fi。
【输出格式】说出尽可能多的互相兼容的活动个数。
【样例输入】
4
1 3
4 6
2 5
1 7
【样例输出】
2
 */

#include <bits/stdc++.h>

using namespace std;

struct qujian{
  long long Begin;
  long long End;
  bool operator< (const qujian &b)const{
    return End < b.End;
  }
};

long n, ans = 0, lastEnd = 0;
qujian q[1024];

int main(){

  scanf("%ld", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &q[i].Begin, &q[i].End);
  }
  sort(q, q + n);

  for(long i = 0; i < n; i++){
    if(q[i].Begin > lastEnd){
      ans++;
      lastEnd = q[i].End;
    }
  }

  printf("%ld", ans);

  return 0;
}
