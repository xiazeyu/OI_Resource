// 书上的代码

#include <bits/stdc++.h>

using namespace std;

struct line{int s, e, v;} a[5005], mid;;
int n, m;
bool used[30005] = {0};
bool cmp(const line &x, const line &y){
  return x.e < y.e;
}

void Init(){
  int i;
  cin>>n>>m;
  for(i = 1; i <= m; i++)
    cin>>a[i].s>>a[i].e>>a[i].v;
  sort(a + 1, a + m + 1, cmp);
}

void Solve(){
  int i, j, k, ans = 0;
  for(i = 1; i <= m; i++){
    k = 0;
    for(j = a[i].s; j <= a[i].e; j++)
      if(used[j]) k++;
    if(k >= a[i].v) continue;
    for(j = a[i].e; j >= a[i].s; j--)
      if(!used[j]){
        used[j] = 1;
        k++;
        ans++;
        if(k == a[i].v) break;
      }
  }
  cout<<ans<<endl;
}

int main(){
  Init();
  Solve();
  return 0;
}
