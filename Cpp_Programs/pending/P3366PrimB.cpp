// P3366 ��ģ�塿��С������
// https://www.luogu.org/problemnew/show/P3366

// Status: TLEx3

// Prim �ڽӾ���

// WARN: ��С������ ȥ��+ȥ��(#8)

#include <bits/stdc++.h>

using namespace std;

const long maxL = 0x3f3f3f3fL;

long n, m, x, y, z, ans = 0;
vector<long> dist;
vector<bool> vis;
vector<vector<long> > mat;

int main(){

  scanf("%ld%ld", &n, &m);
  mat.resize(n + 1);
  dist.resize(n + 1, maxL);
  vis.resize(n + 1);
  for(long i = 0; i < n + 1; i++){
    mat[i].resize(n + 1, maxL);
    mat[i][i] = 0;
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &z);
    if(x != y){ // ȥ��+ȥ��
      mat[x][y] = min(z, mat[x][y]);
      mat[y][x] = min(z, mat[x][y]);
    }
  }

  dist[1] = 0;
  for(long i = 1; i <= n; i++){
    // Ѱ��pos
    long pos = 0;
    for(long j = 1; j <= n; j++){
      if((!vis[j]) && (dist[j] < dist[pos])) pos = j;
    }
    if(pos == 0){
      printf("orz\n");
      return 0;
    }
    // Ϳɫ
    vis[pos] = true;
    ans += dist[pos];
    // �ɳ�
    for(long v = 1; v <= n; v++){
      if((!vis[v]) && (dist[v] > mat[pos][v])){
        dist[v] = mat[pos][v];
      }
    }
  }

  printf("%ld", ans);

  return 0;

}
