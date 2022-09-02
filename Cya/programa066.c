#include "programa065.h"

int main(int argc, char const *argv[])
{
    int tamanio;
    printf("Ingresa el tamanio\n");
    scanf("%d",&tamanio);

    Cola queue = crearCola(tamanio);

    printf("\n\t***Primera ejecucion***\n\n");
    encolarFinal(&queue, 11);
    encolarFinal(&queue, 12);
    mostrarValores(queue);
    mostrarIndices(queue);


    printf("\n\t***Segunda ejecucion***\n\n");
    desencolarInicio(&queue);
    desencolarInicio(&queue);
    mostrarValores(queue);
    mostrarIndices(queue);


    printf("\n\t***Tercera ejecucion***\n\n");
    encolarFinal(&queue, 13);
    encolarFinal(&queue, 14);
    encolarInicio(&queue,10);
    encolarInicio(&queue,9);
    mostrarValores(queue);
    mostrarIndices(queue);

    return 0;
}
