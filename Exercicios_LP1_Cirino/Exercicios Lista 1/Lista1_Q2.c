#include <stdio.h>
#include <stdlib.h>
void prime_number(int number){
    int count = 0;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            count += 1;
            printf("O numero %d nao eh primo!", number);
            break;
        }
    }
     if(count == 0){
         printf("O numero %d eh primo", number);
    }
}   
int main(){
    prime_number(23);
}
