#include <iostream>
#include <cstdlib>
using namespace std;
/*Elabore uma função que identifique o maior valor em um vetor de inteiros.
parametros : vetor de dados
	        quantidade de elementos
retorno :      maior valor contido neste vetor
ordena de forma crescebte ou decrescebte 
identifica a quantidade de elementos; 

*/

enum VetOrdem_t  { V_CRESCE, V_DECRESCE};

void preenche(int *vec, int tam){
 int x; 
    for(x=0; x<tam; x++){
    vec[x]= rand() % 10; }
    
for(x=0; x<tam; x++){
 
    cout << " "<< *(vec+x)<< " ";
   
}
    cout << "\n" <<endl; 
}

void ordena(int *bec,int tam,int ordem){
  int x,j,*psc=NULL; 
    for(x=0; x<tam; x++){
        for(j=x+1; j<tam; j++){
        if(*(bec+x)>*(bec+j)){
            *psc = *(bec+x); 
            *(bec+x)= *(bec+j);
            *(bec+j)= *psc;
        }
    } 
     
    }
   cout << "maior valor " << *(bec+(tam-1)) <<endl; 
if(ordem==1){
    for(x=0; x<tam; x++){
        cout << " "<< *(bec+x)<< " "; 
}}
else{
   
    for(x=(tam-1); x>=0; x--){
       cout << " "<< *(bec+x)<< " ";
}
}
}
int main()
{ 
    int *vet, elementos, ord;
    
    cout << "entre com o nmr de elementos: "<<endl; 
    cin >> elementos;  
    cout<< "0 para decrescente e 1 para crescente: "<<endl; 
    cin>> ord; 
  vet= new int(elementos);
  preenche(vet, elementos); 
    ordena(vet, elementos, ord);
delete(vet); 
}
