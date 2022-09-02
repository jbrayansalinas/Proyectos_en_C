#include "programa064.h"

int main(int argc, char const *argv[])
{
    int cantidadDocumentos;
    printf("Cuantos documentos quieres registrar?\n");
    fflush(stdin);
    scanf("%d",&cantidadDocumentos);

    Documento *apuntadorDocumento = (Documento *)malloc(cantidadDocumentos*sizeof(Documento));

    Cola documentoCola = crearCola();

    for (int i = 0; i < cantidadDocumentos; i++)
    {
        printf("\nEscribe el nombre del documento [%i]\n",(i+1));
        fflush(stdin);
        fgets(apuntadorDocumento[i].nombre,30,stdin);
        printf("Escribe el autor del documento [%i]\n",(i+1));
        fflush(stdin);
        fgets(apuntadorDocumento[i].autor,30,stdin);
        printf("Escribe el numero de paginas del documento [%i]\n",(i+1));
        fflush(stdin);
        scanf("%d",&apuntadorDocumento[i].numeroPaginas);
        printf("Escribe el tamanio del documento [%i]\n",(i+1));
        fflush(stdin);
        scanf("%d",&apuntadorDocumento[i].tamanio);

        encolar(&documentoCola,apuntadorDocumento[i]);

    }
        printf("\n\t***Comenzando la impresion***\n");
    float total = 0.0;
    for (int i = 0; i < cantidadDocumentos; i++)
    {
        Documento ColaRegresada = desencolar(&documentoCola);
        printf("Nombre: %s\n",ColaRegresada.nombre);
        float tiempoSegundo= (ColaRegresada.numeroPaginas)*3;
        (tiempoSegundo) /= 60;
        printf("EL tiempo de impresion en minutos es: %.2f\n", tiempoSegundo);
        total += tiempoSegundo;
    }

    printf("Tiempo total de impresion %.2f\n",total);
        

    return 0;
}