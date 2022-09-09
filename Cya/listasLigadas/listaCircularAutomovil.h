#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Automovil{
    char marca[20];
    char modelo[20];
    char color[20];
}Automovil;

typedef struct Nodo{
    Automovil  automovil;
    struct Nodo* next;
}Nodo;

typedef struct Lista{
    struct Nodo* head;
    int tamano;
}Lista;

void detallesAuto(Lista lista);

Lista crearListaCircularAutomovil(){
    Lista lista;
    lista.head = NULL;
    lista.tamano = 0;
    return lista;
}

void print_listaCirlarAutomovil(Lista lista){
    int indice =0;
    if (lista.head ==NULL)
        printf("La lista esta vacia\n");
    else{
        int tamano = lista.tamano;
        printf("Los elementos de la lista son: \n");
        Nodo *current = lista.head;
        while (tamano > 0){
            printf("[%d]\n",indice);
            printf("Marca: %s\n",current->automovil.marca);
            printf("Modelo: %s\n",current->automovil.modelo);
            printf("Color: %s\n",current->automovil.color);
            current = current->next;
            tamano--;
            indice++;
        }
    }
}

void addFinalCircularAutomovil(Lista *lista, char marca[], char modelo[], char color[]){
    int posicion = lista->tamano;
    if (lista->head ==NULL){
        Nodo *nodo = (Nodo *) calloc(1,sizeof (Nodo));
        strcpy(nodo->automovil.marca, marca);
        strcpy(nodo->automovil.modelo,modelo);
        strcpy(nodo->automovil.color,color);
        nodo->next = nodo;
        lista->head = nodo;
        printf("Ya se agrego el Automovil al final de la lista\n\n");
    }else{
        Nodo *current = lista->head;
        while (posicion!=1){
            current = current->next;
            posicion--;
        }
        Nodo *nuevoNodo;
        nuevoNodo = (Nodo *) calloc(1, sizeof (Nodo));
        current->next = nuevoNodo;
        strcpy(nuevoNodo->automovil.marca, marca);
        strcpy(nuevoNodo->automovil.modelo, modelo);
        strcpy(nuevoNodo->automovil.color, color);
        nuevoNodo->next= lista->head;
        lista->tamano++;
        printf("Ya se agrego el Automovil al final de la lista\n\n");
    }
}

void addPrinciíoListaAutomovil(Lista *lista, char marca[], char modelo[], char color[]) {
    Nodo *node, *temp;
    node = (Nodo *) calloc(1,sizeof(Nodo));
    strcpy(node->automovil.marca, marca);
    strcpy(node->automovil.modelo, modelo);
    strcpy(node->automovil.color, color);
    if (lista->head == NULL)
        node->next = node;
    else {
        node->next = lista->head;
        temp = lista->head;
        while (temp->next != lista->head)
            temp = temp->next;
        temp->next = node;
    }
    lista->head = node;
    lista->tamano++;
    printf("Ya se agrego el Automovil al principio de la lista\n\n");
}

void borrarPrimeroCircularAutomovil(Lista *lista){
    if (lista->head==NULL)
        printf("La lista esta vacia\n");
    else{
        Nodo *nuevo_head = NULL;
        Nodo *temp = lista->head;
        nuevo_head = temp->next;
        if (lista->tamano !=1) {
            free(lista->head);
            lista->head = NULL;
            lista->head = nuevo_head;
            lista->tamano--;
            printf("Ya se elimino al principio de la lista\n\n");
        }else {
            free(lista->head);
            lista->head = NULL;
            lista->tamano--;
            printf("Ya se elimino al principio de la lista\n\n");
        }
    }
}

