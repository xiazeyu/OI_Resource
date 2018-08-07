// P3367 【模板】并查集
// https://www.luogu.org/problemnew/show/P3367

// WARN: 使用printf输出答案时注意 \n 回车 (#6)
// TIP: 并查集操作时join为合并集合而不是元素 (#T2)
// TIP: 并查集在Find中路径压缩 (#T3)

#include <bits/stdc++.h>

using namespace std;

long n, m, x, y, z;
vector<long> par;

long Find(long a){
  if(par[a] == a) return a;
  return par[a] = Find(par[a]);
}

void Join(long x, long y){
  par[Find(x)] = Find(y);
  return;
}

int main(){

  scanf("%ld%ld", &n, &m);
  par.resize(n + 4);
  for(long i = 1; i <= n; i++){
    par[i] = i;
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &z, &x, &y);
    if(z == 1){
      Join(x, y);
    }else{
      if(Find(x) == Find(y)){
        printf("Y\n");
      }else{
        printf("N\n");
      }
    }
  }

  return 0;

}
