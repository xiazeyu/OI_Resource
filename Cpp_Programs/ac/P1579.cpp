// P1579 ¸çµÂ°ÍºÕ²ÂÏë£¨Éý¼¶°æ£©
// https://www.luogu.org/problemnew/show/P1579

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

long n, cnt = 0, prime[20000];
bool isPri[20000];

void getPri(){
  for(long i = 0; i < 20000; i++)
    isPri[i] = true;
  for(long i = 2; i <= n; i++){
    if(isPri[i]) prime[cnt++] = i;
    for(long j = 0; j < cnt && i * prime[j] <= n; j++){
      isPri[i * prime[j]] = false;
      if(i % prime[j] == 0) break; // HERE
    }
  }
}

int main(){

  scanf("%ld", &n);
  getPri();
  for(long i = 0; i < cnt; i++){
    for(long j = i; j < cnt; j++){
      for(long k = j; k < cnt; k++){
        if(prime[i] + prime[j] + prime[k] == n){
          printf("%ld %ld %ld\n", prime[i], prime[j], prime[k]);
          return 0;
        }
      }
    }
  }

  return 0;

}
