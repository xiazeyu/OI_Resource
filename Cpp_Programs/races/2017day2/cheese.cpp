#include <bits/stdc++.h>

using namespace std;

struct point{
  long x, y, z;
  bool operator <(const point &b) const {
    return z < b.z;
  }
};

#define MAXN 1008
long _t, n, h, r;
bool ans, vis[MAXN];
point p[MAXN];

double d(long x1, long y1, long z1, long x2, long y2, long z2){
  return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) + (z1-z2) * (z1-z2));
}

bool touch(long n1, long n2){
  if(d(p[n1].x, p[n1].y, p[n1].z, p[n2].x, p[n2].y, p[n2].z) <= 2.0 * (double)r) return true;
  return false;
}

void dfs(long no){
  if(ans) return;
  if(p[no].z + r >= h){
    ans = true;
    return;
  }
  vis[no] = true;
  for(long i = 0; i < n; i++){
    if(ans) return;
    if(vis[i]) continue;
    if(!touch(i, no)) continue;
    dfs(i);
  }
  vis[no] = false;
}

int main(){

  freopen("cheese.in", "r", stdin);
  freopen("cheese.out", "w", stdout);
  scanf("%ld", &_t);
  for(long __t =  1; __t <= _t; __t++){
    ans = false;
    memset(vis, 0, sizeof(vis));
    scanf("%ld%ld%ld", &n, &h, &r);
    for(long i = 0; i < n; i++){
      scanf("%ld%ld%ld", &p[i].x, &p[i].y, &p[i].z);
    }
    sort(p, p + n);
    for(long i = 0; i < n; i++){
      if(p[i].z <= r)
        dfs(i);
    }

    if(ans)
      printf("Yes\n");
    else
      printf("No\n");
  }


  return 0;
}
