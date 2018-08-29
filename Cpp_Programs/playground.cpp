#include <bits/stdc++.h>

using namespace std;

bool en(long a, long b, long c){
  bool n[10];
  if((b < 100) || (b > 999)) return false;
  if((c < 100) || (c > 999)) return false;
  do{
    n[a % 10] = true;
    a /= 10;


    for(long i = 0; i <= 9; i++)
    cout<<n[i]<<" ";
  cout<<endl;


  }while(a);



  do{
    if(n[b % 10]) return false;
    n[b % 10] = true;
    b /= 10;
  }while(b);

  for(long i = 0; i <= 9; i++)
    cout<<n[i]<<" ";
  cout<<endl;

  do{
    if(n[c % 10]) return false;
    n[c % 10] = true;
    c /= 10;
  }while(c);

  for(long i = 0; i <= 9; i++)
    cout<<n[i]<<" ";
  cout<<endl;

  return true;
}

int main(){

  long a, b, c;
  cin>>a>>b>>c;
  en(a, b, c);

  return 0;

}
