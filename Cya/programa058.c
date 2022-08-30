
#include "programa058.h"

int main(int argc, char const *argv[])
{
    void llenarAlumno(Alumno *din);
    /* printf("Tamanio de objeto Alumno = %d\n", sizeof(Alumno)); */
    Alumno *din1,*din2,*din3;

    din1 = (Alumno *)malloc(5*sizeof(Alumno));
    din2 = (Alumno *)calloc(5, sizeof(Alumno));

    /* printf("Primer apuntador\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Direccion [%d] = %p\n",i,din1+i);
    }printf("\n");
    printf("Segundo apuntador\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Direccion [%d] = %p\n",i,din2+i);
    }printf("\n");


    printf("Con realloc\n"); */

    din3 = (Alumno *)realloc(din2,10*sizeof(Alumno));
    /* for (int i = 0; i < 10; i++)
    {
        printf("&din3[%d] = %p\n", i, din3+i);
    } */
    
    llenarAlumno(din1);
    llenarAlumno(din2);

    printf("\n\nDatos Alumno 1\n");
    printf("Nombre del Alumno %s\n", din1->nombre);
    printf("Apellido del Alumno %s\n", din1->apellido);
    printf("Numero de cuenta del Alumno %d\n", din1->numCuenta);
    printf("Promedio del Alumno %.2f\n", din1->promedio);
    printf("Direccion del alumno: %s #%d, barrio: %s, codigo postal: %d\n\n\n",din1->domicilio.calle,din1->domicilio.num,din1->domicilio.colonia,din1->domicilio.cPostal);

    printf("\n\nDatos Alumno 2\n");
    printf("Nombre del Alumno %s\n", din2->nombre);
    printf("Apellido del Alumno %s\n", din2->apellido);
    printf("Numero de cuenta del Alumno %d\n", din2->numCuenta);
    printf("Promedio del Alumno %.2f\n", din2->promedio);
    printf("Direccion del alumno: %s #%d, barrio: %s, codigo postal: %d\n\n\n",din2->domicilio.calle,din2->domicilio.num,din2->domicilio.colonia,din2->domicilio.cPostal);

    free(din1);
    free(din2);

    system("PAUSE");

    return 0;
}

    void llenarAlumno(Alumno *din){
        printf("LLena los datos del alumno\n\n");
        printf("Escribe su nombre\n");
        fflush(stdin);
        gets(din->nombre);

        printf("Escribe el apellido\n");
        fflush(stdin);
        gets(din->apellido);

        printf("Escribe su numero de cuenta\n");
        fflush(stdin);
        scanf("%d", &din->numCuenta);

        printf("Escribe su promedio\n");
        fflush(stdin);
        scanf("%f", &din->promedio);

        printf("Escribe su Calle\n");
        fflush(stdin);
        gets(din->domicilio.calle);

        printf("Escribe su numero de calle\n");
        fflush(stdin);
        scanf("%d", &din->domicilio.num);

        printf("Escribe su Barrio\n");
        fflush(stdin);
        gets(din->domicilio.colonia);

        printf("Escribe su codigo postal\n");
        fflush(stdin);
        scanf("%d", &din->domicilio.cPostal);

        crearAlumno(din->numCuenta,din->nombre,din->apellido,din->promedio,din->domicilio.calle,din->domicilio.num,din->domicilio.colonia,din->domicilio.cPostal);
        ImprimirAlumno(*din);
    }
