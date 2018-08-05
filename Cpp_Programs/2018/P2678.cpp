// ��ʯͷ
// https://www.luogu.org/problemnew/show/P2678
// TODO: https://www.luogu.org/record/show?rid=9327192
// WARN: ��������ҿ�(#1)

#include <bits/stdc++.h>

using namespace std;

long long l ,le, ri, mid, ans = 0;
long n, m;
vector<long long> d;

bool check(long long dist){
  long long now = 0, nxt = 1;
  // now: ��ǰ��λ��, 0<=index<=n + 1, n �����һ������Ƴ���ʯͷ
  // nxt: ��һ��λ��
  long cnt = 0;
  // cnt: ���ߵ�ʯͷ��
  // ����nxtʯͷ
  while(nxt <= n){ // ��Ϊnxt��ʵ�ʲ�����ʯͷ, ��[1, n]������
    if(d[nxt] - d[now] < dist){
      nxt++;cnt++;
      // ����ʯͷ
    }else{
      now = nxt; // ����nxt��
      nxt++;
    }
  }
  return (cnt <= m);
}

int main(){

  scanf("%lld%ld%ld", &l, &n, &m);
  d.resize(n + 4);
  d[0] = 0;
  d[n + 1] = l;
  for(int i = 1; i <= n; i++){
    scanf("%lld", &d[i]);
  }
  le = 0;
  ri = l + 1;
  while(le < ri){
    mid = (le + ri) / 2;
    if(check(mid)){
      ans = mid;
      le = mid + 1;
    }else{
      ri = mid;
    }
  }

  printf("%lld", ans);

  return 0;

}
