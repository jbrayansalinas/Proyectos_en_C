#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int *dinamico = (int *)malloc(4*sizeof(int));
    int i;

    *dinamico = 10;
    *(dinamico+1) = 20;
    dinamico[2] =30;

    printf("%d\n", *(dinamico+2));
    *(dinamico +2) = 20;
    printf("%d\n", dinamico[2]);
    *(dinamico +3) = 40;

    int *dino = (int *)realloc(dinamico, sizeof(int)*10);
    for (i = 0; i < 10; i++)
    {
        *(dino+i) = (i+1)*10;
        printf("%d ", *(dino+i));
        printf("%p\n", (dino +i));
    }
    
    return 0;
}