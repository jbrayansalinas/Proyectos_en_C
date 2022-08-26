#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* 
    !limite de datos con memoria estatica
    !214748364
    int array[214748364]; */


    /* int *myInteger;
    myInteger = (int*)malloc(4);
    if (myInteger != NULL)
        printf("La memoria se ha otorgado\n");
    else
        printf("Error al adquirir la memoria"); */

    //!Usando sizeof
    /* int *array;
                                //4*8
    array = (int*)malloc(sizeof(int)*8);
    if(array != NULL)
        printf("La memoria se ha otrogado\n");
    else
        printf("Error al adquirir la memoria\n");
    free(array); */

    //!define tamaño
    /* #define SIZE 10000000000

    int *array = (int*)malloc(sizeof(int)*SIZE);
    if(array == NULL)
        printf("Se alcanzó el limite de memoria\n");
    free(array); */

    //!imprime el valor de un puntero
    int *a;
        a = malloc(sizeof(int));
        *a = 5;
        printf("%i",*a);
        free(a);

    return 0;
}