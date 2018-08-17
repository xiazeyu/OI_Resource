#include <bits/stdc++.h>

using namespace std;

string w, out;

int main(){

  freopen("suffix.in", "r", stdin);
  freopen("suffix.out", "w", stdout);

  cin>>w;
  long S = w.size();
  if((S >= 3) && (w[S - 2] == 'e') && (w[S - 1] == 'r')){
    for(long i = 0; i < S - 2; i++){
      out += w[i];
    }
    cout<<out<<endl;
    // er
  } else if((S >= 3) && (w[S - 2] == 'l') && (w[S - 1] == 'y')){
    // ly
    for(long i = 0; i < S - 2; i++){
      out += w[i];
    }
    cout<<out<<endl;
  } else if((S >= 4) && (w[S - 3] == 'i') && (w[S - 2] == 'n') && (w[S - 1] == 'g')){
    // ing
    for(long i = 0; i < S - 3; i++){
      out += w[i];
    }
    cout<<out<<endl;
  } else {
    cout<<w<<endl;
  }

  fclose(stdin);
  fclose(stdout);
  return 0;

}
