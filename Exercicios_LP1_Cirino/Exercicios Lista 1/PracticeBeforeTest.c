#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <time.h>

#define TAM 16
void somaVetores(int A[], int B[]){
    int *p1 = A;
    int *p2 = B;
    int C[5];
    for(int i = 0; i < 5; i++){
        C[i] = p1[i] + p2[i];
    }

    for(int i = 0; i < 5; i++){
        printf("\n%d + %d = %d", p1[i], p2[i], C[i]);
    }
}


void check_palindrome(char x[]){
    char *p = x;
    int tamanho = strlen(x);
    printf("%d %c %c", tamanho, x[0], x[16]);
    for(int i = 0; i < tamanho / 2; i++){
        printf("\n%c - %c", x[i],  x[tamanho - i - 1]);
        if(x[i] != x[tamanho - i - 1]){
            printf("Nao palindromo");
            return 1;
        }
    }
    printf("Palindromo");
}
int main(){
    int A[5] = {1, 3, 8, 6, 5};
    int B[5] = {3, 5, 9, 24, 7};
    char str[25] = "abasedotetodesaba";
    //somaVetores(A, B);
    check_palindrome(str);
}
