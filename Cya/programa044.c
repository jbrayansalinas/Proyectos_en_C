/* 
*Struct
*/

#include <stdio.h>

struct persona
{
    char nombre[20];
    int edad;
}personas[5];

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        fflush(stdin);

        printf("\n%i) Escribe tu nombre: \n", i+1);
        gets(personas[i].nombre);
        printf("%i) Escribe tu edad: \n", i+1);
        scanf("%i", &personas[i].edad);
    }
    
    

    for (i = 0; i < 5; i++)
    {
        printf("\n%i) Su nombre es: %s", i+1, personas[i].nombre);
        printf("\n%i) La edad es: %i\n", i+1, personas[i].edad);
    } printf("\n\n");
    
    
    return 0;
}
