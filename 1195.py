#Construindo um nó da árvore binária 
class No:
    def __init__(self, valor, pai = None):
        self.valor = valor
        self.pai = pai
        self.esq = None
        self.dir = None

    def adiciona(self, valor):
        if valor == self.valor:
            return
        if valor < self.valor:
            if self.esq == None:
                self.esq = No(valor, self)
            else:
                self.esq.adiciona(valor)
        else:
            if self.dir == None:
                self.dir = No(valor, self)
            else:
                self.dir.adiciona(valor)

    def busca(self, valor):
        if valor == self.valor:
            return self
        if valor < self.valor:
            if self.esq == None:
                return None
            return self.esq.busca(valor)
        else:
            if self.dir == None:
                return None
            return self.dir.busca(valor)
    def remove(self):
        if self.esq == None and self.dir == None:
            if self.pai != None:
                if self.pai.esq == self:
                    self.pai.esq = None
                else:
                    self.pai.dir = None
        elif self.esq == None or self.dir == None:
            if self.esq != None:
                filho = self.esq
            else :
                filho = self.dir
            if self.pai != None:
                if self.pai.esq == self:
                    self.pai.esq = filho
                else:
                    self.pai.dir = filho    
        else:
            sucessor = self.dir
            while sucessor.esq != None:
                sucessor = sucessor.esq
            self.valor = sucessor.valor
            sucessor.remove()

    def prefixa(self):
        #global sb ]
        resultado = ''
        resultado = f'{self.valor}'
        #sb += f' {self.valor}'
        if self.esq != None:
            #self.esq.prefixa()
            resultado += ' ' + self.esq.prefixa()
        if self.dir != None:
            resultado += ' ' + self.dir.prefixa()
            #self.dir.prefixa()
        return resultado
    
    def infixa(self):
        #global sb
        resultado = ''
        if self.esq != None:
            #self.esq.infixa()
            #resultado += ' ' + self.esq.infixa()
            resultado += self.esq.infixa()+' '
        #sb += f' {self.valor}'
        resultado += f'{self.valor}'
        if self.dir != None:
            #self.dir.infixa()
            #resultado += ' ' + self.dir.infixa()
            resultado += ' ' + self.dir.infixa()
        return resultado
            
    def posfixa(self):
        #global sb
        resultado = ''
        if self.esq != None:
            #self.esq.posfixa()
            #resultado += ' ' + self.esq.posfixa()
            resultado += self.esq.posfixa()+' '
        if self.dir != None:
            #self.dir.posfixa()
            #resultado += ' ' + self.dir.posfixa()
            resultado += self.dir.posfixa()+' '
        #sb += f' {self.valor}'
        #resultado += f' {self.valor}'
        resultado += f'{self.valor}'
        return resultado
    
class ArvoreBinaria:
    def __init__(self):
        self.topo = None
    
    def adiciona(self, valor):
        if self.topo == None:
            self.topo = No(valor)
        else:
            self.topo.adiciona(valor)
    
    def busca(self, valor):
        if self.topo == None:
            return False
        return self.topo.busca(valor) != None
    
    def remove(self, valor):
        no = self.topo.busca(valor)

        if no != None and no.pai == None:
            if no.esq == None and no.dir == None:
                self.topo = None
            elif no.esq != None or no.dir != None:
                self.topo = no.esq if no.esq != None else no.dir
        no.remove()

def main():
    N = int(input ()) # número de casos de teste 
    i=0

    while i < N:
        qtd_num = int(input()) #qtd de números que vão estar na árvore binária 
        lista = [] # lista com os números que vão estar na árvore binária
        for j in range(qtd_num):
                lista.append(int(input()))
                j+=1
        arvore = ArvoreBinaria() # instância da árvore binária
        for k in range(qtd_num):
            arvore.adiciona(lista[k])
            k+=1
        print ('Caso', i+1, ':')
    
        print('Prefixa:', arvore.topo.prefixa())
        print('Infixa:', arvore.topo.infixa())
        print('Posfixa:', arvore.topo.posfixa())

        i+=1

        # lista = list(map(int, entrada.split())) # lista com os números que vão estar na árvore binária
main()
    
