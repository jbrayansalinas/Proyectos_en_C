#include <stdio.h>
#include <stdlib.h>n

typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

typedef struct Lista{
    struct Nodo* head;
}Lista;

Lista crearLista(){
    Lista lista;
    lista.head = NULL;
    return lista;
}

void print_lista(Lista lista){
    if (lista.head == NULL)
        printf("La lista esta vacia\n");
    else {
        printf("Los elementos de la lista son: \n");
        Nodo *current = lista.head;
        while (current !=0 ){
            printf("%d ",current->val);
            current = current->next;

        } 
    }
}

void addPrincipioLista(Lista *lista, int val){
    Nodo *new_node;
    new_node = (Nodo *)malloc(sizeof(Nodo));
    new_node->val =val;
    new_node->next = lista->head;
    lista->head = new_node;
}

void addFinalLista(Lista *lista, int val){
    if (lista->head == NULL){
        Nodo *nodo =(Nodo*)malloc(sizeof(Nodo));
        nodo->val = val;
        nodo->next = NULL;
        lista->head = nodo;
    }else{
        Nodo *current = lista->head;
        while (current->next != NULL)
            current = current->next;
        Nodo *nuevoNodo = current;
        nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->val = val;
        nuevoNodo->next = NULL;
        current->next = nuevoNodo;
    }
}

void borrarPrimero(Lista *lista){
    if (lista->head == NULL)
        printf("la lista est vacia");
    else{
        Nodo *nuevo_head = NULL;
        Nodo *temp = lista->head;
        nuevo_head = temp->next;
        free(lista->head);
        lista->head = nuevo_head;
    }
}

void borrarUltimo (Lista *lista){
    Nodo *temp = lista->head;
    if (lista->head == NULL)
        printf("La lista esta vacia\n");
    else{
        if (temp->next==NULL){
            lista->head = NULL;
            free(lista->head);
        }else{
            Nodo *current = lista->head;
            while (current->next->next != NULL)
                current = current->next;
            current->next = NULL;
            free(current->next);
        }
    }
}

int primerElemento(Lista lista) {
    return lista.head->val;
}

int buscar(Lista lista, int numBuscar) {
    int contador = 0;
    Nodo *temp = lista.head;
    //Buscamos la cantidad de valores dentro de la lista liganda simple
    while (temp->next!=NULL){
        contador++;
        temp = temp->next;
    }
    if (lista.head == NULL){
        printf("La lista esta vacia\n");
        return 0;
    }
    int cont = 0,band = 0;   
    for (int i = 0; i < contador; i++){
        if (lista.head->val == numBuscar){
            band =1;
            printf("El numero esta en el indice %d\n",cont);
            break;
        }while (lista.head->val != numBuscar && lista.head->next != NULL){
            cont++;
            lista.head = lista.head->next;
            printf("BUscando el numero..\n");
        }
    }
    return band;
}

void agregarNesimo(Lista *lista, int valor, int lugar){
    Nodo *temp = lista->head;
    for (int i = 0; i < lugar-1; i++)
        temp = temp->next;
    Nodo *nuevoValor;
    nuevoValor = (Nodo *)malloc(sizeof(Nodo));
    nuevoValor->val = valor;

    nuevoValor->next = temp->next;
    temp->next=nuevoValor;
}

void eliminarNesimo(Lista *lista, int lugar){
    Nodo *temporal = lista->head;
    Nodo *nodo = lista->head;
    for (int i = 0; i < lugar-1; i++)
        temporal = temporal->next;
    nodo = temporal;
    nodo = nodo->next;
    temporal->next =nodo->next;;
    nodo=NULL;
    free(nodo);
}