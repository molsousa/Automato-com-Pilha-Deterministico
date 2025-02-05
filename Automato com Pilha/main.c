#include "header.h"
#include "carregar_palavra_header.h"
#include "verificar_palavra_header.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Automato automato;
    int opcao;

    system("color F");

    do{
        printf("----------Automato-com-Pilha----------\n");
        printf("|\t1 - Carregar arquivo         |\n");
        printf("|\t2 - Verificar palavra        |\n");
        printf("|\t0 - Sair                     |\n");
        printf("--------------------------------------\n");
        printf("Insira: ");
        scanf("%d", &opcao);

        system("cls");

        switch(opcao){
        case 1:
            limpar_buffer();
            carregar_palavra(&automato);
            break;
        case 2:
            limpar_buffer();
            verificar_palavra(automato);
            break;
        case 0:
            printf("Obrigado!!\n");
            break;
        default:
            printf("Opcao invalida, tente novamente\n");
        }
    }while(opcao != 0);

    return 0;
}
