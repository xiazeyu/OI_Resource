#include <cstdio>

using namespace std;

int main(){
    
    int a;
    scanf("%d", &a);
    
    if(a<=150){
        printf("%.1f", a * 0.4463);
        return 0;
    }
    if(a <=401){
        printf("%.1f", 150 * 0.4463 + (a - 150) * 0.4663);
        return 0;
    }
    
    printf("%.1f", 150 * 0.4463 + (400 - 150) * 0.4663 + (a - 400) * 0.5663);
    return 0;
    
}