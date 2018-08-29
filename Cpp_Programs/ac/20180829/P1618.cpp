// P1618 三连击（升级版）
// https://www.luogu.org/problemnew/show/P1618

// Status: AC

// WARN: 函数内部初始化 (#31)
// WARN: 变量成比例: 必须要被整除 (#32)

#include <bits/stdc++.h>

using namespace std;

bool flag = false;
long _a, _b, _c;

bool en(long a, long b, long c){
  bool n[10] = {0};
  if((b < 100) || (b > 999)) return false;
  if((c < 100) || (c > 999)) return false;
  do{
    if(!(a % 10)) return false;
    if(n[a % 10]) return false; // Here!!!
    n[a % 10] = true;
    a /= 10;
  }while(a);
  do{
    if(!(b % 10)) return false;
    if(n[b % 10]) return false;
    n[b % 10] = true;
    b /= 10;
  }while(b);
  do{
    if(!(c % 10)) return false;
    if(n[c % 10]) return false;
    n[c % 10] = true;
    c /= 10;
  }while(c);
  return true;
}

int main(){

  scanf("%ld%ld%ld", &_a, &_b, &_c);
  for(long i = 100; i <= 999; i++){
    if(i % _a) continue; // Here!!!
    long j = i / _a * _b,
    k = i / _a * _c;
    if(en(i, j, k)){
      flag = true;
      printf("%ld %ld %ld\n", i, j, k);
    }
  }
  if(!flag) printf("No!!!\n");

  return 0;

}
