//Cadenas de texto

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
   /*  system("cls"); */
    char array[100];
    printf("Ingrese un texto: ");
    fflush(stdin);
    scanf("%s", array);
    printf("\n La longitud de la cadena digitada es: %i", strlen(array));    
    
return  0; 
}    