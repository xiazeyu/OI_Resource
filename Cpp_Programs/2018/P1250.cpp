// P1250 ÖÖÊ÷
// https://www.luogu.org/problemnew/show/P1250

#include <bits/stdc++.h>

using namespace std;

struct plant{
  long Begin, End, q;
  operator< (const plant &b) const {
    if(Begin == b.Begin){
      return End < b.End;
    }
    return Begin < b.Begin;
  }
};

long n, h, planted, lastEnd, ans = 0;
vector<bool> tree;
vector<plant> need;


int main(){

  scanf("%ld", &n);
  scanf("%ld", &h);
  tree.resize(n + 4, false);
  need.resize(h + 4);
  for(long i = 0; i < h; i++){
    scanf("%ld %ld %ld", &need[i].Begin, &need[i].End, &need[i].q);
  }
  sort(need.begin(), need.begin() + h);
  lastEnd = need[0].End; // HERE!!!!!
  for(long i = 0; i < h; i++){
    planted = 0;
    for(int j = need[i].Begin; j < lastEnd; j++){
      if(tree[j]) planted++;
    }
    lastEnd = max(need[i].End, lastEnd);
    for(int j = 0; j < need[i].q - planted; j++){
      tree[n - j] = true;
    }
  }

  for(int i = 0; i < n; i++){
    ans++;
  }

  printf("%ld", ans);


  return 0;

}
