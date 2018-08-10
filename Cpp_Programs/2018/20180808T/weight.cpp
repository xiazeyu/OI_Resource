#include <bits/stdc++.h>

using namespace std;

const int t[] = {1, 2, 3, 5, 10, 20};

long a[6], maxM = 0, cnt = 0;

int main(){

  freopen("weight.in", "r", stdin);
  freopen("weight.out", "w", stdout);

  for(long i = 0; i < 6; i++){
    scanf("%ld", &a[i]);
    maxM += a[i] * t[i];
  }

  for(long i = 1; i <= maxM; i++){
    long mT = i;
    for(long j = 5; j >= 0; j--){
      long qT = min(a[j], mT / t[j]);
      mT -= qT * t[j];
    }
    if(mT == 0) cnt++;
  }

  printf("Total=%ld\n", cnt);

  fclose(stdin);
  fclose(stdout);
  return 0;

}
