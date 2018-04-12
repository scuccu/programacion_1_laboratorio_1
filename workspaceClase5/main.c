#include <stdio.h>
#include <stdlib.h>

int main()
{
    float listadoPrecios;
    int indice[5];
    int i;
    float precioAux;
    char seguir;

    for(i=0;i<5;i++)
    {
        indice[i]=0;

        do
        {
            printf("Ingrese un indice");
            scanf("\n%d",&indice);

        }
    }



    for(i=0;i<5;i++)
    {
        printf("\n precio: %f",listadoPrecios[i]);
    }

    return 0;
}
