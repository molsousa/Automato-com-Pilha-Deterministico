# AUTÔMATO COM PILHA DETERMINÍSTICO

## Esse algoritmo é capaz de reconhecer uma especificação de um autômato com pilha determinístico e verificar geração de palavras.

Este repositório contém um algoritmo que simula um autômato com pilha determinístico e verifica a geração de palavras. A estrutura do autômato foi feita utilizando registro. Para as transições também foram utilizados registros, porém a manipulação de pilha foi feita utilizando estrutura de lista encadeada baseada em pilha. O repositório também contém dois arquivos de texto para testar a implementação.

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
 
      ### **Exemplo de especificação:**
            Q=8
            F={q7}
            alfabeto_fita = {a,b,c,d}
            alfabeto_pilha = {X,Y}
            (q0,@,@) = (q1,$)
            (q1,a,@) = (q2,@)
            (q1,c,@) = (q4,YY)
            (q2,b,@) = (q3,X)
            (q3,a,@) = (q2,@)
            (q3,c,@) = (q4,YY)
            (q3,d,X) = (q6,@)
            (q4,c,@) = (q4,YY)
            (q4,d,Y) = (q5,@)
            (q5,d,Y) = (q5,@)
            (q5,d,X) = (q6,@)
            (q6,d,X) = (q6,@)
            (q6,@,$) = (q7,@)
