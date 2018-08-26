#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define eps 1e-8
#define OJ
#define getd(n, w) ((n&(1<<w))>>w)

// Tip #0: �����ܼ�ʵ��
// Tip #0.1: �������Ϊ����
// Tip #1: �ҳ���Ŀ�仯����, ������ �����Ǽ�ģ�� (@P2678)
// Tip #2: ���鼯����ʱjoinΪ�ϲ����϶�����Ԫ�� (@P3367)
// Tip #3: ���鼯��Find��·��ѹ�� (@P3367)
// Tip #4: ��������ע�����Ҷ˵� �������̰�� (@day2eg1ѡ���ཻ��������)
// Tip #5: ��̬�滮״̬���: �޺�Ч��, ����״̬ ���Ӷ�̫�� => �Ż�ת��, ����״̬
// Tip #6: �к�Ч��: ״̬���¶���, ����ά��
// Tip #7: ��̸��Ӷ� > ʱ�临�Ӷ� > �ռ临�Ӷ�
// Tip #8: ע�ʹ󷨺�
// Tip #9: �Ż��ص�������
// �߶��� 4���ռ�
// 1s = 4e8 �����
// 128M, 1e7 long long 8bits
// double �������, long double ����
// dfs: stack: 2MB, 10000 layers
// bfs: 512MB, �ܴ���
// cin: 10e5
// cout<<sizeof(struct{all varibles.})<<endl;

// Rule #1: ����[ , ) ���ִ�ʱ����������+1 (@P2678)
// Rule #2: while �� for �ڲ������Ƴ�����Ҫ���� �Ƿ����/Խ�� (@P2678)
// Rule #3: ʹ��ʵ�����޵ı�����Ϊѭ������, �Ƴ��������� (@P2678)
// Rule #4: �����Ƿ�Ϊ ��������: while(scanf != EOF) (@poweroj2461)
// Rule #5: ���ַ�Χ����λ�ںϷ������� (@tvyj2359)
// Rule #6: ʹ��printf�����ʱע�� \n �س� (@P3367)
// Rule #7: ���鼯����ʱjoinΪ�ϲ����϶�����Ԫ�� (@P3367)
// Rule #8: ��С������ ȥ��+ȥ�� (@P3366PrimB)
// Rule #9: vector::size() == n => a�����һ��Ԫ��Ϊa[n - 1] (@P2141)
// Rule #10: �ر� �Ի� ����ͨ �� (���ȶ����Ƿ�Ϊ�� if(q.empty()) continue;) (@P3371D)
// Rule #11: SPFA: ÿ���ɳ����·���ϵ�һ����, ȷ��һ��������: while(!q.empty());
// Rule #11.1: Dijkstra: ÿ����һ����: for(long i = 1; i <= n; i++)
// Rule #11.2: SPFA �� Dijkstra ������: vis[] ���岻ͬ, ѭ����ֹ������ͬ, Ѱ��pos�㲻ͬ (@P3371D)
// Rule #12: ans += xxx % MOD (������ += , ����һ��Ҫȡģ); ans %= MOD; (@U28036)
// Rule #13: ��������: �ظ�? ì��? ����2�˵�, ��һ������a<=b, �ֶ����� (@poj2777)
// Rule #14: SPFA: dist ���ֵΪ 0x3f3f3f3f, С�����! (��dist + dist) (@3371F)
// Rule #15: 0, 1��������, Ҳ���Ǻ��� (@P3383)
// Rule #17: Dijkstra �ɳ�ʱ (!vis[v]) ���� (@P2384)
// Rule #18: �ڽӱ��¼pre������ for Edge[pre[point]] �ұ� (@2384)
// Rule #19: �ݹ�, ���� ���䷨�Ż� (@1028)
// Rule #20: ��, ��֪�������鲻ʹ��vector, ���ױ������� (@P1250GreedyArray)
// Rule #21: �������˳�ѭ�� (@P3383)
// Rule #22: ����: �ĸ�״̬ת�Ƶ��ĸ�״̬ (@P2730)
// Rule #23: ���ӵĶ���, check�����ɷ������������ (@P1168ss)
// Rule #24: log2������, ע���������Ϊlog(_n, 2)����log(_n, 2) + 1 (while����Ϊ _n - 1) (@P3865)
// Rule #25: ��������ʱ��ǰ��Case Number����Ƿ�����(����while(t--)) (@hdu1166)
// Rule #26: �߶���: ��ֵ(add()::���Ӽ�, pushDown())��, lazy Ϊ���µĸ�ֵ��������, data ��lazy Ӧ�Զ�Ҷ�ӽڵ�Ĳ���Ϊ׼ (@poj2777)
// Rule #27: bitset: �Ƿ���ֱ��ʹ��count()? �Ƿ��ѳ�����Χ��ǰ��0һ���¼? (@poj2777)
// Rule #28: ��������string: getline(cin, str); (@P1598)
// Rule #29: ������תҪȥǰ��0�ͺ�0 (@P1553)

// ʹ��ȫ�ֱ���
// ans �Ƿ�ʹ�� long long, �߾���
// string �洢 ���� ���ʱ while(str[0] == '0') str = str.substr(1); if(!str.length()) str = '0' + str; (@P1106, @P1553)
// array �Ǵ� 0 ��ʼ��
// array ���һλ�� n-1
// ��ͷ����, ��� Begin == End
// �򵥹��ܲ�ʹ�� function
// ѭ���ڶ�������: ѭ����ʼ����
// for (int i = 0; i < count; i++)

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
  // ios::sync_with_stdio(false); cin.tie(0);
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

  return 0;

}
