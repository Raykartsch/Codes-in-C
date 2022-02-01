#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Escrever um programa em C que calcule e imprima o numero de caracteres distintos presentes 
em uma cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas.
*/

//Funcionando apenas com letras, fazer funcionar com numeros também
//Tirar espaços em branco
void count_caracteres(char frase[]){
    #define tam 80
    char letters[tam];
    int count_letters[tam], cont = 0, delimiter = 0, contabilizer = 0;
    char *p = &frase;
    //< Separando e colocando os caracteres distintos em um vetor.
    for(int i = 0; i < strlen(frase); i++){
        int duplicated = 0;
        
        if(frase[i] == " "){
            continue;
        }

        else{
            for (int j = 0; j < strlen(frase) - 1; j++){
                if(frase[i] == letters[j]){
                    duplicated = 1;
                }
            }
            if(duplicated == 0){
                letters[cont] = frase[i];
                cont += 1;
            }
        }
       
            
    }  
    // Final>
    //< Variavel para contar e delimitar o print.
    for(int i=0; i<strlen(frase); i++){
        if((isalpha(letters[i]) == 2 || (isalpha(letters[i]) == 1)) && letters[i] != NULL){
            delimiter += 1;
        }
    }
    // Final>

    //<Contando os caracteres e guardando no vetor.
    for(int i=0; i<strlen(frase); i++){
        for(int j=0; j<strlen(frase); j++){
            if (letters[i] == frase[j]){
                contabilizer += 1;
            }
        }
        count_letters[i] = contabilizer;
        contabilizer = 0;
    }
    // Final>
    printf("O numero de caracteres distintos eh %d\n", delimiter);
    for(int i = 0; i < delimiter; i++){
        printf("\nO digito %c aparece %d vezes", letters[i], count_letters[i]);
    }
}
int main(){
    char frase[80] = "arrozfeijao\0";
    count_caracteres(frase);
}