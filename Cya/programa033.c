/* Funciones matematicas y Funciones trigonométricas*/


#include <stdio.h>
#include <math.h>

/*******************************************************************
*   ceil(x) -> Redondea al entero mayor mas cercano
*   fabs(x) -> Devuelve el valor absoluto de x
*   floor(x) -> Redondea al entero menor más cercano 
*   sqrt(x) -> Saca la raíz cuadrada de x
*   fmod(x, y) -> Calcula el resto de la division de x/y
*   pow(x, y) -> Calcula x elevado a la potencia de y
********************************************************************
*    acos(x) -> Calcula el arco coseno de x
*    asin(x) -> Calcula el arco seno de x
*    atan(x) -> Calcula el arco tangente de x
*    cos(x) -> Calcula el coseno de x
*    sin(x) -> Calcula el seno de x
*    tan(x) -> Calcula la tangente de x
********************************************************************/
void funcionMate();
 
int main()
{
    funcionMate();
    return 0;
}

void funcionMate(){
    double x, y, cambio=0;
    printf("Escribe el numero: \n");
    scanf("%lf", &x);

    cambio = ceil(x);
    printf("%.2lf entero mayor mas cercano \n", cambio);

    cambio = fabs(x);
    printf("%.2lf valor absoluto \n", cambio);

    cambio = floor(x);
    printf("%.2lf entero menor \n", cambio);

    cambio = sqrt(x);
    printf("%.2f raíz cuadrado \n", cambio);

    printf("Escribe otro numero \n");
    scanf("%lf", &y);
    cambio = fmod(x, y);
    printf("%.2lf mod \n", cambio);

    cambio = pow(x, y);
    printf("%.2lf elevado \n", cambio);
}