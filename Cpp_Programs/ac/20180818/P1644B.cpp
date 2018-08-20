// P1644 跳马问题
// https://www.luogu.org/problemnew/show/P1644

// Status: ACx2, TLEx3

// BFS

// Problem: 这种题目BFS能做吗? 如何优化?

#include <bits/stdc++.h>

using namespace std;

const long cx[] = {1, 2, 1, 2}, cy[] = {2, 1, -2, -1};

struct status{
  long x, y;
  status(long xP = 0, long yP = 0){
    x = xP; y = yP;
  }
};

long n, m, cnt = 0;
queue<status> q;

void bfs(){
  status t;
  long nx, ny;
  while(!q.empty()){
    t = q.front();// cout<<"pop: "<<t.x<<" "<<t.y<<endl;
    q.pop();
    if((t.x == m) && (t.y == n)){
      cnt++;
      continue;
    }
    for(long i = 0; i <= 3; i++){
      nx = t.x + cx[i];
      ny = t.y + cy[i];
      if((nx >= 0) && (nx <= m) && (ny >= 0) && (ny <= n)){
        q.push(status(nx, ny));
      }
    }
  }
}

int main(){

  scanf("%ld%ld", &n, &m);
  q.push(status(0, 0));
  bfs();

  printf("%ld", cnt);

  return 0;

}
