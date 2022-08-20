/* Recursividad con funciones */

#include <stdio.h>

void cuentaRegresiva(int numeroActual){
    if (numeroActual <0)
    return;
    else{
        printf("\n%d", numeroActual);
        cuentaRegresiva(numeroActual-1);
    }   
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Numero a empezar: \n");
    scanf("%d", &n);
    cuentaRegresiva(n);

    return 0;
}
