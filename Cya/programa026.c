// Hacer un programa que borre la pantalla al pulsar 1
#include <stdio.h>
#include <stdlib.h>

int main(){

    int numero;
    printf("\n Programa que borra la pantalla al pulsar 1\n");
    printf("-----------------------------------------------\n");
    printf("Escribe el numero 1\n");
    scanf("%i",&numero);

    if (numero == 1)
    {
        system("cls");
        printf("Ha borrado la pantalla\n");
    }else{
        printf("El numero ingresado no es 1\n");
        printf("Escribe el numero 1\n");
        scanf("%i",&numero);
        if (numero == 1)
    {
        system("cls");
        printf("Ha borrado la pantalla\n");
    }
    }
}