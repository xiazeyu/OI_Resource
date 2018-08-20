// P1168 ��λ��
// https://www.luogu.org/problemnew/show/P1168

// Status: AC

// WARN: ���ӵĶ���, check�����ɷ������������ (#23)

// ��״����+����+��ɢ��

#include <bits/stdc++.h>

using namespace std;

struct Node{
  long number, inputOrder, nS;
  Node(long num = 0, long in = 0, long sizeOrder = 0){
    number = num; inputOrder = in; nS = sizeOrder;
  }
  bool operator<(const Node &b) const{
    return number < b.number;
  }
};

long n, t;
Node a[100002], b[100002];
long c[100002];
// a Ϊ nS Ϊ�±������
// b Ϊ inputOrder Ϊ�±������
// c Ϊ��״����, c[i] ��¼��СΪi�����ĸ���

void add(long pos, long value){
  // �ڵ� pos λ���� value
  while(pos <= n){
    c[pos] += value;
    pos += pos & -pos;
  }
  return;
}

long sum(long pos){
  // �� [1, pos] �ĺ�, ������ pos, С�ڵ��� pos �����ĸ���
  long cnt = 0;
  while(pos){
    cnt += c[pos];
    pos -= pos & -pos;
  }
  return cnt;
}

long bSearch(long q){
  // ��b�����л�ȡ�� q ���������Ĵ�С
  // ����(, ]
  long l = 0, r = n, mid;
  while(l < r){
    mid = (l + r) / 2;
    // printf("bSearch(%ld), l=%ld, r=%ld, sum(%ld)=%ld\n", q, l, r, mid, sum(mid));
    if(sum(mid) == q){
      while(sum(mid) == q) mid--;
      return a[++mid].number;
    }else if(sum(mid) > q){
      r = mid;
    }else if(sum(mid) < q){
      l = mid + 1;
    }
  }
  while(sum(mid) == q) mid--;
  return a[++mid].number;
}

int main(){

  scanf("%ld", &n);
  a[0] = Node(-1, 0, 0); // ʹ�������±��1��ʼ <= ��״�����±�����1��ʼ
  for(long i = 1; i <= n; i++){
    scanf("%ld", &t);
    a[i] = Node(t, i, 1);
  }
  // ��ɢ��
  sort(a, a + n + 1);
  for(long i = 1; i <= n; i++){
    a[i].nS = i;
    b[a[i].inputOrder] = a[i];
  } // ���� i, i.nS ��Ϊ����ɢ���Ľ��
  // ��״��������λ��
  for(long i = 1; i <= n; i++){
    // Ͱ��˼��
    // ��λ������sum�� i / 2 + 1 ����
    add(b[i].nS, 1); // ����ɢ�����i����Ͱ��
    // printf("handing: %ld\n", b[i]);
/*
    for(long j = 0; j <= n; j++){
      printf("sum[%ld]=%ld\n", j, sum(j));
    }printf("\n");
*/
    // printf("i=%ld bSearch: %ld\n", i, i / 2 + 1);
    if(i % 2) printf("%ld\n", bSearch(i / 2 + 1)); // ��Ͱ��������λ��
  }

  return 0;

}
