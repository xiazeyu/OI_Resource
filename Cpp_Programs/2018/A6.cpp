// A6
//

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n;
vector<long> pre;

void DFS(long s, long t){
  if(s == 0){
    for(long i = 1; i < t; i++)
      printf("%ld ", pre[i]);
    printf("\n");
    return;
  }
  for(long i = min(s, pre[t - 1]); i >= 1; i--){
    pre[t] = i;
    DFS(s - i, t + 1);
  }
}

int main(){

  scanf("%ld", &n);
  pre.resize(n + 1);
  pre[0] = n;
  DFS(n, 1);

  return 0;

}
