#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarios.h"
#define TAMANIO 10
#define TAMANIOPRO 25
#define OCUPADO 0
#define LIBRE 1

// gets(auxstring), este auxilir string va tener espacio suf para que guarde un dato
//pf("Ingrese edad"), usuario ingresa edad pero puede equivocarse, asi que hay que validar que ese string sea todo numerico
// int isalpha(char)
// int isdigit(char)
//int isspace(char)
// x=validastringentero(auxstring)
//if (x==1){edad=atoi(auxstring); else
//

int eUsuario_init( eUsuario usuario[],int TAMANIO)
{
    int retorno = -1;
    int i;
    if(TAMANIO > 0 && usuario != NULL)
    {
        retorno = 0;
        for(i=0; i<TAMANIO; i++)
        {
            usuario[i].estado= LIBRE;
            usuario[i].idUsuario= 0;
        }
    }
    return retorno;
}

int eUsuario_buscarLugarLibre(eUsuario usuario[],int TAMANIO)
{
    int retorno = -1;
    int i;
    if(TAMANIO > 0 && usuario != NULL)
    {
        retorno = -2;
        for(i=0;i<TAMANIO;i++)
        {
            if(usuario[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUsuario_siguienteId(eUsuario usuario[],int TAMANIO)
{
    int retorno = 0;
    int i;
    if(TAMANIO > 0 && usuario != NULL)
    {
        for(i=0; i<TAMANIO; i++)
        {
            if(usuario[i].estado == OCUPADO)
            {
                    if(usuario[i].idUsuario>retorno)
                    {
                         retorno=usuario[i].idUsuario;
                    }

            }
        }
    }

    return retorno+1;
}


int eGen_buscarPorId(eUsuario usuario[] ,int TAMANIO, int id)
{
    int retorno = -1;
    int i;
    if(TAMANIO > 0 && usuario != NULL)
    {
        retorno = -2;
        for(i=0;i<TAMANIO;i++)
        {
            if(usuario[i].estado == OCUPADO && usuario[i].idUsuario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int eUsuario_mostrarUno(eUsuario usuario[],int TAMANIO)
{
    int retorno = -1;
    int i;
    if(TAMANIO > 0 && usuario != NULL)
    {
        retorno = 0;
        for(i=0; i<TAMANIO; i++)
        {
            if(usuario[i].estado==OCUPADO)
            {

                eUsuario_mostrarUno(usuario[i]);
            }
        }
    }
    return retorno;
}

int eUsuario_alta(eUsuario  usuario[],int TAMANIO)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(TAMANIO > 0 && usuario != NULL)
    {
        retorno = -2;
        indice = eUsuario_buscarLugarLibre(usuario,TAMANIO);
        if(indice >= 0)
        {
            retorno = -3;
            id = eUsuario_siguienteId(usuario,TAMANIO);

                if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))

                retorno = 0;
                strcpy(usuario[indice].nombre,nombre);
                usuario[indice].idUsuario = id;
                usuario[indice].estado = OCUPADO;
        }
    }
    return retorno;
}
int eUsuaio_baja(eUsuario usuario[] ,int TAMANIO, int id)
{
    int retorno=0;
    int opcionLegajo;
    int i;


}


int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps)
{
    char auxStr[256];
    int auxInt, i, retorno = -1;

    for(i=0;i<attemps;i++)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s",errorMessage);
            break;
            continue;

        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("%s",errorMessage);
            continue;

        }
        *input = auxInt;
        retorno = 0;
        break;

    }
    return retorno;

}

