// P3374 ��ģ�塿��״���� 1
// https://www.luogu.org/problemnew/show/P3374

// Status: AC

// Problem: ��״�����±��1��ʼ

#include <bits/stdc++.h>

using namespace std;

long n, m, t, x, y;
long c[500001];

void add(long pos, long value){
  //
  while(pos <= n){ // ��Ӱ����ڵ�(index > pos)
    c[pos] += value;
    pos += pos & - pos; // ���ϴ���
  }
  return;
}

long sum(long pos){
  // ��[1-pos]֮��
  long cnt = 0;
  while(pos){// �Ӹ��ڵ���Ѱ��
    cnt += c[pos];
    pos -= pos & -pos; // ���Ĵ���
  }
  return cnt;
}

int main(){

  scanf("%ld%ld", &n, &m);
  for(long i = 1;i <= n; i++){
    scanf("%ld", &t);
    add(i, t);
  }
  for(long i = 1; i <= m; i++){
    scanf("%ld%ld%ld", &t, &x, &y);
    if(t == 1){
      add(x, y);
    }else{
      printf("%ld\n", sum(y) - sum(x - 1));
    }
  }

  return 0;

}
