#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
* Inicializa los estados en 0 de la estructura
* @param la estructura persona
* @param el tamaño maximo del vector persona
* @return 0 si esta libre
*/
int init( EPersona Persona[],int limite);

/**
* Muestra un solo usuario
* @param la estructura persona
*/
int mostrarUno(EPersona persona);

/**
* Mostrar listado de personas ingresadas
* @param la estructura persona
* @param el tamaño maximo del vector persona
* @return usuarios ingresados
*/
int mostrarPersona(EPersona Persona[],int limite);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param eltamaño maximodel vector persona
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona Persona[], int limite);

/**
* Muestra un mensaje, le pide al usuario un string
* @param mensaje a ser mostrado
* @param cadena en la que el usuario va a escribir
*/
void getString(char mensaje[], char input[]);

/**
* Muestra un mensaje, pide al usuario un string y valida que solo tenga letras
* @param mensaje a ser mostrado
* @param cadena en la que el usuario va a escribir
*/
int getStringLetras(char mensaje[],char input[]);

/**
* Muestra un mensaje, pide al usuario un string y valida que solo tenga numeros
* @param mensaje a ser mostrado
* @param cadena en la que el usuario va a escribir
* @return si esta valido devuelve 1, sino 0
*/
int getStringNumeros(char mensaje[],char input[]);
/**
* Pide un string y valida que contenga solo letras
* @param cadena a ser validada
* @return 0 si la cadena tiene letras, sino devuelve 1
*/
int esSoloLetras(char str[]);
/**
* Pide un string y valida que tenga solo numeros
* @param cadena a ser validada
* @return 0 si la cadena tiene numeros, sino devuelve 1
*/
int esNumerico(char str[]);
/**
* Solicita un flotante al usuario y devuelve el resultado
* @param cadena a ser validada
* @return el flotante ingresado por el usuario
*/
float getFloat(char mensaje[]);
/**
* Solicita un numero al usuario y devuelve el resultado
* @param cadena a ser validada
* @return el numero ingresado por el usuario
*/
int getInt(char mensaje[]);
/**
* Solicita un caracter al usuario y devuelve el resultado
* @param cadena a ser validada
* @return el caracter ingresado por el usuario
*/
char getChar(char mensaje[]);
/**
* Solicito datos al usuario
* @param array de la estructura que se pasa como parametro
* @param el tamaño maximo del vector persona
* @return usuario cargado
*/
int alta(EPersona personas[],int limite);
/**
* Carga hardcode de datos
* @param array de la estrutura que se pasa como parametro
*/
void cargarHarcode(EPersona personas[]);
/**
* Dar de baja
* @param array de la estructura que se pasa como parametro
* @param el tamaño maximo del vector persona
*/
int baja(EPersona personas[],int limite);
/**
* Ordena los usuarios
* @param array de la estructura que se pasa como parametro
* @param el tamaño maximo del vector persona
*/
void ordenarPersona(EPersona persona[], int limite);
/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona Persona[], int dni, int limite);


#endif // FUNCIONES_H_INCLUDED
