#include <bits/stdc++.h>

using namespace std;

struct item{
  long x, w;
  // x: ��С, w: ��ֵ
};

long n, m, ans = 0;
item s[40];

void DFS(long a, long b, long c){
  // �׶�: ��ǰ��Ե�a����Ʒ
  // ״̬: ��ǰ���item[a]��Ʒ, ʣ��b�ռ�, �ѻ��c��ֵ
  // ״̬ת��: ȡ/��ȡ
  // Լ������: �ռ䲻��, ��Ʒȡ��
  if((a == n) || (s[a].x > b)){
    ans = max(ans, c);
    return;
  }
  DFS(a + 1, b, c);
  DFS(a + 1, b - s[a].x, c + s[a].w);
  return;
}

int main(){

  // freopen("pack.in", "r", stdin);
  // freopen("pack.out", "w", stdout);

  scanf("%ld%ld", &n, &m);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &s[i].x, &s[i].w);
  }

  DFS(1, m, 0);
  if(s[0].x > m)
    DFS(1, m - s[0].x, s[0].w);

  printf("%ld\n", ans);

  return 0;

}
