// P1598 垂直柱状图
// https://www.luogu.org/problemnew/show/P1598

// Status: AC

// WARN:读入整行string: getline(cin, str); (#28)

#include <bits/stdc++.h>

using namespace std;
string _t;
long f[26], m = 0;

int main(){

  for(long i = 1; i <= 4; i++){
    getline(cin, _t);
    for(unsigned long j = 0; j < _t.size(); j++)
      if((_t[j] >= 'A') && (_t[j] <= 'Z'))
        f[_t[j] - 'A']++;
  }
  for(long i = 0; i < 26; i++){
    m = max(m, f[i]);
  }
  for(long i = m; i >= 1; i--){
    long s = 0;
    // a的特判
    if(f[0] >= i){
      printf("*");
    }else{
      s = 1;
    }
    for(long j = 1; j < 26; j++){
      if(f[j] >= i){
        for(long k = 1; k <= s; k++) printf(" ");
        printf(" *");
        s = 0;
      }else{
        s += 2;
      }
    }
    printf("\n");
  }
  printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");

  return 0;

}
