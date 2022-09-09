#include <stdlib.h>
#include <stdio.h>

typedef  struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo *prev;
}Nodo;

typedef  struct Lista{
    struct Nodo* head;
}Lista;

Lista crearLista(){
    Lista lista;
    lista.head = NULL;
    return lista;
}

void print_list(Lista lista){
    if (lista.head == NULL)
        printf("La lista esta vacia\n");
    else{
        printf("Los elementos de la lista son\n");
        Nodo *current = lista.head;
        while (current != NULL){
            printf("%d\n", current->val);
            current = current->next;
        }
    }
}

void print_lista2(Lista lista){
    if (lista.head==NULL)
        printf("La lista esta vacia\n");
    else{
        printf("Los elementos de la lista son\n");
        Nodo *current = lista.head;
        if (current->next != NULL){
            do{
                current = current->next;
            } while (current->next!=NULL);
        }
        while (current!=NULL){
            printf("%d\n",current->val);
            current = current->prev;
        }
    }
}

void primerNodo(Lista *lista,int val){
    Nodo *nodo = (Nodo*) malloc(sizeof (Nodo));
    nodo->val = val;
    nodo->next = NULL;
    nodo->prev = NULL;
    lista->head = nodo;
}

void addFinalLista(Lista *lista, int val){
    if (lista->head==NULL)
        primerNodo(lista,val);
    else{
        Nodo *current = lista->head;
        while (current->next !=NULL){
            current = current->next;
        }
        Nodo *nuevoNodo;
        nuevoNodo = (Nodo *) malloc((sizeof (Nodo)));
        nuevoNodo->next = NULL;
        nuevoNodo->prev = current;
        current->next = nuevoNodo;
    }
}

void addPrincipioLista(Lista *lista,int val){
    if (lista->head == NULL)
        primerNodo(lista,val);
    else{
        Nodo *new_node = (Nodo *)malloc(sizeof (Nodo));
        new_node->val = val;
        new_node->next = lista->head;
        new_node->prev = NULL;
        lista->head->prev = new_node;
        lista->head = new_node;
    };
}

void addIesimoLista(Lista * lista, int val){
    int contador, posicion;
    printf("Ingrese la posicion\n");
    scanf("%d",&posicion);
    Nodo *temp;
    temp = lista->head;
    for (contador = 1; contador < posicion-1; ++contador) {
        temp = temp->next;
        if (temp == NULL)
            printf("Hay un error");
    }
    Nodo *nuevoNodo = (Nodo *) malloc(sizeof (Nodo));
    nuevoNodo->val = val;
    nuevoNodo->next = temp->next;
    nuevoNodo->prev = temp;
    temp->next->prev = nuevoNodo;
    temp->next = nuevoNodo;
}