/*Exercício - 0
Fila sequencial
Imagine uma pista de decolagem e implemente um software que controle a chegada e decolagem destes aviões.
Um avião é representado por duas informações: um código e pela empresa aérea que é dona do mesmo.
O software deve utilizar uma estrutura de dados denominada Fila para implementar esse controle, apresentando um menu que permita:
1) a decolagem de um avião.
2) a chegada de um avião na pista.
3) a informação de quantos aviões estão na pista.*/

#include <stdlib.h>
#include <stdio.h>

#define TAM 5

struct Aviao{
    int codigoAviao;
    int codigoEmpresa;
};
typedef struct Aviao Aviao;

struct Pista{
    int posPrimeiroAviao;
    int posUltimoAviao;
    int qtAvioes;
    Aviao* fila[TAM];
};
typedef struct Pista Pista;

Aviao *novoAviao(){
    Aviao *novo;
    novo = (Aviao *)malloc(sizeof(Aviao));

    printf("\nEntre com os dados do aviao:");

    printf("\nCodigo do Aviao: ");
    scanf("%d", &novo->codigoAviao);
    fflush(stdin);

    printf("\nCodigo da Empresa: ");
    scanf("%d", &novo->codigoEmpresa);
    fflush(stdin);

    return novo;
}
Pista* novaPista(){
    Pista *nova;
    nova = (Pista *)malloc(sizeof(Pista));

    nova->posPrimeiroAviao = 0;
    nova->posUltimoAviao = 0;
    nova->qtAvioes = 0;

    return nova;
}
int statusPista(Pista *pista, int operacao){

    switch (operacao){
    case 1: //decolar
        if(pista->qtAvioes > 0){
            return 1; //liberado
        }
        break;
    case 2: //aterrissar
        if(pista->posUltimoAviao < TAM){
            return 1; //liberado
        }
        break;
    default: //não definido
        return -1;
        break;
    }
    return 0; //não liberado
}
void decolar(Pista *pista){
    if(statusPista(pista, 1) == 1){
        printf("\nDecolagem autorizada");
        printf(
            "\nAviao: %d\tCompanhia: %d decolando",
            pista->fila[pista->posPrimeiroAviao]->codigoAviao,
            pista->fila[pista->posPrimeiroAviao]->codigoEmpresa
        );
        for(int i = 0; i < pista->qtAvioes; i++){
            if(pista->fila[i+1]){
                pista->fila[i] = pista->fila[i+1];
            }
        }
        pista->posUltimoAviao--;
        pista->qtAvioes--;
        printf("\nDecolagem Realizada com sucesso");
    } else {
        printf("\nNenhum aviao na pista para decolagem");
    }
}
void aterrissar(Pista *pista){
    if(statusPista(pista, 2) == 1){
        printf("\nAterrissagem autorizada");
        pista->fila[pista->posUltimoAviao] = novoAviao();
        printf(
            "\nAviao: %d\tCompanhia: %d aterrisando",
            pista->fila[pista->posUltimoAviao]->codigoAviao,
            pista->fila[pista->posUltimoAviao]->codigoEmpresa
        );
        pista->posUltimoAviao++;
        pista->qtAvioes++;
        printf("\nAterrissagem Realizada com sucesso");
    } else {
        printf("\nAterrissagem nao autorizada, pista cheia");
    }
}
void lotacaoPista(Pista *pista){
    printf("\nLotacao da pista:");
    if(pista->qtAvioes>0){
        printf("\n%d Avioes na pista:", pista->qtAvioes);
        for(int i = 0; i < pista->qtAvioes; i++){
            printf(
                "\n-Posicao %d:\tAviao: %d\tCompanhia: %d",
                i,
                pista->fila[i]->codigoAviao,
                pista->fila[i]->codigoEmpresa
            );
        }
    } else {
        printf("\nPista vazia");
    }
}

void gerenciadorDePista(Pista *pista){
    int opcao = 0;
    int continuar = 1;
    do{
    printf("\nDigite a opcao desejada:\n\t1-Decolagem\n\t2-Aterrissagem\n\t3-Lotacao da Pista\nOpcao: ");
    scanf("%d", &opcao);
    fflush(stdin);
    switch (opcao){
    case 1:
        decolar(pista);
        break;
    case 2:
        aterrissar(pista);
        break;
    case 3:
        lotacaoPista(pista);
        break;    
    default:
        break;
    }
    printf("\nDeseja realizar mais alguma operacao?\n\t1-Sim\n\t2-Nao\nOpcao: ");
    scanf("%d",&continuar);
    fflush(stdin);

    } while(continuar == 1);
}
int main(){
    printf("Programa");
    /*Teste novo aviao
    Aviao *aviao1 = novoAviao();
    printf("\n%d",aviao1->codigoAviao);
    printf("\n%d",aviao1->codigoEmpresa);
    */
    /*Teste pista e Status
    Pista *pista = novaPista();
    pista->posPrimeiroAviao = 2;
    pista->posUltimoAviao = 2;
    printf("\n%d", statusPista(pista, 1));
    */
    /*Teste aterrissagem e decolagem
    Pista *pista = novaPista();
    aterrissar(pista);
    decolar(pista);
    */
    /*Teste lotacao pista
    Pista *pista = novaPista();
    aterrissar(pista);
    lotacaoPista(pista);
    */
    //Funcionalidades
    Pista *pista = novaPista();
    gerenciadorDePista(pista);
    return 0;
}