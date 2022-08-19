//strrev: invertir la cadena

#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[] = "hola";

    strrev(cadena);
    printf("Cadena invertida: %s", cadena);

    return 0;
}
