#include <stdio.h>
#include <stdlib.h>

int *join_Vector(){
    //Só dá pra usar valor constante em vetores usando o #DEFINE
    #define value 10
    int contador = 0;
    int A[value] = {1, 2, 24, 4, 16, 6, 7, 8, 9, 10};
    int B[value] = {11, 7, 9, 14, 85, 24, 17, 2, 41, 20};
    int C[value] = {21, 65, 31, 35, 25, 26, 14, 7, 29, 30};
    static int X[(value * 3)];
    
    //Junta os valores no vetor X
    for (int i = 0; i < 10; i++){
        X[contador] = A[i];
        X[contador + 10] = B[i];
        X[contador + 20] = C[i];
        contador += 1;
    }
    //Faz a ordenação (vou separar em outra função)
    int tam = (sizeof(X) / 4), aux;
    for (int i = 0; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if (X[j] > X[j + 1]){
                aux = X[j];
                X[j] = X[j + 1];
                X[j + 1] = aux;
            }
        }       
    }
    for(int i = 0; i < 30; i++){
        printf("%d, ", X[i]);
    }
    //Para retornar vetores em C é necessário que coloque "static" na declaração do vetor
    return X;
}
int main(){
    int *vetor;
    vetor = join_Vector();
}