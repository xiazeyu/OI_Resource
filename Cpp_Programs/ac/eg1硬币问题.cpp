/*
��1Ԫ��5Ԫ��10Ԫ��50Ԫ��100Ԫ��500Ԫ6��Ӳ�ң�ÿ��Ӳ���������ޡ�����Ҫ����ЩӲ����֧��AԪ��������Ҫ����öӲ�ң�

�������ʽ��һ�У�һ������A��0<=A<=109
�������ʽ��һ��һ��������

�������룺  ���������
620         4
*/

#include <cstdio>

using namespace std;

int main(){

  long int a, i = 0, cnt = 0;
  const int moneyType[] = {500, 100, 50, 10, 5, 1};

  scanf("%ld", &a);

  while(a > 0){
    cnt += a / moneyType[i];
    a %= moneyType[i];
    i++;
  }

  printf("%ld", cnt);

  return 0;

}
