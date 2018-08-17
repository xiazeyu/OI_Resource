// AT807 ����������ƥ��ȡ�����
// https://www.luogu.org/problemnew/show/AT807

// Status:

#include <bits/stdc++.h>

using namespace std;

vector<long> prime;
vector<bool> vis;
long n, t, cnt = 0;

int main(){

  n = 1000000;
  prime.resize(n + 1);
  vis.resize(n + 1);
  for(long i = 2; i <= n / 2; i++){ // ö�ٺ����������, i <= n / 2ʱ Prime[] ��ȫ, i <= n ʱ Prime[]ȫ
    if(!vis[i]) prime[cnt++] = i; //����Ŀǰ�ҵ��������ı���, ���ҵ�����
    for(long j = 0; j < cnt && i * prime[j] <= n; j++){// ��С������������ӳ˻���Ϊ����, ɸȥ����
      vis[i * prime[j]] = true; //�ҵ��������ı������ٷ���
      if(i % prime[j] == 0) break; // http://www.cnblogs.com/A-S-KirigiriKyoko/articles/6034572.html
    }
  }
  scanf("%ld", &t);
  if(!vis[t])
    printf("YES\n");
  else
    printf("NO\n");

  /* // ������˹����ɸ�� O(nlglgn)
  for(long i = 2; i <= n; i++){
    if(!pri[i]) continue;
    for(long j = 0; j <)

    for(long j = 2; i * j <= n; j++){
      pri[i * j] = false;
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld", &t);
    if(pri[t])
      printf("Yes\n");
    else
      printf("No\n");
  }*/
  return 0;

}
