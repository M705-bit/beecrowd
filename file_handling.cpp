#include <iostream>
#include <fstream>
#include <string>//muito importante para ler o arquivo 
using namespace std; //n sei o que é isso 

int main()
{
    fstream myFile; 
    /*
    //como escrever em um arquivo
    myFile.open("Nomedoarquivo.txt",ios::out);
    if(myFile.is_open()){
        myFile <<"Hello\n"; 
        myFile<<"This is second line\n"; 
        myFile.close();
    }
    //para adicionar mais informações precisamos usar o append mode, modo de anexação
     myFile.open("Nomedoarquivo.txt",ios::app); 
    if(myFile.is_open()){
        myFile <<"This information was appended\n"; 
        myFile.close();
    }
*/
//agora iremos aprender como ler um arquivo: 
  myFile.open("Nomedoarquivo.txt",ios::in);
    if(myFile.is_open()){
       string line; 
       while(getline(myFile,line)){
           cout<<line <<endl; 
       }
        myFile.close();
    }
    return 0;
}
