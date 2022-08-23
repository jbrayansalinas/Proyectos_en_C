/* Promedio alumno */

#include <stdio.h>
#include <string.h>

struct Alumno
{
    char nombre[20];
    int edad;
    float promedio;
}Alumnos[3];




int main(int argc, char const *argv[])
{
    int posicion;
    float mejorCalificacion = 0;
    for (int i = 0; i < 3; ++i)
    {
            fflush(stdin);
            printf("Ingrese el nombre del alumno %d: ", i+1);
            fgets(Alumnos[i].nombre, 20, stdin);
            strtok(Alumnos[i].nombre, "\n");

            printf("Ingrese la edad del alumno %d: ", i+1);
            scanf("%d", &Alumnos[i].edad);

            printf("Ingrese el promedio del alumno %d: ", i+1);
            scanf("%f", &Alumnos[i].promedio);
            printf("\n");
    }

    for (int i = 0; i < 3; ++i)
    {
        if (Alumnos[i].promedio > mejorCalificacion)
        {
            mejorCalificacion = Alumnos[i].promedio;
            posicion =i;
        }
    }
    
    printf("El alumno con mejor promedio es: \n");
    printf("Nombre: %s\n", Alumnos[posicion].nombre);
    printf("Edad: %d\n", Alumnos[posicion].edad);
    printf("Promedio: %.2f\n", Alumnos[posicion].promedio);



    return 0;
}