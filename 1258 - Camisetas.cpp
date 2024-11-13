//ainda estou trabalhando nesse, retorno a noite
#include <iostream>
#include <string>
using namespace std;


typedef struct {
    string nome; 
    char cor[20];
    char tamanho; // Correção do tipo para representar o tamanho da camiseta
} Camiseta;

int main() {
    int N;
   
    
    while(cin>>N){
    cin >> N; 
    Camiseta camisetas[N];
    
    for (int i = 0; i < N; i++) {
        getline(cin, camisetas[i].nome);
        cin >> camisetas[i].cor >> camisetas[i].tamanho;
    }
     for (int i = 0; i < N; i++) {
        cout << camisetas[i].nome; 
        cout << "\n"; 
        cout << camisetas[i].cor; 
        cout << " " << camisetas[i].tamanho; 
    }
}
   

    return 0;
}
