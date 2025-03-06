#include "header.h"
#include "carregar_palavra_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao para carregar o arquivo e armazenar as especificacoes
// Entrada: ponteiro do tipo Automato
// Retorno: nenhum
// Pre-condicao: arquivo .txt com especificacao do automato
// Pos-condicao: nenhuma
void carregar_palavra(Automato *automato)
{
    FILE *arquivo;
    char input[26];
    char linha[100];
    char aux[4][30], *c = (char*) malloc(30*sizeof(char));
    int i = 0, j = 0, flag = 0;

    printf("Digite o nome do arquivo: ");
    fgets(input, 26, stdin);
    strtok(input, "\n");

    arquivo = fopen(input, "r");
    if(!arquivo){
        printf("Nao foi possivel ler o arquivo!\n");
        exit(1);
    }

    automato->num_transicoes = 0; // inicializar o automato
    automato->transicoes = NULL;
    *automato->estados_finais = 0;

    while(i < 4){
        fgets(*(aux+i), 30, arquivo);
        i++;
    }
    strcpy(c, *aux);
    while(*(c) < '0' || *(c) > '9')
        c++;

    i = 0;
    while(aux[1][i] != '\0'){
        if( aux[1][i] >= '0' && aux[1][i] < *c ){ // leitura de estados finais
            *(automato->estados_finais+j) = (int)aux[1][i] - 48;
            j++;
        }
        i++;
    }

    *(automato->estados_finais+j) = -1; // finalizar estados finais

    rewind(arquivo);

    while(fgets(linha, sizeof(linha), arquivo)){ // contar transicoes validas
        if(linha[0] == '(' && linha[1] == 'q'){
            automato->num_transicoes++;
        }
    }
    rewind(arquivo);

    i = 0; j = 0;
    while(aux[2][i] != '\0'){
        if(aux[2][i] == '=')
            flag = 1;
        if(flag){ // leitura dos simbolos de fita (minusculos)
            if(aux[2][i] >= 'a' && aux[2][i] <= 'z'){
                automato->alfabeto_fita[j] = aux[2][i];
                j++;
            }
        }
        i++;
    }

    i = 0; j = 0;
    while(aux[3][i] != '\0'){
        if(aux[3][i] == '=')
            flag = 1;
        if(flag){ // leitura dos simbolos de pilha (maiusculos)
            if(aux[3][i] >= 'A' && aux[3][i] <= 'Z'){
                automato->alfabeto_pilha[j] = aux[3][i];
                j++;
            }
        }
        i++;
    }

    for (i = 0; i < 3; i++) { // comecar pelas transicoes
        fgets(linha, sizeof(linha), arquivo);
    }

    automato->transicoes = (Transicao *) malloc(automato->num_transicoes * sizeof(Transicao)); // alocar memoria para transicoes

    i = 0;
    while(fgets(linha, sizeof(linha), arquivo)){ // ler transicoes
        if(linha[0] == '(' && linha[1] == 'q'){ // verifica se e uma transicao valida
            sscanf(linha, "(q%d,%c,%[^)]) = (q%d,%[^)])", &automato->transicoes[i].estado_atual, &automato->transicoes[i].simbolo,
                   automato->transicoes[i].desempilha, &automato->transicoes[i].proximo_estado, automato->transicoes[i].pilha);
            i++;
        }
    }

    fclose(arquivo);

    if(!automato->transicoes || !automato->num_transicoes || *automato->estados_finais == -1){
        printf("Automato nao carregado!!\n");
        return;
    }

    printf("Automato carregado!!\n");
}
