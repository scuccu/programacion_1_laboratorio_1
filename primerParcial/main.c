#include <stdio.h>
#include <stdlib.h>
#include "usuarios.h"
//#include "susFunciones.h"
#define TAMANIO 10
#define TAMANOPRO 25

int main()
{
    eUsuario usuario[TAMANIO];
    //eProducto producto[TAMANIOPRO];

    eUsuario_init(usuario, TAMANIO);


    int opcionElegida;
    int index;
    char menuInicio[]="1. ALTA USUARIO\n2. MODIFICAR DATOS USUARIO\n3. BAJA\n4. PUBLICAR PRODUCTO\n5. MODIFICAR DATOS PRODUCTO\n6.CANCELAR PRODUCTO\n11. SALIR\n\n\n";
    char menuInicioError[]="Ingrese un numero acorde al listado";

   do
   {
       opcionElegida=0;
       getValidInt(menuInicio, menuInicioError, &opcionElegida,1,11,4);


       switch(opcionElegida)
       {
       case 1:
            eUsuario_alta(usuario,TAMANIO);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Usuario ingresado");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 11:

            break;
       }

   }while(opcionElegida!=11);

   return 0;
}
