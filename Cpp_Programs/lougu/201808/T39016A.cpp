// https://www.luogu.org/problemnew/show/T39016
// TODO: 第3个点以后RE

#include <bits/stdc++.h>

using namespace std;

long n, m, seed, t;

vector<int> a;

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
  while(a.size() - 1){
    sort(a.begin(), a.begin() + a.size());
    if(2 * a[0] > a[1]){
      a[1] = 2 * a[0];
    }
    a.erase(a.begin());
  };
  printf("%d", a[0]);
  return 0;

}
