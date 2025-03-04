"""

Regras:
-> quando chega na estação , os vagões são organizados conforme o chefe da estação deseja. 
-> todos os vagões são desconectados e reconectados em B quando chegam na estação. 
-> o vagão que entra na estação só pode sir pelo lado B
são 26 vagões no máximo, a- z
-> através de um programa é preciso resolver, 
quak a sequência de movimentos é necessária para obrter
 a saída desejada apóes entrar na estação. 
 -> o movimento de entrada e saída da estação é descrito respectivamente pelas letras I e R. Utilizando 

-> 
"""
"""
class Node:
    def __init__(self):
        self.prev = None
        self.next = None 
        self.data = None
class Fila:
    def __init__(self):
        self.top = None
        
    def insere(self, caracter):
        newnode = Node()
        if self.topo is None:
            self.topo = newnode
            return 'I'
        else:
            current = self.topo
            current.next = newnode
            newnode.prev= current
            self.topo = newnode
            return 'I'
    def remove(self):
        if self.topo is None:
            return
        if self.topo.prev is None:
            self.topo = None
            return 'R'
        if self.topo.prev is not None:
            current = self.topo
            current.prev.next = None
            self.topo = current.prev        
            return 'R'
       
        
status = True
fila = Fila()
lista = []
while status:
    N = int(input("Digite o numero de vagões: ")) #número de vagões 
    vagoesA= list(map(int, input("Digite a sequência de vagões para A: ").split()))  # Lista de chaves a serem inseridas
    vagoesB= list(map(int, input("Digite a sequência de vagões para B: ").split())) 
    status = input() #status recebe 0 que corresponde a false e saí
    int j =0 
    for i in range(N):
       lista[i]= fila.insere(vagoesA[j])
       if vagoesA[i] == vagoesB[i]:
           lista[i]=fila.remove()
           j +=1
     
    

# é uma fila sempre insere no final e os primeors elementos saem


"""
class Pilha:
    def __init__(self):
        self.top = None
        self.stack = []  # Usamos uma lista para simular a pilha
    
    def insere(self, caracter):
        self.stack.append(caracter)  # Empilha o vagão
        return 'I'

    def remove(self):
        if self.stack:
            self.stack.pop()  # Desempilha o vagão
            return 'R'
        return None

while True:
    N = int(input("Digite o número de vagões: "))  # Número de vagões
    if N == 0:
        break  # Encerra o programa quando a entrada for 0

    vagoesA = input("Digite a sequência de vagões para A: ").split()  # Entrada de A
    vagoesB = input("Digite a sequência de vagões para B: ").split()  # Saída desejada B
    
    pilha = Pilha()
    resultado = []
    j = 0  # Índice para vagoesB
    impossivel = False

    for i in range(N):
        resultado.append(pilha.insere(vagoesA[i]))  # Sempre empilha o vagão
       
        # Tenta desempilhar enquanto o topo da pilha for o próximo desejado na saída B
        while pilha.stack and j < N and pilha.stack[-1] == vagoesB[j]:
            resultado.append(pilha.remove())
            j += 1  # Avança no vetor B
    
    # Se não conseguimos desempilhar todos os vagões corretamente, é impossível
    if j < N:
        resultado.append("Impossible")

    print(" ".join(resultado))  # Imprime a sequência de operações
