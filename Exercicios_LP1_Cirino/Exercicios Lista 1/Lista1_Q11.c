#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Escrever um programa em C que calcule e imprima todas as palavras que contenham tres vogais ou mais.
#define MAX 15
void tres_mais_vogal(){
    char palavras[10][MAX] = {"banana", "roteador", "livro", "lanterna", "smartphone", "caderno", "microfone", "seriado", "violino"};
    int index = 0, contador = 0;
    printf("Palavras mais que 3 vogais: ");
    for(int i = 0; i<sizeof(palavras)/MAX; i++){
        for(int j = 0; palavras[i][j] != '\0'; j++){        
            if ((palavras[i][j] == 'a') || (palavras[i][j] == 'e') || (palavras[i][j] == 'i') || (palavras[i][j] == 'o') || (palavras[i][j] == 'u')){
                index += 1;
            }
        }
        if(index >= 3){
            printf("%s, ", palavras[i]);
            contador += 1;
        }
        index = 0;  
    }
    printf("\nNo total %d palavras tem 3 vogais ou mais.", contador);
}

int main(){
    tres_mais_vogal();
}