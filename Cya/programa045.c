#include <stdio.h>

struct infoDireccion
{
    char direccion[30];
    char ciudad[20];
    char provincia[20];
};
struct empleado
{
    char nombre[30];
    struct infoDireccion dirEmpleado;
    double salario;
}empleados[2];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 2; i++)
    {
        fflush(stdin);

        printf("%i) Escribe su nombre: ", i+1);
        gets(empleados[i].nombre);
        printf("%i) Escribe su direccion: ", i+1);
        gets(empleados[i].dirEmpleado.direccion);
        printf("%i) Escribe su ciudad: ", i+1);
        gets(empleados[i].dirEmpleado.ciudad);
        printf("%i) Escribe su provincia: ", i+1);
        gets(empleados[i].dirEmpleado.provincia);
        printf("%i) Escribe su salario: ", i+1);
        scanf("%lf", &empleados[i].salario);
        printf("\n");
    }

    for (int i = 0; i < 2; i++)
    {
        printf("\n\nDatos del empleado numero %i: ", i+1);
        printf("\nNombre: %s ", empleados[i].nombre);
        printf("\nDireccion: %s ", empleados[i].dirEmpleado.direccion);
        printf("\nCiudad: %s ", empleados[i].dirEmpleado.ciudad);
        printf("\nProvincia: %s ", empleados[i].dirEmpleado.provincia);
        printf("\nSalario: %.2lf ", empleados[i].salario);
        printf("\n");
    }
    
    
    return 0;
}


