// ����ƻ�
// http://www.joyoi.cn/problem/tyvj-1359

// WARN: ���ַ�Χ����λ�ںϷ�������(#5)

#include <bits/stdc++.h>

using namespace std;

long n, m, ans, l = 0, r = 8, mid;
vector<long> a;

bool check(long mon){
  long cnt = 0, tot = 0; // tot �ǹ�ȥ�ܵ�Ǯ
  for(long i = 1; i <= n; i++){
    if(tot + a[i] > mon){ // ���� ����(i)��������
      tot = a[i]; // ̫����, ��ȡǮ�ٴ�
      cnt++;
    }else{
      tot += a[i]; // ����
    }
  }
  if(tot > 0) cnt++; // ���һ�컹��ûȡ��Ǯ ȡ����
  return (cnt <= m);
}

int main(){

  scanf("%ld%ld", &n, &m);
  a.resize(n + 4);
  for(long i = 1; i <= n; i++){
    scanf("%ld", &a[i]);
    l = max(l, a[i]); // l from max, not from 0
    r += a[i];
  }

  while(l < r){
    mid = (l + r) / 2;
    // printf("c%ld=%d\n", mid, check(mid));
    if(check(mid)){
      r = mid;
      ans = mid;
    }else{
      l = mid + 1;
    }
  }

  printf("%ld", ans);

  return 0;

}
