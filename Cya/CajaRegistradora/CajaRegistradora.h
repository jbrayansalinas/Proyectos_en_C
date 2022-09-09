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
    int cantidadVenta;
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

void registrarVenta(ListaVenta *listaVenta, char fecha[], char comprador[], int cantidad, Productos productos){
    NodoVenta *nodoVenta, *temporal;
    ListaProducto listaProducto;
    nodoVenta = (NodoVenta*) calloc(1,sizeof (NodoVenta));
    strcpy(nodoVenta->venta.fecha,fecha);
    strcpy(nodoVenta->venta.comprador,comprador);

    NodoProducto *current = listaProducto.primer;
    int tamanoProducto = listaProducto.tamanoP;
    if(tamanoProducto>0) {
        while (tamanoProducto > 0) {
            if (nodoVenta->venta.productos.nombre == current->productos.nombre) {
                if (cantidad < current->productos.cantidad) {
                    strcpy(nodoVenta->venta.productos.nombre, current->productos.nombre);
                    nodoVenta->venta.cantidadVenta = cantidad;
                    current->productos.cantidad -=cantidad;
                    nodoVenta->venta.productos.precio = current->productos.precio;
                    nodoVenta->venta.productos.idProducto = current->productos.idProducto;
                    tamanoProducto--;
                } else printf("No hay suficiente suministro");
            } else printf("El producto no existe");
            current = current->sig;
        }
    }else printf("No hay productos");
}

void inventario(ListaVenta listaVenta){
    if (listaVenta.head == NULL)
        printf("La lista esta vacia\n");
    else{
        int tamano = listaVenta.tamanoV;
        printf("Las Ventas son: \n");
        NodoVenta *current = listaVenta.head;
        while (tamano>0){
            printf("id de la venta: %d\n",current->venta.idVenta);
            printf("Comprador: %s\n",current->venta.comprador);
            printf("Fecha: %s\n",current->venta.fecha);
            printf("id del producto: %d\n",current->venta.productos.idProducto);
            printf("Nombre del producto: %s\n",current->venta.productos.nombre);
            printf("Precio: %d\n",current->venta.productos.precio);
            printf("Cantidad: %d\n",current->venta.productos.cantidad);
            current = current->next;
            tamano--;
        }
    }
}