#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <locale>

using namespace std;

int main()
{
    ifstream inFile; // inFile Ã© o arquivo de leitura dos dados


    inFile.open("segredo.txt", ios::in); // abre o arquivo para leitura
        if (! inFile)
        { cerr << "Arquivo saida.txt nao pode ser aberto" << endl;
        return -1;
        }
    int i=0, m=0, *vet, n, l,*aux=nullptr;
    char letra;
    while(inFile.get(letra)){
        i++;
        // procura encontrar o maior intervalo entre 2 espaços ' ', este intervalo vai ser o meu número de linhas
       if(letra== ' '){
            vet= new int(1);

    vet[m]= (i-1)- (1*vet[m-1]+1);
    m++;
       }

        cout<<i<<" "<<letra<<" "<<(int)letra<<endl;

    }
// procura o maior número no vetor, este será o nmr de linhas

   //variável auxiliar, mas n tá apontando pra nada
for (n = 0; n < m; n++) {

    for(l = n+1; l < m; l++) {

           if(*(vet+n)>*(vet+l)){
            *aux= *(vet+n);
            *(vet+n)= *(vet+l);
            *(vet+l)= *aux;
           }
}}
cout <<"linhas " << *(vet+m)<< endl;
cout <<endl << i << " letras" <<endl;
 delete(vet);
    return 0;
}
