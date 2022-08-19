#include<stdio.h>
#include<conio.h>

int main(){

    int lado, perimetro;
    printf("Ingrese el lado: ");
    scanf("%i", &lado);
    perimetro = lado * 4;
    printf("El perimetro es: ");
    printf("%i", perimetro);
    getch();
    return 0;
}

