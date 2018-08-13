// P1644 ��������
// https://www.luogu.org/problemnew/show/P1644

// Status: AC

// DFS, ϵͳջ

// Problem:

#include <bits/stdc++.h>

using namespace std;

const long cx[] = {1, 2, 1, 2}, cy[] = {2, 1, -2, -1};

long n, m, cnt = 0;

void dfs(long x, long y){
  // x, y: ��ǰ����λ��
  if((x == m) && (y == n)){
    cnt++;
    return;
  }
  for(int i = 0; i <= 3; i++){
    long nx = x + cx[i], ny = y + cy[i];
    if((nx <= m) && (nx >= 0) && (ny <= n) && (ny >= 0)){
      dfs(x + cx[i], y + cy[i]);
    }
  }
}

int main(){

  scanf("%ld%ld", &n, &m);
  dfs(0, 0);
  printf("%ld", cnt);

  return 0;

}
