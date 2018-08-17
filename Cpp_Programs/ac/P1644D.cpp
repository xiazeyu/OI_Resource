// P1644 ��������
// https://www.luogu.org/problemnew/show/P1644

// Status: WA

// DFS + �ֹ�ջ

// ��һ����������ʱ��Ҫ���Ĳ���
// ö��������ʱ��Ҫ���Ĳ���
// ��������֮ǰҪ���Ĳ���
// ��ǰ�ڵ�ȫ��ö�����Ժ�Ҫ���Ĳ���

// Problem: �ֹ���ջ����д���Ƿ���ȷ?
// ע: �ֹ���ջ�е��Ϊջ�ռ��, �޷����üĴ����ĸ�Ч��

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
    // ��ǰλ�� x, y, ��Ҫ���е� i �β���, ����i��ʾ���η���, ����i��ʾ������
    if((t.x == n) && (t.y == m)){
    // �ߵ��յ�, ����, ����
      cnt++; s.pop(); continue;
      // cout<<"ANS"<<endl;
    }
    // ���η���, ���¼�������
    if(t.i > 0){
      s.top().i *= -1; // ��Ǳ�ʾ�����ʹ�
      long nx = cx[t.i] + t.x, ny = cy[t.i] + t.y;
      // cout<<"try: ("<<nx<<","<<ny<<")"<<endl;
      if((nx >= 0) && (ny >= 0) && (nx <= n) && (ny <= m)){
        // cout<<"succeed"<<endl;
        s.push(status(nx, ny, 1));
      }
      continue; // ������!!!!!
    }
    // ������(�����Ƿ�ö����)
    // if(t.i < 0){
    long nextI = -t.i + 1;
    if(nextI > 4){ // ����ö����, ����
      s.pop();
    }else{// ��һ������
      s.top().i = nextI; // ������״̬
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
