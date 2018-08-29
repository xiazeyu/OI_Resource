// P1553 数字反转（升级版）
// https://www.luogu.org/problemnew/show/P1553

// Status: AC

// WARN: 分数反转要去前导0和后导0 (#29)

#include <bits/stdc++.h>

using namespace std;

string t, t1, o1, o2;
long type = 0;
// 0: 整数, 1: 小数, 2: 分数, 3: 百分数

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
  if(type == 0){ // 整数
    for(long i = t.size() - 1; i >= 0; i--){
      o1 += t[i];
    }
    while(o1[0] == '0'){
      o1 = o1.substr(1);
    }
    if(!o1.length()) o1 = '0' + o1;
    cout<<o1<<endl;
  }else if(type == 1){ // 小数
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
  }else if(type == 2){ // 分数
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
    while(o2[0] == '0'){ // 分数反转要去前导0和后导0
      o2 = o2.substr(1);
    }
    while(o2[o2.length() - 1] == '0'){
      o2 = o2.substr(0, o2.length() - 1);
    }
    cout<<o1<<"/"<<o2<<endl;
  }else if(type == 3){ // 百分数
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
