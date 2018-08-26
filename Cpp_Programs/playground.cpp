#include <bits/stdc++.h>

using namespace std;

struct item{
  long x, w;
  // x: 大小, w: 价值
};

long n, m, ans = 0;
item s[40];

void DFS(long a, long b, long c){
  // 阶段: 当前面对第a件物品
  // 状态: 当前面对item[a]物品, 剩余b空间, 已获得c价值
  // 状态转移: 取/不取
  // 约束条件: 空间不足, 物品取完
  if((a == n) || (s[a].x > b)){
    ans = max(ans, c);
    return;
  }
  DFS(a + 1, b, c);
  DFS(a + 1, b - s[a].x, c + s[a].w);
  return;
}

int main(){

  // freopen("pack.in", "r", stdin);
  // freopen("pack.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &s[i].x, &s[i].w);
  }

  DFS(1, m, 0);
  if(s[0].x > m)
    DFS(1, m - s[0].x, s[0].w);

  printf("%ld\n", ans);

  return 0;

}
