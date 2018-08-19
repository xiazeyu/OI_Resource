// P1168 中位数
// https://www.luogu.org/problemnew/show/P1168

// Status: AC

#include <bits/stdc++.h>

using namespace std;

long n, t;
priority_queue<long, vector<long>, greater<long> > a; // 小根堆
priority_queue<long, vector<long>, less<long> > b; // 大根堆

int main(){

  scanf("%ld", &n);
  scanf("%ld", &t);
  b.push(t);
  printf("%ld\n", b.top());
  for(int i = 2; i <= n; i++){
    scanf("%ld", &t);
    if(t > b.top()){
      a.push(t);
    }else{
      b.push(t);
    }
    while(abs(a.size() - b.size()) > 1){
      if(a.size() > b.size()){
        b.push(a.top());
        a.pop();
      }else{
        a.push(b.top());
        b.pop();
      }
    }
    if(i % 2){
      if(a.size() > b.size()){
        printf("%ld\n", a.top());
      }else{
        printf("%ld\n", b.top());
      }
    }
  }

  return 0;

}
