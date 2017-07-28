#include <cstdio>

using namespace std;

int main(){
    
    int k, n = 0;
    double sum = 0.0f;
    
    scanf("%d", &k);
    
    while(sum <= (double)k){ // "equal is necessary."
        n++;
        sum += 1 / (double)n;
        // printf("- %lf\n", sum);
    }
    
    printf("%d\n", n);
    
    return 0;
    
}