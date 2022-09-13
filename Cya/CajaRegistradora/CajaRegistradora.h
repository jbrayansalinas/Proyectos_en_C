#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct NodoProducto{
    int idProducto;
    char nombre[30];
    int precio;
    int cantidad;
    struct NodoProducto* sig;
}NodoProducto;
typedef struct ListaProducto{
    struct NodoProducto* primer;
    int tamanoP;
}ListaProducto;
typedef struct NodoVenta{
    int idVenta;
    char fecha[20];
    char comprador[30];
    int cantidadVenta;
    struct ListaProducto* listaProducto;
    struct NodoVenta* next;
}NodoVenta;
typedef struct ListaVenta{
    struct NodoVenta* head;
    int tamanoV;
}ListaVenta;

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

void agregarProducto(ListaProducto *listaProducto, struct NodoProducto producto){
    NodoProducto *temporal,*nodoProducto = NULL;
    nodoProducto = (NodoProducto*) calloc(1,sizeof (NodoProducto));

    strcpy(nodoProducto->nombre, producto.nombre);
    nodoProducto->precio = producto.precio;
    nodoProducto->cantidad = producto.cantidad;
    int tamano = 0;
    tamano = listaProducto->tamanoP++;
    nodoProducto->idProducto = tamano;
        /*printf("Ya se agrg%c el producto\n\n", 162);*/
        if (listaProducto->primer == NULL)
            listaProducto->primer = nodoProducto;
        else {
            temporal = listaProducto->primer;
            listaProducto->primer = nodoProducto;
            listaProducto->primer->sig = temporal;
        }
}

void imprimirProducto(ListaProducto listaProducto){
    if (listaProducto.primer == NULL)
        printf("No hay productos\n");
    else{
        int tamano = listaProducto.tamanoP;
        printf("Los productos son: \n");
        NodoProducto *current = listaProducto.primer;
        while (tamano>0){
            printf("\nid: %d\n",current->idProducto);
            printf("Nombre: %s\n",current->nombre);
            printf("Precio: %d\n",current->precio);
            printf("Cantidad: %d\n",current->cantidad);
            current = current->sig;
            tamano--;
        }
    }
}

void registrarVenta(ListaVenta *listaVenta, ListaProducto *listaProducto, ListaProducto  *otrosProductos, char fecha[], char comprador[], int cantProductos){
    NodoVenta *nodoVenta = NULL, *temporal= NULL;
    struct NodoProducto producto;
    nodoVenta = (NodoVenta*) calloc(1,sizeof (NodoVenta));
    nodoVenta->listaProducto = (struct ListaProducto *) malloc(sizeof(nodoVenta));
    NodoProducto *current = NULL;
    NodoProducto *nodoProducto = NULL;
    nodoProducto = otrosProductos->primer;
    current = listaProducto->primer;
    nodoVenta->listaProducto->primer = NULL;
    nodoVenta->listaProducto->tamanoP = 0;
    int tamanoProducto = 0;
    tamanoProducto = otrosProductos->tamanoP;
    while (tamanoProducto > 0) {
        while (cantProductos>0) {
            if (strcmp(nodoProducto->nombre,current->nombre)==0) {
                if (nodoProducto->cantidad < current->cantidad) {
                    strcpy(nodoVenta->fecha,fecha);
                    strcpy(nodoVenta->comprador,comprador);
                    strcpy(nodoProducto->nombre, current->nombre);
                    current->cantidad -= nodoProducto->cantidad;
                    nodoProducto->precio = current->precio;
                    nodoProducto->idProducto = current->idProducto;
                    nodoVenta->idVenta = listaVenta->tamanoV + 1;
                    nodoVenta->cantidadVenta = nodoProducto->cantidad;
                    strcpy(producto.nombre, nodoProducto->nombre);
                    producto.precio = nodoProducto->precio;
                    producto.idProducto = nodoProducto->idProducto;
                    producto.cantidad = nodoProducto->cantidad;
                    agregarProducto(nodoVenta->listaProducto, producto);
                    cantProductos--;
                    nodoProducto = nodoProducto->sig;
                    current = current->sig;
                }
            }else current = current->sig;
        }
            tamanoProducto--;
    }
    if (listaVenta->head == NULL)
        listaVenta->head = nodoVenta;
    else {
        temporal = listaVenta->head;
        listaVenta->head = nodoVenta;
        listaVenta->head->next = temporal;
    }
    listaVenta->tamanoV++;
    otrosProductos->primer=NULL;
    otrosProductos->tamanoP=0;
}

void listaVentas(ListaVenta listaVenta){
    if (listaVenta.head == NULL)
        printf("No hay ventas\n");
    else {
        printf("\nLas Ventas son: \n\n");
        NodoVenta *current = listaVenta.head;
        int tamanoVenta = listaVenta.tamanoV;
        while (tamanoVenta>0) {
            int tamanoProducto = current->listaProducto->tamanoP;
            NodoProducto *temporal = current->listaProducto->primer;
            printf("id de la venta: %d\n", current->idVenta);
            printf("Comprador: %s\n", current->comprador);
            printf("Fecha: %s\n", current->fecha);
            while (tamanoProducto>0){
                printf("\nid del prducto: %d\n", temporal->idProducto);
                printf("Nombre del producto: %s\n", temporal->nombre);
                printf("Cantidad: %d\n", temporal->cantidad);
                printf("Precio: %d\n", temporal->precio);
                temporal = temporal->sig;
                tamanoProducto--;
            }
            current = current->next;
            tamanoVenta--;
            printf("\n********************************************\n");
        }
    }
}