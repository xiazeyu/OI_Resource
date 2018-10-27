// P3384 【模板】树链剖分
// https://www.luogu.org/problemnew/show/P3384

// Status: AC

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100008

long n, m, r, p, _inw[MAXN], _inx, _iny, _inc, _inz, t,
     fa[MAXN], depth[MAXN], size[MAXN], hevSon[MAXN],
	   top[MAXN], weight[MAXN], ord[MAXN], footmark[MAXN],
	   BIT1[MAXN], BIT2[MAXN];
vector<int> Edge[MAXN];

// fa[ID] 节点父亲
// depth[ID] 节点深度
// size[ID] 子树大小(包含自身)
// hevSon[ID] 节点重儿子
// top[ID] 链头!!!非链的前继
// ord[ID] ID -> DFSID
// weight[DFSID] 权值
// footmark[DFSID] DFSID -> ID

void _debug_print_TCD();
void _debug_print_BIT();
void _debug_print_Tree();

inline void _addBIT(long pos, long v){
  // 对原始的pos加上v
  // 不能直接使用
  long t = pos;
  while(t <= n){
    BIT1[t] += v;
    BIT2[t] += pos * v;
    t += t & -t;
  }
  return;
}

inline void addBIT(long l, long r, long v){
  // 对[l, r]差分加上v
  _addBIT(l, v); _addBIT(r + 1, -v);
  return;
}

inline long _getBIT(long pos){
  // 求[1-pos]之和
  long t = pos, cnt = 0;
  while(t){// 从根节点逐步寻找
    cnt += (pos + 1) * BIT1[t] - BIT2[t];
    t -= t & -t;
  }
  return cnt;
}

inline long getBIT(long l, long r){
  // 求[l, r]之和
  return _getBIT(r) - _getBIT(l - 1);
}

void dfs1(long node){
  // 了解一些节点的初步信息
  // 父节点fa, 深度depth, 包含自己的子树大小size, 重儿子hevSon
  size[node] = 1; // 子树个数包含本身
  for(unsigned long i = 0; i < Edge[node].size(); i++){
  	long v = Edge[node][i];
  	if(v == fa[node]) continue; // 防止死循环!
  	fa[v] = node;
  	depth[v] = depth[node] + 1;
  	dfs1(v);
  	size[node] += size[v];
  	if((hevSon[node] == 0) || (size[v] > size[hevSon[node]])) hevSon[node] = v;
  }
  return;
}
// ord[ID] ID -> DFSID

void dfs2(long node, long tp){
  // 开始剖分, 优先重儿子
  // 当期链顶端顶点top, 树状链footmark, 新点编号ord, 新点权值weight
  top[node] = tp; // 链头
  ord[node] = ++t; // 新顺序
  footmark[t] = t; // 按新顺序甩进树状链footmark里
  weight[t] = _inw[node]; // 更新新点权值
  if(hevSon[node]){ // 非叶子节点
  	dfs2(hevSon[node], tp); // 先拉重儿子
	for(unsigned long i = 0; i < Edge[node].size(); i++){ // 拉其他的点
	  long v = Edge[node][i];
	  if((v == fa[node]) || (v == hevSon[node])) continue;
	  dfs2(v, v); // 轻儿子以自己为起点
	}
  }
}

// 有用信息:
// getBIT(l, r), 获取[l, r]区间点权和
// addBIT(l, r, v) 在区间[l, r]点权增加w

inline void addRange(long x, long y, long w){
  w %= p;
  while(top[x] != top[y]){ // 不在同一条链上
    if(depth[top[x]] < depth[top[y]]) swap(x, y); // x链顶端!!!深度比y大
    addBIT(ord[top[x]], ord[x], w); // 在[top[x], x]链上增加权值w
    x = fa[top[x]]; // x跳到更上面的链上
  }
  // 在同一条链上
  if(depth[x] > depth[y]) swap(x, y); // x在y前
  addBIT(ord[x], ord[y], w);
  return;
}

inline long getRangeSum(long x, long y){
  long cnt = 0;
  while(top[x] != top[y]){ // 不在同一条链上
    if(depth[top[x]] < depth[top[y]]) swap(x, y); // / x链顶端!!!深度比y大
    cnt += getBIT(ord[top[x]], ord[x]); // 将[top[x], x]链上的权值加到cnt
    cnt %= p;
    x = fa[top[x]]; // 跳到更上面的链上
  }
  // 在同一条链上
  if(depth[x] > depth[y]) swap(x, y); // x在y前
  return (cnt + getBIT(ord[x], ord[y])) % p;
}

inline void addTree(long node, long v){
  // 即区间[ord[node], ord[node] + size[node] - 1]
  addBIT(ord[node], ord[node] + size[node] - 1, v % p); // 减去自身
  return;
}

inline long getTreeSum(long node){
  return getBIT(ord[node], ord[node] + size[node] - 1) % p;
}


/*
8 0 1 0
1 2 3 4 5 6 7 8
1 2
1 6
6 7
6 8
2 3
2 5
3 4
*/
inline void _debug_print_TCD(){
  printf("n:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", i);
  printf("\nfa:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", fa[i]);
  printf("\ndepth:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", depth[i]);
  printf("\nsize:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", size[i]);
  printf("\nhevSon:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", hevSon[i]);
  printf("\nord:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", ord[i]);
  printf("\n\nn:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", i);
  printf("\ntop:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", top[i]);
  printf("\nweight:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", weight[ord[i]]);
  printf("\n");
}


inline void _debug_print_BIT(){
  printf("\n\nn:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", i);
  printf("\nBIT1:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", BIT1[i]);
  printf("\nBIT2:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", BIT2[i]);
  printf("\nwInBIT:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", getBIT(i, i));
  printf("\n");
}

inline void _debug_print_Tree(){
  printf("\n\nn:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", i);
  printf("\nweight:\t");
  for(long i = 1; i <= n; i++)
    printf("%ld\t", getBIT(ord[i], ord[i]));
  printf("\n");
}

int main(){

  // Input
  scanf("%ld%ld%ld%ld", &n, &m, &r, &p);
  for(long i = 1; i <= n; i++)
    scanf("%ld", &_inw[i]);
  for(long i = 1; i <= n - 1; i++){
  	scanf("%ld%ld", &_inx, &_iny);
  	if(_inx == _iny) continue;
  	Edge[_inx].push_back(_iny);
  	Edge[_iny].push_back(_inx);
  }

  // Start!
  dfs1(r);
  dfs2(r, r);
  for(long i = 1; i <= n; i++)
    addBIT(i, i, weight[i]);

  // DEBUG
  // _debug_print_TCD();
  // _debug_print_BIT();

  for(long i = 1; i <= m; i++){
  	scanf("%ld", &_inc);
  	if(_inc == 1){
  	  scanf("%ld%ld%ld", &_inx, &_iny, &_inz);
  	  addRange(_inx, _iny, _inz);
	  }else if(_inc == 2){
	    scanf("%ld%ld", &_inx, &_iny);
	    printf("%ld\n", getRangeSum(_inx, _iny));
	  }else if(_inc == 3){
	    scanf("%ld%ld", &_inx, &_inz);
	    addTree(_inx, _inz);
	  }else if(_inc == 4){
	    scanf("%ld", &_inx);
	    printf("%ld\n", getTreeSum(_inx));
	  }
  }


  return 0;

}
