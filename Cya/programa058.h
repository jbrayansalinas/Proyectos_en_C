#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Direccion
{
    char calle[20];
    int num;
    char colonia[20];
    int cPostal;
}Direccion;

typedef struct Alumno
{
    int numCuenta;
    char nombre[15];
    char apellido[15];
    float promedio;
    Direccion domicilio;
}Alumno;

Alumno crearAlumno(int,char*,char*,float,char*,int,char*,int);

void ImprimirAlumno(Alumno);


Alumno crearAlumno(int numeroCuenta, char* nombre, char* apellido, float promedio, char* calle, int num, char* colonia, int cPostal){
    Alumno alumnoCreado;
    alumnoCreado.numCuenta = numeroCuenta;
    strcpy(alumnoCreado.nombre,nombre);
    strcpy(alumnoCreado.apellido,apellido);
    alumnoCreado.promedio = promedio;
    strcpy(alumnoCreado.domicilio.calle,calle);
    alumnoCreado.domicilio.num = num;
    strcpy(alumnoCreado.domicilio.colonia,colonia);
    alumnoCreado.domicilio.cPostal = cPostal;



    return alumnoCreado;
}

void ImprimirAlumno(Alumno alumnoPrint){
    printf("\n\nNumero de Cuenta: %d\n", alumnoPrint.numCuenta);
    printf("Nombre del alumno: %s\n", alumnoPrint.nombre);
    printf("Apellido del alumno: %s\n", alumnoPrint.apellido);
    printf("Promedio del alumno: %.2f\n", alumnoPrint.promedio);
    printf("Direccion del alumno: %s #%d, barrio: %s, codigo postal: %d\n\n\n", alumnoPrint.domicilio.calle, alumnoPrint.domicilio.num, alumnoPrint.domicilio.colonia, alumnoPrint.domicilio.cPostal);
}