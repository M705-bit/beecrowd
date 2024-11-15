/* não terminei o exercício, falta separa por tamanho. */

#include <stdio.h>
#include <string.h>

// Definição da estrutura Camiseta
typedef struct {
    char nome[100];
    char cor[10]; 
    char tamanho[10];
} Camiseta;

// Função para trocar o conteúdo de dois elementos de um array de camisetas
void swap(Camiseta *camisetas, int a, int b) {
    Camiseta temp;
    strcpy(temp.nome, camisetas[a].nome);
    strcpy(camisetas[a].nome, camisetas[b].nome);
    strcpy(camisetas[b].nome, temp.nome);
}

// Função de ordenação insertion sort para ordenar as camisetas por nome
void insertionSort(Camiseta camisetas[], int nmr_de_camisetas) {
    for (int i = 1; i < nmr_de_camisetas; ++i) {
        int j = i, k = j - 1;
        while (k > -1 && strcmp(camisetas[j].nome, camisetas[k].nome) < 0) {
            swap(camisetas, j, k);
            --j, --k;
        }
    }
}

int main() {
    int N;
    
    // Recebendo o número de camisetas do usuário
    scanf("%d", &N);

    // Criando um array de camisetas
    Camiseta camisetas[N];

    // Recebendo os nomes, cores e tamanhos das camisetas do usuário
    for (int i = 0; i < N; ++i) {
        scanf(" %[^\n]", camisetas[i].nome);
        scanf("%s %s", camisetas[i].cor, camisetas[i].tamanho);
    }

    // Ordenando as camisetas por nome
    insertionSort(camisetas, N);

    // Imprimindo as camisetas ordenadas
    printf("Camisetas ordenadas por nome:\n");
    for (int i = 0; i < N; ++i) {
        printf("%s\n", camisetas[i].nome);
    }

    // Criando arrays de camisetas vermelhas e brancas
    int tam_vermelhas = 0;
    Camiseta vermelhas[N]; // Corrigido: agora o tamanho do array é N
    int tam_brancas = 0;
    Camiseta brancas[N]; // Corrigido: agora o tamanho do array é N

    // Separando as camisetas por cor
    for (int i = 0; i < N; ++i) {
        if (strcmp(camisetas[i].cor, "vermelho") == 0) {
            strcpy(vermelhas[tam_vermelhas].nome, camisetas[i].nome);
            strcpy(vermelhas[tam_vermelhas].cor, camisetas[i].cor);
            strcpy(vermelhas[tam_vermelhas].tamanho, camisetas[i].tamanho);
            ++tam_vermelhas;
        } else if (strcmp(camisetas[i].cor, "branco") == 0) {
            strcpy(brancas[tam_brancas].nome, camisetas[i].nome);
            strcpy(brancas[tam_brancas].cor, camisetas[i].cor);
            strcpy(brancas[tam_brancas].tamanho, camisetas[i].tamanho);
            ++tam_brancas;
        }
    }

   // Imprimindo as camisetas separadas por cor e dps nome 
    for (int i = 0; i < tam_brancas; ++i) {
        printf("%s - %s - %s\n", brancas[i].nome, brancas[i].cor, brancas[i].tamanho);
    }

    for (int i = 0; i < tam_vermelhas; ++i) {
        printf("%s - %s - %s\n", vermelhas[i].nome, vermelhas[i].cor, vermelhas[i].tamanho);
    }
    return 0;
}
