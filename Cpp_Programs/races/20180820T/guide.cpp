#include <bits/stdc++.h>

using namespace std;

struct point{
  long x, y;
  point(long _x = 0, long _y = 0){
    x = _x; y = _y;
  }
};

bool comp1(const point &a, const point &b){
    if(a.x == b.x){
      return a.y < b.y;
    }return a.x < b.x;
  }

bool comp2(const point &a, const point &b){
  if(a.x * a.y == b.x * b.y){
    if(a.x == b.x){
      return a.y < b.y;
    }return a.x < b.x;
  }
  return a.x * a.y < b.x * b.y;
}

long num, n, tx, ty, ans1, ans2;
point t[50000], e[50000];

long getAns(){
  long ans = 0;
  for(long i = 0; i < n; i++){
    for(long j = 0; j < n; j++){
      if((t[i].x <= e[j].x) && (t[i].y <= e[j].y)){
        ans++; e[j].x = -1; e[j].y = -1;
        break;
      }
    }
  }
  return ans;
}

int main(){

  freopen("guide.in", "r", stdin);
  freopen("guide.out", "w", stdout);

  scanf("%ld%ld", &num, &n);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &tx, &ty);
    t[i] = point(tx, ty);
  }
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &tx, &ty);
    e[i] = point(tx, ty);
  }
  if(num == 1){
    if(t[0].x <= e[0].x){
      printf("1\n");
    }else{
      printf("0\n");
    }
  }else{
    sort(t, t + n, comp1);
    sort(e, e + n, comp1);
    ans1 = getAns();
    sort(t, t + n, comp2);
    sort(e, e + n, comp2);
    ans2 = getAns();
    printf("%ld\n", max(ans1, ans2));
  }

  return 0;

}
