/*
有1元，5元，10元，50元，100元，500元6种硬币，每种硬币数量不限。现在要用这些硬币来支付A元，最少需要多少枚硬币？

【输入格式】一行，一个整数A，0<=A<=109
【输出格式】一行一个整数：

样例输入：  样例输出：
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
