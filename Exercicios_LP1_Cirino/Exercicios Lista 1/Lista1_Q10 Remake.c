#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 10)Escrever um programa em C que calcule a frequência de uso de cada palavra dentro de uma cadeia de
caracteres que possui diversas palavras. Considerar o tamanho máximo da cadeia como sendo de 80
colunas */
void countWords(){
    #define TAM 20
    char *frase;
    frase = (char * )malloc(80);
    frase = "There are many variations of passages of Lorem Ipsum available";
    char Vetor[50];
    for(int i = 0; i < 50; i++){
        Vetor[i] = '\0';
    }
    typedef struct {
        char nome[20];
        int qtd;
    } Contador;
    Contador word_report[TAM];
    int cont = 0, res = 0, limit = 0, not_duplicated = 0;
    int controller = 0;
    do{
        for(int j = 0; frase[controller] != ' '; j++){
            Vetor[j] = frase[controller];
            controller += 1;
        }
        
        for(int i = 0; i < TAM; i++){
            res = strcmp(word_report[i].nome, Vetor);
            if(res == 0){
                word_report[i].qtd += 1;
                not_duplicated = 1;
                break;
            }
        }
        if(not_duplicated == 0){
            strcpy(word_report[limit].nome, Vetor);
            word_report[limit].qtd = 1;
            limit += 1;
        }
        not_duplicated = 0;
        controller += 1; 
        memset(Vetor, '\0', sizeof(Vetor));
        }  while(controller < strlen(frase));
    
    for(int i = 0; i < limit; i++){
        printf("\n%s", word_report[i].nome); 
        printf(" - %d", word_report[i].qtd);   
    }      
}
int main(){
   countWords();
}
