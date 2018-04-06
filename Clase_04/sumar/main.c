#include <stdio.h>
#include <stdlib.h>

/*
5!=5.4.3.2.1=120(factorial)
si  se cuantas repiticiones e




*/

/** \brief calcula el factorial de un numero
 *
 * \param int un numero
 * \return int el factorial del que recibe como parametro
 *
 */
int factorial(int numero);

int main()
{
    int numero=5;
    int factor;
    factor=factorial(numero);
    printf("el factor es : %d",factor);
    /*int numero= 5;
    int factor=1;
    int i;
    for(i=numero;i>=1;i--)
    {
      factor=factor*i;
    }
    printf("el factorial es : %d", factor);*/
   return 0;

}
int factorial(int numero)
{
    int respuesta;
    if(numero==0)
    {
        respuesta= 1;
    }
    else{
        respuesta =numero * factorial(numero-1);
    }

    return respuesta;



}

