#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define TAMANIO 10
#define OCUPADO 0
#define LIBRE 1

int eUsuario_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idUsuario= 0;
        }
    }
    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idUsuario>retorno)
                    {
                         retorno=listado[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}


int eGen_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsuario_siguienteId(listado,limite);

                if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))

                retorno = 0;
                strcpy(listado[indice].nombre, );
                listado[indice].idUsuario = id;
                listado[indice].estado = OCUPADO;
        }
    }
    return retorno;
}
int eUsuaio_baja(eUsuario[] ,int limite, int id)
{
    int retorno=0;
    int opcionLegajo;
    int i;


}
