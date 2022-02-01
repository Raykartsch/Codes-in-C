
/*

Faça um Programa para um caixa eletrônico. O programa deverá perguntar ao usuário a valor do saque e depois informar quantas notas de cada valor serão fornecidas. As notas disponíveis serão as de 1, 5, 10, 50 e 100 reais. 

O valor mínimo é de 10 reais e o máximo de 600 reais. O programa não deve se preocupar com a quantidade de notas existentes na máquina.

Exemplo 1: Para sacar a quantia de 256 reais, o programa fornece duas notas de 100, uma nota de 50, uma nota de 5 e uma nota de 1;

Exemplo 2: Para sacar a quantia de 399 reais, o programa fornece três notas de 100, uma nota de 50, quatro notas de 10, uma nota de 5 e quatro notas de 1 */
#include <stdio.h>
#include <stdlib.h>

#define typeof(var) _Generic( (var), int *: "Pointer")

void sacar_moeda(int money){
    int Vet[6] = {100, 50, 25, 10, 5, 1};
    int count[6] = {0, 0, 0, 0, 0, 0}, *pcount;
    pcount = &count;
    int tam = (sizeof(Vet)/4), res, contador = 0;
    printf("Valor inicial: %d reais\n --- TROCO ---\n", money);
    while (contador <= tam)
    {
        if(money >= Vet[contador])
        {
            res = money / Vet[contador];
            money = money % Vet[contador];    
            pcount[contador] += res;
        }
        else
        {
            contador += 1;
        }
    }

    for(int i=0; i<6; i++){
        printf("%d notas de %d reais\n", pcount[i], Vet[i]);
    }   
}

int main(){
    sacar_moeda(248); 
}