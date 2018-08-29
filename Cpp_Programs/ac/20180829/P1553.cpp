// P1553 ���ַ�ת�������棩
// https://www.luogu.org/problemnew/show/P1553

// Status: AC

// WARN: ������תҪȥǰ��0�ͺ�0 (#29)

#include <bits/stdc++.h>

using namespace std;

string t, t1, o1, o2;
long type = 0;
// 0: ����, 1: С��, 2: ����, 3: �ٷ���

int main(){

  getline(cin, t);
  for(unsigned long i = 0; i < t.size(); i++){
    if(t[i] == '.'){
      type = 1; break;
    }else if(t[i] == '/'){
      type = 2; break;
    }else if(t[i] == '%'){
      type = 3; break;
    }
  }
  if(type == 0){ // ����
    for(long i = t.size() - 1; i >= 0; i--){
      o1 += t[i];
    }
    while(o1[0] == '0'){
      o1 = o1.substr(1);
    }
    if(!o1.length()) o1 = '0' + o1;
    cout<<o1<<endl;
  }else if(type == 1){ // С��
    long dP = 0;
    while(t[dP] != '.'){
      dP++;
    }
    for(long i = dP - 1; i >= 0; i--){
      o1 += t[i];
    }
    while(o1[0] == '0'){
      o1 = o1.substr(1);
    }
    if(!o1.length()) o1 = '0' + o1;
    for(long i = t.size() - 1; i > dP; i--){
      o2 += t[i];
    }
    while(o2[o2.length() - 1] == '0'){
      o2 = o2.substr(0, o2.length() - 1);
    }
    if(!o2.length()) o2 = '0' + o2;
    cout<<o1<<"."<<o2<<endl;
  }else if(type == 2){ // ����
    long dP = 0;
    while(t[dP] != '/'){
      dP++;
    }
    for(long i = dP - 1; i >= 0; i--){
      o1 += t[i];
    }
    while(o1[0] == '0'){
      o1 = o1.substr(1);
    }
    if(!o1.length()) o1 = '0' + o1;
    for(long i = t.size() - 1; i > dP; i--){
      o2 += t[i];
    }
    while(o2[0] == '0'){ // ������תҪȥǰ��0�ͺ�0
      o2 = o2.substr(1);
    }
    while(o2[o2.length() - 1] == '0'){
      o2 = o2.substr(0, o2.length() - 1);
    }
    cout<<o1<<"/"<<o2<<endl;
  }else if(type == 3){ // �ٷ���
    for(long i = t.size() - 2; i >= 0; i--){
      o1 += t[i];
    }
    while(o1[0] == '0'){
      o1 = o1.substr(1);
    }
    if(!o1.length()) o1 = '0' + o1;
    cout<<o1<<"%"<<endl;
  }

  return 0;

}
