// P1644 跳马问题
// https://www.luogu.org/problemnew/show/P1644

// Status: WA

// DFS + 手工栈

// 第一次遇到它的时候要做的操作
// 枚举子树的时候要做的操作
// 子树回溯之前要做的操作
// 当前节点全部枚举完以后要做的操作

// Problem: 手工开栈这样写法是否正确?
// 注: 手工开栈有点仅为栈空间大, 无法利用寄存器的高效率

#include <bits/stdc++.h>

using namespace std;

const long cx[] = {0, 1, 2, 1, 2}, cy[] = {0, 2, 1, -2, -1};

struct status{
  long x, y, i;
  status(long xP = 0, long yP = 0, long iP = 0){
    x = xP; y = yP; i = iP;
  }
};

long n, m, cnt = 0;
stack<status> s;

void dfs(){
  status t;
  while(!s.empty()){
    t = s.top();
    // cout<<"top: "<<t.x<<" "<<t.y<<" "<<t.i<<endl;
    // 当前位于 x, y, 将要进行第 i 次操作, 正数i表示初次访问, 负数i表示被回溯
    if((t.x == n) && (t.y == m)){
    // 走到终点, 计数, 回溯
      cnt++; s.pop(); continue;
      // cout<<"ANS"<<endl;
    }
    // 初次访问, 往下继续查找
    if(t.i > 0){
      s.top().i *= -1; // 标记表示被访问过
      long nx = cx[t.i] + t.x, ny = cy[t.i] + t.y;
      // cout<<"try: ("<<nx<<","<<ny<<")"<<endl;
      if((nx >= 0) && (ny >= 0) && (nx <= n) && (ny <= m)){
        // cout<<"succeed"<<endl;
        s.push(status(nx, ny, 1));
      }
      continue; // 别忘了!!!!!
    }
    // 被回溯(子树是否被枚举完)
    // if(t.i < 0){
    long nextI = -t.i + 1;
    if(nextI > 4){ // 子树枚举完, 回溯
      s.pop();
    }else{// 下一棵子树
      s.top().i = nextI; // 推入新状态
    }
  }

}

int main(){

  scanf("%ld%ld", &n, &m);
  s.push(status(0, 0, 1));
  dfs();

  printf("%ld", cnt);

  return 0;

}
