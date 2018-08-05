// https://www.luogu.org/problemnew/show/T39016
// AC AC AC WA WA WA(¾ùÎªansµÄ1/2) RE RE RE...

#include <bits/stdc++.h>

using namespace std;

long n, m, seed, Min;

vector<int> a;
vector<int>::iterator it;
priority_queue<int, vector<int>, greater<int> > que;

void generate_array(vector<int> &a, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; ++i) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        a.push_back(x % m + 1);
    }
}

int main(){

  scanf("%ld %ld %ld", &n, &m, &seed);
  generate_array(a, n, m, seed);
  for(it = a.begin(); it != a.end(); it++){
    que.push(*it);
  }

  while(1){
    Min = que.top();
    que.pop();
    if(que.empty()) break;
    if(2 * Min > que.top()){
      que.pop();
      que.push(2 * Min);
    }
  }

  printf("%d\n", Min);
  return 0;

}
