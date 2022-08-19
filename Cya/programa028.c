/* Continue y break */

#include <stdio.h>

int main()
{
    int numero;
    printf("Escribe el numero que sera ignorado : ");
    scanf("%d", &numero);

    for (int i = 0; i <= 100; i++)
    {
        if (i==numero)       
            continue;//salta a la siguiente iteracion
            printf("\n%d ", i);    
    }
    printf("\n\n");
    for (int i = 0; i <= 100; i++)
    {
        if (i==24)
            break; //sale del for
        printf("\n%d ", i);
        
    }

    return 0;
}
