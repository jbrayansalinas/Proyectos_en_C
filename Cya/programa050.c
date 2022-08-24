#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *fd;

struct datosPersona
{
    char nombre[20];
    char apellidos[20];
    char emails[30];
}datos;

int main(int argc, char const *argv[])
{
    char direccion[] = "C:\\Users\\Wposs\\Documents\\C\\Proyectos_en_C\\Cya\\prueba050.txt";
    char rpt;

    fd = fopen(direccion, "at");

    if (fd == NULL)
    {
        printf("error al tratar de localizar el archivo");
        return 1;
    }

    printf("\n\t .:Agregando emails:.\n");
    fprintf(fd, "\t.:Emails:.");

    do
    {
        fflush(stdin);

        printf("\nNombre: "); gets(datos.nombre);
        printf("Apellidos: "); gets(datos.apellidos);
        printf("Email: "); gets(datos.emails);

        //!fprintf -> (Puntero, informacion)
        //!fwrite -> (Dato a guardar, tamaño, longitud, puntero)
        fprintf(fd, "\n\nNombre: "); fwrite(datos.nombre,1,strlen(datos.nombre),fd);
        fprintf(fd, "\nApellidos: "); fwrite(datos.apellidos,1,strlen(datos.apellidos),fd);
        fprintf(fd, "\nEmail: "); fwrite(datos.emails,1,strlen(datos.emails),fd);

        printf("Desea seguir agregando mas contactos(s): ");
        scanf("%c",&rpt);

    } while (rpt == 's');
    
    
fclose(fd);

    return 0;
}
