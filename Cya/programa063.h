#include <stdio.h>
#include <stdlib.h>

typedef struct Cola{

    int primero;
    int ultimo;
    int lista[100];
}Cola;

Cola crearCola(){
    Cola c;
    c.primero =1;
    c.ultimo =0;
    return c;
}

int isEmpty(Cola c){
    if(c.primero==c.ultimo+1) 
        return 1;
    return 0;
}

void encolar(Cola *c, int x){
    c->lista[c->ultimo] = x;
    c->ultimo++;
}

int desencolar(Cola *c){
    int aux;
    if (isEmpty(*c)==1)
        printf("La cola esta vacia\n");
    else{
        aux=c->lista[c->primero-1];
        c->primero++;
        if(c->primero==c->ultimo+1)
        *c = crearCola();
    }
    return aux;
}

int firsCola(Cola c){
    c.primero++;
    return c.lista[c.primero-1];
}