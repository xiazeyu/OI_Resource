// P3366 ��ģ�塿��С������
// https://www.luogu.org/problemnew/show/P3366

// Prim �ڽӱ�

// Status: AC

// Question: ��ͼ����ͨ ����д����

#include <limits.h>
#include <bits/stdc++.h>

const long maxL = 0x3f3f3f3f;

using namespace std;

struct Node{
  long v, w;
  Node(long a = 0, long b = 0){
    v = a; w = b;
  }
};

vector<bool> vis;
vector<long> dist;
vector<vector<Node> > Edge;
long n, m, x, y, z, ans = 0;

int main(){

  scanf("%ld%ld", &n, &m);
  vis.resize(n + 1);
  dist.resize(n + 1, maxL);
  Edge.resize(n + 1);
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &x, &y, &z);
    Edge[x].push_back(Node(y, z));
    Edge[y].push_back(Node(x, z));
  }
  dist[1] = 0;
  for(long i = 1; i <= n; i++){
    long pos = 0; // �ҵ�v���ϵ������
    for(long j = 1; j <= n; j++){
      if((!vis[j])&&(dist[j] < dist[pos])) pos = j;
    }
    if(pos == 0){ // δ�ҵ���v��ͨ�ĵ�
      printf("orz\n");
      return 0;
    }
    vis[pos] = true; // pos Ϳɫ
    ans += dist[pos];

    for(long j = 0; j < Edge[pos].size(); j++){ // �ɳ� v
      long v = Edge[pos][j].v;
      if((!vis[v]) && (dist[v] > Edge[pos][j].w)){
        dist[v] = Edge[pos][j].w;
      }
    }
  }

  printf("%ld\n", ans);

  return 0;

}
