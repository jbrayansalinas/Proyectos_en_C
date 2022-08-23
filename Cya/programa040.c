/* 
*Busquedad secuentcial 
*/ 


#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[10]= {2,4,6,8,0,1,3,5,7,9};
    int i, dato;
    char band = 'F';

    printf("Escribe un numero \n");
    scanf("%i", &dato);

    //! Busquedad Secuencial
    i= 0;
    while (band == 'F' && (i<10))
    {
        if (a[i]==dato)
        {
            band = 'V';
        }
        i++;
    }

    if (band=='F')
    {
        printf("El numero no existe en la lista\n");
    }else if (band == 'V')
    {
        printf("El numero existe, en la posicion %i ", i);
    }
    
    

    return 0;
}
