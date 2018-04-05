#include <stdio.h>
#include <stdlib.h>

int pedirNumeroPar();
int getEntero(char* mensaje, char* mensajeError, int minimo,int maximo);


int main()
{
    int numero;
    numero=getEntero("Ingrese su edad","Error, debe ser entre 1 y 199",1,199);
    printf("en entero ingresado es : %d" ,numero);

}

int getEntero(char* mensaje, char* mensajeError, int minimo,int maximo){

    int retorno=-1;
    do{
        printf("%s :",mensaje);
        scanf("%d",&retorno);
        if(retorno<maximo && retorno>minimo)
        {
            break;
        }
        printf("%s  \n",mensajeError);
    }while(0);

    return retorno;


}

