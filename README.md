# AUTÔMATO COM PILHA DETERMINÍSTICO

## Esse algoritmo é capaz de reconhecer uma especificação de um autômato com pilha determinístico e verificar geração de palavras.

### O formato da especificação deve ser feito da seguinte forma:

- 1ª linha: Q=ɑ -> Q representa numeros de estados.
- 2ª linha: F={θ} -> F representa estados finais.
- 3ª linha: alfabeto_fita = {x, y, z} -> alfabeto que pode ser lido pelo autômato (em minúsculo).
- 4ª linha: alfabeto_pilha = {X, Y} -> alfabeto pilha que pode ser empilhado pelo autômato (em maiúsculo).
- 5ª linha: (qɑ, x, X) = (qβ, Y) -> especificação para transição, onde:
    - qɑ -> estado atual.
    - x -> simbolo lido.
    - X -> simbolo empilhado.
    - qβ -> proximo estado.
    - Y -> simbolo desempilhado.
