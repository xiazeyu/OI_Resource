#include <bits/stdc++.h>

using namespace std;

struct Node{
  long d;
  bool v;
  Node(long dep = 0, long value = false){
    d = dep; v = value;
  }
};

char t, pt;
long cnt, no = 0;
// ���
stack<Node, vector<Node> > s;

bool r(char a){
  return (a == 'T');
}

int main(){
  while(1){
    no++;
    while(s.size()) s.pop();
    s.push(Node(-1, 0));
    cnt = 0;
    pt = 0;
    t = 0;
    while(t != '\n'){
      pt = t;
      t = getchar();
      if((pt == '(') && (t == ')')) return 0;
      if(t == '('){
        // �����½ڵ�����
        cnt++;
        // cout<<"newDepth: "<<cnt<<"(from: "<<cnt - 1<<")"<<endl;
        continue;
      }
      if(t == ')'){
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
      if((t == 'T') || (t == 'F')) // check here is necessary
        s.push(Node(cnt, r(t)));
      // cout<<"pushNode: "<<cnt<<" "<<r(t)<<endl;
    }
    if(s.top().v){
      cout<<no<<". "<<"true"<<endl;
    }else{
      cout<<no<<". "<<"false"<<endl;
    }
  }

  return 0;

}
