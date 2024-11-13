/*A princípio funciona, mas há um erro "timeout: the monitored command dumped core", não sei a origem do erro, então por enquanto vai ficar por isso mesmo
Problema 2929 "Menor da Pilha" do beecrowd link: https://www.beecrowd.com.br/judge/pt/problems/view/2929*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pilhaNo {
    int valor;
    struct pilhaNo* abaixo;
};

struct pilha {
    int tamanho;
    struct pilhaNo* topo;
};

void push(struct pilha* p, int valor) {
    p->tamanho += 1;
    struct pilhaNo* novoTopo = (struct pilhaNo*)malloc(sizeof(struct pilhaNo));
    novoTopo->valor = valor;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void pop(struct pilha* p) {
    if (p->tamanho > 0) {
        p->tamanho -= 1;
        struct pilhaNo* velhoTopo = p->topo;
        p->topo = velhoTopo->abaixo;
        free(velhoTopo);
    }
}

int top(struct pilha* p) {
    return p->topo->valor;
}

void liberar_pilha(struct pilha* p) {
    while (p->topo != NULL) {
        pop(p);
    }
    free(p);
}

int main() {
    struct pilha* p = (struct pilha*)malloc(sizeof(struct pilha));
    p->tamanho = 0;
    p->topo = NULL;

    int tam, numero;
    char myWord[100];
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++) {
        scanf("%s", myWord);

        if (strcmp(myWord, "PUSH") == 0) {
            scanf("%d", &numero);
             if (p->topo == NULL || p->topo->valor > numero) {
            push(p, numero);
            }
            else{
                push(p, p->topo->valor);
            }
        } else if (strcmp(myWord, "POP") == 0) {
            if(p->tamanho==0){
                printf("EMPTY"); 
            }
            else{pop(p);}
            
        } else if (strcmp(myWord, "MIN") == 0) {
            int top1 = top(p);
            printf("%d\n", top1);
        }
    }

    // Liberar memória da pilha
    liberar_pilha(p);

    return 0;
}
