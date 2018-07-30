/*
有1元，5元，10元，50元，100元，500元6种硬币，每种硬币数量不限。现在要用这些硬币来支付A元，最少需要多少枚硬币？

【输入格式】一行，一个整数A，0<=A<=109
【输出格式】一行一个整数：

样例输入：  样例输出：
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
