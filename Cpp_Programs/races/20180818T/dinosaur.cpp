#include <bits/stdc++.h>

using namespace std;

struct section{
  long Begin, End;
  section(long sBegin = 0, long sEnd = 0){
    Begin = sBegin; End = sEnd;
  }
  bool operator< (const section &b) const{
    if(Begin == b.Begin){
      return End < b.End;
    }
    return Begin < b.Begin;
  }
};

long n, p, h, l, r, ans = -1;
section s[300000];

int main(){
  // 分析:
  // 对于每个仙人掌, 可以将高度向数轴映射, 其区间的两个端点为 [起跳点, 落地点]
  // 对于每个区间: 只要能被一次跳跃覆盖, 即可成功
  // 对于每个跳跃: 跳跃的最大高度为 (落地点-起跳点 - 1) / 2
  // 对于每个跳跃, 不能有其他跳跃与其重合
  // 要求:
  // 使得最大跳跃最短, 并且跳跃全覆盖仙人掌

  freopen("dinosaur.in", "r", stdin);
  freopen("dinosaur.out", "w", stdout);

  scanf("%ld", &n);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &p, &h);
    if(p < h){
      printf("-1\n");
      return 0;
    }
    s[i] = section(p - h, p + h);
  }
  sort(s, s + n);
  l = s[0].Begin; r = s[0].End;
  for(long i = 0; i < n; i++){
    if((s[i].Begin <= r - 1) && (s[i].End > r)){
      r = s[i].End;
    }else if (s[i].Begin > r - 1){
      ans = max(ans, r - l);
      // printf("newLength=%ld(%ld, %ld)[%ld]\n", ans, l, r, r - l);
      l = s[i].Begin;
      r = s[i].End;
    }
  }
  ans = max(ans, r - l);
  // printf("newLength=%ld(%ld, %ld)[%ld]\n", ans, l, r, r - l);
  if(ans % 2){
    printf("%ld.5\n", ans / 2);
  }else{
    printf("%ld.0\n", ans / 2);
  }

  return 0;
}
