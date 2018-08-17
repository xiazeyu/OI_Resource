#include <bits/stdc++.h>

using namespace std;

long n, a1, b1, a2, b2, mode;

int main(){
  // freopen("girls.in", "r", stdin);
  // freopen("girls.out", "w", stdout);

  scanf("%ld", &n);
  for(long i = 1; i <= n; i++){
    scanf("%ld%ld%ld%ld", &a1, &a2, &b1, &b2);
    // mode: 0: 任意, 1: a装进b, 2: b装进a
    if(a1 == b1){
      mode = 0;
    }else if(a1 < b1){
      mode = 1;
    }else{
      mode = 2;
    }
    if(mode == 0){
      printf("Yes\n");
    }else if(mode == 1){
      if(a2 <= b2){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }else{
      if(b2 <= a2){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }
  }


  return 0;

}
