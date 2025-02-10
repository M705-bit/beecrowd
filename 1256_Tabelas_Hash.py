'''
Resposta aceita pelo beecrowd
'''
class Hash_Table:
    def __init__(self, size):
        self.size = size  # Quantidade de endereços-base na hash table
        self.table = [[] for _ in range(size)]  # Lista de listas para tratar colisões por encadeamento externo

    def _hash(self, value):
        return abs(value) % self.size  # Usa o valor absoluto para calcular o índice  

    def AddKey(self, keys):
        for key in keys:
            index = self._hash(key)
            self.table[index].append(key)

    def get(self):
        for i in range(self.size):
            if self.table[i]:  # Se houver elementos armazenados no índice
                print(f"{i} -> {' -> '.join(map(str, self.table[i]))} -> \\")
            else:  # Se não houver elementos armazenados
                print(f"{i} -> \\")
        
def main():
    N = int(input())  # Número de casos de teste
    for case in range(N):
        M, C = map(int, input().split())  # M = tamanho da hash table, C = quantidade de chaves
        keys = list(map(int, input().split()))  # Lista de chaves a serem inseridas

        tabela_hash = Hash_Table(M)
        tabela_hash.AddKey(keys)
        tabela_hash.get()  # Imprime a tabela formatada

        if case < N - 1:  # Adiciona uma linha em branco entre casos de teste, exceto no último
            print()

main()
