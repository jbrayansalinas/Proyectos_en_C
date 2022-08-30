/* Matrices */

#include <stdio.h>

int main()
{
    /* int hola[2][2][3] = {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}}; */

    /* printf("hola [1][2] = %d\n", hola[1][2]); */

    /* for (int i = 0; i < 6; i++)
    {
        hola[i];
        printf("hola = %d\n", hola[i]);
    } */
    
   /*  for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 3; k++)
            {
                printf("%d ", hola[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    } */

    printf("Digite un numero\n");
    int n;    scanf("%d", &n);
    int otro, array[n][n];

    if (n>1){
        for (int i = 0; i < n; i++){
        for (int j = 0; j < (n-1); j++){
            scanf("%d ", &array[i][j]);
        }
        printf("\n");
    }
    }
    
    
    


    return 0;
}