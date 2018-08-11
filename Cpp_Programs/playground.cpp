#include <bits/stdc++.h>

using namespace std;

priority_queue<long, vector<long>, greater<long> > q;

int main(){

  q.push(1);
  q.push(2);
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  q.pop();

  return 0;

}
