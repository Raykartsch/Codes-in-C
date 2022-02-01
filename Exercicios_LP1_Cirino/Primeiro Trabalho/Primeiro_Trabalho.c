#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

typedef struct {
    char tipo[15];
    char local[80];
    char qualidade[10];
    char resumo[400];
} Description;
typedef struct {
    char nome[100];
    Description Info;
    char regiao[5];
} Atracao;

//Vai printar todas as regiões e pedir para um usuario e selecionar uma delas e consultar os dados
void connect_region(){
    printf("Conectando a uma regiao!");
    int x;
    printf("\n ----- Conectando-se a uma regiao ----- \
            \n1 - (N) Norte \
            \n2 - (S) Sul \
            \n3 - (CO) Centro Oeste \
            \n4 - (SE) Sudeste \
            \n5 - (NO) Nordeste \ 
            \nDigite um numero e conecte-se a uma regiao para modificar a sua agenda: ");
    
    scanf("%d", &x);
    switch (x){
        case 1:
                struct_by_region("N");
                break;
        case 2:
                struct_by_region("S");
                break;
        case 3:
                struct_by_region("CO");
                break;
        case 4:
                struct_by_region("SE");
                break;
        case 5:
                struct_by_region("NO");
                break;
        default:
            printf("Opcao invalida. Tente novamente");
            connect_region();
            break;
    }  
}

void geral_menu(){
    int command = 0;
    int regiao = 0;
    printf("\n --------------- Boas vindas, Visitante! --------------- \
        \nSelecione uma das opcoes abaixo: \
        \n1 - Conectar a uma regiao do Brasil \
        \n2 - Consultar dados de uma determinada regiao \
        \n3 - Encerrar o programa \
        \nDigite uma das opcoes acima: ");
    scanf("%d", &command);

    switch (command){
        case 1:{
            connect_region();
            break;
        }
        case 2:{
            fflush(stdin);
            printf("\n ----- Conectando-se a uma regiao ----- \
            \nConecte-se a uma regiao e modifique a sua agenda: \
            \n1 - (N) Norte \
            \n2 - (S) Sul \
            \n3 - (CO) Centro Oeste \
            \n4 - (SE) Sudeste \
            \n5 - (NO) Nordeste  \
            \nDigite a regiao que deseja consultar: ");
            scanf("%d", &regiao);
            switch (regiao){
                case 1:
                        consult_data_region("N");
                        break;
                case 2:
                        consult_data_region("S");
                        break;
                case 3:
                        consult_data_region("CO");
                        break;
                case 4:
                        consult_data_region("SE");
                        break;
                case 5:
                        consult_data_region("NO");
                        break;
                default:
                    printf("Opcao inválida. Tente novamente");
                    geral_menu();
                    break;
            }  
        }

        case 3:{
            printf("Saindo...");
            sair();
            break;
        }
        
        default:{
            printf("\nComando invalido. Digite uma opcao novamente para continuar a execucao do programa");
            geral_menu();
            break;
        }
    }
}

void sair(){
    return 1;
}

//Limitar à 100 registros
// Limitar os dados por região na hora que incluir no vetor
void consult_data_region(char region[5]){
    printf("\nConsultando dados de uma regiao!");
    printf("\n--- Consultando atracoes da regiao %s----", region);
    Atracao read_archive;
    int found = 0;
    FILE *read = fopen("ArquivoTexto.txt", "rb");
    if (read != NULL){
        while(fread(&read_archive, sizeof(Atracao), 1, read)){
            if(strcmp(read_archive.regiao, region) == 0){
                found = 1;
                printf("\n- %s", read_archive.nome);
            }
        }
    }
    fclose(read);
    int command;
    if (found == 0){
        printf("\nNenhum registro encontrado! \
        -------------------------------------------\
        \n1 - Registrar um registro na regiao %s \
        \n2 - Voltar ao menu principal \
        \nSelecione uma das opcoes acima: ", region);
        fflush(stdin);
        scanf("%d", &command);
        switch (command){
            case 1:{
                write_register(region);
                break;
            }         
            case 2:{
                geral_menu();
                break;
            }    
            default:{
                geral_menu();
                break;
            }        
        } 
    }
    else{
        printf("\n ------------------------- \
        \n1 - Modificar agenda %s \
        \n2 - Voltar ao menu principal \
        \nSelecione uma das opcoes acima: ", region);
        fflush(stdin);
        scanf("%d", &command);
        switch (command){
            case 1:{
                inner_menu(region);
                break;
            }         
            case 2:{
                geral_menu();
                break;
            }    
            default:{
                geral_menu();
                break;
            }        
        } 
    }
}

void struct_by_region(char select_region[5]){
    printf("\nEstruturando a regiao no vetor!");
    int aux_index = 0;
    char regiao[5];
    strcpy(regiao, select_region);
    Atracao read_archive[100];
    Atracao auxiliar;

    FILE *read = fopen("ArquivoTexto.txt", "rb+");

    if(read != NULL){
        while(fread(&auxiliar, sizeof(Atracao), 1, read)){
            if((strcmp(auxiliar.regiao, regiao) == 0) && auxiliar.regiao != NULL){
                memcpy(&read_archive[aux_index], &auxiliar, sizeof(Atracao));
                aux_index += 1;
            }
        }
        fclose(read);
    }
    else{
        fclose(read);

        FILE *read = fopen("ArquivoTexto.txt", "wb+");
        while(fread(&auxiliar, sizeof(Atracao), 1, read)){
            if((strcmp(auxiliar.regiao, regiao) == 0) && auxiliar.regiao != NULL){
                memcpy(&read_archive[aux_index], &auxiliar, sizeof(Atracao));
                aux_index += 1;
            }
        }
        fclose(read);
    }
    
    // if(read == NULL){
    //     printf("Problemas na abertura do arquivo\n");

    // }
    // else{
    //     while(fread(&auxiliar, sizeof(Atracao), 1, read)){
    //         if((strcmp(auxiliar.regiao, regiao) == 0) && auxiliar.regiao != NULL){
    //             memcpy(&read_archive[aux_index], &auxiliar, sizeof(Atracao));
    //             aux_index += 1;
    //         }
    //     }
    // }
    // fclose(read);
    if(strlen(read_archive) == 0){
        printf("\n------- AGENDA DA REGIAO %s VAZIA! ------- \
                \n|1 - Registrar uma atracao na regiao %s \t|\
                \n|2 - Conectar-se a agenda de uma outra regiao do Brasil \t|\
                \n|3 - Voltar ao menu principal \t|\
                \n-------------------------------------- \
                \nEscolha uma das opcoes acima: ", regiao, regiao);
        int c;
        scanf("%d", &c);
        switch (c){
            case 1:
                write_register(regiao);
                break;
            case 2:
                connect_region();
                break;
            case 3:
                geral_menu();
                break;
            default:
                geral_menu();
                break;
        }
    }
    printf("\nQuantidade de registros: %d", aux_index);
    printf("\n--------------------------------");
    printf("\nRegiao %s conectada com sucesso!\n", read_archive->regiao);
    printf("----------------------------------");
    for(int i = 0; i < aux_index; i++){
        printf("\n| %s \t\t|", read_archive[i].nome);
    }
    printf("\n--------------------------------\n");
    Sleep(500);
    inner_menu(regiao);
}

void print_select_region(char region[5]){
    Atracao read_archive;
    int found = 0;
    FILE *read = fopen("ArquivoTexto.txt", "rb");
    printf("\n---------------------------------");
    if (read != NULL){
        while(fread(&read_archive, sizeof(Atracao), 1, read)){
            if(strcmp(read_archive.regiao, region) == 0){
                found = 1;
                printf("\n- %s", read_archive.nome);
            }
        }
    }
    printf("\n---------------------------------");
    fclose(read);
}
void inner_menu(char select_region[5]){
    char regiao[5];
    strcpy(regiao, select_region);
    print_select_region(regiao);
    printf("\n----------- Regiao conectada: %s ----------- \n\
Digite uma opcao para MODIFICAR sua agenda - \n \
1 - Registrar uma nova atracao\n \
2 - Alterar uma atracao\n \
3 - Deletar uma atracao\n \
4 - Mostrar a descricao de uma atracao\n \
5 - Voltar ao menu inicial\n \
Selecione uma opcao: ", regiao);

    int command;
    scanf("%d", &command);
    char str[100];
    switch (command){
        //Registrar uma nova atracao
        case 1:
            write_register(regiao);
        //Alterar uma atracao
        case 2:
            printf("\n ---------------------------------------------- \
            \nOPCAO 2: \nDigite aqui o nome da atracao que deseja ALTERAR da sua agenda: ");
            fflush(stdin);
            scanf("%[^\n]s", &str);
            alter_register(str, regiao);
            break;
        //Deletar uma atracao
        case 3:
            printf("\n ---------------------------------------------- \
            \nOPCAO 3: \nDigite aqui o nome da atracao que deseja EXCLUIR da sua agenda: ");
            fflush(stdin);
            scanf("%[^\n]s", &str);
            delete_register(str, regiao);
            break;
        //Mostrar detalhes de uma atracao
        case 4: 
            printf("\n --------------------------------- \
            OPCAO 4:\nDigite aqui o nome da atracao que deseja MOSTRAR a descricao: ");
            fflush(stdin);
            scanf("%[^\n]s", &str);
            show_register(str, regiao);
            break;
        //Voltar ao menu principal
        case 5:
            geral_menu();
            break;
        default:
            printf("Opcao incorreta.");
            inner_menu(regiao);
            break;
    }
}

void write_register(char s_reg[5]){
    char regiao[5];
    strcpy(regiao, s_reg);
    printf("\n ---- Registrar atracao na regiao %s----", regiao);
    FILE *arq;
    Atracao aux;
    fflush(stdin);
    printf("\nDigite aqui o nome da atracao: ");
    scanf("%[^\n]s", &aux.nome);
    fflush(stdin);
    
    printf("----- Cadastre aqui as informacoes do evento: %s -----", aux.nome);
    strcpy(aux.regiao, regiao);
    fflush(stdin);

    printf("\nTipo: ");
    scanf("%s", &aux.Info.tipo);
    fflush(stdin);

    printf("\nLocal: ");
    scanf("%[^\n]s", &aux.Info.local);
    fflush(stdin);

    printf("\nQualidade: ");
    scanf("%s", &aux.Info.qualidade);
    fflush(stdin);

    printf("\nResumo: ");
    fflush(stdin);
    scanf("%[^\n]s", &aux.Info.resumo);
    fflush(stdin);

    arq = fopen("ArquivoTexto.txt", "ab");
    if (arq == NULL){
        printf("\nProblemas na abertura do arquivo - write register! \
        ----------------------------------------------------");
        return 1;
    }
    if (arq != NULL){
        fwrite(&aux, sizeof(aux), 1, arq);
        printf("\nAtracao registrada na agenda com sucesso! \
        ----------------------------------------------------");
    }
    fclose(arq);
    inner_menu(regiao);
}

void show_register(char x[100], char regiao[5]){  
    FILE *arq = fopen("ArquivoTexto.txt", "rb");
    Atracao temp;
    int found = 0;
    printf("\n------------------------------");
    while(fread(&temp, sizeof(Atracao), 1, arq)){
        if(strcmp(temp.nome, x) == 0){
            printf("\n|Registro da atracao encontrado! ");
            printf("\n|Nome da atracao: %s ", temp.nome);
            printf("\n|Regiao: %s ", temp.regiao);
            printf("\n|Tipo: %s ", temp.Info.tipo);
            printf("\n|Local: %s ", temp.Info.local);
            printf("\n|Qualidade: %s ", temp.Info.qualidade);
            printf("\n|Resumo: %s ", temp.Info.resumo);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nRegistro nao encontrado na agenda! Busque novamente ou altere a regiao!");
    }
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\n------------------------------\n");
    inner_menu(regiao);
}

void alter_register(char x[100], char regiao[5]){
    Atracao read_archive, auxiliar;
    FILE *arq = fopen("ArquivoTexto.txt", "rb+");
    int i = 0;
    if (arq){
        printf("Arquivo aberto com sucesso!");
        while(fread(&read_archive, sizeof(Atracao), 1, arq) && strcmp(read_archive.nome, x) != 0){
            printf("%s", read_archive.nome);
            i++;
        }
        strcpy(auxiliar.nome, read_archive.nome);
        printf("%s", auxiliar.nome);
        strcpy(auxiliar.regiao, read_archive.regiao);
        printf("%s", auxiliar.regiao);

        printf("Altere o evento: ");
        printf("\nTipo: ");
        scanf("%s", &auxiliar.Info.tipo);
        fflush(stdin);

        printf("\nLocal: ");
        scanf("%[^\n]s", &auxiliar.Info.local);
        fflush(stdin);

        printf("\nQualidade: ");
        scanf("%s", &auxiliar.Info.qualidade);
        fflush(stdin);

        printf("\nResumo: ");
        scanf("%[^\n]s", &auxiliar.Info.resumo);
        fflush(stdin);  
        fseek(arq, i * sizeof(Atracao), SEEK_SET);  
        fwrite(&auxiliar, sizeof(Atracao), 1, arq);
        fclose(arq);
    }
    else{
        printf("Erro ao alterar evento!");
    }
    inner_menu(regiao);
}

void delete_register(char x[100], char regiao[5]){
    Atracao read;
    FILE *arq = fopen("ArquivoTexto.txt", "rb");
    FILE *temp = fopen("temporary.txt", "wb");
    int found = 0;
    while(fread(&read, sizeof(Atracao), 1, arq)){
        printf("\n%s - ", read.nome);
        if (strcmp(x, read.nome) == 0){
            found = 1;
            continue;
        }
        else{
            fwrite(&read, sizeof(Atracao), 1, temp);
        }
    }
    fclose(arq);
    fclose(temp);
    if(found == 1){
        FILE *temp = fopen("temporary.txt", "rb");
        FILE *arq = fopen("ArquivoTexto.txt", "wb");
        while(fread(&read, sizeof(Atracao), 1, temp)){
            fwrite(&read, sizeof(Atracao), 1, arq);
        }
        printf("\nRegistro deletado com sucesso!");
    } else {
        printf("\nRegistro nao encontrado na agenda! Busque novamente ou troque a regiao!");
    }
    fclose(arq);
    fclose(temp);
    inner_menu(regiao);
}

int main(){
    geral_menu(); 
}
