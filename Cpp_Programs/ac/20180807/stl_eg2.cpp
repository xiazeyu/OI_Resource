#include <bits/stdc++.h>

using namespace std;

struct Student{
  string name;
  long score;
  Student(string n, long s){
    name = n;
    score = s;
  }
  operator< (const Student &b) const {
    if(score == b.score){
      return name < b.name;
    }else{
      return score > b.score;
    }
  }
};

long n, tn;
vector<Student> p;
string ts;

int main(){

  cin>>n;
  for(long i = 0; i < n; i++){
    cin>>ts>>tn;
    p.push_back(Student(ts, tn));
  }
  sort(p.begin(), p.begin() + n);
  for(long i = 0; i < n; i++){
    cout<<p[i].name<<" "<<p[i].score<<endl;
  }

  return 0;

}
