#include "programa061.h"

int main(int argc, char const *argv[])
{
    Pila miPila = crearPila();
    Push(&miPila,10);
    printf("El valor del tope es: %d\n", miPila.tope);
    printf("El valor dentro del tope es: %d\n", miPila.lista[miPila.tope-1]);

    Push(&miPila,12);
    Push(&miPila,13);
    Push(&miPila,14);

    printf("El valor dentro del tope es: %d\n", top(miPila));


    //!Se le resta una el tope luego se mostrarse
    printf("El valor dentro del tope restado es: %d\n", pop(&miPila));

    pop(&miPila);
    pop(&miPila);
    pop(&miPila);
    pop(&miPila);

    return 0;
}
