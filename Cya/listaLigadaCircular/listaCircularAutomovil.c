#include "listaCircularAutomovil.h"

int main(){
    int opcion,valor,bandera=1,posicion;
    char marca[20],modelo[20],color[20];

    printf("\tEste programa usa las listas ligadas circulares para evaluar sus operaciones con el TDA del automovil\t\n");

    Lista nuevaLista = crearListaCircularAutomovil();
    printf("Se creo una nueva lista\n");

    while (bandera !=0){
        printf("\n\tQue operacion te gustaria realizar? \n\n");
        printf("1) Agregar Automovil al principio\n");
        printf("2) Agregar Automovil al final\n");
        printf("3) Eliminar Automovil al principio\n");
        printf("4) Eliminar Automovil al final\n");
        printf("5) Imprimir la lista\n");
        printf("6) Ubicar un elemento en la lista\n");
        printf("7) Agregar enesimo\n");
        printf("8) Elimnar enesimo\n");
        printf("9) Recorrer lista\n");
        printf("0) Salir \n");
        scanf("%d",&opcion);

        switch (opcion){
            case 1:
                printf("Seleccionaste agregar Automovil al principio\n Marca: ");
                fflush(stdin);
                fgets(marca,20,stdin);
                strtok(marca, "\n");
                printf("Modelo: ");
                fflush(stdin);
                fgets(modelo,20,stdin);
                strtok(modelo, "\n");
                printf("Color: ");
                fflush(stdin);
                fgets(color,20,stdin);
                strtok(color, "\n");
                addPrinciíoListaAutomovil(&nuevaLista,marca,modelo,color);
                break;
            case 2:
                printf("Seleccionaste agregar Automovil al final\n Marca: ");
                fflush(stdin);
                fgets(marca,20,stdin);
                strtok(marca, "\n");
                printf("Modelo: ");
                fflush(stdin);
                fgets(modelo,20,stdin);
                strtok(modelo, "\n");
                printf("Color: ");
                fflush(stdin);
                fgets(color,20,stdin);
                strtok(color, "\n");
                addFinalCircularAutomovil(&nuevaLista,marca,modelo,color);
                break;
            case 3:
                printf("Seleccionaste eliminar al principio\n");
                borrarPrimeroCircularAutomovil(&nuevaLista);
                break;
            case 4:
                printf("Seleccionaste eliminar al final\n");
                borrarUltimoCircularAutomovil(&nuevaLista);
                break;
            case 5:
                printf("Seleccionaste imprimir lista\n");
                print_listaCirlarAutomovil(nuevaLista);
                break;
            case 6:
                printf("Seleccionaste Ubicar un elemento en la lista\n Marca: ");
                fflush(stdin);
                fgets(marca,20,stdin);
                strtok(marca, "\n");
                if (buscarCircularAutomovil(nuevaLista,marca)==0)
                    printf("Auto no encontrado en la lista");
                break;
            case 7:
                printf("Seleccionaste agregar nesimo\n Marca: ");
                fflush(stdin);
                fgets(marca,20,stdin);
                strtok(marca, "\n");
                printf("Modelo: ");
                fflush(stdin);
                fgets(modelo,20,stdin);
                strtok(modelo, "\n");
                printf("Color: ");
                fflush(stdin);
                fgets(color,20,stdin);
                strtok(color, "\n");
                printf("En que posicion? ");
                fflush(stdin);
                scanf("%d",&posicion);
                agregarNesimoCircularAutomovil(&nuevaLista,marca,modelo,color,posicion);
                break;
            case 8:
                printf("Seleccionaste eliminar nesimo\n En que posicion te gustaria eliminar? ");
                fflush(stdin);
                scanf("%d",&posicion);
                eliminarNesimoCircularAutomovil(&nuevaLista,posicion);
                break;
            case 9:
                printf("Seleccionaste recorrer lista de autos\n");
                recorrerLIstaAutomovil(nuevaLista);
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