  #include <bits/stdc++.h> // broken

  using namespace std;

  struct fangzi{
    long Begin;long End;long tree;
    bool operator< (const fangzi &b)const{
      if( End == b.End ){
        return Begin < b.Begin;
      }else{
        return End < b.End;
      };
    };
  };

  long n, h;
  fangzi q[512];
  bool stat[30008] = {0};

  long searchTree(long a, long b){
    long cnt = 0;
    for(int i = a; i <= b; i++){
      if(stat[i]) cnt++;
    }
    return cnt;
  }

  void plantTree(long from, long num){
    for(int i = 0; i < num; i++){
      stat[from - i] = true;
    }
    return;
  }

  int main(){

    int lastEnd;

    scanf("%ld %ld", &n, &h);
    for(int i = 0; i < h; i++){
      scanf("%ld %ld %ld", &q[i].Begin, &q[i].End, &q[i].tree);
    }
    sort(q, q + h);
    lastEnd = q[0].End;

    for(int i = 0; i < h; i++){
      long treeToPlant = q[i].tree - searchTree(q[i].Begin, lastEnd);
      lastEnd = q[i].End;
      plantTree(q[i].End, treeToPlant);
    }

    printf("%ld", searchTree(0, n));

    return 0;
  }
