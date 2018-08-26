#include <bits/stdc++.h>
#define LuN 100069
#define Inf 0x3f3f3f3f
#define eps 1e-8
#define OJ
#define getd(n, w) ((n&(1<<w))>>w)

// Tip #0: 尽可能简单实现
// Tip #0.1: 将无序变为有序
// Tip #1: 找出题目变化规律, 不变量 而不是简单模拟 (@P2678)
// Tip #2: 并查集操作时join为合并集合而不是元素 (@P3367)
// Tip #3: 并查集在Find中路径压缩 (@P3367)
// Tip #4: 区间问题注意左右端点 排序后考虑贪心 (@day2eg1选择不相交区间问题)
// Tip #5: 动态规划状态设计: 无后效性, 精简状态 复杂度太高 => 优化转移, 精简状态
// Tip #6: 有后效性: 状态重新定义, 增加维度
// Tip #7: 编程复杂度 > 时间复杂度 > 空间复杂度
// Tip #8: 注释大法好
// Tip #9: 优化重叠子问题
// 线段树 4倍空间
// 1s = 4e8 条语句
// 128M, 1e7 long long 8bits
// double 读入输出, long double 计算
// dfs: stack: 2MB, 10000 layers
// bfs: 512MB, 很大了
// cin: 10e5
// cout<<sizeof(struct{all varibles.})<<endl;

// Rule #1: 区间[ , ) 二分答案时右区间至少+1 (@P2678)
// Rule #2: while 及 for 内部所有推出量均要考虑 是否溢出/越界 (@P2678)
// Rule #3: 使用实际受限的变量作为循环变量, 推出其他变量 (@P2678)
// Rule #4: 输入是否为 多组输入: while(scanf != EOF) (@poweroj2461)
// Rule #5: 二分范围必须位于合法区间内 (@tvyj2359)
// Rule #6: 使用printf输出答案时注意 \n 回车 (@P3367)
// Rule #7: 并查集操作时join为合并集合而不是元素 (@P3367)
// Rule #8: 最小生成树 去重+去环 (@P3366PrimB)
// Rule #9: vector::size() == n => a的最后一个元素为a[n - 1] (@P2141)
// Rule #10: 重边 自环 不连通 环 (优先队列是否为空 if(q.empty()) continue;) (@P3371D)
// Rule #11: SPFA: 每次松弛最短路径上的一条边, 确定一个或多个点: while(!q.empty());
// Rule #11.1: Dijkstra: 每次找一个点: for(long i = 1; i <= n; i++)
// Rule #11.2: SPFA 与 Dijkstra 代码差别: vis[] 意义不同, 循环终止条件不同, 寻找pos点不同 (@P3371D)
// Rule #12: ans += xxx % MOD (由于是 += , 这里一定要取模); ans %= MOD; (@U28036)
// Rule #13: 输入数据: 重复? 矛盾? 给出2端点, 不一定满足a<=b, 手动排序 (@poj2777)
// Rule #14: SPFA: dist 最大值为 0x3f3f3f3f, 小心溢出! (会dist + dist) (@3371F)
// Rule #15: 0, 1不是素数, 也不是合数 (@P3383)
// Rule #17: Dijkstra 松弛时 (!vis[v]) 条件 (@P2384)
// Rule #18: 邻接表记录pre后仍需 for Edge[pre[point]] 找边 (@2384)
// Rule #19: 递归, 递推 记忆法优化 (@1028)
// Rule #20: 大, 已知长度数组不使用vector, 容易被卡常数 (@P1250GreedyArray)
// Rule #21: 特殊判退出循环 (@P3383)
// Rule #22: 审题: 哪个状态转移到哪个状态 (@P2730)
// Rule #23: 复杂的二分, check函数可分三种情况讨论 (@P1168ss)
// Rule #24: log2函数中, 注意最终求得为log(_n, 2)还是log(_n, 2) + 1 (while条件为 _n - 1) (@P3865)
// Rule #25: 多组输入时当前的Case Number输出是否正常(不能while(t--)) (@hdu1166)
// Rule #26: 线段树: 赋值(add()::是子集, pushDown())中, lazy 为最新的赋值操作本身, data 与lazy 应以对叶子节点的操作为准 (@poj2777)
// Rule #27: bitset: 是否能直接使用count()? 是否会把超出范围的前导0一起记录? (@poj2777)
// Rule #28: 读入整行string: getline(cin, str); (@P1598)
// Rule #29: 分数反转要去前导0和后导0 (@P1553)

// 使用全局变量
// ans 是否使用 long long, 高精度
// string 存储 数字 输出时 while(str[0] == '0') str = str.substr(1); if(!str.length()) str = '0' + str; (@P1106, @P1553)
// array 是从 0 开始的
// array 最后一位是 n-1
// 两头搜索, 检查 Begin == End
// 简单功能不使用 function
// 循环第二个参数: 循环开始条件
// for (int i = 0; i < count; i++)

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
  // ios::sync_with_stdio(false); cin.tie(0);
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

  return 0;

}
