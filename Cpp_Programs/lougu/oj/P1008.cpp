#include <cstdio>
#include <iostream>

using namespace std;

bool check(int a, int b, int c){
     if((a > 999) || (b > 999) || (c > 999)) return false;
     
     int i;
     int t[10] = {0};
     
     t[a % 10] = 1;
     t[(a % 100) / 10] = 1;
     t[a / 100] = 1;
     t[b % 10] = 1;
     t[(b % 100) / 10] = 1;
     t[b / 100] = 1;    
     t[c % 10] = 1;
     t[(c % 100) / 10] = 1;
     t[c / 100] = 1;
     
     for(i = 1; i <= 9; i++){
         if(t[i] == 0) return false;
     }
     
     return true;
     
}

int main(){

    int a, b, c;
    
    for(a = 100; a <= 999; a++){
        
        b = a * 2;
        c = a * 3;
        if(check(a, b, c)) printf("%d %d %d\n", a, b, c);
        
    }
    
    return 0;
}