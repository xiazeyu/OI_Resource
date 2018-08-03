// https://www.oj.swust.edu.cn/problem/show/2461

#include <bits/stdc++.h>

using namespace std;

long long a, b, c, x, y, z, c1, c2, c3, sum;

bool check(long long q){
  long long nA = a * q > x ? (a * q - x) * c1 : 0;
  long long nB = b * q > y ? (b * q - y) * c2 : 0;
  long long nC = c * q > z ? (c * q - z) * c3 : 0;
  if (nA + nB + nC > sum) return false;
  return true;
}

  int main(){

    long long l, r, mid, ans = 0;

    while(scanf("%ld%ld%ld%ld%ld%ld%lld%ld%ld%ld", &a, &b, &c, &x, &y, &z, &sum, &c1, &c2, &c3) != EOF){

      l = 0;
      r = (sum / min(a * c1, min(b * c2, c * c3))) + (max(x / a, max(y / b, z / c))) + 16;
      // r = 1e14

      while(l < r){
        mid = (l + r) / 2; // mid = (l + r) >> 1;
        if(check(mid)){
          ans = mid;
          l = mid + 1;
        }else{
          r = mid;
        }
      }
      printf("%lld\n", ans);
    }

    return 0;

  }
