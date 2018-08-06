// P1012 Æ´Êý
// https://www.luogu.org/problemnew/show/P1012

#include <bits/stdc++.h>

using namespace std;

int n;
string num[12];

bool comp(const string &a, const string &b){
  return b + a < a + b /* a < b */;
}

int main(){

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num[i];
  }
  sort(num, num + n, comp);
  for(int i = 0; i < n; i++){
    cout << num[i];
  }

  return 0;

}
