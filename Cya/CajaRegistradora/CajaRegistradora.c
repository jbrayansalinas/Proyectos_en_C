#include "CajaRegistradora.h"

int main(){
    ListaProducto listaProducto = crearListaProducto();
    ListaVenta  listaVenta = crearListaVenta();
    printf("Digite un producto: \n");
    agregarProducto(&listaProducto,"johs",1000,15);
    agregarProducto(&listaProducto,"brayan",2000,25);
    imprimirProducto(listaProducto);
    return 0;
}