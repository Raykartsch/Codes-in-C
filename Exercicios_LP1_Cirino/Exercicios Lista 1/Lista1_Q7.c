#include <stdio.h>
#include <stdlib.h>

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
int main(){
    maior_media();
}