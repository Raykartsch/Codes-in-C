#include <stdio.h>
#include <stdlib.h>
void divisers(){
    int divisers[3] = {3, 5, 7};
    int rest[3] = {2, 3, 4};
    int limit = 0;
    while (limit < 3){
        for(int i = 0; i < 100; i++){
            float valor = i / divisers[limit];
            printf("\nValor: %f", valor);
            int resto = i % divisers[limit];
            printf("\nResto: %d", resto);
            if((resto == rest[limit]) && (int)valor != 0){
                printf("\nO valor %d satisfaz a condicao imposta!", i);
                break;
            }
        }
        limit += 1;
    } 
}
int main(){
    divisers();
    printf("%f", 3/5);
}