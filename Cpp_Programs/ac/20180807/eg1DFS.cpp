/*
��1Ԫ��5Ԫ��10Ԫ��50Ԫ��100Ԫ��500Ԫ6��Ӳ�ң�ÿ��Ӳ���������ޡ�����Ҫ����ЩӲ����֧��AԪ��������Ҫ����öӲ�ң�

�������ʽ��һ�У�һ������A��0<=A<=109
�������ʽ��һ��һ��������

�������룺  ���������
620         4
*/

#include <cstdio>
#include <algorithm>

using namespace std;

long int a, ans = 0x7fffffff;
const int moneyType[] = {500, 100, 50, 10, 5, 1};

void dfs(long int remainMoney, long int coinsUsed){
  if(remainMoney == 0){
    ans = min(ans, coinsUsed);
    return;
  }
  for(int i = 0; i < (sizeof(moneyType) / sizeof(moneyType[0])); i++){
    if(remainMoney >= moneyType[i]){
      dfs(remainMoney % moneyType[i], coinsUsed + remainMoney / moneyType[i]);
    }
  }
}

int main(){

  scanf("%ld", &a);

  dfs(a, 0);

  printf("%ld", ans);

  return 0;

}
