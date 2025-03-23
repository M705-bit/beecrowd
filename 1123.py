import heapq

def dijkstra(N, C, K, adj):
    INF = float('inf')
    dist = [INF] * N
    dist[K] = 0
    pq = [(0, K)]  # Fila de prioridade (custo, cidade)
    
    while pq:
        custo, u = heapq.heappop(pq)  # Retira o nó com menor custo
        
        if custo > dist[u]:
            continue
        
        for v, p in adj[u]:
            if u < C and v != u + 1:  # Se estiver na rota de serviço, deve seguir a rota
                continue
            
            if dist[u] + p < dist[v]:  # Relaxamento
                dist[v] = dist[u] + p
                heapq.heappush(pq, (dist[v], v))
    
    return dist[C - 1]  # Retorna o menor custo para a cidade destino

def RegistraRotas(N, M, C, K, estradas):
    adj = [[] for _ in range(N)]
    
    for u, v, p in estradas:
        adj[u].append((v, p))
        adj[v].append((u, p))
    
    return dijkstra(N, C, K, adj)

while True:
    N, M, C, K = map(int, input().split())
    if N == M == C == K == 0:
        break
    
    estradas = [tuple(map(int, input().split())) for _ in range(M)]
    
    print(RegistraRotas(N, M, C, K, estradas))