// P3372 【模板】线段树 1
// https://www.luogu.org/problemnew/show/P3372

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

long long t[400008];
int n, m;

void addV(int now, long tB, long tE, long long v){
  // now: 当前结点
  // t: 要增加的区间
  // v: 值
  if((nowL == nowR) && (tB <= nowL) && (tE >= nowR)){
    t[nowL] += v;
    return;
  }
  long l1 = nowL,
  r1 = (nowL + nowR),
  l2 = (nowL + nowR) + 1,
  r2 = nowR,
  if((tb <= l1) && (tE >= r1)){
    addV(l1, r1, tB, tE, v);
  }
  if((tb <= l2) && (tE >= r2)){
    addV(l2, r2, tB, tE, v);
  }
  t[]
}

int main(){

  scanf("%d%d", &n, &m);


  return 0;

}
