//strrchr: es como un substring

#include <stdio.h>
#include <string.h>

int main()
{
    char abecedario[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char corte;

    printf("\nLetra donde se cortara el abecedario: ");
    fflush(stdin);
    scanf("%c",&corte);
    printf("\n%s", strrchr(abecedario,corte));

    return 0;
}
