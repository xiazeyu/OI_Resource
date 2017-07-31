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

int n, m;
char dat[ 512 ][ 512 ] = {0};
long long int ans[ 512 ][ 512 ] = {0};
bool flag = true;

long long int funcanso( long int a, long int b ){
    if( ans[a][b] != 0 ) return ans[a][b];
    ans[a][b] = funcanso(a + 1, b) + funcanso(a, b + 1);
    return ans[a][b];
}


bool ifhw( string t ){
    for( int i = 1; i <= t.length() / 2; i++){
        if(t.c_str()[i - 1] != t.c_str()[t.length() - i]) return false;
    }
    return true;
}

long long int bpbaoli(string t, int x, int y){
    t += dat[x][y];
    if(t.length() != m + n - 1){
        return bpbaoli(t, x + 1, y) + bpbaoli(t, x, y + 1);
    }
    if(ifhw(t)) return 1; else return 0;
}
int main(){
	#ifndef OJ
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	scanf("%d %d", &n, &m);
	for ( int i = 1; i <= n; i++ ){
        string t;
        cin >> t;// if(ifhw(t)) cout<<"True"<<endl;
        for ( int j = 1; j <= m; j++){
            dat[ j ][ i ] =  t[ j - 1 ];
            if ( dat[ j ][ i ] != 'a' ) flag = false;
        }
	}
/*
	for(int y = 1; y <= n; y++){
        for ( int x = 1; x <= m; x++ ){
            cout<<dat[x][y];
        }
        cout << endl;
	}
*/
	if( flag ){
		for(int i = 1; i <= n; i++){
            ans[ m ][ i ] = 1;
		}
		for( int i = 1; i <= n; i++){
            ans[ i ][ n ] = 1;
		}

		cout << funcanso(1, 1) << endl;
		return 0;
	}

	cout << bpbaoli("", 1, 1) << endl;


	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;

}
