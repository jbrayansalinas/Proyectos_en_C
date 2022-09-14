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

/*
 * Metodo para agregar un producto a una lista, valida si ya está creado, y si no lo está lo va a guardar en la primer posicion de la lista
 * */
void agregarProducto(ListaProducto *listaProducto, struct NodoProducto producto) {
    //nodoProducto se usa como nodo auxiliar, es donde se van a guardar todos los datos para luego indexarlo al principio de la lista
    NodoProducto *temporal, *nodoProducto = NULL, *revNombre = NULL;
    nodoProducto = (NodoProducto *) calloc(1, sizeof(NodoProducto));
    //revNombre se usa para recorrer la lista y saber si ya se ha ingresado antes un producto del mismo nombre
    revNombre = listaProducto->primer;
    int bandera = 0;
    strcpy(nodoProducto->nombre, producto.nombre);
    nodoProducto->precio = producto.precio;
    nodoProducto->cantidad = producto.cantidad;
    int tamano = 0;
    //Si no se ha ingresado un producto antes va a guardar el nodo en la primer posicion ademas de incrementar el id y su tamaño
    if (listaProducto->primer == NULL) {
        tamano = listaProducto->tamanoP++;
        nodoProducto->idProducto = tamano;
        listaProducto->primer = nodoProducto;
    } else
        while (bandera != 1) {
                //Va a recorer hasta que encuentre el nombre en ambas listas, sino lo encuntra se sale
                while (strcmp(producto.nombre, revNombre->nombre) != 0) {
                    if (revNombre->sig!=NULL)
                        revNombre = revNombre->sig;
                    else break;
                }
                //Si encuentra el producto es xq ya se ha ingresado antes
                if (strcmp(producto.nombre, revNombre->nombre) == 0) {
                    printf("Ya digit%c el producto\n", 162);
                    bandera=1;
                }
                else {
                    //Si no está ingresado antes se agrega al principio de la lista
                    tamano = listaProducto->tamanoP++;
                    nodoProducto->idProducto = tamano;
                    temporal = listaProducto->primer;
                    listaProducto->primer = nodoProducto;
                    listaProducto->primer->sig = temporal;
                    bandera = 1;
                }
        }
}

//Metodo para imprimir los productos, va recorerrse hasta que no encuentre más productos
void imprimirProducto(ListaProducto listaProducto){
    if (listaProducto.primer == NULL)
        printf("No hay productos\n");
    else{
        int tamano = listaProducto.tamanoP;
        printf("Los productos son: \n");
        NodoProducto *current = listaProducto.primer;
        while (tamano>0){
                printf("\nid: %d\n", current->idProducto);
                printf("Nombre: %s\n", current->nombre);
                printf("Precio: %d\n", current->precio);
                printf("Cantidad: %d\n", current->cantidad);
                current = current->sig;
            tamano--;
        }
    }
}

/*
 * Metodo para registrar una venta, va a recibir la lista donde se van a guardar las ventas, una lista donde están almacenados los productos existentes,
 * una lista auxiliar que se creó para almacenar los productos digitados y a continuacion guardarlos en la listaVenta, la fecha y el comprador
 * */
