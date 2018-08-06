#include <bits/stdc++.h>

using namespace std;

struct Node{
  long no, weight;
  Node(long iN, long iW){
    no = iN;
    weight = iW;
  }
  operator< (const Node &b) const {
    if(weight == b.weight){
      return no < b.no;
    }
    return weight < b.weight;
  }
};

long n;
vector<Node> a;

int main(){

  while(scanf("%ld", &n) != EOF){
    a.push_back(Node(a.size() + 1, n));
    sort(a.begin(), a.begin() + a.size());
    printf("\nno:\t");
    for(long i = 0; i < a.size(); i++){
      printf("%ld\t", a[i].no);
    }
    printf("%\nweight:\t");
    for(long i = 0; i < a.size(); i++){
      printf("%ld\t", a[i].weight);
    }
    printf("\n");
  }

  return 0;

}
