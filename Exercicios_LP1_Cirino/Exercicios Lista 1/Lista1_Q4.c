#include <stdio.h>
#include <stdlib.h>

int factorial(int num){
    int fatorial = 1;
    for(int i=1; i<=num; i++){
        fatorial *= i;
    }
    return fatorial;
}

int main(){
    int fact = factorial(4);
    printf("%d", fact);
}