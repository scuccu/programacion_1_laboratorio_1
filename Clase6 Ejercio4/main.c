#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char palabra1[15];
   char palabra2[15];
   char buffer[1024];
   int i;
   int cant;
   int comp;

    printf("\nIngrese una palabra: ");
    fflush(stdin);
  gets(buffer);

    while(strlen(buffer)>14)
    {
        printf("\nReingrese una palabra: ");
        fflush(stdin);
        gets(buffer);
    }

  strcpy(palabra1, buffer);
  strcpy(palabra2, "Gato");
  comp=strcmp(palabra2, palabra1);

printf("\nComparacion: %d",comp);

  printf("\npalabra1: %s\nPalabra2: %s",palabra1,palabra2);

    return 0;
}
