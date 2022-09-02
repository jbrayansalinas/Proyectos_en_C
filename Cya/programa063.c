#include "programa063.h"

int main(int argc, char const *argv[])
{
    Cola colita=crearCola();
    Cola colota=crearCola();

    printf("El primer elemeto de la cola es %d\n", colita.primero);
    printf("El ultimo elemeto de la cola es %d\n", colita.ultimo);

    printf("La cola esta vacia? %d\n", isEmpty(colita));

    encolar(&colita,10);
    encolar(&colita,13);
    encolar(&colita,19);

    encolar(&colota,10);
    encolar(&colota,13);
    encolar(&colota,19);

    printf("La cola esta vacia? %d\n", isEmpty(colita));

    printf("%d\n",desencolar(&colita));
    printf("%d\n",desencolar(&colita));
    printf("%d\n",desencolar(&colita));
    
    printf("%d\n",desencolar(&colota));
    printf("%d\n",desencolar(&colota));
    printf("%d\n",desencolar(&colota));
    
    return 0;
}