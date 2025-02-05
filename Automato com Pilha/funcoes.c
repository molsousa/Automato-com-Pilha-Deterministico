#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Verificar condicao da pilha
// Entrada: ponteiro do tipo Pilha
// Retorno: 1 caso vazia, 0 caso esteja em uso
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
int vazia(Pilha *p)
{
    return (p->topo == NULL);
}

// Funcao para criacao de uma pilha vazia
// Entrada: nenhuma
// Retorno: retorna um ponteiro do tipo Pilha
// Pre-condicao: ponteiro do tipo pilha ja criado
// Pos-condicao: cria uma pilha com o topo inicialmente nulo
Pilha *criar_pilha_vazia()
{
    Pilha *aux = (Pilha*) malloc(sizeof(Pilha));
    aux->topo = NULL;

    return aux;
}

// Funcao para adicionar elemento na pilha
// Entrada: ponteiro do tipo Pilha e um caractere a ser empilhado
// Retorno: nenhum
// Pre-condicao: pilha criada e um elemento do usuario
// Pos-condicao: retorna com um valor empilhado
void push(Pilha *p, char x)
{
    struct no *aux = (struct no*) malloc(sizeof(struct no));

    aux->elemento = x;
    aux->prox = p->topo;

    p->topo = aux;
}

// Funcao para remover elemento na pilha
// Entrada: ponteiro do tipo Pilha e um caractere a ser desempilhado
// Retorno: nulo caso nao consiga desempilhar, retorna o caractere caso desempilhado
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
char *pop(Pilha *p, char c)
{
    if (!vazia(p)) {
        char *x = (char*) malloc(sizeof(char));
        struct no *aux = p->topo;

        if(c == aux->elemento){
            *x = aux->elemento;
            p->topo = aux->prox;

            free(aux);

            return x;
        }
        return NULL;
    }
    return NULL;
}

// Funcao para impressao da pilha
// Entrada: ponteiro do tipo Pilha
// Retorno: nenhum
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
void imprimir_pilha(Pilha *p)
{
    struct no* aux;

    if(p->topo == NULL){
        printf(" ");
        return;
    }

    for(aux = p->topo; aux != NULL; aux = aux->prox)
        printf("%c", aux->elemento);
}

// Funcao para limpar a entrada do usuario
// Entrada: nenhuma
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void limpar_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
