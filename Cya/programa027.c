/* Ungrese un numero y calcule e imprima su raiz cuadrada.
so  el numero es
negativo imprima el numero y un mensaje que diga tiene raiz imaginaria*/

#include <stdio.h>
#include <math.h>

int main()
{
    float numero;
    float raizCuadrada;

    printf("Escribe un numero\n");
    scanf("%f", &numero);

    if (numero>= 0)
    {
        raizCuadrada = sqrt(numero);
        printf("su raiz Cuadrada = %.2f\n", raizCuadrada);
    }else {
        printf("un numero es imaginario\n");
    }
    
    return 0;
}
