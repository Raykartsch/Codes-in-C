#include <stdio.h>
#include <stdlib.h>
void biggest_two_numbers(){
    int Vetor[50], *pVetor, aux, tam = sizeof(Vetor)/4;
    pVetor = &Vetor;
    srand(time(NULL));
    for(int i=0; i < tam; i++){
        pVetor[i] = rand()%(100 - 1)+1;
    }
    for(int i=0; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if (pVetor[j] > pVetor[j + 1]){
                aux = pVetor[j];
                pVetor[j] = pVetor[j + 1];
                pVetor[j + 1] = aux;
            }
        }
    }
    for(int i=0; i < tam; i++){
        printf("%d, ", Vetor[i]);
    }
    printf("\nTOP 1: %d - TOP 2: %d", Vetor[49], Vetor[48]);
}
int main(){
    biggest_two_numbers();
}