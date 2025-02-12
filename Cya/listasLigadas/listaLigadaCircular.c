#include "listaLigadaCircular.h"

int main(){
    int opcion,valor,bandera=1,posicion;
    printf("Este programa usa listas ligadas circulares para evaluar sus operaciones\n");

    Lista nuevaLista = crearListaCircular();
    printf("Se creo una nueva lista circular\n");
    while (bandera !=0){
        printf("\n\tQue operacion te gustaria realizar? \n\n");
        printf("1) Agregar al principio\n");
        printf("2) Agregar al final\n");
        printf("3) Eliminar al principio\n");
        printf("4) Eliminar al final\n");
        printf("5) Imprimir la lista\n");
        printf("6) Ubicar un elemento en la lista\n");
        printf("7) Agregar enesimo\n");
        printf("8) Elimnar enesimo\n");
        printf("0) Salir \n");
        scanf("%d",&opcion);

        switch (opcion){
            case 1:
                printf("Seleccionaste agregar al principio\n Que valor te gustaria agregar?  ");
                fflush(stdin);
                scanf("%d",&valor);
                addPrincipioListaCircular(&nuevaLista,valor);
                printf("Ya se agrego %d al principio de la lista\n\n",valor);
                break;
            case 2:
                printf("Seleccionaste agregar al final\n Que valor te gustaria agregar? ");
                fflush(stdin);
                scanf("%d",&valor);
                addFinalCircular(&nuevaLista,valor);
                printf("Ya se agrego %d al final de la lista\n\n",valor);
                break;
            case 3:
                printf("Seleccionaste eliminar al principio\n");
                borrarPrimeroCircular(&nuevaLista);
                printf("Ya se elimino al principio de la lista\n\n");
                break;
            case 4:
                printf("Seleccionaste eliminar al final\n");
                borrarUltimoCircular(&nuevaLista);
                printf("Ya se elimino al final de la lista\n\n");
                break;
            case 5:
                printf("Seleccionaste imprimir lista\n");
                print_listaCircular(nuevaLista);
                break;
            case 6:
                printf("Seleccionaste Ubicar un elemento en la lista\n Que valor te gustaría buscar? ");
                fflush(stdin);
                scanf("%d",&valor);
                if (buscarCircular(nuevaLista,valor)==0)
                    printf("Numero no encontrado en la lista");
                break;
            case 7:
                printf("Seleccionaste agregar nesimo\n Que valor te gustaría agregar? ");
                fflush(stdin);
                scanf("%d",&valor);
                printf("En que posicion? ");
                fflush(stdin);
                scanf("%d",&posicion);
                agregarNesimoCircular(&nuevaLista,valor,posicion);
                printf("Ya se agrego %d en la posicion %d de la lista\n\n",valor,posicion);
                break;
            case 8:
                printf("Seleccionaste eliminar nesimo\n En que posicion te gustaría eliminar? ");
                fflush(stdin);
                scanf("%d",&posicion);
                eliminarNesimoCircular(&nuevaLista,posicion);
                printf("Ya se elimino en la posicion %d de la lista\n\n",posicion);
                break;
            case 0:
                printf("Gracias por usar el programa");
                bandera=0;
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }
    return 0;
}