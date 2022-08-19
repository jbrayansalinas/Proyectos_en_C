#include<stdio.h>
#include<conio.h>

int main(){

    int num1, num2, suma, producto;
    printf("Ingrese primer valor: ");
    scanf("%i", &num1);
    printf("Ingrese segundo valor: ");
    scanf("%i", &num2);
    suma = num1 + num2;
    producto = num1 * num2;
    printf("La suma de los dos valores es: ");
    printf("%i", suma);
    printf("\n");
    printf("El producto de los dos valores es: ");
    printf("%i", producto);
    getch();
    return 0;
}