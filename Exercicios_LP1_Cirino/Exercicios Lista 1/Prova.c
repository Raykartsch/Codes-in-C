#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void antes(){
    int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}}, *pa[3] = {a[0], a[1], a[2]};
    int *p = a[0];
    
    for(int i=0; i<3; i++)
    	printf("%d %d\n", *pa[i], p[i]);
	return 1;

    // char nome[] = "UNIVERSIDADE DO ESTADO DO RIO DE JANEIRO";
    // printf("%s\n", nome+3);


}



typedef struct{
    char ultnome[16];
    char nome[25];
} endereco;

// int comparator(const void *first, const void *second){
//     char s1;
//     char s2;
//     int c, tams1, tams2;
//     strcpy(s1, (*(struct endereco*)first).ultnome);
//     strcpy(s2, (*(struct endereco*)second).ultnome);

//     for (int i = 0; i < strlen(s1); i++) {
//         c = *s1[i];
//         printf("%d", c);

//         tams1 = tams1 + c;

//     } 
//     for (int i = 0; i < strlen(s1); i++) {
//         c = s2[i];
//         printf("%d", c);

//         tams2 = tams2 + c;
//     }
//     if (tams1 < tams2){
//         return -1;
//     }
//     else if (tams1 == tams2){
//         return 0;
//     }
//     else{
//         return 1;
//     }
// }





float alfa(float x, float y, float z){
    float res = pow(x, 2) + (y + z);
    printf("\n%f", res);
    return (pow(x, 2) + (y + z));
}

int cmpstr(const void* a, const void* b){
    const endereco *first = (struct endereco *) a;
    const endereco *second =  (struct endereco *)b;
    return strcmp(first->ultnome, second->ultnome);
}

int main(){
    // endereco agenda[100];
    // char *p = &agenda[0];
    // qsort(agenda, 100, sizeof(endereco), cmpstr);

    // int x;
    // float vet[3];
    // for(x=0; x <= 2; x++){
    //     printf("\n[%d] digite:", x);
    //     scanf("%f", &vet[x]);
    // }
    // printf("\n\nResultado: %3.2f\n", alfa(vet[0], vet[1], vet[2]));
    // printf("\n\n");
    // system("pause");
    // return(0);

    // int tams1 = 0;
    // int tams2 = 0;
    // int c = 0;
    // char s1[50] = "abacaxi";
    // char s2[50] = "abecaxi";
    // for (int i = 0; i < strlen(s1); i++) {
    //     c = s1[i];
    //     printf("%d", c);

    //     tams1 = tams1 + c;

    // } 
    // for (int i = 0; i < strlen(s1); i++) {
    //     c = s2[i];
    //     printf("%d", c);

    //     tams2 = tams2 + c;
    // } 
    // printf("\n----%d", tams1);
    // printf("\n----%d", tams2);
    
    antes();

}
