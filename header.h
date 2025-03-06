#ifndef APD_H_
#define APD_H_

// cabecalho para funcoes de pilha, estruturas e limpar buffer

// Estrutura de lista para pilha dinamica
struct no{
    char elemento;
    struct no *prox;
};

// Estrutura da pilha
typedef struct{
    struct no *topo;
}Pilha;

// Estrutura para as transicoes
typedef struct{
    int estado_atual;
    char simbolo;
    char desempilha[10];
    int proximo_estado;
    char pilha[10];
}Transicao;

// Estrutura para o automato
typedef struct{
    int estados_finais[10];
    char alfabeto_fita[10];
    char alfabeto_pilha[10];
    Transicao *transicoes;
    int num_transicoes;
}Automato;

// Verificar condicao da pilha
// Entrada: ponteiro do tipo Pilha
// Retorno: 1 caso vazia, 0 caso esteja em uso
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
int vazia(Pilha *p);

// Funcao para criacao de uma pilha vazia
// Entrada: nenhuma
// Retorno: retorna um ponteiro do tipo Pilha
// Pre-condicao: ponteiro do tipo pilha ja criado
// Pos-condicao: cria uma pilha com o topo inicialmente nulo
Pilha *criar_pilha_vazia();

// Funcao para adicionar elemento na pilha
// Entrada: ponteiro do tipo Pilha e um caractere a ser empilhado
// Retorno: nenhum
// Pre-condicao: pilha criada e um elemento do usuario
// Pos-condicao: retorna com um valor empilhado
void push(Pilha *p, char x);

// Funcao para remover elemento na pilha
// Entrada: ponteiro do tipo Pilha e um caractere a ser desempilhado
// Retorno: nulo caso nao consiga desempilhar, retorna o caractere caso desempilhado
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
char *pop(Pilha *p, char c);

// Funcao para impressao da pilha
// Entrada: ponteiro do tipo Pilha
// Retorno: nenhum
// Pre-condicao: pilha criada
// Pos-condicao: nenhuma
void imprimir_pilha(Pilha *p);

// Funcao para limpar a entrada do usuario
// Entrada: nenhuma
// Retorno: nenhum
// Pre-condicao: nenhuma
// Pos-condicao: nenhuma
void limpar_buffer();

#endif // APD_H_
