#include <cstdio>

using namespace std;

int main(){
    
    int i, saved = 0, remains = 0, t;
    
    for(i = 1; i <= 12; i++){
        
        scanf("%d", &t);
        remains = remains + 300;
        remains -= t;
        
        if(remains < 0){
            printf("-%d\n", i);
            return 0;
        }
        
        if(remains >= 100){
            saved += remains / 100;
            remains = remains % 100;
        }
        
        
    }
    
    printf("%d\n", remains + saved * 120);
    
    return 0;
    
    
}