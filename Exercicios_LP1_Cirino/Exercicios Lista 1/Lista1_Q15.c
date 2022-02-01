#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
int main(){
    dados_transito();

}