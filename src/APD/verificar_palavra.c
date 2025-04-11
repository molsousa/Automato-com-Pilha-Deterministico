#include "../header.h"
#include "verificar_palavra_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao para verificar palavra inserida
// Entrada: variavel do tipo Automato
// Retorno: nenhum
// Pre-condicao: especificacao do automato lida
// Pos-condicao: nenhuma
void verificar_palavra(Automato automato)
{
    printf("Insira a palavra: ");

    char *entrada = inserir_entrada();
    Pilha *pilha = criar_pilha_vazia();
    int i, estado_atual = 0, flag = 0;

    // imprime antes de qualquer transicao
    imprimir_estado(entrada, 0, estado_atual, pilha);

    // inicializa a pilha com '$' se necessario
    if(*automato.transicoes->pilha == '$' && automato.transicoes->simbolo == '@'){
        push(pilha, '$');
        estado_atual = automato.transicoes->proximo_estado;
        flag = 1;
    }

    // imprime o estado inicial
    if(flag)
        imprimir_estado(entrada, 0, estado_atual, pilha);

    flag = 0;

    // processa a entrada
    for(i = 0; entrada[i] != '\0'; i++){
        int transicao_encontrada = 0;

        // tenta aplicar uma transicao para o simbolo atual
        int novo_estado;
        if(aplicar_transicao(&automato, pilha, estado_atual, entrada[i], &novo_estado)){
            estado_atual = novo_estado;
            transicao_encontrada = 1;

            // imprime o estado atual apos a transicao
            imprimir_estado(entrada, i+1, estado_atual, pilha);
        }

        // se nenhuma transicao for encontrada, rejeita a palavra
        if(!transicao_encontrada){
            printf("REJEITADA\n");
            free(entrada);
            return;
        }
    }

    // verifica se e possivel desempilhar '$' sem ler simbolo
    for(i = 0; i < automato.num_transicoes; i++){
        if (automato.transicoes[i].estado_atual == estado_atual &&
            automato.transicoes[i].simbolo == '@' &&
            *automato.transicoes[i].desempilha == '$'){

            if(pop(pilha, '$') == NULL){
                printf("REJEITADA\n");
                free(entrada);
                return;
            }

            estado_atual = automato.transicoes[i].proximo_estado;

            imprimir_estado(entrada, strlen(entrada), estado_atual, pilha);
            break;
        }
    }

    for(i = 0; automato.estados_finais[i] != -1; i++){
        // verifica se o automato atingiu um estado final e a pilha esta vazia
        if(estado_atual == automato.estados_finais[i] && vazia(pilha))
            flag = 1;
    }

    if(flag)
        printf("ACEITA\n");
    else
        printf("REJEITADA\n");

    free(entrada);
}

// Funcao para inserir a entrada do usuario
// Entrada: nenhuma
// Retorno: ponteiro de caractere
// Pre-condicao: nenhuma
// Pos-condicao: retorna um ponteiro de caractere
char *inserir_entrada()
{
    char *entrada = NULL;
    int n = 1;
    char c;

    while((c = getchar()) != '\n' && c != EOF){
        entrada = (char*) realloc(entrada, n*sizeof(char));
        if(entrada == NULL){
            printf("Nao foi possivel alocar memoria!\n");
            exit(1);
        }
        entrada[n-1] = c;
        n++;
    }

    entrada = (char*) realloc(entrada, n*sizeof(char));
    if(entrada == NULL){
        printf("Nao foi possivel alocar memoria!\n");
        exit(1);
    }
    entrada[n-1] = '\0';

    return entrada;
}

// Funcao para aplicar a transicao
// Entrada: variaval do tipo Automato, variavel do tipo Pilha, estado atual, simbolo lido, proximo estado
// Retorno: 1 para transicao lida, 0 para caso nao encontre transicao possivel
// Pre-condicao: automato carregado
// Pos-condicao: retorna sucesso ou erro na transicao
int aplicar_transicao(Automato *automato, Pilha *pilha, int estado_atual, char simbolo, int *novo_estado)
{
    int i, j;

    for(i = 0; i < automato->num_transicoes; i++){
        if(automato->transicoes[i].estado_atual == estado_atual &&
            (automato->transicoes[i].simbolo == simbolo || automato->transicoes[i].simbolo == '@')){

            // verifica se o topo da pilha e compativel com a transicao
            if(*automato->transicoes[i].desempilha == '@' ||
                (!vazia(pilha) && pilha->topo->elemento == automato->transicoes[i].desempilha[0])){
                // desempilha os elementos
                if(*automato->transicoes[i].desempilha != '@') {
                    for(j = 0; automato->transicoes[i].desempilha[j] != '\0'; j++){
                        if(pop(pilha, automato->transicoes[i].desempilha[j]) == NULL){
                            return 0; // erro ao desempilhar
                        }
                    }
                }

                // empilha os novos elementos
                if(*automato->transicoes[i].pilha != '@'){
                    for(j = 0; automato->transicoes[i].pilha[j] != '\0'; j++){
                        push(pilha, automato->transicoes[i].pilha[j]);
                    }
                }

                // atualiza o estado atual
                *novo_estado = automato->transicoes[i].proximo_estado;
                return 1; // transicao aplicada
            }
        }
    }
    return 0; // nenhuma transico valida encontrada
}

// Funcao para impressao do estado
// Entrada: entrada do usuario, posicao atual na string, estado atual, variavel do tipo Pilha
// Retorno: nenhum
// Pre-condicao: automato carregado e palavra inserida
// Pos-condicao: nenhuma
void imprimir_estado(const char *entrada, int posicao, int estado_atual, Pilha *pilha)
{
    printf("fita: %.*s[q%d]%s pilha: ", posicao, entrada, estado_atual, entrada+posicao);
    imprimir_pilha(pilha);
    printf("\n");
}
