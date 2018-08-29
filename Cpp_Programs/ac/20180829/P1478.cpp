// P1478 ÌÕÌÕÕªÆ»¹û£¨Éý¼¶°æ£©
// https://www.luogu.org/problemnew/show/P1478

// Status: AC

#include <bits/stdc++.h>

using namespace std;

struct Apple{
  long x, y;
  bool operator< (const Apple &b) const {
    if(y == b.y)
      return x < b.x;
    return y < b.y;
  }
};

long n, s, a, b, ans = 0;
Apple p[5001];

int main(){

  scanf("%ld%ld%ld%ld", &n, &s, &a, &b);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &p[i].x, &p[i].y);
    if(p[i].x > b) p[i].x -= a;
  }
  sort(p, p + n);
  for(long i = 0; i < n; i++){
    if((p[i].y <= s) && (p[i].x <= b)){
      ans++;
      s -= p[i].y;
    }
  }

  printf("%ld\n", ans);

  return 0;

}
