#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define OJ

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
/*
inline ull int unsllmin(ull int a, ull int b){
    return a > b ? b : a;
}
*/
ull int n, m;
ll int cnt = 0;

int main(){
	#ifndef OJ
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif


    cin >> n >> m;
    if ( n == 1 ){
        cout << m << endl;
        return 0;
    }
    while ( ( n > 1 ) && ( m > 1 ) ){
        ull int t, rate = 1;
        t = min( m, n ); // printf("t%lld\n", t);
        if( n >= m ){
            rate = n / t;
            n -= t * rate;
            cnt += rate;
        }else{
            rate = m / t;
            m -= t * rate;
            cnt += rate;
        }// printf("%lld %lld\n", m, n);
    }
    if ( n == 1 ){
        cnt += m;
    }
    if ( m == 1){
        cnt += n;
    }
    cout << cnt << endl;


	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;

}