void registrarVenta(ListaVenta *listaVenta, ListaProducto *listaProducto, ListaProducto  *otrosProductos, char fecha[], char comprador[]){
    /*nodoVenta se usa como nodo auxiliar, es donde se van a guardar todos los datos para luego indexarlo al principio de la lista
     * temporal se va a usar para asignar el nodoVenta al principio de la lista*/
    NodoVenta *nodoVenta = NULL, *temporal= NULL;
    nodoVenta = (NodoVenta*) calloc(1,sizeof (NodoVenta));
    //Es necesario asignarle memoria a la lista producto porque es una sublista de la listaVenta, pero su memoria es independiente al de la primera
    nodoVenta->listaProducto = (struct ListaProducto *) malloc(sizeof(nodoVenta));
    /*current se usa para recorrer la lista
     * nodoProducto se usa para llamar los datos de la lista otrosProductos, hacer sus operaciones y asignarlos al nodoVenta*/
    NodoProducto *current = NULL,*nodoProducto = NULL;
    //La estructura producto se usa para almacenar los datos de forma temporal
    struct NodoProducto producto;
    nodoProducto = otrosProductos->primer;
    current = listaProducto->primer;
    nodoVenta->listaProducto->primer = NULL;
    nodoVenta->listaProducto->tamanoP = 0;
    int tamanoProducto = 0;
    tamanoProducto = otrosProductos->tamanoP;
    //Se crean 2 while con la misma condicion para poder recorrerlos, sin los 2 while el ciclo se cierra antes de lo esperado
    while (tamanoProducto > 0) {
        while (tamanoProducto>0) {
            if (current!=NULL) { //si current es null significa que ya recorrió toda la lista y no encontró el producto, por lo que no existe
                if (strcmp(nodoProducto->nombre, current->nombre) == 0) { //si el nombre de nodoProducto (el nodo de la lista auxiliar) es igual al de current (el nodo de la listaProductos, la del almacen), entonces va a seguir, sino, se va a pasar al siguente nodo de la listaProductos hasta encontrar o ser null
                    if (nodoProducto->cantidad < current->cantidad) {//si no hay suficientes productos en el almacen, se va a salir del programa con un mensaje
                        //Se van a guardar dentro de nodoProducto, para luego asignarse a la estructura
                        strcpy(nodoVenta->fecha, fecha);
                        strcpy(nodoVenta->comprador, comprador);
                        strcpy(nodoProducto->nombre, current->nombre);
                        current->cantidad -= nodoProducto->cantidad;//Se descuenta al almacen la cantidad digitada
                        nodoProducto->precio = current->precio;
                        nodoProducto->idProducto = current->idProducto;
                        nodoVenta->idVenta = listaVenta->tamanoV + 1;//el id se aumentea por cada iteracion
                        nodoVenta->cantidadVenta = nodoProducto->cantidad;
                        //Se guarda dentro de la estructura para llamar al metodo agregarProducto y asignarle los productos a la lista nodoVenta
                        strcpy(producto.nombre, nodoProducto->nombre);
                        producto.precio = nodoProducto->precio;
                        producto.idProducto = nodoProducto->idProducto;
                        producto.cantidad = nodoProducto->cantidad;
                        agregarProducto(nodoVenta->listaProducto, producto);
                        tamanoProducto--;//Se decrementa el valor de la lista auxiliar para poder iterar
                        nodoProducto = nodoProducto->sig; //Se continua al siguiente producto por guardar
                        current = listaProducto->primer; //Vuelve al valor iniciar para poder validar el nombre desde la primer posicion
                        listaVenta->tamanoV++;//El tamano de la listaVenta se incrementa por cada iteracion
                    } else {
                        printf("No hay suficientes\n");
                        nodoVenta=NULL;
                        break;
                    }
                } else current = current->sig;
            }else {
                printf("El producto no se encuntra\n");
                nodoVenta=NULL;
                break;
            }
        }
            tamanoProducto--;//Es necesario para poder conluir el ciclo
    }
    if (listaVenta->head == NULL) {//Si no hay más productos se va a asignar a la primer posicion
        listaVenta->head = nodoVenta;
    }
    else {//Si ya existen otros productos, se usa el nodo temporal para que el antiguo primero ahora sea el segundo
        temporal = listaVenta->head;
        listaVenta->head = nodoVenta;
        listaVenta->head->next = temporal;
    }
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
        //Se va a imprimir hasta que el tamaño de las ventas sea 0, es decir que no hayan más
        while (tamanoVenta>0) {
            int tamanoProducto = current->listaProducto->tamanoP;
            NodoProducto *temporal = current->listaProducto->primer;
            printf("id de la venta: %d\n", current->idVenta);
            printf("Comprador: %s\n", current->comprador);
            printf("Fecha: %s\n", current->fecha);
            while (tamanoProducto>0){
                //Cada venta se va a imprimir dependiendo la cantidad de productos que tenga
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