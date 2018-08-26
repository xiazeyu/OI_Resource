#include <bits/stdc++.h>

using namespace std;

struct item{
  long long x, w;
  // x: 大小, w: 价值
};

long long n, m, ans = -1, minSpace = -1;
item s[41];

void DFS(long long a, long long b, long long c){
  // 阶段: 当前面对a物品
  // 状态: 当前面对item[a]物品, 剩余b空间, 已获得c价值
  // 状态转移: 取/不取
  // 约束条件: 空间不足, 物品取完
  // printf("DFS(%lld, %lld, %lld)\n", a, b, c);
  if((a == n) || (b < minSpace)){
    ans = max(ans, c);
    return;
  }
  DFS(a + 1, b, c);
  if(b - s[a].x >= 0)
    DFS(a + 1, b - s[a].x, c + s[a].w);
  return;
}

int main(){

  freopen("pack.in", "r", stdin);
  freopen("pack.out", "w", stdout);

  scanf("%lld%lld", &n, &m);
  for(long i = 0; i < n; i++){
    scanf("%lld%lld", &s[i].x, &s[i].w);
    if(minSpace == -1) minSpace = s[0].x;
    minSpace = min(minSpace, s[i].x);
  }

  DFS(0, m, 0);

  printf("%lld\n", ans);

  return 0;

}
