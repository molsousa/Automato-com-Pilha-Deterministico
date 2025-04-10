# AUTÔMATO COM PILHA DETERMINÍSTICO

## Esse algoritmo é capaz de reconhecer uma especificação de um autômato com pilha determinístico e verificar geração de palavras.

### O formato da especificação deve ser feito da seguinte forma:

- 1ª linha: Q=n -> Q representa numeros de estados
- 2ª linha: F={n} -> F representa estados finais
- 3ª linha: alfabeto_fita = {x, y, z} -> alfabeto que pode ser lido pelo automato (em minusculo)
- 4ª linha: alfabeto_pilha = {X, Y} -> alfabeto pilha que pode ser empilhado pelo automato (em maiusculo)
- 5ª linha: (qn, x, X) = (qm, Y) -> especificação para transicao, onde:
    - qn -> estado atual
    - x -> simbolo lido
    - X -> simbolo empilhado
    - qm -> proximo estado
    - Y -> simbolo desempilhado
