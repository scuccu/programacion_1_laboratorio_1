#include <stdio.h>
#include <stdlib.h>
//(1)Prototipo y firma

    int sumar(int NumeroUno ,int NumeroDos);

//(2)invocar a la funcion
int main()
{
    int numero;
    numero=sumar(3,3);
    printf("%d" ,numero);
    return 0;
}

//(3))Definir la funcionalidad

     int sumar(int NumeroUno,int NumeroDos)
    {
        int resultado=0;

        resultado=NumeroUno+NumeroDos;

        return resultado;
    }
