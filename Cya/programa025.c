//Simular una ienda con entradas y salidas de capital

#include <stdio.h>

int main()
{
    int opcion;
    float agregar, retirar;
    float saldo=3000;

    printf("\n\t*****************************************\n");
    printf("\t*Este es un Simulador de tienda o cajero*\n");
    printf("\t*****************************************\n\n");
    printf("\tSelecciona una opcion\n\n");
    printf("\t1) Depositar dinero\n");
    printf("\t2) Retirar dinero\n");
    printf("\t3) Salir del cajero\n");
    printf("\nOpcion seleccionada: \n");
    scanf("%i", &opcion);

    switch (opcion) {
    case 1:
        printf("Cuanto dinero quiere depositar? \n");
        scanf("%f", &agregar);
        saldo += agregar;
        printf("Tu saldo actual es: %.1f\n", saldo);
    break;
    
    case 2:
        printf("Cuanto dinero quiere retirar? \n");
        scanf("%f", &retirar);
        if (retirar>saldo)
        {
            printf("Tu saldo disponible solo es de %.1f\n", saldo);
        } else {
            saldo -= retirar;
            printf("Tu saldo actual es: %.1f\n", saldo);
        }
    break;
    case 3: 
        printf("Gracias por usar la aplicacion \n hasta la proxima");
        default:
    break;
    }

    return 0;
}


    