#include <cstdio>

using namespace std;

int main(){

    int i;

    for(i = 1; i <= 7; i++){

        int a, b;
        scanf("%d %d", &a, &b);
        if(a + b > 8){
            printf("%d\n", i);
            return 0;
        }

    }

    printf("0\n");

    return 0;


}
