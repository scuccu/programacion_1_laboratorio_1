#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define OCUPADO 0
#define LIBRE 1
#include <ctype.h>

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

float getFloat(char mensaje[])
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}
int getInt (char mensaje[])
{

   int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}
char getChar(char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}


int init(EPersona Persona[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && Persona != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            //Persona[i].estado= LIBRE;
            Persona[i].estado= 0;
        }
    }
    return retorno;
}

int mostrarUno(EPersona persona)
{
     printf("\n %s - %d - %d -%d",persona.nombre,persona.edad,persona.estado,persona.dni);

}
int mostrarPersona(EPersona Persona[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && Persona != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(Persona[i].estado==1)
            {

                mostrarUno(Persona[i]);
            }
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona Persona[],int limite)
{
    for(int i=0; i<limite; i++)
    {
        if(Persona[i].estado==0)
        {
            return i;
        }
    }
    return -1;
}

int alta(EPersona personas[],int limite)
{
    int retorno =-1;
    int i;
    char auxiliarDni[50];
    char auxiliarEdad[50];
    int dni;
    int edad;
    int menores18=0;
    int de19a35=0;
    int mayor35=0;

    i=obtenerEspacioLibre(personas,limite);
    if(i>=0)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(personas[i].nombre);
        while(esSoloLetras(personas[i].nombre)==0)
        {
            printf("Error, ingrese un nombre: ");
            fflush(stdin);
            gets(personas[i].nombre);
        }
        printf("Ingrese la edad: ");
        fflush(stdin);
        gets(auxiliarEdad);
        while(esNumerico(auxiliarEdad)==0)
        {
            printf("error, ingrese una edad: ");
            fflush(stdin);
            gets(auxiliarEdad);
        }
        edad=atoi(auxiliarEdad);
        if(edad<19)
        {
            menores18++;
        }
        else if(edad>18 || edad<36)
        {
            de19a35++;
        }
        else
        {
            mayor35++;
        }
        personas[i].edad=edad;

        printf("Ingrese el dni: ");
        fflush(stdin);
        gets(auxiliarDni);

        while(esNumerico(auxiliarDni)==0)
        {
            printf("Error, ingrese un dni: ");
            fflush(stdin);
            gets(auxiliarDni);
        }
        dni=atoi(auxiliarDni);
        personas[i].dni=dni;

        personas[i].estado=1;
        retorno=0;
        mostrarPersona(personas, limite);
    }
    return retorno;
}

void cargarHarcode(EPersona personas[])
{
    int i;

    EPersona auxPersonas[15]={{"Elena",25,1,38200321},{"Jorge",56,1,17520362},{"Hernan",18,1,40589126},{"Sonia",35,1,28145201},{"Camila",32,1,29178359},{"Carlos",28,1,39447895},{"Ju",20,1,40321589},{"Gra",33,1,27556551},{"Juli",24,1,38156031},{"Car",30,1,25654785},{"Marcos",23,1,39154265},{"Ru",26,1,39222555},{"Nic",32,1,35125633},{"Javier",29,1,34562135},{"Sandra",31,1,33554669}};

    for(i=0; i<15; i++)
    {
        personas[i]=auxPersonas[i];
    }
}

int baja(EPersona personas[],int limite)
{
    char auxiliarDniBaja[235];
    int busqueda;
    char respuesta;
    int auxiliarDniBa;
    mostrarPersona(personas, limite);

    getStringNumeros("\nIngrese el Dni que desea dar de baja: ",auxiliarDniBaja);
    auxiliarDniBa=atoi(auxiliarDniBaja);

    busqueda=buscarPorDni(personas,auxiliarDniBa,limite);
    if(!busqueda)
    {
        printf("Dni incorrecto\n");
    }
    printf("Desea dar de baja este usuario? s/n \nNombre:%s\nDni:%d\nEdad:%d\n",personas[busqueda].nombre,personas[busqueda].dni,personas[busqueda].edad);
    respuesta=getche();
    if(respuesta=='s')
    {
        printf("Se dio de baja al usuario.\n");
        personas[busqueda].estado=0;
    }
    else
    {
        printf("Se ha cancelado la baja.\n");
    }
    return 0;
}

int buscarPorDni(EPersona persona[],int dni,int limite)
{
    for(int i=0; i<limite; i++)
    {
        if(persona[i].estado==1 && persona[i].dni==dni)
        {
            return i;
        }
    }
    return -1;
}

void ordenarPersona(EPersona persona[], int limite)
{
    EPersona auxiliar;
    int i;
    int j;

    for(i=0; i<limite; i++)
    {
        for(j=i+1; j<limite; j++)
        {
            if(persona[i].estado==1&&persona[j].estado==1)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    auxiliar=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxiliar;
                }
            }
        }
    }
}
