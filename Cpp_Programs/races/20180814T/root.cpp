#include <bits/stdc++.h>

using namespace std;

long n, x, y;
vector<long> t, ans;

int main(){

  freopen("root.in", "r", stdin);
  freopen("root.out", "w", stdout);

  scanf("%ld", &n);
  if(n <= 3){
    printf("%ld\n", n);
    for(long i = 1; i <= n; i++){
      printf("%ld ", i);
    }
  }else if (n <= 4){
    t.resize(n + 1);
    for(long i = 1; i <= n - 1; i++){
      scanf("%ld%ld", &x, &y);
      t[x]++; t[y]++;
    }
    for(long i = 1; i <= n; i++){
      if(t[i] <= 2) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for(long i = 0; i < ans.size(); i++){
      printf("%ld ", ans[i]);
    }
  }else{
    t.resize(n + 1);
    for(long i = 1; i <= n - 1; i++){
      scanf("%ld%ld", &x, &y);
      t[x]++; t[y]++;
    }
    for(long i = 1; i <= n; i++){
      if(t[i] >= 4){
        printf("0\n");
        fclose(stdin);
        fclose(stdout);
        return 0;
      }
      if(t[i] <= 2) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for(long i = 0; i < ans.size(); i++){
      printf("%ld ", ans[i]);
    }
  }

  fclose(stdin);
  fclose(stdout);
  return 0;

}
