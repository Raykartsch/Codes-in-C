#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countWords(char frase[], char cmp_str[]){
    //Sempre que for preenchida um vetor de char, coloca o valor como N + 1 pois tem sobrar espaço para o '\0' no final de uma string
    //Arrumar espaço em branco!
    int rep_word = 0;
    int tam_comparator = strlen(cmp_str);
    char sentence[4];
    char *sent;
    sent = &sentence;

    printf("\n%d - %d - %d", strlen(frase), strlen(sentence), strlen(cmp_str));
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
    char string[80];
    gets(&string);
    printf("%s", string);
    countWords("abcdefghijklmnopqrstuv", string);
}