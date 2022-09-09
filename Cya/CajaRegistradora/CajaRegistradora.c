#include "CajaRegistradora.h"

int main(){
    ListaProducto listaProducto = crearListaProducto();
    ListaVenta  listaVenta = crearListaVenta();
    //Funcion para calcular la fecha actual
    time_t t=time(NULL);
    struct tm *tm = localtime(&t);
    char fechayhora[100];
    strftime(fechayhora, 100, "%d/%m/%Y", tm);

    agregarProducto(&listaProducto,"papa",1000,15);
    agregarProducto(&listaProducto,"yuca",2000,25);
    Productos productos;
    char *nombreProducto = strcpy(productos.nombre,"papa");
    registrarVenta(&listaVenta,fechayhora,"Yop",3,nombreProducto);
    imprimirProducto(listaProducto);

    return 0;
}