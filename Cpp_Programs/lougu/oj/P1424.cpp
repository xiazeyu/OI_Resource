#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define OJ

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

int main(){
	#ifndef OJ
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	#endif

	ull int cnt = 0;
    long int x, n;

    cin>>x>>n;
    for(int i = 1; i <= n; i++){
        if(x == 6){
			x++;
			continue;
        }else{
            if(x == 7){
				x = 1;
				continue;
            }else{
                x++;
				cnt += 250;
            }

        }
    }

    cout<<cnt<<endl;

	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;

}
