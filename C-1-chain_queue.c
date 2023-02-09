/*Exercício - 1
Fila encadeada
Imagine uma pista de decolagem e implemente um software que controle a chegada e decolagem destes aviões.
Um avião é representado por duas informações: um código e pela empresa aérea que é dona do mesmo.
O software deve utilizar uma estrutura de dados denominada Fila para implementar esse controle, apresentando um menu que permita:
1) a decolagem de um avião.
2) a chegada de um avião na pista.
3) a informação de quantos aviões estão na pista.*/

#include <stdlib.h>
#include <stdio.h>

struct Aviao{
    int codigoAviao;
    int codigoEmpresa;
    struct Aviao *anterior;
    struct Aviao *proximo;
};
typedef struct Aviao Aviao;

struct Pista{
    Aviao* posPrimeiroAviao;
    Aviao* posUltimoAviao;
    int qtAvioes;
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
Pista *novaPista(){
    Pista *nova;
    nova = (Pista *)malloc(sizeof(Pista));

    nova->posPrimeiroAviao = NULL;
    nova->posUltimoAviao = NULL;
    nova->qtAvioes = 0;

    return nova;
}

Pista* aterrissar(Pista *pista){
    printf("\nAterrissagem autorizada");
    Aviao *novo = novoAviao();

    if(pista){
        printf(
            "\nAviao: %d\tCompanhia: %d aterrisando",
            novo->codigoAviao,
            novo->codigoEmpresa
        );
        if(pista->posPrimeiroAviao == NULL){
            pista->posPrimeiroAviao = novo;
            novo->anterior = NULL;

        } else {
            pista->posUltimoAviao->proximo = novo;
            novo->anterior = pista->posUltimoAviao;

        }

        pista->posUltimoAviao = novo;
        novo->proximo = NULL;
        pista->qtAvioes++;
        printf("\nAterrissagem Realizada com sucesso");

    } else {
        printf("\nAterrissagem Não Permitida");
    }

    return pista;
}
Pista *decolar(Pista *pista){
    if(pista->posPrimeiroAviao){
        printf("\nDecolagem autorizada");
        Aviao *decolando = pista->posPrimeiroAviao;
        printf(
            "\nAviao: %d\tCompanhia: %d decolando",
            decolando->codigoAviao,
            decolando->codigoEmpresa
        );
        if(decolando == pista->posUltimoAviao){
            printf("\nUltimo");
            free(pista);
            pista = novaPista();

        } else {
            pista->posPrimeiroAviao = pista->posPrimeiroAviao->proximo;
            pista->posPrimeiroAviao->anterior = NULL;
            pista->qtAvioes--;
        }
        free(decolando);
        printf("\nDecolagem Realizada com sucesso");
    } else {
        printf("\nNenhum aviao na pista para decolagem");
    }
    return pista;
}
void lotacaoPista(Pista *pista){
    printf("\nLotacao da pista:");
    Aviao *pAux = pista->posPrimeiroAviao;
    int i = 1;
    if(pista->qtAvioes>0){
        printf("\n%d Avioes na pista:", pista->qtAvioes);
        while(pAux != NULL){
            printf(
                "\n-Posicao %d:\tAviao: %d\tCompanhia: %d",
                i,
                pAux->codigoAviao,
                pAux->codigoEmpresa
            );
            i++;
            pAux = pAux->proximo;
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
    /*Testes
    Pista *pista = novaPista();
    printf("\n%u, %u, %d",
        pista->posPrimeiroAviao,
        pista->posUltimoAviao,
        pista->qtAvioes
    );
    pista = aterrissar(pista);
    pista = aterrissar(pista);
    lotacaoPista(pista);

    pista = decolar(pista);
    pista = decolar(pista);
    lotacaoPista(pista); */

    //Funcionalidades
    Pista *pista = novaPista();
    gerenciadorDePista(pista);
    
    return 0;
}