'''
Esse código utiliza o algoritmo Fenwick Tree (BIT) para resolver o problema. O que seria bom se o problema fosse a complexidade do tempo. Porém, este código está falhando muito antes disso, 
aparentemente está ficando preso em um looping infinito. POr hora, isso vaialém do meu conhecimento atual, então não posso resolver. Espero no futuro ser capaz de resolver tal problema. 
'''
def main():
    while True:
        # 1. Pegar os 3 dígitos
        string = input("Digite 3 dígitos, separe os dígitos por espaço: ")
        digitos = list(map(int, string.split(' ')))
        
        if (digitos[0] > 1000 or digitos[1] > 1000 or digitos[2] > 10):
            print("Erro. A largura e comprimento da área são menor que 1000, reescreva")
            continue  # Volta ao início do loop para pedir a entrada novamente
        
        cols, rows = digitos[1], digitos[0]
        arr = [[0 for j in range(cols + 1)] for i in range(rows + 1)]  # +1 para lidar com índices 1-based
        print(arr)
        
        p = digitos[2]
        q = int(input("Digite quantas msg: \n"))
        n_msg = 0
        
        while n_msg < q:
            string = input()
            entrada = string.split(' ')
            n_msg += 1
            
            if entrada[0] == 'A':
                x, y = int(entrada[2]), int(entrada[3])
                n = int(entrada[1])
                updateBIT(arr, x, y, rows, cols, n)
                
            elif entrada[0] == 'P':
                x, y, x1, y1 = map(int, (entrada[1], entrada[2], entrada[3], entrada[4]))
                print(getQuery(arr, x, y, x1, y1))
                print('\n')
                print(arr)
        botao= input("quero sair= aperte 4")
        if botao == 4:
            break
        else:
            continue

def updateBIT(BIT, x, y, maxX, maxY, val):
    while x <= maxX:
        y_inner = y
        while y_inner <= maxY:
            BIT[x][y_inner] += val
            y_inner += (y_inner & -y_inner)
        x += (x & -x)

def getSum(BIT, x, y):
    sum = 0
    i = x
    while i > 0:
        j = y
        while j > 0:
            sum += BIT[i][j]
            j -= (j & -j)
        i -= (i & -i)
    return sum

def getQuery(BIT, x1, y1, x2, y2):
    if x1 > x2:
        x1, x2 = x2, x1
    if y1 > y2:
        y1, y2 = y2, y1
    return getSum(BIT, x2, y2) - getSum(BIT, x1 - 1, y2) - getSum(BIT, x2, y1 - 1) + getSum(BIT, x1 - 1, y1 - 1)

main() 

