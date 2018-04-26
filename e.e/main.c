#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 2

int buscarLibre(int[], int);
void mostrarAlumnos(int[], char[][20], int[], int[], float[], int);
float calcularPromedio(int, int);
int cargarAlumno(int[], char[][20], int[], int[], float[], int);
void modificarAlumno(int[], char[][20], int[], int[], float[], int);
void darDeBaja(int[], char[][20], int[], int[], float[], int);

int main()
{
    int legajo[TAM]= {1, 24};
    char nombre[TAM][20]={"Calos", "Julia"};
    int nota1[TAM]={4,8};
    int nota2[TAM]={4,8};
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    int j;
    int auxiliarChar[20];
    int auxiliarInt;

    do
    {
        printf("1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
            if(index == -1)
            {
                printf("No hay lugar");
            }
            else
            {
                printf("Alumno ingresado");
            }
            break;

        case 2:

        mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);

        break;

        case 3:
            modificarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);

            break;

        case 4:
            darDeBaja(legajo, nombre, nota1, nota2, promedio, TAM);
            break;

        case 5:
            for(i=0;i<TAM;i++)
            {
                for(j=i+1;j<TAM;j++)
                {
                    if(strcmp(nombre[i],nombre[j])>0)
                    {
                        strcpy(auxiliarChar, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j],auxiliarChar);

                        auxiliarInt=legajo[i];
                        legajo[i]=legajo[j];
                        legajo[j]=auxiliarInt;

                        auxiliarInt=nota1[i];
                        nota1[i]=nota1[j];
                        nota1[j]=auxiliarInt;
                        auxiliarInt=nota2[i];
                        nota2[i]=nota2[j];
                        nota2[j]=auxiliarInt;

                        auxiliarInt=promedio[i];
                        promedio[i]=promedio[j];
                        promedio[j]=auxiliarInt;

                    }
                }
            }
                for(i=0;i<TAM;i++)
                {
                    if(legajo[i]!=0)
                    {
                        printf("nombre:%s legajo:%d Nota1:%d Nota2:%d Promedio:%.2f\n", nombre[i], legajo[i], nota1[i], nota2[i], promedio[i]);
                    }
                }
            break;

        }

    }
    while(opcion!=9);

    return 0;
}

int buscarLibre(int legajo[], int tam)
{
    int i;
    int index=-1;
    for(i=0;i<tam;i++)
    {
        if(legajo[i]==0)
        {
            index=i;
            break;
        }
    }

    return index;
}

int cargarAlumno(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int index ;
    index = buscarLibre(legajo, tam);
            if(index!=-1)
            {
                printf("Ingrese un legajo: \n",legajo);
                scanf("%d",&legajo[index]);
                printf("Ingrese su nombre: \n",nombre);
                scanf("%d",&nombre[index]);
                printf("Ingrese primera nota: \n",nota1);
                scanf("%d",&nota1[index]);
                printf("Ingrese segunda nota: \n",nota2);
                scanf("%d",&nota2[index]);
                promedio[index]=calcularPromedio(nota1[index],nota2[index]);
            }
            return index;
}


float calcularPromedio(int nota1, int nota2)
{
    float promedio;
    promedio = (float)(nota1+nota2)/2;
    return promedio;
}

void mostrarAlumnos(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
            {
                if(legajos[i]!=0)
                {
                    promedio[i]=calcularPromedio(nota1[i],nota2[i]);
                    printf("%d %s %d %d %f\n", legajos[i], nombres[i], nota1[i], nota2[i], promedio[i] );
                }

            }
}
void modificarAlumno(int legajos[], char nombres[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int opcion;
    int opcionLegajo;
    char nombreAuxiliar[20];
    int i;
    int auxiliarNota;

    mostrarAlumnos(legajos, nombres, nota1, nota2, promedio, TAM);
    printf("Ingrese el legajo a modificar\n",opcionLegajo);
    scanf("%d",&opcionLegajo);

    for(i=0;i<TAM;i++)
    {
        if(opcionLegajo==legajos[i])
        {
            printf("Modificar: \n 1-NOMBRE \n 2-NOTA UNO \n 3-NOTA DOS");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                printf("Nombre actual:%s Ingrese su nuevo nombre: \n",nombres[i],nombreAuxiliar);
                scanf("%c",&nombreAuxiliar);
                strcpy(nombres[i],nombreAuxiliar);//strcpy:copia una cadena de caracteres de un lugar a otro
                printf("El nuevo nombre es: %s\n",nombres[i]);//le aviso a usuario de la modificación
                break;

            case 2:
                printf("Nota actual: %d Ingrese una nueva nota:",nota1[i],auxiliarNota);//como el paso anterior, muestro nota actual y pido reemplazo
                scanf("%d",&auxiliarNota);

                while(auxiliarNota>11 || auxiliarNota<0)//valido nota
                {
                    printf("Ingrese una nota correcta\n");
                    scanf("%d",&auxiliarNota);
                }
                nota1[i]=auxiliarNota; //no puedo utilizar el strcpy por que no es char

                promedio[i]=calcularPromedio(nota1[i],nota2[i]); //al cambiar la nota, cambia el promedio, tengo que reestablecer los parametros nuevos
                printf("La nota ha sido modificada\n");
                break;

            case 3://copio de nota1 y pego, modifico a nota2,mismo proceso
                printf("Nota actual: %d Ingrese una nueva nota:",nota2[i],auxiliarNota);//como el paso anterior, muestro nota actual y pido reemplazo
                scanf("%d",&auxiliarNota);

                while(auxiliarNota>11 || auxiliarNota<0)//valido nota
                {
                    printf("Ingrese una nota correcta\n");
                    scanf("%d",&auxiliarNota);
                }
                nota1[i]=auxiliarNota; //no puedo utilizar el strcpy por que no es char

                promedio[i]=calcularPromedio(nota1[i],nota2[i]); //al cambiar la nota, cambia el promedio, tengo que reestablecer los parametros nuevos
                printf("La nota ha sido modificada\n");
                break;
            }

        }
    }

}
void darDeBaja(int legajo[], char nombre[][20], int nota1[], int nota2[], float promedio[], int tam)
{
    int opcionLegajo;
    int i;

    mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);
    printf("Ingrese el legajo a dar de baja\n",opcionLegajo);
    scanf("%d",&opcionLegajo);

    for(i=0;i>TAM;i++) //iteraciones para buscar el legajo
    {
        if(opcionLegajo==legajo[i])//si el numero y el legajo coinciden, se modifican
        {
            legajo[i]=0;
            printf("Se ha dado de baja al legajo\n");
        }
    }
}