void borrarUltimoCircularAutomovil(Lista *lista){
    Nodo *temp = lista->head;
    int posicion = lista->tamano;
    if (lista->head == NULL)
        printf("La lista esta vacia\n");
    else if (lista->tamano !=1) {
        if (temp->next == lista->head){
            temp->next = NULL;
            free(temp->next);
            lista->tamano--;
        }else{
            Nodo *current =  lista->head;
            while (posicion!=1){
                current = current->next;
                posicion--;
            }
            current->next = NULL;
            free(current->next);
            current->next = lista->head;
            lista->tamano--;
        }
    }else {
        free(lista->head);
        lista->head = NULL;
        lista->tamano--;
        printf("Ya se elimino al final de la lista\n\n");
    }
}

int buscarCircularAutomovil(Lista lista, char marcaBuscar[]){
    if (lista.head==NULL)
        printf("La lista esta vacia\n");
    int cont = 0,band=0,control=0;
    for (int i = 0; i < lista.tamano; ++i) {
        if (stricmp(lista.head->automovil.marca,marcaBuscar)==0){
            band =1;
            printf("El auto esta en el indice %d de la lista\n",cont);
            break;
        }
        while (stricmp(lista.head->automovil.marca,marcaBuscar)!= 0 && control<lista.tamano){
            cont++;
            control++;
            lista.head = lista.head->next;
            printf("Buscando el auto...\n");
        }
    }
        return band;
}

void agregarNesimoCircularAutomovil(Lista *lista, char marca[], char modelo[], char color[], int lugar) {
    if(lugar<=lista->tamano){
        if (lista->head == NULL || lugar ==0) {
            addPrinciíoListaAutomovil(lista, marca, modelo, color);
        }
        else {
            Nodo *temp = lista->head;
            for (int i = 0; i < (lugar - 1); ++i)
                temp = temp->next;
            Nodo *nuevoValor = (Nodo *) calloc(1, sizeof(Nodo));
            strcpy(nuevoValor->automovil.marca, marca);
            strcpy(nuevoValor->automovil.modelo, modelo);
            strcpy(nuevoValor->automovil.color, color);
            nuevoValor->next = temp->next;
            temp->next = nuevoValor;
            lista->tamano++;
            printf("Ya se agrego el Automovil en la posicion %d de la lista\n\n", lugar);
        }
    }else
        printf("El lugar debe ser menor");
}

void eliminarNesimoCircularAutomovil(Lista *lista, int lugar){
    if(lugar<=lista->tamano){
        if (lista->head == NULL|| lugar ==0) {
            borrarPrimeroCircularAutomovil(lista);
        }
        else {
            Nodo *temporal = lista->head;
            Nodo *nodo;
            for (int i = 0; i < (lugar - 1); ++i)
                temporal = temporal->next;
            nodo = temporal;
            nodo = nodo->next;
            temporal->next = nodo->next;
            nodo = NULL;
            free(nodo);
            lista->tamano--;
            printf("Ya se elimino en la posicion %d de la lista\n\n", lugar);
        }
    }else
        printf("El lugar debe ser menor");
}

void detallesAuto(Lista lista) {
    printf("Marca %s\n",lista.head->automovil.marca);
    printf("Modelo %s\n",lista.head->automovil.modelo);
    printf("Color %s\n",lista.head->automovil.color);
}

void recorrerLIstaAutomovil(Lista lista){
    if (lista.head == NULL)
        printf("La lista esta vacia\n");
    else {
        int opcion, bandera = 0;
        while (bandera == 0) {
            printf("\nEste es el modelo del automovil actual %s\n", lista.head->automovil.modelo);
            printf("1) Ver detaller del auto\n2)Avanzar al siguiente\n0) Salir\n");
            fflush(stdin);
            scanf("%d", &opcion);

            switch (opcion) {
                case 1:
                    printf("Selecionaste ver detaller del auto\n");
                    detallesAuto(lista);
                    break;
                case 2:
                    printf("Selecionaste avanzar a ver el siguiente auto\n");
                    if(lista.head != lista.head->next)
                        lista.head = lista.head->next;
                    else printf("No hay más autos\n");
                    break;
                case 0:
                    printf("Saliste del menu\n");
                    bandera = 1;
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
            }
        }
    }
}