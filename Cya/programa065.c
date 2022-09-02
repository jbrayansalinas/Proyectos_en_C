/* Cola doble */

#include "programa065.h"

int main(int argc, char const *argv[])
{
    Cola queue = crearCola(10);
    encolarInicio(&queue,10);
    encolarInicio(&queue,20);
    encolarInicio(&queue,30);
    encolarInicio(&queue,40);
    encolarInicio(&queue,50);
    encolarFinal(&queue,11);


    mostrarValores(queue);
    printf("%d\n",desencolarFinal(&queue));
    printf("%d\n",desencolarFinal(&queue));
    printf("%d\n",desencolarInicio(&queue));
    
    mostrarValores(queue);
    mostrarIndices(queue);
    return 0;
}