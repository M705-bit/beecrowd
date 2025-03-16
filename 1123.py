def bubble_sort(arr):
    swapped = True
    while swapped:
        swapped = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:  
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
    return arr  # Retorna a lista ordenada

def RegistraRotas(N, M, C, K, estrada):
    pedagio = []
    rota = 0
    for i in range(len(estrada)):
        if estrada[i][0] == K:
            pedagio.append(estrada[i][2])  # Adiciona um novo pedágio
            j = 0
            while j < len(estrada) and estrada[j][1] != C - 1:
                if estrada[j][0] == estrada[i][1]:
                    pedagio[rota] += estrada[j][2]
                    i = j
                j += 1
            rota += 1

    if pedagio:  # Evita erro caso a lista esteja vazia
        pedagio = bubble_sort(pedagio)
        return pedagio[0]
    return None  # Retorna None se não houver rota válida

N, M, C, K = map(int, input().split())
while (N + M + C + K) != 0:
    estrada = []
    for _ in range(M):  
        u, v, p = map(int, input().split())  
        estrada.append((u, v, p))  

    print(RegistraRotas(N, M, C, K, estrada))

    N, M, C, K = map(int, input().split())  # Atualiza os valores para evitar loop infinito

