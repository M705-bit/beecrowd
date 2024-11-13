/******************************************************************************
raju ganha um ponto a cada resposta correta e meena ganha a cada resposta errada de raju
casos teste < 65 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int comp(const int *a, const int *b){
    return *(int*)a - *(int*)b;
}
void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particao(int* V, int inicio, int fim){
    int pivo = V[fim - 1]; //última posição considerando o 0, por isso -1  
    int i = inicio; //primeira posção i=0
    for(int j = inicio; j < fim; ++j){
        if(comp(&V[j], &pivo) < 0){ //v[j] menor que o pivo  
            swap(&V[j], &V[i]); //posição inicial agr é v[j]
            i += 1; //i =1 
        }
    }
    if(comp(&pivo, &V[i]) < 0){
        swap(&V[i], &V[fim - 1]);
    }
    return i;
}

void quickSort(int* V, int inicio, int fim){
    if(fim > inicio){
        int posicaoPivo = particao(V, inicio, fim);
        quickSort(V, inicio, posicaoPivo);
        quickSort(V, posicaoPivo + 1, fim);
    }
}

int pesquisaBinaria(int *V, int n, int valor){
    int inicio = 0, fim = n;
;
    while(inicio < fim){
       int meio = (inicio + fim) / 2;

        int c = comp(&V[meio], &valor);
        if(c == 0){ //elementos de mesmo valor 
             printf("devolvendo %i", meio);
            return meio;
           
        }else if(c > 0){ //  meio maior que o valor 
            fim = meio; //descarta tds as posições posteriores ao meio 
        }else{  
            inicio = meio + 1; //descarta tds as posições anteriores  
        }
    }

    return -1;
}

int main()
{ 
    int marmore=0; //nmr de mármores 
    int consulta=0; //nmr de consultas de meena 
   int count=0; 
   int vet[count];  
   scanf("%d %d", &marmore, &consulta);
 printf("\n");
  for(int i; i<marmore; i++){
     int num;
      scanf("%d",&num);
    vet[count++] = num; 
  }
   size_t n = sizeof(vet)/sizeof(vet[0]); //infomei o tamanho de
  quickSort(vet, 0, n);
   printf("CASE %d\n", consulta); 
  for(int i=0; i<consulta; i++){
      //escreve o numeron que que consultar
      int valor=0; 
      scanf("%d", &valor); 
       int posicao=0;
       posicao = pesquisaBinaria(vet,n,valor); 
      if(posicao!=-1){
          printf("%d fount at %d", valor, posicao);
      }
      else{
          printf("%d not found", valor);
      }
}

    return 0;
}
