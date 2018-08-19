#include <bits/stdc++.h>

using namespace std;

struct section{
  long Begin, End;
  section(long sBegin = 0, long sEnd = 0){
    Begin = sBegin; End = sEnd;
  }
  bool operator< (const section &b) const{
    if(Begin == b.Begin){
      return End < b.End;
    }
    return Begin < b.Begin;
  }
};

long n, p, h, l, r, ans = -1;
section s[300000];

int main(){
  // ����:
  // ����ÿ��������, ���Խ��߶�������ӳ��, ������������˵�Ϊ [������, ��ص�]
  // ����ÿ������: ֻҪ�ܱ�һ����Ծ����, ���ɳɹ�
  // ����ÿ����Ծ: ��Ծ�����߶�Ϊ (��ص�-������ - 1) / 2
  // ����ÿ����Ծ, ������������Ծ�����غ�
  // Ҫ��:
  // ʹ�������Ծ���, ������Ծȫ����������

  freopen("dinosaur.in", "r", stdin);
  freopen("dinosaur.out", "w", stdout);

  scanf("%ld", &n);
  for(long i = 0; i < n; i++){
    scanf("%ld%ld", &p, &h);
    if(p < h){
      printf("-1\n");
      return 0;
    }
    s[i] = section(p - h, p + h);
  }
  sort(s, s + n);
  l = s[0].Begin; r = s[0].End;
  for(long i = 0; i < n; i++){
    if((s[i].Begin <= r - 1) && (s[i].End > r)){
      r = s[i].End;
    }else if (s[i].Begin > r - 1){
      ans = max(ans, r - l);
      // printf("newLength=%ld(%ld, %ld)[%ld]\n", ans, l, r, r - l);
      l = s[i].Begin;
      r = s[i].End;
    }
  }
  ans = max(ans, r - l);
  // printf("newLength=%ld(%ld, %ld)[%ld]\n", ans, l, r, r - l);
  if(ans % 2){
    printf("%ld.5\n", ans / 2);
  }else{
    printf("%ld.0\n", ans / 2);
  }

  return 0;
}
