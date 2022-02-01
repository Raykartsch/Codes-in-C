#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <io.h>
#include <windows.h>

//Segmentation fault ao retornar ponteiro de leitura para o começo do arquivo
typedef struct{
    int num_mesa;
    int cod_garcom;
    float tot_pedido;
    struct Mesa *Prox;
    struct Mesa *Ant;
    struct Pedidos *L_Pedidos;
} Mesa;

typedef struct {
    int cod_pedido;
    int qtd_pedido;
    struct Pedidos *Prox;
} Pedidos;

// estruturas para guardar no arquivo binário
typedef struct {
    char nome[100];
    float preco;
    int codigo_item;
    int active;
} Cardapio;

typedef struct {
    char nome[50];
    int codigo_garcom;
    int active;
} Garcom;

void imprimir_mesas(Mesa *table){
    printf("\n-------- Imprimindo Mesas --------\n");
    Mesa *a = &*table;
    printf("Mesas: ");
    while(a != NULL){
        printf("0%d -->", a->num_mesa);
        a = a->Prox;
    }
}
void imprimir_pratos(){
    printf("\n-------- Cardapio --------");
    FILE *read = fopen("Cardapio.txt", "rb+");
    Cardapio aux;
    while(fread(&aux, sizeof(Cardapio), 1, read)){
        printf("\n| Codigo: %d \t| Nome: %s\t | ", aux.codigo_item, aux.nome);
    }
    printf("\n--------------------------------");
}

void imprimir_garcons(){
    printf("\n----------- Garcons -----------");
    FILE *read = fopen("Funcionarios.txt", "rb+");
    Garcom aux_func;
    while(fread(&aux_func, sizeof(Garcom), 1, read)){
        printf("\n| Codigo: %d \t|Nome: %s\t|", aux_func.codigo_garcom, aux_func.nome);
    }
    printf("\n--------------------------------");
}

void verificar_status_mesa(Mesa *table, int cod){
    Mesa *p = &*table;
    while(p->Prox != NULL && p->num_mesa != cod){
        p = p->Prox;
    }
    FILE *read_garc = fopen("Funcionarios.txt", "rb+");
    Garcom garc_aux;
    while(fread(&garc_aux, sizeof(Garcom), 1, read_garc)){
        if(garc_aux.codigo_garcom == p->cod_garcom){
            break;
        }
    }

    printf("--------- Verificar status da mesa %d ---------", p->num_mesa);
    printf("\n|Garcom: %s: \t\t\t|", garc_aux.nome);
    FILE *read_order = fopen("Cardapio.txt", "rb+");
    Cardapio aux_comida;
    Pedidos *a = p->L_Pedidos;
    printf("\n|Pedidos:");
    while (a != NULL){
        while(fread(&aux_comida, sizeof(Cardapio), 1, read_order)){
            if(aux_comida.codigo_item == a->cod_pedido){
                printf("\n| \t Nome: %s \t Quantidade: %d \t|", aux_comida.nome, a->qtd_pedido);
            }
        }
        a = a->Prox;
        fseek(read_order, 0, SEEK_SET);
    }  
}

int check_garcom_disponivel(int cod_garcom){
    FILE *read_garcom = fopen("Funcionarios.txt", "rb+");
    Garcom r_garc;
    int found = 0;
    while(fread(&r_garc, sizeof(Garcom), 1, read_garcom)){
        if(r_garc.codigo_garcom == cod_garcom){
            found = 1;
            return cod_garcom;
        }
    }
    if(found == 0){
        printf("Garcom nao encontrado! Busque novamente!");
        int cg = (int *)malloc(sizeof(int));
        scanf("%d", &cg);
        check_garcom_disponivel(cg);
    }
}

int check_comida_disponivel(int cod_comida){
    FILE *read_comida = fopen("Cardapio.txt", "rb+");
    Cardapio r_comida;
    int found = 0;
    while(fread(&r_comida, sizeof(Cardapio), 1, read_comida)){
        if(r_comida.codigo_item == cod_comida){
            found = 1;
            return cod_comida;
        }
    }
    if(found == 0){
        printf("Comida nao cadastrada no sistema! Busque novamente!");
        int cc = (int *)malloc(sizeof(int));
        scanf("%d", &cc);
        check_comida_disponivel(cc);
    }
}

