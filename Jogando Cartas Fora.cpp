#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> cartas; //declarando deque caras 
    int N;

    while(cin >> N){ //enquanto cin recebe n 
        if (!N) break; // se n==0 break 

        for(int i = 1; i <= N; ++i){
            cartas.push_back(i); //vai adicionando no vetor 
        }

        bool first = true;
        cout << "Discarded cards: ";
        while(cartas.size() > 1){ //enquanto no deque cartas eu tiver mais de 1 
            int topo = cartas.front(); //o topo é o primeiro elementto do deque 
            cartas.pop_front(); // função para deletar primeiro elemento, diminui o size by one pq
            if (first)  first = false;
            else        cout << ", ";
            cout << topo;
            topo = cartas.front();
            cartas.pop_front();
            cartas.push_back(topo);
        }
        cout << endl;

        cout << "Remaining card: " << cartas.front() << endl;
        cartas.pop_front();
    }

    return 0;
}
