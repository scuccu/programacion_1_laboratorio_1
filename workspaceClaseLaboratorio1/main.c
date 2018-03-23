#include <stdio.h>
#include <stdlib.h>
/* se ingresan numeros (disintos de cero), no se sabe cuantos.
se piden mostrar:
cantidad de pares e impares.
porcentaje de numeros positivos y negativos.
maximo y minimo.
maximo numero par.
cantidad de numeros comprendidos entre 125 y 236.

*/
int main()
{
    int numero;
    int contadorNumero;
    char respuesta='s';
    int numeroPar=0;
    int numeroImpar=0;
    int numeroPositivo=0;
    int numeroNegativo=0;
    float porcentajePositivos;
    float porcentajeNegativos;
    int maximo;
    int minimo;
    int flag=0;
    int flagPar=0;
    int maximoPar;
    int numeroComprendidos=0;



    while(respuesta=='s')
    {

        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        while(numero==0)
        {
          printf("Ingrese un numero: ");
          scanf("%d", &numero);
        }

        if(numero%2==0)
            {
                if(numeroPar==0 || numero>maximoPar)
                {
                    maximoPar=numero;
                }

                numeroPar++;
            }

        else
        {
            numeroImpar++;
        }

        if(numero>0)
        {
            numeroPositivo++;

        }
        else
        {
            numeroNegativo++;

        }


     /* PRIMERO FOMA DE HACERLO

         if(flag==0)
        {
            maximo=numero;
            minimo=numero;
            flag=1;
        }
        else
        {
            if(numero<minimo)
            {
                minimo=numero;
            }
            if(numero>maximo)
            {
                maximo=numero;
            }
        }*/

        if(flag==0 || numero>maximo)
        {
            maximo=numero;

        }
        if(flag==0 || numero<minimo)
        {
           minimo=numero;
           flag=1;
        }




        printf("Desea ingresar un nuevo dato? s/n");
        respuesta=getche(stdin);

    }


        contadorNumero=numeroPositivo+numeroNegativo;

        porcentajePositivos=(float)(numeroPositivo*100)/contadorNumero;
        porcentajeNegativos= 100-porcentajePositivos;        //(numeroNegativo*100)/contadorNumero;

        printf("\nCantidad de numeros pares %d",numeroPar);
        printf("\nCantidad de numero impares %d",numeroImpar);
        printf("\nPorcentaje de numeros positivos %% %f",porcentajePositivos);
        printf("\nPorcentaje de numeros negativos %% %f",porcentajeNegativos);
        printf("\nEl maximo es:  %d",maximo);
        printf("\nEl minimo es: %d",minimo);



    return 0;
}
