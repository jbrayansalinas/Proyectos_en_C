/* 
*Struct
*/

#include <stdio.h>

struct persona
{
    char nombre[20];
    int edad;
}
persona1/*  = {"Jorge", 19} */, 
persona2/*  = {"Ricardo",18} */;

int main(int argc, char const *argv[])
{

    printf("Escribe tu nombre: \n");
    gets(persona1.nombre);
    printf("Escribe tu edad: \n");
    scanf("%i", &persona1.edad);
    fflush(stdin);



printf("\nEscribe otro nombre: \n");
    gets(persona2.nombre);
    printf("Escribe otra edad: \n");
    scanf("%i", &persona2.edad);


    printf("Su nombre es: %s \n", persona1.nombre);
    printf("La edad es: %i\n\n", persona1.edad);

    printf("Su nombre es: %s \n", persona2.nombre);
    printf("La edad es: %i", persona2.edad);
    return 0;
}
