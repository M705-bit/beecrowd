/******************************************************************************
ideia: passar tudo isso para c++, dessa forma vpu poder utilizar copy constructor e colocar esse conhecimento em prática 
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int moradores; 
    int consumo; 
    int media; 
} cidade;

int main()
{  int tam; 
    cidade Cidade[tam];
   int N, num=1;
   
   while(scanf("%d", &N)!=EOF){
       if(!N) break; 
       for(int i=0; i<N; i++){
          scanf("%d %d", &Cidade[tam].moradores, &Cidade[tam].consumo); 
          Cidade[tam].media=  Cidade[tam].consumo/Cidade[tam].moradores;
       }
       
    // Declaração de aux como um array de ponteiros para cidade
    cidade *aux[tam];
    int m=0; 
     //bubble sort
    for(int i=0; i<tam; i++){
           for(int j=i+1; j<tam; i++){
            if (Cidade[j].media > Cidade[i].media)
             aux[m++] = &Cidade[i];
             else
            aux[m++] = &Cidade[j];
                         }
                     }
    int consumo_total=0, populacao=0;
    printf("Cidade# %d", num); 
    printf("\n"); 
    num++; 
    for(int i=0; i<N; i++){
    printf("%d-%d ", aux[i]->moradores, aux[i]->media); 
    consumo_total+= aux[i]->consumo;
    populacao+= aux[i]->moradores;
    }
    float media_total= consumo_total/populacao; 
    printf("\n"); 
    printf("Consumo medio: %2.f m3", media_total);
                 }

 
    return 0;
}
