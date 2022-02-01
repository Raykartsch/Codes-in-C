#include <stdio.h>
#include <stdlib.h>

/* conseguir: 
    a) a quilometragem obtida por litro de gasolina entre cada par de paradas do reabastecimento;
    b) a quilometragem obtida por litro de gasolina em toda a viagem
    c) custo do combustivel por quilometro rodado em toda a viagem 
*/
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
int main(){
    calculoGasolina(3);
}