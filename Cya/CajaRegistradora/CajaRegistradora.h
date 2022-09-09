#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Productos{
    int idProducto;
    char nombre[30];
    int precio;
    int cantidad;
}Productos;
typedef struct Venta{
    int idVenta;
    char fecha[20];
    char comprador[30];
    Productos productos;
}Venta;
typedef struct NodoVenta{
    Venta venta;
    struct NodoVenta* next;
}NodoVenta;
typedef struct NodoProducto{
    Productos productos;
    struct NodoProducto* sig;
}NodoProducto;
typedef struct ListaVenta{
    struct NodoVenta* head;
    int tamanoV;
}ListaVenta;
typedef struct ListaProducto{
    struct NodoProducto* primer;
    int tamanoP;
}ListaProducto;

ListaVenta crearListaVenta(){
    ListaVenta listaVenta;
    listaVenta.head=NULL;
    listaVenta.tamanoV = 0;
    return listaVenta;
}

ListaProducto crearListaProducto() {
    ListaProducto listaProducto;
    listaProducto.primer = NULL;
    listaProducto.tamanoP = 0;
    return listaProducto;
}

void agregarProducto(ListaProducto *listaProducto, char nombre[], int precio, int cantidad){
    NodoProducto *temporal,*nodoProducto;
    int tamano = listaProducto->tamanoP,cont=0;
    nodoProducto = (NodoProducto*) calloc(1,sizeof (NodoProducto));
        strcpy(nodoProducto->productos.nombre, nombre);
        nodoProducto->productos.precio = precio;
        nodoProducto->productos.cantidad = cantidad;
        if (listaProducto->primer == NULL)
            nodoProducto->sig = nodoProducto;
        else {
            nodoProducto->sig = listaProducto->primer;
            temporal = listaProducto->primer;
            while (temporal->sig != listaProducto->primer)
                temporal = temporal->sig;
            temporal->sig = nodoProducto;
        }
        listaProducto->primer = nodoProducto;
        listaProducto->tamanoP++;
    for (int i = 0; i < tamano; i++) {
        nodoProducto->productos.idProducto = tamano;
        printf("Ya se agrg%c el producto\n\n", 162);
    }
}

void imprimirProducto(ListaProducto listaProducto){
    if (listaProducto.primer == NULL)
        printf("La lista esta vacia\n");
    else{
        int tamano = listaProducto.tamanoP;
        printf("Los productos son: \n");
        NodoProducto *current = listaProducto.primer;
        while (tamano>0){
            printf("id: %d\n",current->productos.idProducto);
            printf("Nombre: %s\n",current->productos.nombre);
            printf("Precio: %d\n",current->productos.precio);
            printf("Cantidad: %d\n",current->productos.cantidad);
            current = current->sig;
            tamano--;
        }
    }
}

void registrarVenta(ListaVenta *listaVenta, char fecha[], char Comprador[], Productos productos){
    NodoVenta *nodoVenta, *temporal;
    nodoVenta = (NodoVenta*) calloc(1,sizeof (NodoVenta));

}