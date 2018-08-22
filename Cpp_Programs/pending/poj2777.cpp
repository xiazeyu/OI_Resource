// Poj 2777 Count Color
// http://poj.org/problem?id=2777

// Status: AC

// WARN: �߶���: ��ֵ(add()::���Ӽ�, pushDown())��, lazy Ϊ���µĸ�ֵ��������, data ��lazy Ӧ�Զ�Ҷ�ӽڵ�Ĳ���Ϊ׼ (#27)
// WARN: bitset: �Ƿ���ֱ��ʹ��count()? �Ƿ��ѳ�����Χ��ǰ��0һ���¼? (#28)
// WARN: �������, ����2�˵�, ��һ������a<=b, �ֶ����� (#13)

#include <iostream>
#include <bitset>

using namespace std;

struct Node{
  bitset<32> color, lazy;
};

long n, t, o, a, b, c;
char _o;
Node tr[400008];

void pushDown(long rt, long l, long r){
  if((tr[rt].lazy.none()) || (l == r)) return;
  tr[rt<<1].color = tr[rt].lazy;
  tr[rt<<1].lazy = tr[rt].lazy;
  tr[rt<<1|1].color = tr[rt].lazy;
  tr[rt<<1|1].lazy = tr[rt].lazy;
  tr[rt].lazy.reset();
  return;
}

void add(long rt, long l, long r, long s, long e, long color){
  if((s <= l) && (r <= e)){
    tr[rt].lazy = 1<<color; // lazy��Ǳ���Ϊ����һ�εĲ���
    tr[rt].color = 1<<color; // ���丳ֵ�Ľ����������Ӽ�ȫ����Ϊ������ֵ
    return;
  }
  long mid = (l + r)>>1;
  pushDown(rt, l, r);
  if(s <= mid) add(rt<<1, l, mid, s, e, color);
  if(mid + 1 <= e) add(rt<<1|1, mid + 1, r, s, e, color);
  // pushUp, ������
  tr[rt].color.reset();
  tr[rt].color |= tr[rt<<1].color;
  tr[rt].color |= tr[rt<<1|1].color;
  return;
}

bitset<32> query(long rt, long l, long r, long s, long e){
  if((s <= l) && (r <= e)) return tr[rt].color;
  long mid = (l + r)>>1;
  bitset<32> ans;
  pushDown(rt, l, r);
  if(s <= mid) ans |= query(rt<<1, l, mid, s, e);
  if(mid + 1 <= e) ans |= query(rt<<1|1, mid + 1, r, s, e);
  return ans;
}

int main(){

  // scanf("%ld%ld%ld", &n, &t, &o);
  cin>>n>>t>>o;
  for(long i = 0; i <= 4 * n + 1; i++){
    tr[i].color.set(0);
  }
  // l: ����
  // t: ��ɫ����
  // o: ������
  for(long i = 1; i <= o; i++){
    cin>>_o;
    if(_o == 'C'){
      cin>>a>>b>>c;
      if(a > b){
        long t = a; a = b; b = t;
      }
      add(1, 1, n, a, b, c - 1);
    }else{
      cin>>a>>b;
      if(a > b){
        long t = a; a = b; b = t;
      }
      cout<<query(1, 1, n, a, b).count()<<endl;
    }
  }

  return 0;

}
