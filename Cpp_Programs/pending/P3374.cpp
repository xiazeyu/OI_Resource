// P3374 【模板】树状数组 1
// https://www.luogu.org/problemnew/show/P3374

// Status: AC

// Problem: 树状数组下标从1开始

#include <bits/stdc++.h>

using namespace std;

long n, m, t, x, y;
long c[500001];

void add(long pos, long value){
  //
  while(pos <= n){ // 会影响根节点(index > pos)
    c[pos] += value;
    pos += pos & - pos; // 往上处理
  }
  return;
}

long sum(long pos){
  // 求[1-pos]之和
  long cnt = 0;
  while(pos){// 从根节点逐步寻找
    cnt += c[pos];
    pos -= pos & -pos; // 往夏处理
  }
  return cnt;
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 1;i <= n; i++){
    scanf("%ld", &t);
    add(i, t);
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &t, &x, &y);
    if(t == 1){
      add(x, y);
    }else{
      printf("%ld\n", sum(y) - sum(x - 1));
    }
  }

  return 0;

}