void AcrescentarMesa(Mesa *table){
    printf("\n------ Acrescentando Mesa no Sistema ------");
    Mesa *p;
    Mesa *s = &*table;
    int codigo_garcom;
    p = &*table;
    while(p->Prox != NULL){
        p = p->Prox;
    }
    Mesa *n;
    n = (Mesa *)malloc(sizeof(Mesa));
    n->num_mesa = p->num_mesa + 1;
    printf("\nAcrescentar Mesa: Numero %d", n->num_mesa);
    fflush(stdin);
    imprimir_garcons();
    printf("\nDigite o codigo do garcom que esta servindo a mesa: ");
    scanf("%d", &codigo_garcom);
    n->cod_garcom = check_garcom_disponivel(codigo_garcom);
    n->Prox = NULL;
    p->Prox = &*n;
    n->Ant = &*p;
    n->L_Pedidos = NULL;
    menu_principal(s);
}

void AcrescentarPedido(Mesa *table, int id){
    imprimir_pratos();
    Mesa *p;
    Mesa *s = &*table;
    p = &*table;
    Pedidos *n;
    Pedidos *a;
    float total_mesa = 0;
    int codigo_comida = (int *)malloc(sizeof(int));
    while(p->Prox != NULL && (p->num_mesa != id)){
        p = p->Prox;
    }
    if(p->num_mesa == id){
        printf("\n ----- Acrescentando Pedido da Mesa: %d ----- ", p->num_mesa);
        if(p->L_Pedidos == NULL){
            n = (Pedidos *)malloc(sizeof(Pedidos));
            printf("\nCodigo do prato: ");
            scanf("%d", &codigo_comida);
            n->cod_pedido = check_comida_disponivel(codigo_comida);
            printf("\nDigite a quantidade de pratos servidos: ");
            scanf("%d", &n->qtd_pedido);
            p->L_Pedidos = &*n;
            n->Prox = NULL; 

            FILE *read = fopen("Cardapio.txt", "rb+");
            Cardapio auxiliar;
            while(fread(&auxiliar, sizeof(Cardapio), 1, read)){
                if(n->cod_pedido == auxiliar.codigo_item){
                    total_mesa = total_mesa += (auxiliar.preco*n->qtd_pedido);
                    break;
                }
            }
            fclose(read);
        }
        else{
            n = p->L_Pedidos;
            while(n->Prox != NULL){
                n = n->Prox;
            }   
            printf("\nAnterior Cod-pedido: %d", n->cod_pedido);
            Pedidos *aux;
            aux = (Pedidos *)malloc(sizeof(Pedidos));
            fflush(stdin);
            printf("\nCodigo do prato: ");
            scanf("%d", &aux->cod_pedido);
            printf("\nDigite a quantidade de pratos servidos: ");
            scanf("%d", &aux->qtd_pedido);
            aux->Prox = NULL;
            n->Prox = &*aux;


            Pedidos *sum = p->L_Pedidos;
            FILE *read_c = fopen("Cardapio.txt", "rb+");
            Cardapio aux_cardap;
            while(sum != NULL){
                while(fread(&aux_cardap, sizeof(Cardapio), 1, read_c)){
                    printf("\nCodigo: %d | Nome: %s", aux_cardap.codigo_item, aux_cardap.nome);
                    if(sum->cod_pedido == aux_cardap.codigo_item){
                        total_mesa = total_mesa += (aux_cardap.preco * n->qtd_pedido);
                        break;
                    }
                }
                sum = sum->Prox;
                fseek(read_c, 0, SEEK_SET);
            }
        }
        p->tot_pedido = total_mesa;
    }
    else{
        printf("\nMesa nao encontrada no sistema! Tente novamente!");
    }
    menu_principal(s);
}

void Fechar_Conta(Mesa *table, int cod){ 
    printf("----------------------------------------------");
    printf("\nEmitindo a nota fiscal........");
    Mesa *a = &*table;
    Mesa *p = &*table;
    while(p->Prox != NULL && p->num_mesa != cod){
        p = p->Prox;
    }

    if(p->num_mesa == cod){ 
        printf("\n------------- \t Nota Fiscal \t ------------- \n| Mesa %d", cod);
        // Funcionário que atendeu a mesa
        FILE *read_f = fopen("Funcionarios.txt", "rb+");
        Garcom aux;
        while(fread(&aux, sizeof(Garcom), 1, read_f)){
            if (p->cod_garcom == aux.codigo_garcom){
                printf("\t\t\t Garcom: %s |", aux.nome);
                break;
            }
        }

        // Todos os pedidos feitos pela mesa e seu total
        FILE *read_orders = fopen("Cardapio.txt", "rb+");
        Cardapio order_aux;
        Pedidos *order = p->L_Pedidos;
        float total = 0;
        while(order != NULL){
            while(fread(&order_aux, sizeof(Cardapio), 1, read_orders)){        
                if (order->cod_pedido == order_aux.codigo_item){
                    printf("\n| Prato: %s | Qtd: %-d | Valor: R$ %.2f |", order_aux.nome, order->qtd_pedido, order_aux.preco*order->qtd_pedido);
                    total = total += order_aux.preco*order->qtd_pedido;
                }
            }
            order = order->Prox;
            fseek(read_orders, 0, SEEK_SET);
        }
        printf("\n| \t\t\t\t Total: R$%.2f | \n----------------------------------------------", total);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        //Limpar os nós com pedidos
        limpar_pedidos(p);
        //Desalocar nó da mesa
        desalocar_mesa(p);
    }
    else{
        printf("Mesa nao encontrada no sistema! Tente novamente!");
        printf("----------------------------------------------\n");
    }
}

