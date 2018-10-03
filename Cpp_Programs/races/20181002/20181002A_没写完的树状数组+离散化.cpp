#include <bits/stdc++.h>

/*
10
1 3 6 9 0 8 5 7 4 2
*/

using namespace std;

struct Node{
  long origin, order;
  Node(long _ori = 0, long _ord = 0){
    origin = _ori; order = _ord;
  }
  operator< (const Node &b) const {
    return origin < b.origin;
  }
};

long n, _a, ord[5008], cnt, ans, treeArr[5008];
Node a[5001];

void add(long pos, long value){
  while(pos <= n){
    treeArr[pos] += value;
    pos += pos & -pos;
  }
  return;
}

long sum(long pos){
  // [1, pos]
  long cnt = 0;
  while(pos){
    cnt += treeArr[pos];
    pos -= pos & -pos;
  }
  return cnt;
}

int main(){

  while(scanf("%ld", &n) != EOF){
    for(long i = 0; i < n; i++){
      scanf("%ld", &_a);
      a[i] = Node(_a, i);
    }
    sort(a, a + n);
    for(long i = n; i > 0; i--){
      a[i] = a[i - 1];
    }
    for(long i = 1; i <= n; i++){
      ord[a[i].order] = i;
      cout<<a[i].order<<" "<<i<<endl;
    }
    for(long i = 0; i < n; i++){

    }
  }

  return 0;

}
