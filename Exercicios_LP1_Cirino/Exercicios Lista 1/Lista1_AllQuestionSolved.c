#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>
#include <time.h>

/* 
    Na função main (final do arquivo), 
    todas as funções referentes à cada exercício da lista estão com '//' no começo 
    (Ex: //divisers(); ) e antes de um comentário escrito '// FIM'.

*/

//Questão 1
void divisers(){
    int divisers[3] = {3, 5, 7};
    int rest[3] = {2, 3, 4};
    int limit = 0;
    while (limit < 3){
        for(int i = 0; i < 100; i++){
            float valor = i / divisers[limit];
            printf("\nValor: %f", valor);
            int resto = i % divisers[limit];
            printf("\nResto: %d", resto);
            if((resto == rest[limit]) && (int)valor != 0){
                printf("\nO valor %d satisfaz a condicao imposta!", i);
                break;
            }
        }
        limit += 1;
    } 
}
// Questão 2
void prime_number(int number){
    int count = 0;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            count += 1;
            printf("O numero %d nao eh primo!", number);
            break;
        }
    }
     if(count == 0){
         printf("O numero %d eh primo", number);
    }
}   
// Questão 3
int perfect_number(){
    int limit = 1, divisible_num = 0;
    while (limit < 32767){
        for(int i=1; i < limit; i++){
            if(limit % i == 0){
                divisible_num += i;
            }
        }
        if(divisible_num == limit){
            printf("%d, ", divisible_num);
        }
        limit += 1;
        divisible_num = 0;
    }
}
// Questão 4
int factorial(int num){
    int fatorial = 1;
    for(int i=1; i<=num; i++){
        fatorial *= i;
    }
    return fatorial;
}
// Questão 5
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
// Questão 6
 void calculoGasolina(int rounds){
    int distance[rounds], odometro[rounds + 1], tot_gas = 0;
    float gas_used[rounds]; 
    float preco = 0, tot_distance = 0;

    printf("Digite aqui o odometro ANTES de iniciar sua viagem: ");
    scanf("%d", &odometro[0]);
    for(int i=1; i<=rounds; i++){
        printf("--- %d POSTO --- \n Digite aqui a ocorrencia do odometro no %d reabastecimento: ", i, i);    
        scanf("%d", &odometro[i]);
        printf("Digite aqui a quantidade de litros de gasolina abastecida no %d posto: ", i);    
        scanf("%f", &gas_used[i - 1]);
        printf("Digite aqui o preco do LITRO da gasolina no %d posto: ", i);    
        scanf("%f", &preco);
        preco += preco * gas_used[i - 1];
        printf("%f", preco);
    }
    for(int i = 0; i < rounds; i++){
        distance[i] = odometro[i + 1] - odometro[i];
        tot_distance += distance[i];
        tot_gas += gas_used[i];
     } 
    printf("\n--- RELATORIO ---");
    printf("\na) a quilometragem obtida por litro de gasolina entre cada par de paradas do reabastecimento");
     for(int i = 1; i < (rounds); i++){
         float kmL = distance[i]/gas_used[i];
         printf("\nEntre o %d posto e o %d posto: %f KM/L\n", i, i + 1, kmL);
     }
    printf("\nb) A quilometragem obtida por litro de gasolina em toda a viagem: %f KM/L", tot_distance / tot_gas);
    printf("\nc) Custo do combustivel por quilometro rodado em toda a viagem: R$ %f por KM", preco / tot_gas);
    printf("\n%f - %d", preco, tot_gas);

    printf("\n%f - %f - %f", gas_used[0], gas_used[1], gas_used[2]);
}
//Questão 7
void maior_media(){
    srand(time(NULL));
    typedef struct {
        int nome;
        float p1;
        float p2;
        float media;
    } Ficha_Aluno;
    float class_media = 0;
    Ficha_Aluno aux;
    Ficha_Aluno Povo[50];
    for(int i=0; i < 50; i++){
        Povo[i].nome = rand()%(10000 - 1)+1;
        Povo[i].p1 = rand()%(10 - 1)+1;
        Povo[i].p2 = rand()%(10 - 1)+1;
        Povo[i].media = (Povo[i].p1 + Povo[i].p2) / 2;
        class_media += Povo[i].media; 
    }
    for(int i=0; i < (50-1); i++){
        for(int j = (i + 1); j < 50; j++){
            if (Povo[j].media > Povo[j + 1].media){
                aux = Povo[j];
                Povo[j] = Povo[j + 1];
                Povo[j + 1] = aux;
            }
        }
    }
    printf("\nMedia classe: %f", class_media / 50);
    for(int i=0; i < 5; i++){
        printf("\nTop %d - %d - %f", i + 1, Povo[49-i].nome, Povo[49-i].media);
    }
}
//Questão 8
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
//Questão 9
void count_caracteres(char frase[]){
    #define tam 80
    char letters[tam];
    int count_letters[tam], cont = 0, delimiter = 0, contabilizer = 0;
    //< Separando e colocando os caracteres distintos em um vetor.
    for(int i = 0; i < strlen(frase); i++){
        int duplicated = 0;
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
//Questão 10
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
//Questão 11
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



//---------Questão 12
//Calcular tamanho do numero
int lenHelper(int num){
    if (num < 10) return 1;
    else if(num < 100) return 2;
    else if(num < 1000) return 3;
    else if(num < 10000) return 4;
}
//Repartir o numero em partes
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
// devolver cada digito separado em extenso
void extenseNumber(){
    int number, *num, *separated_value;
    char unidades[10][8] = {" ", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char milhar[10][15] = {" ", "mil", "dois mil", "tres mil", "quatro mil", "cinco mil", "seis mil", "sete mil", "oito mil", "nove mil"};
    char centenas[10][15] = {" ", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char dezenas[10][12] = {" ", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"}; 
    printf("Digite um numero para escreve-lo em extenso: ");
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


//Questão 13
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
    int tam_11 = (sizeof(X) / 4), aux;
    for (int i = 0; i < tam_11; i++){
        for(int j = 0; j < tam_11 - 1; j++){
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
//Questão 14
void cronometer(){
    int cronometro[6] = {0,0,0,0,0,0};
    while((cronometro[0] != 2) || (cronometro[1] != 4)){
        printf(" %d%d:%d%d:%d%d \n", cronometro[0], cronometro[1], cronometro[2], cronometro[3], cronometro[4], cronometro[5]); 

        switch(cronometro[5]){
            case 9:
                cronometro[4] += 1;
                cronometro[5] = 0; 
                Sleep(1000);
                break;
            default:
                cronometro[5] += 1;
                Sleep(1000);
                break;
        }
        switch(cronometro[4]){
            case 6:
                cronometro[3] += 1;
                cronometro[5] = 0;
                cronometro[4] = 0; 
                Sleep(1000);        
                break;  
        }
        switch (cronometro[3]){
            case 10:
                cronometro[2] += 1;
                cronometro[3] = 0;
                Sleep(1000);
                break;
        }
        switch(cronometro[2]){
            case 6:
                cronometro[1] += 1;
                cronometro[2] = 0;
                cronometro[3] = 0;
                Sleep(1000);  
                break;
        }
        switch(cronometro[1]){
            case 10:
                cronometro[0] += 1;
                cronometro[1] = 0;
                Sleep(1000);
                break;
        }
        switch(cronometro[0]){
            case 2:
                if(cronometro[1] == 4){
                    cronometro[0] = 0;
                    cronometro[1] = 0;
                    cronometro[2] = 0;
                    cronometro[3] = 0;
                    cronometro[4] = 0;
                    cronometro[5] = 0;
                    Sleep(1000);
                    break;
                }
        }             
    }
}
//Questão 15
void dados_transito(){
    struct tm *p;
    time_t seconds;
    time(&seconds);
    p = localtime(&seconds);
    int anoAtual = p->tm_year + 1900;
    char ch, sex;
    int year_born, procedence, tot_people = 0, condition_a = 0, condition_b = 0, condition_c = 0, condition_d = 0, citizen = 1;
    int break_cond = 0;
    printf("--- PESQUISA --- \nDigite abaixo os dados requisitados para realizar o balancete:");
    while(break_cond != 1){
        printf("\n ----- %d CIDADAO -----\n", citizen);
        citizen += 1;
        printf("Ano de nascimento: ");
        scanf("\n%d", &year_born);
        printf("Procedencia (0 - Capital; 1 - Interior; 2 - Outro estado): ");
        scanf("\n%d", &procedence);
        printf("Sexo (M - Masculino; F - Feminino): ");
        scanf("\n%s", &sex);
       
        tot_people += 1;
        if((anoAtual - year_born) <= 21){
            condition_a += 1;
        }
        if((sex == 102) && (procedence == 0)){
            condition_b += 1;
        }
        if(((anoAtual - year_born) >= 60) && (procedence == 2)){
            condition_c += 1;
        }
        if((sex == 102) && ((anoAtual - year_born) > 60)){
            condition_d += 1;
        }
        printf("\n------------\nDigite 'n' para interromper o programa ou qualquer tecla para continuar a registrar: ");
        scanf("%s", &ch);
        if (ch == 110){
            break_cond += 1;
            break;
        }
        else{
            continue;
        }
    }
    printf("------ RESULTADO DA PESQUISA ------\n");
    printf("a) Cerca de %.2f porcento dos motoristas tem menos de 21 anos\n", (condition_a / (float)tot_people) * 100);
    printf("b) No total, %d mulheres sao da capital\n", condition_b);
    printf("c) Ao menos, %d motoristas sao do interior do estado e sao maiores do que 60 anos\n", condition_c);
    printf("d) No total, temos %d mulheres maiores de 60 anos na pesquisa.\n", condition_d);
}
//Questão 16
void dice_launcher(){
    int p1_victory = 0;
    int p2_victory = 0;
    int *p1 = &p1_victory, *p2 = &p2_victory;
    srand(time(NULL));
    printf("PROGRAMA DICE LAUNCHER");
    for(int i=0; i<11; i++){
        int player1[2] = {rand()%(7 - 1)+1, rand()%(7 - 1)+1};
        int player2[2] = {rand()%(7 - 1)+1, rand()%(7 - 1)+1};
        printf("\n---- ROUND %d ---- ", i + 1);
        //Primeiro condicional: Verifica ambos os vetores em busca de valores iguais nas duas posições
        if((player1[0] == player1[1]) || (player2[0] == player2[1])){
            if ((player1[0] == player1[1]) && (player2[0] != player2[1])){
                *p1 += 1;
                printf("Player 1 wins the round!\n");
            }
            else if((player2[0] == player2[1]) && (player1[0] != player1[1])){
                *p2 += 1;
                printf("Player 2 wins the round!\n");
            }
            else if((player1[0] == player1[1]) && (player2[0] == player2[1])){
                if (player1[0] > player2[0]){
                    *p1 += 1;
                    printf("Player 1 wins the round!\n");
                }
                else if(player1[0] < player2[0]){
                    *p2 += 1;
                    printf("Player 2 wins the round!\n");
                }
                else if((player1[0] == player2[0]) && ((player1[1] == player2[1])) || (player1[0] == player2[1]) && ((player1[1] == player2[0]))){
                    printf("Empate!\n");
                }
            }
        }
        /* Segundo condicional: Uma vez passado pelo de cima, verifica se ambos os vetores tem 
        valores diferentes para fazer o procedimento
        */
        else if((player1[0] != player1[1]) && (player2[0] != player2[1])){
            if((player1[0] + player1[1]) > (player2[0] + player2[1])){
                *p1 += 1;
                printf("Player 1 wins the round!\n");
            }
            else{
                *p2 += 1;
                printf("Player 2 wins the round!\n");
            }
        }
        printf("Player 1: { %d , %d } | Pts: %d\n", player1[0], player1[1], *p1);
        printf("Player 2: { %d , %d } | Pts: %d\n", player2[0], player2[1], *p2); 
    }  
    if (*p1 > *p2){
        printf("\n\nCongratulations! \n- Player 1 won the match! - %d points\n- Player 2 - %d points", *p1, *p2);
    }
    else{
        printf("Congratulations! \n- Player 2 won the match! - %d points\n- Player 1 - %d points", *p2, *p1);
    }

} 

int main(){

    /* 
    1) Escreva um programa em C que encontre o menor inteiro positivo n que atenda as seguintes condições :
    n / 3 = x inteiro e resto 2
    n / 5 = y inteiro e resto 3
    n / 7 = z inteiro e resto 4
    */

    
    // divisers();

    //FIM
    /* 
    2) Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou não primo.      
    */

    // prime_number(23);

    //FIM
    /* 3) Um inteiro perfeito n é igual a soma de todos os seus divisores próprios. A faixa de seus divisores
    próprios vai de 1 a (n-1). Por exemplo : 6 é um inteiro perfeito; a soma de todos os seus divisores próprios (
    1 + 2 + 3) é igual a 6. Escreva um programa em C que determine se um número no intervalo de 1 a 32767 é
    um inteiro perfeito*/

    // perfect_number();

    //FIM
    /* 
    4) Escreva um programa em C que calcule o fatorial de um número inteiro positivo.
    */

    // int fact = factorial(4);
    // printf("%d", fact);

    //FIM
    /* 
    5) O troco em moedas é uma combinação de moedas com os seguintes valores :
    R$ 1,00 ; 0,50; 0,25; 0,10; 0,05; 0,01
    Escreva um programa em C que leia qualquer valor em centavos (R$0,01 até R$1,00). Calcule e imprima
    seu equivalente em moedas. Encontre a solução que utilize o menor número possível de moedas.
    */

    //sacar_moeda(248); 

    //FIM
    /* 
    6) Um motorista acaba de retornar de um feriado prolongado. Em cada parada de reabastecimento ele
    registrou a leitura de seu odômetro, a quantidade de gasolina comprada (suponha que ele tenha enchido o
    tanque cada vez) e o preço pago. Além disso, suponha também que ele tenha enchido o tanque antes de
    partir e imediatamente após retornar. Escreva um programa em C para ler, em primeiro lugar, o número total
    de reabastecimentos feitos (incluindo o primeiro e o último) e, a seguir, os dados relativos à compra de
    gasolina e calcular :
    a) a quilometragem obtida por litro de gasolina entre cada par de paradas de reabastecimento;
    b) a quilometragem obtida por litro de gasolina em toda a viagem
    c) custo do combustível por quilometro rodado em toda a viagem
    */

    //calculoGasolina(3);

    //FIM
    /* 
    7) Escreva um programa em C onde, se possa representar os nomes e as notas de alunos de um curso da
    universidade. O programa deverá imprimir os nomes dos cinco alunos que obtiverem as maiores notas
    acima da média da turma. Considerar que a turma tenha 50 alunos. Usar a estrutura multivalorada vista em
    sala de aula.
    */

    //maior_media();

    //FIM
    /* 
    8)Para um vetor A de 50 números inteiros, escrever um programa em C que determine o maior e o segundo
    maior elemento desse vetor. Assumir que todos os elementos são distintos
   */

    //biggest_two_numbers();

    //FIM
    /* 
    9) Escrever um programa em C que calcule e imprima o número de caracteres distintos presentes em uma
    cadeia de caracteres dada. Considerar o tamanho máximo da cadeia como sendo de 80 colunas.
    */

    //Arrumar espaço em branco
    // char frase[80] = "arrozefeijaobatatafrita\0";
    // count_caracteres(frase);

    //FIM
    /*  
    10)Escrever um programa em C que calcule a frequência de uso de cada palavra dentro de uma cadeia de caracteres que possui diversas palavras. Considerar o tamanho máximo da cadeia como sendo de 80 colunas.
    */

    //countWords();

    //FIM
    /* 

    11) Escrever um programa em C que leia uma cadeia de caracteres e imprima todas as palavras que
    contenham três ou mais vogais
    */

    //tres_mais_vogal();

    //FIM
    /* 
    12)Escrever um programa em C que leia um valor inteiro (limite na casa do milhar), e o imprima em forma
    de caracteres, ou seja, por extenso. Ex. : 98 = noventa e oito.
    */

    extenseNumber();

    //FIM
    /* 
    13) Dados três vetores com 10 posições cada um, preenchidos com números inteiros, fazer um programa
    em C que, após a leitura dos vetores coloque-os em ordem crescente.
    */
   
    // int *vetor;
    // vetor = join_Vector();

    //FIM
    /* 
    14) Faça um programa em C que simule um cronômetro com horas, minutos e segundos. A simulação
    deverá mostrar no vídeo o cronômetro no seguinte formato HH: MM: SS. Inicialmente o cronômetro será
    zerado ( 00: 00: 00 ), sendo que os segundos começarão a ser incrementados, depois os minutos e
    depois as horas. Lembre-se que a cada 60 segundos os minutos deverão ser incrementados, depois os
    minutos voltarão a zero. Quando as horas estiverem prestes a chegar em 24, o cronômetro deverá
    voltar a zero ( 00: 00: 00 ).
    */

    //cronometer();

    //FIM
    /*
    15) O Departamento de trânsito do estado anotou dados de acidentes de trânsito no último ano. Para cada motorista envolvido no acidente, tem-se as seguintes informações:
    - Ano de nascimento;
    - Sexo (M - Masculino, F - Feminino)
    - Procedência ( 0 - Capital, 1 - Interior, 2 - Outro estado);
    Faça um programa em C que :
    a) Calcule a porcentagem de motoristas com menos de 21 anos;
    b) Calcule quantas mulheres são da capital;
    c) Calcule quantos motoristas do interior do estado tem idade maior que 60 anos;
    d) Verifique se existe alguma mulher com idade maior que 60 anos;
    */

    //dados_transito();

    //FIM
    /*
    16) Faça um programa em C que atenda às regras do seguinte jogo de dados. Dois jogadores estão
    confrontando-se entre si, usando dois dados, numerados de 1 até 6 (dado RAND(5) + 1). Vence uma
    rodada quem obtiver o maior número no lançamento. Entretanto, caso um jogador obtiver um
    lançamento com dois dados iguais (por exemplo, 1 e 1, 2 e 2,....) e o outro jogador não, o jogador que
    tiver lançado a dupla ganha. Caso os dois jogadores fizerem o lançamento e o resultado for de duas
    duplas para os dois jogadores, ganha o jogador com a dupla maior. A disputa é em 11 lançamentos.
    Indique o jogador vencedor ou se houve empate.
    */

    //dice_launcher();

    //FIM

}
