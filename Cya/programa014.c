#include<stdio.h>
#include<conio.h>

void presentacion(){

    printf("Programa que permite cargar dos valores por teclasdo.\n");
    printf("Efectua la suma de los valores\n");
    printf("Muestra el resultado de la suma\n");
    printf("**********************************\n");
}

void cargaSuma(){

    int valor1, valor2, suma;
    printf("Ingrese el primer valor: ");
    scanf("%i", &valor1);
    printf("Ingrese el segundo valor: ");
    scanf("%i", &valor2);
    suma = valor1+valor2;
    printf("La suma de los dos valores es: %i ", suma);
}

void finalizacion(){

    printf("\n**********************************\n");
    printf("Gracias por utilizar este producto");
}

int main(){

    presentacion();
    cargaSuma();
    finalizacion();
    getch();
    return 0;
}
