#include <bits/stdc++.h>

using namespace std;

struct qujian{
  long long Begin;
  long long End;
  bool operator< (const qujian &b)const{
    return End < b.End;
  }
};

long n, ans = 0, lastEnd = 0;
qujian q[1024];

int main(){

  scanf("%ld", &n);
  for(int i = 0; i < n; i++){
    scanf("%lld %lld", &q[i].Begin, &q[i].End);
  }
  sort(q, q + n);

  for(long i = 0; i < n; i++){
    if(q[i].Begin > lastEnd){
      ans++;
      lastEnd = q[i].End;
    }
  }

  printf("%ld", ans);

  return 0;
}
