#include "operaciones.h"

int main(int argc, char const *argv[])
{
    int *p_a,*p_b,a=10,b=5;
    p_a=&a;
    p_b=&b;

    int respuestaSuma = suma(p_a, p_b);
    int respuestaResta = resta(p_a, p_b);
    int respuestaMultiplicacion = multiplicacion(p_a, p_b);
    int respuestaDivision = division(p_a, p_b);

    printf("\nEl valor de la suma es: %i", respuestaSuma);
    printf("\nEl valor de la resta es: %i", respuestaResta);
    printf("\nEl valor de la multiplicacion es: %i", respuestaMultiplicacion);
    printf("\nEl valor de la divicion es: %i", respuestaDivision);
    
    return 0;
}
