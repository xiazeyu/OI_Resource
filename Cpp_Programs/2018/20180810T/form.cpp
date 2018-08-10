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
// ���
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
        // �����½ڵ�����
        cnt++;
        // cout<<"newDepth: "<<cnt<<"(from: "<<cnt - 1<<")"<<endl;
        continue;
      }
      if(tree[i] == ')'){
        long dep = s.top().d;
        bool val = s.top().v;
        s.pop();
        while(s.top().d == dep){ // ͬ������
          if(dep % 2){
            // ���� and
            val = val && s.top().v;
          }else{
            // ż�� or
            val = val || s.top().v;
          }
          s.pop();
        }
        // ������ɴ���
        cnt--;
        s.push(Node(dep - 1, val));
        continue;
      }
      // else ��ջ
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
