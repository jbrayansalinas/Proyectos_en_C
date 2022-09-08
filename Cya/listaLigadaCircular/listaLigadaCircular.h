#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

typedef struct Lista {
    struct Nodo* head;
    int tamano;
}Lista;

Lista crearListaCircular(){
    Lista lista;
    lista.head = NULL;
    lista.tamano = 0;
    return lista;
}

void print_listaCircular(Lista lista){
    if (lista.head == NULL)
        printf("La lista esta vacia\n");
    else {
        int tamano = lista.tamano;
        printf("Los elementos de la lista son: \n");
        Nodo *current = lista.head;
        while (tamano !=0) {
            printf("%d ", current->val);
            current = current->next;
            tamano--;
        }
    }
}

void addFinalCircular(Lista * lista, int valor){
    int posicion = lista->tamano;
    if(lista->head==NULL){
        Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
        nodo->val = valor;
        nodo->next = nodo;
        lista->head = nodo;
    }else{
        Nodo *current = lista->head;
        while (posicion!=1){
            current = current->next;
            posicion --;
        }
        Nodo *nuevoNodo = (Nodo*) malloc(sizeof (Nodo));
        current->next=nuevoNodo;
        nuevoNodo->val = valor;
        nuevoNodo->next = lista->head;
        lista->tamano++;
    }
}

void addPrincipioListaCircular(Lista *lista, int valor){
    Nodo *node,*temp;
    node = (Nodo*) malloc(sizeof (Nodo));
    node->val = valor;
    if (lista->head ==NULL)
        node->next = node;
    else{
        node->next = lista->head;
        temp = lista->head;
        while (temp->next !=lista->head)
            temp = temp->next;
        temp->next = node;
    }
    lista->head = node;
    lista->tamano++;
}

void borrarPrimeroCircular(Lista * lista){
    if(lista->head ==NULL)
        printf("La lista esta vacia\n");
    else{
        Nodo *nuevo_head = NULL;
        Nodo *temp = lista->head;
        nuevo_head = temp->next;
        free(lista->head);
        lista->head = nuevo_head;
        lista->tamano--;
    }
}

void borrarUltimoCircular(Lista *lista){
    Nodo *temp = lista->head;
    int posicion = lista->tamano;
    if(lista->head == NULL)
        printf("La lista esta vacia\n");
    else{
        if(temp->next == lista->head) {
            temp->next = NULL;
            free(temp->next);
            lista->tamano--;
        }else{
                Nodo *current = lista->head;
            while (posicion != 1){
                current = current->next;
                posicion--;
            }
            current->next = NULL;
            free(current->next);
            current->next = lista->head;
            lista->tamano--;
        }
    }
}

int buscarCircular(Lista lista, int numBuscar){
    if(lista.head ==NULL){
        printf("La lista esta vacia\n");
        return 0;
    }
    int cont = 0, band = 0, control = 0;
    for (int i = 0; i < lista.tamano; ++i) {
        if (lista.head->val==numBuscar){
            band = 1;
            fflush(stdin);
            printf("El numero esta en el indice: %d\n",cont);
            break;
        }
        while (lista.head->val!= numBuscar&& control < lista.tamano){
            cont++;
            control++;
            lista.head = lista.head->next;
            printf("Buscando numero...\n");
        }
    }
    return band;
}

void agregarNesimoCircular(Lista *lista, int valor, int lugar){
    Nodo *temp = lista->head;
    for (int i = 0; i < (lugar - 1); ++i)
        temp = temp->next;
    Nodo *nuevoValor = (Nodo*) malloc(sizeof (Nodo));
    nuevoValor->val=valor;
    nuevoValor->next = temp->next;
    temp->next=nuevoValor;
    lista->tamano++;
}

void eliminarNesimoCircular(Lista *lista, int lugar){
    Nodo *temporal = lista->head;
    Nodo *nodo;
    for (int i = 0; i < (lugar-1); ++i)
        temporal = temporal->next;
    nodo = temporal;
    nodo = nodo->next;
    temporal->next = nodo->next;
    nodo = NULL;
    free(nodo);
    lista->tamano--;
}