// P1432 µπÀÆŒ Ã‚
// https://www.luogu.org/problemnew/show/P1432

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

struct status{
  long a, b, n;
  string pre;
  status(long ca = 0, long cb = 0, long remain = 0, string gpre = ""){
    a = ca; b = cb; n = remain; pre = gpre;
  }
  bool operator== (const status &i) const{
    if((a == i.a) && (b == i.b) && (n == i.n)){
      return true;
    }return false;
  }
};

struct lowstatus{
  long a, b, n;
  lowstatus(long ca = 0, long cb = 0, long remain = 0){
    a = ca; b = cb; n = remain;
  }
  bool operator== (const lowstatus &i) const{
    if((a == i.a) && (b == i.b) && (n == i.n)){
      return true;
    }return false;
  }
};

long t, a, b, n;
queue<status> q;
vector<lowstatus> s;
status fail;

bool inSet(status a){
  lowstatus t = lowstatus(a.a, a.b, a.n);
  for(long i = 0; i < s.size(); i++){
    if(t == s[i]) return true;
  }
  return false;
}
void putSet(status a){
  s.push_back(lowstatus(a.a, a.b, a.n));
  return;
}

status oper(status s, long i){
  if(i == 1){
    if((s.a < a) && (s.n > 0)){
      long w = min(a - s.a, s.n);
      s.n -= w;
      s.a += w;
      return s;
    }else{
      return fail;
    }
  }else if(i == 2){
    if((s.b < b) && (s.n > 0)){
      long w = min(b - s.b, s.n);
      s.n -= w;
      s.b += w;
      return s;
    }else{
      return fail;
    }
  }else if(i == 3){

  }
}

void bfs(){
  while(1){
    if(q.front().b == n){
      return;
    }
    if(inSet(q.front())){
      q.pop();
      continue;
    }
    for(long i = 1; i <= 6; i++){
      status newS = oper(q.front(), i);
      if(!(newS == fail)) q.push(newS);
    }
    putSet(q.front());
    q.pop();
  }
  return;
}

int main(){
  fail.a = -1; fail.b = -2; fail.n = -3;
  cin>>t;
  for(long i = 1; i <= t; i++){
    cin>>a>>b>>n;
    while(q.size()) q.pop();
    q.push(status(a, b, n));
    bfs();
    cout<<q.front().pre.size()<<" "<<q.front().pre<<endl;
  }

  return 0;

}
