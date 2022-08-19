//strlwr: convertir todo a minuscula
//strupr: convertir todo a mayuscula

#include <stdio.h>
#include <string.h>

int main() {

    char texto[100];
    printf("Escriba un texto con mayusculas y minusculas: \n");
    fflush(stdin);
    gets(texto);

    printf("\nEl nuevo texto en minusculas es el siguente: \n");
    printf("%s", strlwr(texto));
    printf("\n\nEl nuevo texto en mayusculas es el siguente: \n");
    printf("%s", strupr(texto));



return 0;  
}