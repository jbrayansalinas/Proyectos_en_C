#include <stdio.h>


typedef struct persona
{
    int edad;
    float dinero;
    char nombre[20];
}cliente;

cliente juan,*pJuan = &juan;

int main(int argc, char const *argv[])
{
    juan.edad=20;
    printf("El valor de la edad de Juan es de %d\n", juan.edad);
    (*pJuan).edad=30;
    printf("El valor de la edad de Juan es de %d\n", juan.edad);
    pJuan->edad=50;
    printf("El valor de la edad de Juan es de %d\n", pJuan->edad);
    
    return 0;
}