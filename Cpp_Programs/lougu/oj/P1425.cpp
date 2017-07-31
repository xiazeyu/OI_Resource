#include <cstdio>

using namespace std;

int main(){
    
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    b = b + a * 60;
    d = d + c * 60;
    d = d - b;
    printf("%d %d", d / 60, d % 60);
    
    return 0;
    
}