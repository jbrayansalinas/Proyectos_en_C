#include <stdio.h>
#include <stdlib.h>

typedef struct Documento{

    char nombre[30];
    char autor[30];
    int numeroPaginas;
    int tamanio;
}Documento;

typedef struct Cola{
    int primero;
    int ultimo;
    Documento documento[100];
}Cola;

Cola crearCola(){
    Cola c;
    c.primero = 1;
    c.ultimo = 0;
    return c;
}

int isEmpty(Cola c){
    if(c.primero == c.ultimo+1)return 1; return 0;
    }
    
void encolar(Cola *c, Documento x){
    c->documento[c->ultimo]=x;
    c->ultimo++;
}

Documento desencolar(Cola *c){
    Documento aux;
    if(isEmpty(*c)==1)
        printf("La cola esta vacia\n");
    else{
        aux= c->documento[c->primero-1];
        c->primero++;
        if(c->primero == c->ultimo+1)
            *c = crearCola();
    }
    return aux;
}

Documento first(Cola c){
    c.primero++;
    return c.documento[c.primero];
}