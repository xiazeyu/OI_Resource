#include<bits/stdc++.h>
using namespace std;

set<long> s;
set<long>::iterator it;
pair<set<long>::iterator, bool> rst;

int main()
{

  s.insert(2);
  s.insert(3);
  s.insert(6);
  s.insert(8);
  s.insert(9);
  s.insert(10);
  cout<<*s.lower_bound(3)<<" "<<*s.lower_bound(4)<<" "<<*s.lower_bound(11)<<endl;
  cout<<*s.upper_bound(3)<<" "<<*s.upper_bound(4)<<" "<<*s.upper_bound(8)<<endl;
  for(it = s.begin(); it != s.end(); it++){
    cout<<*it<<endl;
  }

  return 0;
}
