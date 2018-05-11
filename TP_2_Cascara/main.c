#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    EPersona Persona[TAM];
    char seguir='s';
    int opcion=0;


    init(Persona,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                alta(Persona,TAM);
                break;
            case 2:
                baja(Persona,TAM);
                break;
            case 3:
                ordenarPersona(Persona, TAM);
                mostrarPersona(Persona, TAM);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;

        system("cls");
        }
    }

    return 0;
}
