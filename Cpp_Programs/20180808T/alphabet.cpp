#include <bits/stdc++.h>

using namespace std;

long t, n, u, v;
vector<char> c;
vector<vector <long> > Edge;

string s, path;

int main(){

  freopen("alphabet.in", "r", stdin);
  freopen("alphabet.out", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n;
    c.resize(n + 1);
    Edge.resize(n);
    for(long i = 1; i <= n - 1; i++){
      cin>>u>>v;
      if(u != v){
        Edge[u].push_back(v);
        Edge[v].push_back(u);
      }
    }
    for(long i = 1; i <= n - 1; i++){
      c[i] = getchar();
    }
    cin>>s;
    // Floyd��¼·��?
    // ö�����
    // Ѱ��pos
    // Ϳɫ
    // �ɳ�
  }

  fclose(stdin);
  fclose(stdout);
  return 0;

}
