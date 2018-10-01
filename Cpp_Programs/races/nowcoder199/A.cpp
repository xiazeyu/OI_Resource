#include <bits/stdc++.h>

using namespace std;

long n, m, a, b;
bool cannotBeIn1[100000], group1[100000], group2[100000];
vector<int> Edge[100000];

int main(){

  scanf("%ld%ld", &n, &m);
  if(m == 0){
    for(long i = 1; i < n; i++){
      printf("1 ");
    }
    printf("1\n");
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld", &a, &b);
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  cannotBeIn1[1] = true;
  group1[1] = true;
  for(long i = 1; i <= n; i++){
    if(cannotBeIn1[i]){
      group2[i] = true;
      continue;
    }
    for(unsigned long j = 0; j < Edge[i].size(); j++){
      long cur = Edge[i][j];
      if(!cannotBeIn1[cur]){
        group1[cur] = true;
        cannotBeIn1[cur] = true;
        for(unsigned long k = 0; k < Edge[cur].size(); k++){
          cannotBeIn1[Edge[cur][k]] = true;
        }
      }
    }
  }

  printf("-1\n");

}
