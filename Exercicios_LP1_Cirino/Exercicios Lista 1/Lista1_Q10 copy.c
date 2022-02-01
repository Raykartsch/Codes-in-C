#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char frase[80], char cmp_str[80]){
    //Sempre que for preenchida um vetor de char, coloca o valor como N + 1 pois tem sobrar espaço para o '\0' no final de uma string
    //Arrumar espaço em branco!
    printf("\nDENTRO DA FUNCAO!!!!!!\n");
    int rep_word = 0;
    int tam_comparator = strlen(cmp_str);
    #define tam_h tam_comparator
    printf("Tamanho comparador: %d", tam_h);
    char sentence[tam_h], *sent;
    sent = &sentence;
    

    printf("\nTamanho da frase: %d \nTamanho da sentenca para comparar: %d \nTamanho da palavra que o usuario esta buscando: %d", strlen(frase), strlen(sentence), strlen(cmp_str));
    for(int i=0; i < (strlen(frase) - strlen(cmp_str) + 1); i++){
        for(int j=0; j < strlen(sentence); j++){
            sent[j] = frase[i + j];
        }
        printf("\n%s - %d", sentence, strlen(sentence));      
        if(strcmp(sentence, cmp_str) == 0){
            rep_word += 1;
        } 
    }
    printf("\nA sentenca %s foi encontrada %d na string solicitada.", cmp_str, rep_word);
}
int main(){
    char cmp_str[80];
    gets(&cmp_str);
    int tam = strlen(cmp_str);
    printf("Tamanho string: %d\n", strlen(cmp_str));
    countWords("abcdefghijklmnopqrstuv", cmp_str);
}