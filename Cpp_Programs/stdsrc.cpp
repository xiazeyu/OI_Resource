#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define eps 1e-8
#define OJ

// turn disorder into order

// Tip #1: �ҳ���Ŀ�仯����, ������ �����Ǽ�ģ��(@P2678)
// realize simplily
// programming complexity > time complexity > space complexity.
// leave comments!
// optimize: reduce repeat workload.�ص�������
// �߶��� 4���ռ�
// 1s = 4*10^8.
// 128M, 1*10^7 long long 8bits
// double 15
// long double 18

// Rule #1: ����[ , ) ���ִ�ʱ����������+1 (@P2678)
// Rule #2: while �� for �ڲ������Ƴ�����Ҫ���� �Ƿ����/Խ�� (@P2678)
// Rule #3: ʹ��ʵ�����޵ı�����Ϊѭ������, �Ƴ��������� (@P2678)
// Rule #4: �����Ƿ�Ϊ ��������: while(scanf != EOF) (@poweroj2461)
// Rule #5: ���ַ�Χ����λ�ںϷ������� (@tvyj2359)
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

inline int qmin(int a, int b){ // λ������ٵ����С�� - ����ֵ ��С��
  int diff = b - a;
  // b < a : a + (diff & -1)
  // b > a : a + (diff & 0)
  return a + (diff & (diff >> 31));
}
inline int qmax(int a, int b){ // λ������ٵ���ϴ��� - ����ֵ �ϴ���
  int diff = b - a;
  // b < a : b - (diff & -1)
  // b > a : b - (diff & 0)
  return b - (diff & (diff >> 31));
}
inline int qabs(int a){ // λ������ٵľ���ֵ  - ����ֵ ����ֵ
  int t = (a >> 31);
  return (a + t) ^ t;
}
inline bool isOdd(int a){ // �ж���ż�� - ���� 1 ������; ���� 0 ��ż��
  return (a & 1) == 1;
}
inline void qswap(int* a, int* b){ // λ������ٵĿ��ٽ��� - �÷� qswap(&a, &b);
  (*a) ^= (*b) ^= (*a) ^= (*b);
  return;
}
inline int qread(){ // ���ٶ���int - ���� �������
  char c = getchar();
  int f = 1, x = 0;
  while(!isdigit(c)){if(c == '-') f= -1; c = getchar();}
  while(isdigit(c)){x = x * 10 + c - '0'; c = getchar();}
  return f * x;
}

inline int qpow( int a, int b ){ // ������ - ���� a ^ b
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
