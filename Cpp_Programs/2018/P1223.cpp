#include <bits/stdc++.h>

using namespace std;

struct person{
  long time, order;
  bool operator<(const person &b) const {
    return time < b.time;
  }
};

long n;
long long s = 0, sum = 0;
vector<person> t;

int main(){

  scanf("%ld", &n);
  t.resize(n + 4);
  for(int i = 0; i < n; i++){
    scanf("%ld", &t[i].time);
    t[i].order = i + 1;
  }
  sort(t.begin(), t.begin() + n);
  for(int i = 0; i < n; i++){
    s += t[i].time;
    sum += s;
    printf("%ld ", t[i].order);
  }
  printf("\n%.2lf", (sum - s) / (double)n);


  return 0;

}
