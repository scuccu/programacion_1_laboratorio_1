#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    printf("Ingrese su edad\n");
    scanf("%d",&numeroUno);
    printf("Ingresaste: %d",numeroUno);
    return 0;

    int notaUno;
    int notaDos;
    int notaTres;
    int maximo;


    printf("Ingrese una nota del 1 al 10\n");
    scanf("%d",&notaUno);
    printf("Ingrese una nota del 1 al 10\n");
    scanf("%d",&notaDos);
    printf("Ingrese una nota del 1 al 10\n");
    scanf("%d",&notaTres);


   if(notaUno>notaDos && notaUno>notaTres)
   {
       maximo=notaUno;
   }
   else
    if(notaDos>notaTres)
    {
        maximo=notaDos;
    }
    else
    {
        maximo=notaTres;
    }

    printf("El numero maximo es %d",maximo);

    return 0;


}

