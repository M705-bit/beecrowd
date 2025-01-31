'''
esse é um dos probolemas mais estranhos que já vi, mas vamos lá
presumo que Schweisens sejam um tipo de barata no nosso gramado teremos de detetizá-lo, para isso 
usaremos um detetizador. Sabendo que um detetizador pode matar uma schweisen teremos de calcular o número 'N' de schwiesens para retornar o 
número de detetizddores que teremos de comprar,lembrando que cada detetizador custa um certo preço 'P'. O conan vai nos informar isso mandadno msgs 'Q'. 
Pq o tamanho do campo imoorta?
'''
def main():
    while True:
            #1. Pegar os 3 dígitos 
        
        string = input("Digite 3 dígitos, separe os dígitos por vírgula: ")
        digitos= []
        digitos.extend(map(int, string.split(' ')))  
        if (digitos[0] and digitos[1]>1000 ) or (digitos[2]>10):
            print("Erro. A largura e comprimento da área são menor que 1000, reescreva")
            string = input("Digite 3 dígitos, separe os dígitos por vírgula: ")
            digitos= []
            digitos.extend(map(int, string.split(',')))  
       
        rows, cols = (digitos[1], digitos[0])
        arr = [[0 for i in range(cols)] for j in range(rows)]
        print(arr)
        p = digitos[2]
        q = input("Digite quantas msg: \n")
        while True: 
            string =  input() 
            entrada= []
            entrada.extend(string.split(' '))
            if entrada[0] == 'A':
                y, x = (int(entrada[2]),int(entrada[1]))
                n = int(entrada[1])
                Insere_Schweisen(y, x, rows, cols, n, arr)
            elif entrada[0] == 'P':
                y, x, y1, x1 = map(int, (entrada[2], entrada[1], entrada[4], entrada[3]))
                print(Procura_Schweisen(y, x, y1, x1, rows, cols, arr))
                print('\n')

       
def Insere_Schweisen(y, x, rows, cols, n, arr):
    #usando o simples bubble sort
    for i in range (rows):
          if rows[i]== y: 
            for j in range (cols):
                if cols[j]== x:
                    # insere a schweisen aqui
                    if arr[i][j]== None: 
                        arr[i][j].append(n)
                        return 
                    else:
                        arr[i][j]+= n
                        return

def Procura_Schweisen(y, x, y1, x1, rows, cols, arr):
    #procura dentro da matriz
    sum = 0
    if y>y1:
        temp = y
        y = y1
        y1 = temp 
   
    if x>x1:
        temp = x
        x = x1
        x1 = temp

    for i in range(x):
        for j in range(y):
            sum+= arr[i][j]
            
    return sum

main()

esse código tá com problema e ainda não estou sabendo resolver urghhhhh
