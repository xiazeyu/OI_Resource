#include <bits/stdc++.h>
#define Inf 0x3f3f3f3f
#define ll long long

using namespace std;

inline int qmin(int a, int b){
	int diff = b - a;
	// b < a : a + (diff & -1)
	// b > a : a + (diff & 0)
	return a + (diff & (diff >> 31));
}
inline int qmax(int a, int b){
	int diff = b - a;
	// b < a : b - (diff & -1)
	// b > a : b - (diff & 0)
	return b - (diff & (diff >> 31));
}
inline int qabs(int a){
	int t = (a >> 31);
	return (a + t) ^ t;
}

int main(){
	
	
	
	return 0;
	
}
