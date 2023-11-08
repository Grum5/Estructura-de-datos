'''
    Tarea 4: Funciones NO recursivas

    Javier Osvaldo Perez Bretado - 22760591
'''

def suma_sucesivas(n, m):
    '''Funcion que calcula el producto de dos numeros enteros a partir de sumas sucesivas'''

    resultado = n # Se inicializa el resultado con el valor de n

    for i in range(1,m):
        resultado = resultado + n # Se suma el valor de n al resultado

    return resultado # Se retorna el resultado


def dec_bin(dec):
    '''Funcion que convierte un numero decimal a binario'''

    residuos = [] # Lista que almacena los residuos de la division

    while (dec > 0):
        residuos.append( str(int(dec % 2)) ) # Se agrega el residuo a la lista
        dec = dec // 2 # Se actualiza el valor de dec

    residuos.reverse()  # Se invierte la lista de residuos
    binario = ''.join(residuos) # Se convierte la lista de residuos en un string

    return int(binario) # Se convierte el string en un numero entero y se retorna

def suma_N(n):
    '''Funcion que calcula la suma de los numeros hasta un numero N'''

    resultado = 0 # Se inicializa el resultado en 0

    for i in range(0, n + 1):
        resultado = resultado + i # Se suma el valor de i al resultado

    return resultado # Se retorna el resultado

def suma_potencia(x, n):
    '''Funcion que calcula la suma de un numero x a n potencias'''

    resultado = 0 # Se inicializa el resultado en 0

    for i in range(0, n + 1):
        resultado = resultado + x**i # Se suma el valor de x elevado a la i al resultado

    return resultado # Se retorna el resultado

if __name__ == "__main__": # Main para pruebas
    print("Suma sucesivas: ",suma_sucesivas(5, 3))
    print("Decimal a binario: ", dec_bin(5))
    print("Suma de un numero a n potencias: ", suma_potencia(3, 3))
    print("Suma de los numeros hasta un numero N: ", suma_N(5))
