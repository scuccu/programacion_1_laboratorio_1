#include <stdio.h>
#include <stdlib.h>

int contarpares(int[],int);
int buscarchar(char[],int,char);

int main()
{
    int vector[5]={5,2,9,6,5};
    char letras[5]={'f','g','i','m','q'};
    int indexletra;
    int cantidad;
    cantidad=contarpares(vector,5);
    indexletra=buscarchar(letras,5,'a');

    /**
    if(indexletra==-1)
    {
        printf("No se encuentra el caracter\n");
    }

    else{ printf("el caracter esta en el array\n");}

    printf("index=%d\n",indexletra);
    printf("Cantidad de pares %d",cantidad);
*/
    return 0;
}


int contarpares(int array[],int cantidad)
{
    int contadorpares=0;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(array[i]%2==0)
        {
            contadorpares++;
        }
    }

    return contadorpares;
}

int buscarchar (char array[],int cantidad,char caracter)
{
    int index= -1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(array[i]==caracter)
        {
            index=i;
            break;
        }

    }
    return index;
}