void limpar_pedidos(Mesa *table){
    //printf("\n\nLimpar pedidos!");
    Pedidos *stat_p = NULL;
    Pedidos *move_p = table->L_Pedidos;
    while(move_p != NULL){
        //printf("\nNum_pedido: %d\n", move_p->cod_pedido);    
        stat_p = move_p;
        move_p = move_p->Prox;
        table->L_Pedidos = move_p;
        free(stat_p);
    }
}

void desalocar_mesa(Mesa *table){
    //printf("\nDesalocando mesa!");
    Mesa *p = &*table;
    Mesa *pAnt = NULL;
    Mesa *pProx = NULL;
    if(p->Prox == NULL){
        pAnt = *&p->Ant;
        p->Prox = NULL;
        p->Ant = NULL;
        pAnt->Prox = NULL;
        free(p);
    }
    else if(p->Ant == NULL){
        pProx = *&p->Prox;
        p->Prox = NULL;
        p->Ant = NULL;
        pProx->Ant = NULL;
        free(p);
    }
    else{
        pAnt = *&p->Ant;
        pProx = *&p->Prox;
        printf("%d", p->num_mesa);
        pAnt->Prox = *&p->Prox;
        pProx->Ant = *&pAnt;
        free(p);
    }
}

#define item_tam 8
#define func_tam 4
// Criar um booleano na estrutura da comida
void padrao(){
    //Adicionar mais itens e funcionarios para o sistema
    Cardapio items[item_tam];
    Garcom funcionarios[func_tam];

    strcpy(items[0].nome, "Batata Frita");
    items[0].preco = 7.90;
    items[0].codigo_item = 1;

    strcpy(items[1].nome, "Hamburguer");
    items[1].preco = 15;
    items[1].codigo_item = 2;

    strcpy(items[2].nome, "Coca-Cola");
    items[2].preco = 5;
    items[2].codigo_item = 3;

    strcpy(items[3].nome, "File de Peixe");
    items[3].preco = 18.90;
    items[3].codigo_item = 4;

    strcpy(items[4].nome, "Salada");
    items[4].preco = 4.90;
    items[4].codigo_item = 5;

    strcpy(items[5].nome, "Choppzada");
    items[5].preco = 8.90;
    items[5].codigo_item = 6;

    strcpy(items[6].nome, "Strogonoff");
    items[6].preco = 19.90;
    items[6].codigo_item = 7;

    strcpy(items[7].nome, "Churrasquinho");
    items[7].preco = 12.90;
    items[7].codigo_item = 8;

    strcpy(funcionarios[0].nome, "Jorge");
    funcionarios[0].codigo_garcom = 1;

    strcpy(funcionarios[1].nome, "Antonio");
    funcionarios[1].codigo_garcom = 2;

    strcpy(funcionarios[2].nome, "Josefina");
    funcionarios[2].codigo_garcom = 3;

    strcpy(funcionarios[3].nome, "Maria");
    funcionarios[3].codigo_garcom = 4;


    Cardapio aux_card;
    FILE *cardapio = fopen("Cardapio.txt", "rb+");
    

    if(cardapio != NULL){
        for(int i = 0; i < item_tam; i++){
            memcpy(&aux_card, &items[i], sizeof(Cardapio));
            fwrite(&aux_card, sizeof(Cardapio), 1, cardapio);
        }
        fclose(cardapio);
    }
    else{
        fclose(cardapio);

        FILE *cardapio = fopen("Cardapio.txt", "wb+");
        for(int i = 0; i < item_tam; i++){
            memcpy(&aux_card, &items[i], sizeof(Cardapio));
            fwrite(&aux_card, sizeof(Cardapio), 1, cardapio);
            printf("\nNaoExiste-Escrevendo pratos!");
        }
        fclose(cardapio);
    }

    FILE *func = fopen("Funcionarios.txt", "rb+");
    Garcom aux_func;
    if(func != NULL){
        for(int j = 0; j < func_tam; j++){
            memcpy(&aux_func, &funcionarios[j], sizeof(Garcom));
            fwrite(&aux_func, sizeof(Garcom), 1, func);
            printf("\nExiste-Escrevendo funcionarios!");
        }
        printf("RB-Funcionarios");
    }
    else{
        fclose(func);

        FILE *func = fopen("Funcionarios.txt", "wb+");
        for(int j = 0; j < func_tam; j++){
            memcpy(&aux_func, &funcionarios[j], sizeof(Garcom));
            fwrite(&aux_func, sizeof(Garcom), 1, func);
            printf("\nNaoExiste-Escrevendo funcionarios!");
        }
        fclose(func);
    }

    Mesa *n;
    n = (Mesa *)malloc(sizeof(Mesa));
    n->num_mesa = 0;
    n->cod_garcom = 0001;
    n->Prox = NULL;
    n->Ant = NULL;
    n->L_Pedidos = NULL;
    menu_principal(n);
}

