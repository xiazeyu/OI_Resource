// P2730 Ä§°å Magic Squares
// https://www.luogu.org/problemnew/show/P2730

// Status: AC

// WARN: ÉóÌâ: ÄÄ¸ö×´Ì¬×ªÒÆµ½ÄÄ¸ö×´Ì¬ (#22)

#include <bits/stdc++.h>

using namespace std;

const string c[] = {"A", "B", "C"};

struct Node{
  string o;
  long s;
  Node(long status = 0, string operation = ""){
    o = operation;
    s = status;
  }
};

long t, n;
string ans;
queue<Node> q;
vector<long> Hash[2333];

long oper(long sta, long no){
  long d1 = sta / 10000000,
  d2 = (sta % 10000000) / 1000000,
  d3 = (sta % 1000000) / 100000,
  d4 = (sta % 100000) / 10000,
  d5 = (sta % 10000) / 1000,
  d6 = (sta % 1000) / 100,
  d7 = (sta % 100) / 10,
  d8 = sta % 10;
  if(no == 0)
    return d8 * 10000000 + d7 * 1000000 + d6 * 100000 + d5 * 10000 + d4 * 1000 + d3 * 100 + d2 * 10 + d1;
  if(no == 1)
    return d4 * 10000000 + d1 * 1000000 + d2 * 100000 + d3 * 10000 + d6 * 1000 + d7 * 100 + d8 * 10 + d5;
  if(no == 2)
    return d1 * 10000000 + d7 * 1000000 + d2 * 100000 + d4 * 10000 + d5 * 1000 + d3 * 100 + d6 * 10 + d8;
  return -1;
}

bool inHash(long n){
  long d = n % 2321;
  if(Hash[d].empty()) return false;
  bool flag = false;
  for(long i = 0; i < Hash[d].size(); i++){
    if(Hash[d][i] == n){
      flag = true; break;
    }
  }
  return flag;
}

void putHash(long n){
  long d = n % 2321;
  if(inHash(n)) return;
  Hash[d].push_back(n);
  return;
}

void bfs(){
  Node t;
  while(1){
    if(q.front().s == n){
      ans = q.front().o;
      return;
    }
    if(inHash(q.front().s)){
      q.pop();
      continue;
    }
    for(int i = 0; i <= 2; i++){
      long newS = oper(q.front().s, i);
      q.push(Node(newS, q.front().o + c[i]));
    }
    putHash(q.front().s);
    q.pop();
  }
}

int main(){

  for(long i = 7; i > 0; i--){
    cin>>t;
    for(long j = 1; j <= i; j++)
      t *= 10;
    n += t;
  }
  cin>>t;
  n += t;
/*
  while(1){
  long g;cin>>g; n = oper(n, g);
  cout<<n<<endl;
  }
*/
  q.push(Node(12345678, ""));
  bfs();

  // ans = "1111111111111111111111111111111111111111111111111111111111111111";
  printf("%ld\n", ans.size());
  if(ans.size() > 60){
    for(long i = 0; i < ans.size(); i++){
      if((!(i % 60)) && (i != 0)) cout<<endl;
      cout<<ans[i];
    }
  }else{
    cout<<ans<<endl;
  }

  return 0;

}
