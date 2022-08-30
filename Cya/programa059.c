/*********************** 
*?Algoritmos de ordenamiento
***********************/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[5] = {3,2,4,1,5};
    int i,j,aux;


/*********************** 
*!Metodo burbuja
***********************/
    /* for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            if (array[j]>array[j+1]){
                aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
        }
    } */

/*********************** 
*!Metodo Bubble sort
***********************/

    /* for (i = 0; i < 5; i++){    
        for (j = 0; j < 5; j++){
            if (array[i]<array[j]){
                aux=array[i];
                array[i]=array[j];
                array[j]=aux;
            }
        }
    } */

/*********************** 
*!Metodo Insersion
***********************/

    /* for (i = 0; i < 5; i++){
        j = i;
        aux = array[i];
        while ((j>0)&&(aux<array[j-1]))
        {
            array[j] = array[j-1];
            j--;
        }
        array[j] = aux;
    }  */   

/*********************** 
*!Metodo Seleccion
***********************/
    for (i = 0; i < 5; i++){    
        int min = i;
        for (j = i+1; j < 5; j++){
            if (array[j]<array[min]){
                min = j;
            }
        }
        aux=array[i];
        array[i]=array[min];
        array[min]=aux;
    }


    //*Ascendente
    for (i = 0; i < 5; i++){
        printf("%i, ",array[i]);
    }printf("\n\n");
    

    //*Descendente
    for (i = 4; i>=0; i--){
        printf("%i, ",array[i]);
    }

    return 0;
}