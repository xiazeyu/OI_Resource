// P1308 统计单词数
// https://www.luogu.org/problemnew/show/P1308

// Status:

// Problem:

#include <bits/stdc++.h>

using namespace std;

string word, article;

int main(){

  cin>>word;
  word += ' ';
  cin>>noskipws>>article;
  for(long i = 0; i < word.size(); i++){
    word[i] = tolower(word[i]);
  }
  for(long i = 0; i < article.size(); i++){
    article[i] = tolower(article[i]);
  }
  word = ' ' + word + ' ';
  article = ' ' + article + ' ';
  if(article.find(word) == string::npos){
    cout<<-1<<endl;
  }else{
    long cnt = 0, f = article.find(word), t = article.find(word);
    while(t != string::npos){
      cnt++;
      t = article.find(word, t + 1);
    }
    cout<<cnt<<' '<<f<<endl;
  }

  return 0;

}
