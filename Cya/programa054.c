//Uso de malloc y calloc

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nombre[20], *p_nombre;
    int longitud;

    strcpy(nombre, "Jorge");
    longitud = strlen(nombre);

    printf("La longitud del nombre es: %i\n",longitud);

    /* p_nombre = calloc((longitud+1),sizeof(char)); */ //?limpia la memoria antes de traer el dato, es decir que viene en 0
    p_nombre = malloc((longitud+1)*sizeof(char)); //?Acá se multiplica

    strcpy(p_nombre,nombre);
    printf("Nombre: %s", p_nombre);

    free(p_nombre);
    printf("\nNombre: %s", p_nombre);

    return 0;
}
