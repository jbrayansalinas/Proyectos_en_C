#include<stdio.h>

int main(){

    int horastrabajadas;
    float costohora;
    float sueldo;
    printf("ingrese las horas trabajadas por el empleado: ");
    scanf(" %i", &horastrabajadas);
    printf("ingrese el pago por hora: ");
    scanf("%f", &costohora);
    sueldo = horastrabajadas*costohora;
    printf("el sueldo total del operativo es ");
    printf("%f", sueldo);
    getchar();
    return 0;
}