#include <stdio.h>
#include <stdlib.h>

typedef struct tNodo
{
    int valor;
    struct tNodo* sig;
}Nodo;

typedef struct tList
{
    int tamano;
    Nodo* primerItem;
    Nodo* ultimoItem;
}listaLigada;

Nodo* getNode(int valor){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->valor = valor;
    nodo->sig = NULL;
    return nodo;
}

listaLigada* obtenerNuevaListaLigada(){
    listaLigada* ll = (listaLigada*)malloc(sizeof(listaLigada));
    ll->tamano=0;
    ll->primerItem=NULL;
    ll->ultimoItem=NULL;
    return ll;
}

//Operaciones CRUD

void add(listaLigada* ll,Nodo* nodo){
    if(ll->primerItem == NULL) ll->primerItem = nodo;
    else ll->ultimoItem->sig = nodo;
    ll->ultimoItem = nodo;
    ll->tamano++;
}

Nodo* read(listaLigada* ll, unsigned int indice){
    if(ll->tamano && indice<ll->tamano){
        Nodo* exploradorLista = ll->primerItem;
        int i = 0;
        while (i++ < indice)
            exploradorLista = exploradorLista->sig;
        return exploradorLista;
        
    }
}

void update(listaLigada* ll, unsigned int indice, int nuevoValor){
    if(ll->tamano && indice<ll->tamano){
        Nodo* exploradorLista = ll->primerItem;
        int i = 0;
        while (i++ < indice)
            exploradorLista = exploradorLista->sig;
        exploradorLista->valor = nuevoValor;
    }
}

void removed(listaLigada* ll, unsigned int indice){
    if(ll->tamano && indice<ll->tamano){
        Nodo* aux;
        if (indice == 0){
            aux = ll->primerItem;
            ll->primerItem = ll->primerItem->sig;
            free(aux);
        } else {
            Nodo* exploradorLista = ll->primerItem;
            int i = 0;
            while (i++<indice-1)
                exploradorLista = exploradorLista->sig;
            aux = exploradorLista->sig;
            if(indice==ll->tamano-1){
                exploradorLista->sig =NULL;
                ll->ultimoItem = exploradorLista;
            } else exploradorLista->sig = exploradorLista->sig->sig;
        }
        free(aux);
        ll->tamano--;
        
    }
}

int	main()
{
    listaLigada* lista = obtenerNuevaListaLigada();
    Nodo* a = getNode(1);
    Nodo* b = getNode(2);
    Nodo* c = getNode(3);

    add(lista,a);
    add(lista,b);
    add(lista,c);

    printf("El valor es %d\n", read(lista,1)->valor);
    update(lista,1,6);
    printf("El valor es %d\n", read(lista,1)->valor);
    removed(lista,1);
    printf("El valor es %d\n", read(lista,1)->valor);

    free(lista);
    return 0;
}