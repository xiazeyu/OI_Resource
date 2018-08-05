#include <bits/stdc++.h>

using namespace std;

struct quest{
  long order, x, y;
  quest(long a, long b, long c){
    order = a;
    x = b;
    y = c;
  }
  operator< (const quest &b) const {
    if(x == b.x){
      return y < b.y;
    }
    return x < b.x;
  }
};

long n, q, tx, ty, nowT = 0;
vector<long long> a, ans, appendV, fina;
vector<quest> qu;

int main(){

  // ��������
  scanf("%ld", &n);
  a.resize(n + 4);
  fina.resize(n + 4);
  for(long i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
  }
  fina = a;
  scanf("%ld", &q);
  ans.resize(q + 4);
  for(long i = 0; i < q; i++){
    scanf("%ld %ld", &tx, &ty);
    qu.push_back(quest(i, tx, ty));
  }
  // ��x��������
  sort(qu.begin(), qu.begin() + q);
  // ģ��(�Ż�?����?), ������ԭ��order˳�������ans������
  for(long i = 0; i < q; i++){ // iΪq��˳��
    for(; qu[i].x > nowT; nowT++){
      fina = a;
      for(long k = 1; k < n; k++){
        fina[k] %= 998244353;fina[k] += a[k + 1];fina[k] %= 998244353;
      }
      fina[n] %= 998244353;fina[n] += a[1];fina[n] %= 998244353;
      a = fina;
    }
    ans[qu[i].order] = a[qu[i].y];
  }
  // ���ans����
  for(long i = 0; i < q; i++){
    printf("%lld\n", ans[i]);
  }

  return 0;

}
