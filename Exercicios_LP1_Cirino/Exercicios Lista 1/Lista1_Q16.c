#include <stdio.h>
#include <stdlib.h>

//Refazer com o switch case e utilizar ponteiros!!
void dice_launcher(num){
    int p1_victory = 0;
    int p2_victory = 0;
    int *p1, *p2;
    p1 = &p1_victory;
    p2 = &p2_victory;
    srand(time(NULL));
    printf("PROGRAMA DICE LAUNCHER");
    for(int i=0; i<num; i++){
        int player1[2] = {rand()%(7 - 1)+1, rand()%(7 - 1)+1};
        int player2[2] = {rand()%(7 - 1)+1, rand()%(7 - 1)+1};
        printf("\n---- ROUND %d ---- ", i + 1);
        //Primeiro condicional: Verifica ambos os vetores em busca de valores iguais nas duas posições
        if((player1[0] == player1[1]) || (player2[0] == player2[1])){
            if ((player1[0] == player1[1]) && (player2[0] != player2[1])){
                p1_victory += 1;
                printf("Player 1 ganhou!\n");
            }
            else if((player2[0] == player2[1]) && (player1[0] != player1[1])){
                p2_victory += 1;
                printf("Player 2 ganhou!\n");
            }
            else if((player1[0] == player1[1]) && (player2[0] == player2[1])){
                if (player1[0] > player2[0]){
                    p1_victory += 1;
                    printf("Player 1 ganhou!\n");
                }
                else if(player1[0] < player2[0]){
                    p2_victory += 1;
                    printf("Player 2 ganhou!\n");
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
                p1_victory += 1;
                printf("Player 1 ganhou!\n");
            }
            else{
                p2_victory += 1;
                printf("Player 2 ganhou!\n");
            }
        }
        printf("Player 1: { %d , %d } | Pts: %d\n", player1[0], player1[1], p1_victory);
        printf("Player 2: { %d , %d } | Pts: %d\n", player2[0], player2[1], p2_victory); 
    }  
    if (p1_victory > p2_victory){
        printf("Congratulations! \nPlayer 1 wins - %d points\nPlayer 2 - %d points", p1_victory, p2_victory);
    }
    else{
        printf("Congratulations! \nPlayer 2 wins - %d points\nPlayer 1 - %d points", p2_victory, p1_victory);
    }
} 
int main(){
    dice_launcher(11);
}