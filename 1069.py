"""
João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>". Ele deve excluir todas as particulas de areia "." do 
processo e a cada retirada de diamante, novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são 
formados. O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. Em seguida o segundo diamante é retirado, restando
 .<.......>....>>>. O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.
"""
#excluir todas as partículas de areia

class Pilha:
      def __init__(self):
        self.top = None
        
      def empilha(self, caracter):
        #adiciona como topo da fila comohead 
        newnode = Node()
        newnode.data = caracter
        if self.top is None:
            self.top = newnode
            return
        current = self.top
        current.next = newnode
        newnode.prev = current
        self.top = newnode
      
      def desempilha(self):
          if self.top is None:
              return
          current = self.top
          current.next= None 
          self.top = current.prev
     

class Node: 
    def __init__(self):
        self.prev = None
        self.next = None 
        self.data = None

N = int(input())
lista = [0]*N
for i in range (N):
   lista[i]= list(input())  # Lista de chaves a serem inseridas
   tamanho_da_pilha=0
   diamante=0
   pilha = Pilha()
   for c in range(len(lista[i])):
      if(lista[i][c] == '<'):
           pilha.empilha(lista[i][c])
           tamanho_da_pilha +=1
      elif lista[i][c] == '>':
        if pilha.top is not None:
            pilha.desempilha()
            diamante +=1
            tamanho_da_pilha -=1
   print(diamante)
