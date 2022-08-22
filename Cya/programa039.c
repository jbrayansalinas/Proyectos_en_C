#include <stdio.h>


/*****************
*
*    Prototipos 
*
*****************/
void datosArreglo(int arregloi[]);
void llenarArreglo(int arreglo1[]);
void sumarElementos(int arreglo1[]);
void multiplicarElementos(int arreglo1[]);
void sumarElementosTres(int arreglo1[]);
void multiplicarElementosTres(int arreglo1[]);




/*****************
*
*    Main 
*
*****************/
int main(int argc, char const *argv[])
{
    int arreglo1[10], bucle=1, opcion;
    
    printf("Este programa ejecuta operaciones sobre un arreglo de 10 elementos\n");


    for (int i = 0; i < 10; ++i)
    {
        printf("Escribe el elemento [%i] del arreglo \n", i);
        scanf("%d",&arreglo1[i]);
    }


    while (bucle)
    {
        printf("\nSelecciona la opcion que quieres\n\n");
        printf("1) Ingresar o modificar elementos del arreglo\n2) Mostrar la Suma de los elementos\n3) Realizar la multiplicacion de los elementos\n4) Realizar la suma solo de los elementos divisibles\n5) Multiplicar por 3 cada elemento del arreglo\n0) Salir\n\n");
        scanf("%d", &opcion);
        datosArreglo(arreglo1);

        switch (opcion)
        {
        case 1:
            printf("\n1) Ingresar o modificar elementos del arreglo\n");
            datosArreglo(arreglo1);
            llenarArreglo(arreglo1);
            datosArreglo(arreglo1);
            break;
        case 2:
            printf("\n2) Mostrar la Suma de los elementos\n");
            sumarElementos(arreglo1);
            break;
        case 3:
            printf("\n3) Realizar la multiplicacion de los elementos\n");
            datosArreglo(arreglo1);
            multiplicarElementos(arreglo1);
            break;
        case 4:
            printf("\nn4) Realizar la suma solo de los elementos divisibles\n");
            sumarElementosTres(arreglo1);
            break;
        case 5:
            printf("\n5) Multiplicar por 3 cada elemento del arreglo\n");
            datosArreglo(arreglo1);
            multiplicarElementosTres(arreglo1);
            break;
        case 0:
        bucle = 0;
            break;
        
        default:
            printf("Opcion no valida");
            break;
        }
    }
    
    return 0;
}




/*****************
*
*    Funciones 
*
*****************/
void datosArreglo(int arregloi[]){
    for (int i = 0; i < 10; ++i)
    {
        printf("Posicion [%i] = %i\n", i,arregloi[i]);
    }
    
}

void llenarArreglo(int arreglo1[]){
    for (int i = 0; i < 10; ++i)
    {
        printf("Escriba el numero para el arreglo en la posicion [%i]\n", i);
        scanf("%d", &arreglo1[i]);
    }
}

void sumarElementos(int arreglo1[]){
    int sumatoria = 0;
    for (int i = 0; i < 10; ++i)
    {
        sumatoria += arreglo1[i];
    }
    printf("La suma de todos los elementos del arrelo es %i\n", sumatoria);
    
}

void multiplicarElementos(int arreglo1[]){
    int multiplicacion = 1;
    for (int i = 0; i < 10; ++i)
    {
        multiplicacion *= arreglo1[i];
    }
    printf("La multiplicacion de todos los elementos del arreglo es %i\n", multiplicacion);
    
}

void sumarElementosTres(int arreglo1[]){
    int sumatoria = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (arreglo1[i]%3 == 0)
            sumatoria += arreglo1[i];
        
    }
    printf("La suma de los elementos divisibles entre 3 del arreglo es %i\n", sumatoria);
    
}

void multiplicarElementosTres(int arreglo1[]){
    for (int i = 0; i < 10; ++i)
    {
        arreglo1[i] *= 3;
    }
    for (int i = 0; i < 10 ; ++i)
    {
        printf("La multiplicacion por 3 en la posicion [%i] =  %i\n", i, arreglo1[1]);
    }
    
}
