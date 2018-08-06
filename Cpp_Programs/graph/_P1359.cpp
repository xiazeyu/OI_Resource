// P1359 租用游艇
// 最短路
// https://www.luogu.org/problemnew/show/P1359

// 22:56

#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e2+8;

int n;
int v[maxN][maxN];

int main(){

  scanf("%d", &n);
  memset(v, 0x7f, sizeof(v));
  for(int i = 1; i <= n; i++){
    for(int j = i + 1; j <= n; j++){
      scanf("%d", &v[i][j]);
    }
  }

  return 0;

}
