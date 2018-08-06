#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define eps 1e-8
#define OJ

// turn disorder into order

// Tip #1: 找出题目变化规律, 不变量 而不是简单模拟(@P2678)
// realize simplily
// programming complexity > time complexity > space complexity.
// leave comments!
// optimize: reduce repeat workload.重叠子问题
// 线段树 4倍空间
// 1s = 4*10^8.
// 128M, 1*10^7 long long 8bits
// double 15
// long double 18

// Rule #1: 区间[ , ) 二分答案时右区间至少+1 (@P2678)
// Rule #2: while 及 for 内部所有推出量均要考虑 是否溢出/越界 (@P2678)
// Rule #3: 使用实际受限的变量作为循环变量, 推出其他变量 (@P2678)
// Rule #4: 输入是否为 多组输入: while(scanf != EOF) (@poweroj2461)
// Rule #5: 二分范围必须位于合法区间内 (@tvyj2359)
// \n when use printf
// ans += xxx % MOD; ans %= MOD;!!!!!
// See if input have repeat datas.

// ans prefer long long.
// remove 0 in the front of a num-string, and check ans.length == 0.
// define all varibles at the head.
// prefer global varible.
// the index of an array is started from 0.
// the last index of an array is n-1.
// search from both end, check if Begin == End.
// use long double rather than double.
// avoid too long varible names.
// prefer not to use function uncomplex codes.

using namespace std;

inline int qmin(int a, int b){ // 位运算加速的求较小数 - 返回值 较小数
  int diff = b - a;
  // b < a : a + (diff & -1)
  // b > a : a + (diff & 0)
  return a + (diff & (diff >> 31));
}
inline int qmax(int a, int b){ // 位运算加速的求较大数 - 返回值 较大数
  int diff = b - a;
  // b < a : b - (diff & -1)
  // b > a : b - (diff & 0)
  return b - (diff & (diff >> 31));
}
inline int qabs(int a){ // 位运算加速的绝对值  - 返回值 绝对值
  int t = (a >> 31);
  return (a + t) ^ t;
}
inline bool isOdd(int a){ // 判断奇偶性 - 返回 1 是奇数; 返回 0 是偶数
  return (a & 1) == 1;
}
inline void qswap(int* a, int* b){ // 位运算加速的快速交换 - 用法 qswap(&a, &b);
  (*a) ^= (*b) ^= (*a) ^= (*b);
  return;
}
inline int qread(){ // 快速读入int - 返回 读入的数
  char c = getchar();
  int f = 1, x = 0;
  while(!isdigit(c)){if(c == '-') f= -1; c = getchar();}
  while(isdigit(c)){x = x * 10 + c - '0'; c = getchar();}
  return f * x;
}

inline int qpow( int a, int b ){ // 快速幂 - 返回 a ^ b
    int r = 1, base = a;
    while( b ){
    if( b & 1 ) r *= base;
        base *= base;
        b >>= 1;
    }
    return r;
}

int main(){
  #ifndef OJ
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  #endif



  #ifndef OJ
  fclose(stdin);
  fclose(stdout);
  #endif
  return 0;

}
