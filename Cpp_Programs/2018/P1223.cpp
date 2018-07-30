#include <cstdio>
#include <algorithm>

using namespace std;

struct person{
  long int time;
  long int no;
  bool operator< (person const &a){ // HERE!!!!!
    return time < a.time;
  }
};

int main(){
  long int n, t;
  long long int s = 0, sum = 0; // HERE!!!!!!
  person q[1024];

  scanf("%ld", &n);
  for(long int i = 1; i <= n; i++){
    scanf("%ld", &t);
    q[i - 1].time = t;
    q[i - 1].no = i;
  }
  sort(q, q + n);
  for(int i = 1; i <= n; i++){
    printf("%ld ", q[i - 1].no);
    s += q[i - 1].time;
    sum += s;
  }
  printf("\n%.2lf", (sum - s) / (double)n);

  return 0;

}
