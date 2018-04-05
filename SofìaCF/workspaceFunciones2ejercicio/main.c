#include <stdio.h>
#include <stdlib.h>

float dividirEnteros(int numeroUno, int numeroDos);
int main()
{
    float numero;
    numero=dividirEnteros(10,3);
    printf("%f" ,numero);
    return 0;
}
float dividirEnteros(int numeroUno, int numeroDos)
{
    float resultado=0;
    resultado=(float)numeroUno/numeroDos;
    return resultado;
}
