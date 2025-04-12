# AUTÔMATO COM PILHA DETERMINÍSTICO

## Esse algoritmo é capaz de reconhecer uma especificação de um autômato com pilha determinístico e verificar geração de palavras.

### O formato da especificação deve ser feito da seguinte forma:

- 1ª linha: Q=ɑ -> Q representa numeros de estados.
- 2ª linha: F={qɣ,qθ,...,qm} -> F representa estados finais.
- 3ª linha: alfabeto_fita = {a,b,...,z} -> alfabeto que pode ser lido pelo autômato (em minúsculo).
- 4ª linha: alfabeto_pilha = {A,B,...,Z} -> alfabeto pilha que pode ser empilhado pelo autômato (em maiúsculo).
- 5ª linha: (qɑ, x, X) = (qβ, Y) -> especificação para transição, onde:
    - qɑ -> estado atual.
    - x -> simbolo lido.
    - X -> simbolo desempilhado.
    - qβ -> proximo estado.
    - Y -> simbolo empilhado.
