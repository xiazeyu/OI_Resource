// P1250 ����
// https://www.luogu.org/problemnew/show/P1250

// Status: AC

// ̰��, ��������

// WARN:

#include <bits/stdc++.h>

using namespace std;

struct Need{
  long b, e, n;
  Need(long Begin = 0, long End = 0, long num = 0){
    b = Begin; e = End; n = num;
  }
  bool operator< (const Need &o) const {
    if(e == o.e) // ����
      return b < o.b;
    return e < o.e;
  }
};

long n, h, b, e, t, ans = 0;
bool plant[30001];
Need work[5000];

int main(){

  scanf("%ld%ld", &n, &h);
  for(long i = 0; i < h; i++){
    scanf("%ld%ld%ld", &work[i].b, &work[i].e, &work[i].n);
  }
  // ����λ����������
  sort(work, work + h);
  // ̰��
  for(long i = 0; i < h; i++){
    // cout<<work[i].b<<" "<<work[i].e<<" "<<work[i].n<<endl;
    // �� i ������
    // ��������������
    long cnt = 0;
    for(long j = work[i].b; j <= work[i].e; j++){
      if(plant[j]) cnt++;
    }
    // cout<<"cnt: "<<cnt<<endl;
    if(cnt >= work[i].n) continue;
    // ��β����ʼ����
    for(long j = work[i].e; j >= work[i].b; j--){ // for ѭ���ڶ�������: ѭ����ʼ����
    // cout<<"try to plant: "<<j<<endl;
      if(!plant[j]){
        // cout<<"plant: "<<j<<endl;
        plant[j] = true;
        cnt++; ans++;
        if(cnt == work[i].n) break;
      }
    }
  }

  printf("%ld", ans);


  return 0;

}
