#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, i = 0, aux = 0, col;
    
     while(scanf("%d", &N) != EOF){
        if(!N)  break;
   
    // Aloca memória inicial para estacao
    int* estacao = malloc(1 * sizeof(int));
  
    // Enquanto receber dados, aumenta o tamanho de estacao conforme necessário
    while (scanf("%d", &aux)) {
        if (!aux) {
            printf("\n");
            break;
        }
        estacao[i] = aux;
        i++;
        estacao = realloc(estacao, (i + 1) * sizeof(int)); // realoca com tamanho atualizado
        
    }

    // Imprime as permutações
    int* pilhaA = malloc(i * sizeof(int));
    int* pilhaB = malloc(i * sizeof(int));

    if (pilhaA == NULL || pilhaB == NULL) {
        printf("Erro ao alocar memória.");
        return 1;
    }

    //Pilha A
    for (int x = 0; x < i; x++) {
        pilhaA[x] = x + 1;
    }


   //Pilha B
    for (int x = 0; x < i; x++) {
        pilhaB[x] = i - x;
    }
   

    // Compara estacao com pilhaA e pilhaB
    int resp = memcmp(estacao, pilhaB, i * sizeof(int));
    if (resp == 0) {
        printf("Yes\n");
    } else {
        resp = memcmp(estacao, pilhaA, i * sizeof(int));
        if (resp == 0) {
            printf("Yes\n");
        } else {
            printf("No");
        }
    }

    // Libera memória alocada
    free(estacao);
    free(pilhaA);
    free(pilhaB);
}
    return 0;
}