void menu_principal(Mesa *table){
    Mesa *n = &*table;
    Mesa *a = &*n;
    Pedidos *p = table->L_Pedidos;
    int command, cod_mesa;
    imprimir_mesas(n);
    printf("\n -------------- Gerenciador de Pedidos ------------------ \
            \n1 - Criar Novo Registro de Mesa \
            \n2 - Registrar Novo Pedido de Uma Mesa \
            \n3 - Fechar Conta de Uma Mesa \
            \n4 - Consultar Mesas e seus Pedidos \
            \n5 - Acrescentar novo garcom no sistema \
            \n6 - Acrescentar novo prato no cardapio \
            \n7 - Encerrar programa \
            \nSelecione uma das opcoes acima: ");
    scanf("%d", &command);
    printf("\n----------------------------------------------\n");
    switch(command){
        case 1:
            AcrescentarMesa(n);
            break;
        case 2:
            imprimir_mesas(n);
            printf("\nACRESCENTAR o pedido na mesa: ");
            cod_mesa = (int *)malloc(sizeof(int));
            scanf("%d", &cod_mesa);
            AcrescentarPedido(n, cod_mesa);
            break;
        case 3:
            printf("Digite o codigo da mesa para FECHAR os pedidos: ");
            cod_mesa = (int *)malloc(sizeof(int));
            scanf("%d", &cod_mesa);
            Fechar_Conta(n, cod_mesa);
            break;
        case 4:
            printf("Digite o codigo da mesa para realizar uma consulta: ");
            cod_mesa = (int *)malloc(sizeof(int));
            scanf("%d", &cod_mesa);
            verificar_status_mesa(n, cod_mesa);
            break;
        case 5:
            adicionar_garcom();
            menu_principal(n);
            break;
        case 6:
            adicionar_prato();
            menu_principal(n);
            break;
        case 7:
            sair();
            printf("Saindo......");
            break;
        default:
            menu_principal(n);
            break;
    }
    if(command != 7){
        menu_principal(n);
    }
}

void adicionar_garcom(){
    FILE *arq = fopen("Funcionarios.txt", "ab+");
    Garcom aux_garc;

    if (arq == NULL){
        printf("\nProblemas ao adicionar registro de garcom!");
        return 1;
    }
    else{
        fflush(stdin);
        printf("\nDigite o nome do garcom: ");
        scanf("%[^\n]s", &aux_garc.nome);
        fflush(stdin);
        printf("Digite o codigo do garcom novo: ");
        scanf("%d", &aux_garc.codigo_garcom);
        fwrite(&aux_garc, sizeof(aux_garc), 1, arq);
        printf("\nGarcom adicionado ao restaurante!");
    }
    fclose(arq);
}

void adicionar_prato(){
    FILE *arq = fopen("Cardapio.txt", "ab+");
    Cardapio aux_prato;

    if (arq == NULL){
        printf("\nProblemas ao adicionar registro de prato!");
        return 1;
    }
    else{
        fflush(stdin);
        printf("\nDigite o nome do prato novo: ");
        scanf("%[^\n]s", &aux_prato.nome);
        fflush(stdin);
        printf("Digite o codigo do prato novo: ");
        scanf("%d", &aux_prato.codigo_item);
        printf("Digite o preco do prato novo: ");
        scanf("%f", &aux_prato.preco);
        fwrite(&aux_prato, sizeof(aux_prato), 1, arq);
        printf("\nPrato adicionado ao restaurante!");
    }
    fclose(arq);
}

void sair(){
    return 1;
}

int main(){
    padrao();  
}
