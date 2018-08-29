// P1308 统计单词数
// https://www.luogu.org/problemnew/show/P1308

// Status: AC

// Problem:

#include <bits/stdc++.h>

using namespace std;

struct w{
  long pos;
  string d;
  w(long _pos = 0, string _d = ""){
    pos = _pos; d = _d;
  }
};

string word, article, t;
vector<w> f;
long cnt = 0, pos;

int main(){

  getline(cin, word);
  getline(cin, article);
  article += ' ';
  for(unsigned long i = 0; i < word.size(); i++){
    if((word[i] <= 'Z') && (word[i] >= 'A'))
      word[i] = word[i] - 'A' + 'a';
  }
  for(unsigned long i = 0; i < article.size(); i++){
    if((article[i] <= 'Z') && (article[i] >= 'A'))
      article[i] = article[i] - 'A' + 'a';
  }
  // cout<<":"<<word<<":"<<endl;
  // cout<<":"<<article<<":"<<endl;
/*
u
tIXHUguyz PZYAJL BIv NAPoemaJ aTF LOvhV m s LSa n xDn mQnO T ettIq T AL fG B Xme t fct U tQ d
*/
  for(unsigned long i = 0; i < article.size(); i++){
    if(article[i] == ' '){
      // cout<<"pushBack:"<<t<<":"<<i - t.size()<<":"<<endl;
      f.push_back(w(i - t.size(), t));
      t.clear();
    }else{
      t += article[i];
    }
  }
  for(unsigned long i = 0; i < f.size(); i++){
    if(word == f[i].d){
      if(!cnt){
        pos = f[i].pos;
      }
      cnt++;
    }
  }
  if(cnt){
    cout<<cnt<<" "<<pos<<endl;
  }else{
    cout<<-1<<endl;
  }

  return 0;

}
