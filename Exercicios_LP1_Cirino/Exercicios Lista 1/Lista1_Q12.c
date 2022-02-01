#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Tenho que arrumar do onze até o dezenove
int lenHelper(int num){
    if (num < 10) return 1;
    else if(num < 100) return 2;
    else if(num < 1000) return 3;
    else if(num < 10000) return 4;
}
int *nthdig(int n, int *k){
    int separated_num[sizeof(*k)], *s, mod;
    s = &separated_num;
    while(n--){
        mod = *k%10;
        s[n] = mod;
        *k/=10;
    }
    return s;
}
void extenseNumber(){
    int number, *num, *separated_value;
    char unidades[10][8] = {" ", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char milhar[10][15] = {" ", "mil", "dois mil", "tres mil", "quatro mil", "cinco mil", "seis mil", "sete mil", "oito mil", "nove mil"};
    char centenas[10][15] = {" ", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char dezenas[10][12] = {" ", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"}; 
    scanf("%d", &number);
    num = &number;
    int length = lenHelper(number);
    separated_value = nthdig(sizeof(num), num);
    // Setar strings para o 11 até 19
    switch(length){
        //Números até unidades
        case 1: printf("%s", unidades[separated_value[3]]);
        // Números até dezenas
        case 2:
            if(separated_value[3] == 0){
                printf("%s", dezenas[separated_value[2]]);
            }
            else if(separated_value[3] == 1 && separated_value[2] == 1){
                printf("Onze");
            }
            else{
                printf("%s e %s", dezenas[separated_value[2]], unidades[separated_value[3]]);
            }
        // Numeros até centenas
        case 3:
            if ((separated_value[1] == 1) && (separated_value[2] == 0) && (separated_value[3] == 0)){
                printf("cem");
            }
            else if((separated_value[2] == 0)){
                printf("%s e %s", centenas[separated_value[1]], unidades[separated_value[3]]);
            }
            else if((separated_value[3] == 0)){
                printf("%s e %s", centenas[separated_value[1]], dezenas[separated_value[2]]);
            }
            else if(separated_value[3] == 1 && separated_value[2] == 1){
                printf("%s e onze", centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 2){
                printf("%s e doze", centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 3){
                printf("%s e treze", centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 4){
                printf("%s e catorze", centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 5){
                printf("%s e quinze", centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 6){
                printf("%s e dezesseis", centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 7){
                printf("%s e dezessete", centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 8){
                printf("%s e dezoito", centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 9){
                printf("%s e dezenove", centenas[separated_value[1]]);
            }
            else{
                printf("%s e %s e %s", centenas[separated_value[1]], dezenas[separated_value[2]], unidades[separated_value[3]]);
            }
        // Números até o milhar
        case 4:        
            if((separated_value[1] == 0) && (separated_value[2] == 0) && (separated_value[3] == 0)){
                printf("%s", milhar[separated_value[0]]);
            }   
            else if((separated_value[1] == 0) && (separated_value[3] == 0)){
                printf("%s e %s", milhar[separated_value[0]], dezenas[separated_value[2]]);
            }
            else if((separated_value[2] == 0)){
                printf("%s %s e %s", milhar[separated_value[0]], centenas[separated_value[1]], unidades[separated_value[3]]);
            }
            else if((separated_value[3] == 0)){
                printf("%s %s e %s", milhar[separated_value[0]], centenas[separated_value[1]], dezenas[separated_value[2]]);
            }
            else if(separated_value[3] == 1 && separated_value[2] == 1){
                printf("%s %s e onze", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 2){
                printf("%s %s e doze", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 3){
                printf("%s %s e treze", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 4){
                printf("%s %s e catorze", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 5){
                printf("%s %s e quinze", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 6){
                printf("%s %s e dezesseis", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
             else if(separated_value[2] == 1 && separated_value[3] == 7){
                printf("%s %s e dezessete", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 8){
                printf("%s %s e dezoito", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
            else if(separated_value[2] == 1 && separated_value[3] == 9){
                printf("%s %s e dezenove", milhar[separated_value[0]], centenas[separated_value[1]]);
            }
            else {
                printf("%s %s e %s e %s", milhar[separated_value[0]], centenas[separated_value[1]], dezenas[separated_value[2]], unidades[separated_value[3]]);
            }          
    } 
}
int main(){
    extenseNumber();
}