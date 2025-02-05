#ifndef VERIFICAR_PALAVRA_H_
#define VERIFICAR_PALAVRA_H_

// Cabecalho para funcoes de verificacao de palavra

// Funcao para verificar palavra inserida
// Entrada: variavel do tipo Automato
// Retorno: nenhum
// Pre-condicao: especificacao do automato lida
// Pos-condicao: nenhuma
void verificar_palavra(Automato automato);

// Funcao para inserir a entrada do usuario
// Entrada: nenhuma
// Retorno: ponteiro de caractere
// Pre-condicao: nenhuma
// Pos-condicao: retorna um ponteiro de caractere
char *inserir_entrada();

// Funcao para aplicar a transicao
// Entrada: variaval do tipo Automato, variavel do tipo Pilha, estado atual, simbolo lido, proximo estado
// Retorno: 1 para transicao lida, 0 para caso nao encontre transicao possivel
// Pre-condicao: automato carregado
// Pos-condicao: retorna sucesso ou erro na transicao
int aplicar_transicao(Automato *automato, Pilha *pilha, int estado_atual, char simbolo, int *novo_estado);

// Funcao para impressao do estado
// Entrada: entrada do usuario, posicao atual na string, estado atual, variavel do tipo Pilha
// Retorno: nenhum
// Pre-condicao: automato carregado e palavra inserida
// Pos-condicao: nenhuma
void imprimir_estado(const char *entrada, int posicao, int estado_atual, Pilha *pilha);

#endif // VERIFICAR_PALAVRA_H_
