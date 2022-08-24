/* 
*Manejo de archivos 


? r -> Lectura, el archivo debe existir
? w -> Escritura, si el archivo no existe, se crea, si existe, se sobrescribe
? a -> Escritura al final del documento. Si no existe se cera
? rb -> Binario, para lectura
? r+ -> Lectura y escritua, el archivo debe existir
? w+ -> Crea un archivo para escritura, si existe se sobrescribe
? rb+ -> Binario. Para actualizacion (Lectura y escritura)


!fopen() -> abre un archivo
!fclose() -> Cierra un archivo
!fgets() -> Lee una cadena de un archivo
!fputs() -> Escribe una cadena en un archivo
!fseek() -> Busca un byte especifico de un archivo
!fprintf() -> Escribe una salida con formato en el archivo
!fscanf() -> una entrada con formato desde el archivo
!feof() -> Devuelve cierto si se llega al final del archivo
!ferror() -> Devuelve ecierto si se produce un error
!rewind() -> Coloca el localizador de posicion del archivo al principio del mismo
!remove() -> Borra un archivo
!fflush() -> Vacía un archivo

*/


/* //*fopen



 !Saber si el archivo existe
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fd;

    char direccion[] = "C:\\Users\\Wposs\\Documents\\C\\Proyectos_en_C\\Cya\\prueba_Programa049.txt";

    fd = fopen(direccion, "r");

    if (fd == NULL)
    printf("El archivo no existe");
    else {
        printf(">Se encontro el arcchivo\n");
        printf("Su ubicacion es: %s\n", direccion);
    }
    
  return 0;
} */

/* 
//* creacion de archivo

#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE* Archivo = fopen("Prueba.txt", "at");

    if (Archivo == NULL)
        printf("Error al intentar crear/acceder al archivo");
    else{
        char Texto;

        !sale al dar enter
        ////(Texto = getchar()) != '\n'
        !sale al dar ctrl + z
        while ((Texto = getchar()) != EOF)
        {
            fputc(Texto,Archivo); //!Escribe lo que digite en el archivo
        }
        
    }

    fclose(Archivo);

    return 0;
} */








//*Leer un archivo

#include <stdio.h>
#include <stdlib.h>

FILE *fd;

int main(int argc, char const *argv[])
{
    int c;
    char direccion[]= "C:\\Users\\Wposs\\Documents\\C\\Proyectos_en_C\\Cya\\prueba_Programa049.txt";

    fd = fopen(direccion, "rt");

    if (fd == NULL)
    {
        printf("Error al tratar de leer el archivo");
        return 1;
    }

    while ((c= fgetc(fd)) != EOF)
    {
        if (c=='\n')
        {
            printf("\n");
        }else {
            putchar(c);
        }
    }
    
    fclose(fd);
    return 0;
}

