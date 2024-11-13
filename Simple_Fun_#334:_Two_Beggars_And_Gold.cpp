/*DESCRIPTION:
The following problem was taken from https://www.onlinegdb.com/online_c_compiler but it is c++ language 
Task
In the field, two beggars A and B found some gold at the same time. They all wanted the gold, and they decided to use simple rules to distribute gold:

They divided gold into n piles and be in line. 
The amount of each pile and the order of piles all are randomly.

They took turns to take away a pile of gold from the 
far left or the far right.

They always choose the bigger pile. That is to say, 
if the left is 1, the right is 2, then choose to take 2.

If the both sides are equal, take the left pile.
Given an integer array golds, and assume that A always takes first. Please calculate the final amount of gold obtained by A and B. returns a two-element array [amount of A, amount of B].

Example
For golds = [4,2,9,5,2,7], the output should be [14,15].

The pile of most left is 4, 
The pile of most right is 7, 
A choose the largest one -- > take 7

The pile of most left is 4, 
The pile of most right is 2, 
B choose the largest one -- > take 4

The pile of most left is 2, 
The pile of most left is 2, 
A choose the most left one -- > take 2

The pile of most left is 9, 
The pile of most right is 2, 
B choose the largest one -- > take 9

The pile of most left is 5, 
The pile of most left is 2, 
A choose the largest one -- > take 5

Tehn, only 1 pile left, 
B  -- > take 2

A: 7 + 2 + 5 = 14
B: 4 + 9 + 2 = 15
For golds = [10,1000,2,1], the output should be [12,1001].

A take 10
B take 1000
A take 2
B take 1

A: 10 + 2 = 12
B: 1000 + 1 = 1001
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime> 
using namespace std;

array<int, 6> golds;
int n = sizeof(golds) / sizeof(golds[0]);

int compara_tamanho(int& left, int& right) {
    if (golds[right] > golds[left]) {
        int valor = golds[right];
        right--; // Atualiza o índice do lado direito
        return valor;
    } else {
        int valor = golds[left];
        left++; // Atualiza o índice do lado esquerdo
        return valor;
    }
}

int main() {
    int beggers[] = {0, 0};  
    srand(static_cast<unsigned int>(time(nullptr)));

    // Preenchendo gold com números aleatórios 
    for (int i = 0; i < n; i++) {
        golds[i] = rand() % 1000; // Esse número tem que ser diferente de 0 
        cout << golds[i] << endl; 
    }

    int left = 0;
    int right = n - 1;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // A sempre será o primeiro a pegar já que é par
            cout << "The pile of most left is " << golds[left] << endl;
            cout << "The pile of most right is " << golds[right] << endl;
            int valor = compara_tamanho(left, right);
            cout << "A choose the largest one --> take " << valor << endl;
            beggers[0] += valor;
        } else { // B sempre pega depois de A, pois é ímpar
            cout << "The pile of most left is " << golds[left] << endl;
            cout << "The pile of most right is " << golds[right] << endl;
            int valor = compara_tamanho(left, right);
            cout << "B choose the largest one --> take " << valor << endl;
            beggers[1] += valor;
        }
    }

    cout << "[amount of " << beggers[0] << ", amount of " << beggers[1] << "]";

    return 0;
}
