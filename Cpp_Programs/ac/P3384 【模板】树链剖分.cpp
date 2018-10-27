// P3384 ��ģ�塿�����ʷ�
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

// fa[ID] �ڵ㸸��
// depth[ID] �ڵ����
// size[ID] ������С(��������)
// hevSon[ID] �ڵ��ض���
// top[ID] ��ͷ!!!������ǰ��
// ord[ID] ID -> DFSID
// weight[DFSID] Ȩֵ
// footmark[DFSID] DFSID -> ID

void _debug_print_TCD();
void _debug_print_BIT();
void _debug_print_Tree();

inline void _addBIT(long pos, long v){
  // ��ԭʼ��pos����v
  // ����ֱ��ʹ��
  long t = pos;
  while(t <= n){
    BIT1[t] += v;
    BIT2[t] += pos * v;
    t += t & -t;
  }
  return;
}

inline void addBIT(long l, long r, long v){
  // ��[l, r]��ּ���v
  _addBIT(l, v); _addBIT(r + 1, -v);
  return;
}

inline long _getBIT(long pos){
  // ��[1-pos]֮��
  long t = pos, cnt = 0;
  while(t){// �Ӹ��ڵ���Ѱ��
    cnt += (pos + 1) * BIT1[t] - BIT2[t];
    t -= t & -t;
  }
  return cnt;
}

inline long getBIT(long l, long r){
  // ��[l, r]֮��
  return _getBIT(r) - _getBIT(l - 1);
}

void dfs1(long node){
  // �˽�һЩ�ڵ�ĳ�����Ϣ
  // ���ڵ�fa, ���depth, �����Լ���������Сsize, �ض���hevSon
  size[node] = 1; // ����������������
  for(unsigned long i = 0; i < Edge[node].size(); i++){
  	long v = Edge[node][i];
  	if(v == fa[node]) continue; // ��ֹ��ѭ��!
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
  // ��ʼ�ʷ�, �����ض���
  // ���������˶���top, ��״��footmark, �µ���ord, �µ�Ȩֵweight
  top[node] = tp; // ��ͷ
  ord[node] = ++t; // ��˳��
  footmark[t] = t; // ����˳��˦����״��footmark��
  weight[t] = _inw[node]; // �����µ�Ȩֵ
  if(hevSon[node]){ // ��Ҷ�ӽڵ�
  	dfs2(hevSon[node], tp); // �����ض���
	for(unsigned long i = 0; i < Edge[node].size(); i++){ // �������ĵ�
	  long v = Edge[node][i];
	  if((v == fa[node]) || (v == hevSon[node])) continue;
	  dfs2(v, v); // ��������Լ�Ϊ���
	}
  }
}

// ������Ϣ:
// getBIT(l, r), ��ȡ[l, r]�����Ȩ��
// addBIT(l, r, v) ������[l, r]��Ȩ����w

inline void addRange(long x, long y, long w){
  w %= p;
  while(top[x] != top[y]){ // ����ͬһ������
    if(depth[top[x]] < depth[top[y]]) swap(x, y); // x������!!!��ȱ�y��
    addBIT(ord[top[x]], ord[x], w); // ��[top[x], x]��������Ȩֵw
    x = fa[top[x]]; // x���������������
  }
  // ��ͬһ������
  if(depth[x] > depth[y]) swap(x, y); // x��yǰ
  addBIT(ord[x], ord[y], w);
  return;
}

inline long getRangeSum(long x, long y){
  long cnt = 0;
  while(top[x] != top[y]){ // ����ͬһ������
    if(depth[top[x]] < depth[top[y]]) swap(x, y); // / x������!!!��ȱ�y��
    cnt += getBIT(ord[top[x]], ord[x]); // ��[top[x], x]���ϵ�Ȩֵ�ӵ�cnt
    cnt %= p;
    x = fa[top[x]]; // ���������������
  }
  // ��ͬһ������
  if(depth[x] > depth[y]) swap(x, y); // x��yǰ
  return (cnt + getBIT(ord[x], ord[y])) % p;
}

inline void addTree(long node, long v){
  // ������[ord[node], ord[node] + size[node] - 1]
  addBIT(ord[node], ord[node] + size[node] - 1, v % p); // ��ȥ����
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
