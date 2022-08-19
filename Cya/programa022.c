#include <stdio.h>

int main()
{
    int a = 1;
    int b = ++a;

    printf("El valor de a es de: %i\n", a);
    printf("El valor de b es de: %i\n\n\n", b);

    int c = 1;
    int d = c++;

    printf("El valor de c es de: %i\n", c);
    printf("El valor de d es de: %i\n", d);

    return 0;
}