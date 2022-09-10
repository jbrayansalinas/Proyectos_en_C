#include "CajaRegistradora.h"

int main(){
    ListaProducto listaProducto = crearListaProducto();
    ListaVenta  listaVenta = crearListaVenta();
    int opcion, continuar,bandera =1;
    char comprador[30];
    //Funcion para calcular la fecha actual
    time_t t=time(NULL);
    struct tm *tm = localtime(&t);
    char fechayhora[100];
    strftime(fechayhora, 100, "%d/%m/%Y", tm);

    agregarProducto(&listaProducto,"papa",1000,15);
    agregarProducto(&listaProducto,"yuca",2000,25);
    imprimirProducto(listaProducto);
    struct Productos producto;
    /*strcpy(producto.nombre,"yuca");
    producto.cantidad = 3;
    registrarVenta(&listaVenta,&listaProducto,fechayhora,"Yop",producto);
    inventario(listaVenta);*/
    imprimirProducto(listaProducto);

    while (bandera !=0) {
        printf("\n\tCaja resgistradora\n");
        printf("Escoja una opcion: \n");
        printf("1) Registrar venta\n");
        printf("2) Inventario\n");
        printf("3) Lista Ventas\n");
        printf("0) Salir\n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                do {
                    printf("Nombre del comprador: ");
                    fflush(stdin);
                    gets(comprador);
                    printf("Nombre del producto: ");
                    fflush(stdin);
                    gets(producto.nombre);
                    printf("cantidad: ");
                    fflush(stdin);
                    scanf("%d", &producto.cantidad);
                    registrarVenta(&listaVenta, &listaProducto, fechayhora, comprador, producto);
                    printf("Desea agregar otro producto? 1)SI 2)NO");
                    scanf("%d", &continuar);
                } while (continuar != 2);
                printf("Se agrego correctamente\n");
                break;
            case 2:
                break;
            case 3:
                inventario(listaVenta);
                break;
            case 0:
                printf("Gracias por usar la caja registradora\n");
                bandera = 0;
                break;
            default:
                printf("Opcion incorrecta\n");
                break;

        }
    }

    return 0;
}