import sys

INT_MAX = sys.maxsize

def shortest_path_algorithm(arr, N):
   k=1
   for k in range(1,N+1):
        for i in range(1,N+1):
            for j in range(1,N+1):
                if arr[i][j]>(arr[i][k]+arr[k][j]):
                    arr[i][j] = arr[i][k]+arr[k][j]
                
   return arr

def main():
    N, E = input().split(' ')
    N = int(N)
    E = int(E)

    #preciso inicializar a matriz 
    arr = [[INT_MAX for _ in range(N+1)] for _ in range(N+1)]
    #[[print(f"{arr[i][j]}", end=' ') for j in range(5)] and print() for i in range(5)]

    for i in range(E):
        X,Y,H = map(int, input().split(' '))
        arr[X][Y] = H

    for i in range(N):
        for j in range(i, N):
            if arr[i][j] != INT_MAX and arr[j][i]!=INT_MAX:
                arr[i][j] = 0
                arr[j][i] = 0
    arr=shortest_path_algorithm(arr,N)

    # o K é para consultas
    K = int(input())
    i = 0
    while i < K:
        O,D = map(int, input().split(' '))
        if 1 <= O <= N and 1 <= D <= N:
            i += 1
        else:
            print("Números inválidos")
            continue

        if arr[O][D] == INT_MAX:
            print("Não é possível entregar a carta")
        else:
            print(arr[O][D])
main()
'''
O problema envolve cidades conectadas por estradas, e cada estrada tem um tempo de viagem, o objetivo é descobrir o menor tempo possível para ir de uma cidade a outra.
'''



