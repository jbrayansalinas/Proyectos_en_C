#include "CajaRegistradora.h"

int main(){
    ListaProducto listaProducto = crearListaProducto();
    ListaVenta  listaVenta = crearListaVenta();
    ListaProducto otrosProductos = crearListaProducto();
    struct NodoProducto producto;
    int opcion, continuar,bandera =1,cantProductos=0,otraOpcion;
    char comprador[30];
    //Funcion para calcular la fecha actual
    time_t t=time(NULL);
    struct tm *tm = localtime(&t);
    char fechayhora[100];
    strftime(fechayhora, 100, "%d/%m/%Y", tm);

    /*strcpy(producto.nombre,"yuca");
    producto.cantidad = 25;
    producto.precio = 2000;
    agregarProducto(&listaProducto,producto);

    strcpy(producto.nombre,"papa");
    producto.cantidad = 15;
    producto.precio = 1000;

    agregarProducto(&listaProducto,producto);
    imprimirProducto(listaProducto);


    strcpy(comprador,"johs");
    strcpy(producto.nombre,"yuca");
    producto.cantidad = 5;
    agregarProducto(&otrosProductos,producto);
    strcpy(producto.nombre,"papa");
    producto.cantidad = 4;
    agregarProducto(&otrosProductos,producto);
    cantProductos=2;
    registrarVenta(&listaVenta,&listaProducto,&otrosProductos,fechayhora,comprador, cantProductos);
    strcpy(producto.nombre,"yuca");
    strcpy(comprador,"brayan");
    producto.cantidad = 3;
    agregarProducto(&otrosProductos,producto);
    cantProductos=1;
    registrarVenta(&listaVenta,&listaProducto,&otrosProductos,fechayhora,comprador, cantProductos);
    listaVentas(listaVenta);
    imprimirProducto(listaProducto);*/

    while (bandera !=0) {
        system("clear");
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
                printf("Nombre del comprador: ");
                fflush(stdin);
                gets(comprador);
                do {
                    printf("Nombre del producto: ");
                    fflush(stdin);
                    gets(producto.nombre);
                    printf("cantidad: ");
                    fflush(stdin);
                    scanf("%d", &producto.cantidad);
                    printf("Desea agregar otro producto? 1)SI 2)NO");
                    scanf("%d", &continuar);
                    cantProductos += 1;
                    agregarProducto(&otrosProductos,producto);
                } while (continuar == 1);
                    registrarVenta(&listaVenta,&listaProducto,&otrosProductos,fechayhora,comprador, cantProductos);
                printf("Se agrego correctamente\n");
                cantProductos=0;
                break;
            case 2:
                printf("Escoja una opcion\n");
                printf("1) Crear Producto\n");
                printf("2) Listar Productos\n");
                printf("3) Regresar\n");
                fflush(stdin);
                scanf("%d", &otraOpcion);
                switch (otraOpcion) {
                    case 1:
                        printf("\nNombre del producto: ");
                        fflush(stdin);
                        gets(producto.nombre);
                        printf("Precio: ");
                        fflush(stdin);
                        scanf("%d", &producto.precio);
                        printf("Cantidad: ");
                        fflush(stdin);
                        scanf("%d", &producto.cantidad);
                        agregarProducto(&listaProducto,producto);
                        break;
                    case 2:
                        imprimirProducto(listaProducto);
                        break;
                    case 3:
                        system("clear");
                        break;
                }
                break;
            case 3:
                listaVentas(listaVenta);
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