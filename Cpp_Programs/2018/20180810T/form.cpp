#include <bits/stdc++.h>

using namespace std;

struct Node{
  long d, v;
  Node(long dep = 0, long value = false){
    d = dep; v = value;
  }
};

string tree;
long cnt, no = 0;
// 深度
stack<Node, vector<Node> > s;

bool r(char a){
  if(a == 'T') return true;
  return false;
}

int main(){
  freopen("form.in", "r", stdin);
  freopen("form.out",  "w", stdout);

  while(cin>>tree){
    if(tree == "()") break;
    no++;
    while(s.size()) s.pop();
    s.push(Node(-1, 0));
    cnt = 0;

    for(long i = 0; i < tree.size(); i++){
      if(tree[i] == '('){
        // 增加新节点的深度
        cnt++;
        // cout<<"newDepth: "<<cnt<<"(from: "<<cnt - 1<<")"<<endl;
        continue;
      }
      if(tree[i] == ')'){
        long dep = s.top().d;
        bool val = s.top().v;
        s.pop();
        while(s.top().d == dep){ // 同层运算
          if(dep % 2){
            // 奇数 and
            val = val && s.top().v;
          }else{
            // 偶数 or
            val = val || s.top().v;
          }
          s.pop();
        }
        // 运算完成传回
        cnt--;
        s.push(Node(dep - 1, val));
        continue;
      }
      // else 入栈
      s.push(Node(cnt, r(tree[i])));
      // cout<<"pushNode: "<<cnt<<" "<<r(tree[i])<<endl;
    }
    if(s.top().v){
      cout<<no<<". "<<"true"<<endl;
    }else{
      cout<<no<<". "<<"false"<<endl;
    }
  }

  fclose(stdin);
  fclose(stdout);
  return 0;

}
