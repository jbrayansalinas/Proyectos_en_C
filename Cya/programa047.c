#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *pNumero,numero=20;
    printf("Dato %i", numero);
    printf("\nPosicion %p\n",&numero);

    pNumero = &numero;
    printf("\nValor de la variable\n");
    printf("Dat: %i", numero);
    printf("\nDato: %i\n", *pNumero);

    printf("\nPosicion de memoria:");
    printf("\nPosicion: %p", &numero);
    printf("\nPosicion %p", pNumero);

    return 0;
}
