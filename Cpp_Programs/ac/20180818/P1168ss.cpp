// P1168 中位数
// https://www.luogu.org/problemnew/show/P1168

// Status: AC

// WARN: 复杂的二分, check函数可分三种情况讨论 (#23)

// 树状数组+二分+离散化

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
// a 为 nS 为下标的数组
// b 为 inputOrder 为下标的数组
// c 为树状数组, c[i] 记录大小为i的数的个数

void add(long pos, long value){
  // 在第 pos 位加上 value
  while(pos <= n){
    c[pos] += value;
    pos += pos & -pos;
  }
  return;
}

long sum(long pos){
  // 求 [1, pos] 的和, 即包含 pos, 小于等于 pos 的数的个数
  long cnt = 0;
  while(pos){
    cnt += c[pos];
    pos -= pos & -pos;
  }
  return cnt;
}

long bSearch(long q){
  // 在b数组中获取有 q 个数的数的大小
  // 区间(, ]
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
  a[0] = Node(-1, 0, 0); // 使得数组下标从1开始 <= 树状数组下标必须从1开始
  for(long i = 1; i <= n; i++){
    scanf("%ld", &t);
    a[i] = Node(t, i, 1);
  }
  // 离散化
  sort(a, a + n + 1);
  for(long i = 1; i <= n; i++){
    a[i].nS = i;
    b[a[i].inputOrder] = a[i];
  } // 对于 i, i.nS 即为其离散化的结果
  // 树状数组求中位数
  for(long i = 1; i <= n; i++){
    // 桶排思想
    // 中位数处的sum有 i / 2 + 1 个数
    add(b[i].nS, 1); // 将离散化后的i丢到桶里
    // printf("handing: %ld\n", b[i]);
/*
    for(long j = 0; j <= n; j++){
      printf("sum[%ld]=%ld\n", j, sum(j));
    }printf("\n");
*/
    // printf("i=%ld bSearch: %ld\n", i, i / 2 + 1);
    if(i % 2) printf("%ld\n", bSearch(i / 2 + 1)); // 在桶中搜索中位数
  }

  return 0;

}
