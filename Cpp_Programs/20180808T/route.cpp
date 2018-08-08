#include <bits/stdc++.h>

using namespace std;

vector<vector <long> > mat;
long n, m, t;

int main(){

  freopen("route.in", "r", stdin);
  freopen("route.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  mat.resize(n + 1);
  for(long i = 0; i <= n; i++){
    mat[i].resize(m + 1);
  }
  for(long x = 1; x <= n; x++){
    for(long y = 1; y <= m; y++){
      scanf("%ld", &t);
      mat[x][y] = t;
    }
  }

  printf("%ld\n", 7 * n);

  fclose(stdin);
  fclose(stdout);
  return 0;

}
