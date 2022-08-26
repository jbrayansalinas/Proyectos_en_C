//realloc

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *vector, *vectorConvertido;
    int i;
    vector = malloc(3*sizeof(int)); //Reserva memoria para 3 elementos

    //Primer vector
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;

    for (i = 0; i <3; i++)
    {
        printf("%i ", vector[i]);
    }
    printf("\n\n");

    //Realloc
    vectorConvertido = realloc(vector, 5*sizeof(int));
    //Ampliando el arrray a 5

    //Agregamos los demas valores

    vector[3] = 4;
    vector[4] = 5;

    for (i = 0; i < 5; i++)
    {
        printf("%i ", vectorConvertido[i]);
    }

    free(vectorConvertido);
    return 0;
}