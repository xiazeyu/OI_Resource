// P3383 ��ģ�塿����ɸ����
// https://www.luogu.org/problemnew/show/P3383

// Status: 4ms-800ms, AC

// WARN: 0, 1 �������� (#15)
// WARN: �������˳�ѭ�� (#21)

#include <bits/stdc++.h>

using namespace std;

vector<long> prime;
vector<bool> isPri;
long n, m, t, cnt = 0;

int main(){

  scanf("%ld%ld", &n, &m);
  prime.resize(n + 1);
  isPri.resize(n + 1, true);
  for(long i = 2; i <= n / 2; i++){ // ö�ٺ����������, i <= n / 2ʱ Prime[] ��ȫ, i <= n ʱ Prime[]ȫ
    if(isPri[i]) prime[cnt++] = i; //����Ŀǰ�ҵ��������ı���, ���ҵ�����
    for(long j = 0; j < cnt && i * prime[j] <= n; j++){// ��С������������ӳ˻���Ϊ����, ɸȥ����
      isPri[i * prime[j]] = false; //�ҵ��������ı������ٷ���
      if(i % prime[j] == 0) break; // http://www.cnblogs.com/A-S-KirigiriKyoko/articles/6034572.html
    }
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld", &t);
    if((t == 0) || (t == 1)){
      printf("No\n");
      continue; // �������˳�ѭ��
    }
    if(isPri[t])
      printf("Yes\n");
    else
      printf("No\n");
  }


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
