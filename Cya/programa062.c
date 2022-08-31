#include "programa061.h"

int main(int argc, char const *argv[])
{
    //?Creamos 3 pilas con la funcion crear pila

    Pila pilaUsuario = crearPila();
    Pila pilaMenor = crearPila();
    Pila pilaAuxiliar = crearPila();

    //?Creamos este bucle para agregar los valores a la pila Usuario
    for (int i = 0; i < 8; i++)
    {
        int valor;
        printf("Escribe el valor [%d] de la pila\n",i);
        scanf("%d",&valor);
        fflush(stdin);
        Push(&pilaUsuario, valor);
    }

    //?Determinar el menor de los datos ingresados por el usuario
    while (isEmpty(pilaUsuario)==0)
    {
        Push(&pilaMenor,pop(&pilaUsuario));
        while (isEmpty(pilaUsuario)==0)
        {
            if (top(pilaUsuario)>top(pilaMenor))
            {
                Push(&pilaAuxiliar,pop(&pilaUsuario));
            }else{
                Push(&pilaAuxiliar,pop(&pilaMenor));
                Push(&pilaMenor,pop(&pilaUsuario));
            }
            
        }
        
        printf("El valor menor de los ingresados es el %d", pop(&pilaMenor));
    }
    
    return 0;
}
