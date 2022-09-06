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
    ll->primerItem==NULL;
    ll->ultimoItem==NULL;
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

int	main()
{
    listaLigada* LISTA = obtenerNuevaListaLigada();
     Nodo* a = getNode(1);
     Nodo* b = getNode(2);
     Nodo* c = getNode(3);
     Nodo* d = getNode(4);
 
     add(LISTA,a);
     add(LISTA,b);
     add(LISTA,c);
     add(LISTA,d);
 
     printf("%d\n",read(LISTA,3)->valor);
    return 0;
}