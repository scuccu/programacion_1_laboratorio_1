#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define OCUPADO 0
#define LIBRE 1


int ePer_init( EPersona Persona[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && Persona != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            Persona[i].estado= LIBRE;
            Persona[i].estado= 0;
        }
    }
    return retorno;
}

int ePer_mostrarUno(EPersona persona)
{
     printf("\n %s - %d - %d -%d",persona.nombre,persona.edad,persona.estado,persona.dni);

}
int ePer_mostrarPersona(EPersona Persona[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && Persona != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(Persona[i].estado==OCUPADO)
            {

                ePer_mostrarUno(Persona[i]);
            }
        }
    }
    return retorno;
}

int ePer_mostrarListado(EPersona Persona[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && Persona != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(Persona[i].estado==OCUPADO)
            {

                ePer_mostrarUno(Persona[i]);
            }
        }
    }
    return retorno;
}

