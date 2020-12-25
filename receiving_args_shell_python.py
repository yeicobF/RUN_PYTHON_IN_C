import sys

def main():
    print("\n - RECEIVING ARGUMENTS -\n")
    # Aquí voy a imprimir de otra forma.
    # Voy a utilizar los parámetros de impresión para probarlos.
    print("\n -> FIRST ARGUMENT -> NAME: [", sys.argv[0], "]", sep=' ', end=" -\n")
    # Imprimir los demás argumentos.
    if( len(sys.argv) > 1 ): # Hay más de un argumento.
        print("\n - ARGUMENTS LIST:")
        for i in range(1, len(sys.argv)):
            print("\n\tArg[{}]: {}" .format(i, sys.argv[i]))
        print("\n - ALL DONE -\n")
    else:
        print("\n - NO ARGUMENTS RECEIVED - \n")

if __name__ == "__main__":
    main()
