/* Recursividad */

#include <stdio.h>

long factorial(int n);


int main(int argc, char const *argv[])
{
    int n;
    printf("Escribe un numero: \n");
    scanf("%i", &n);

    printf("El Factorial es: %li\n", factorial(n));
    return 0;
}

long factorial(int n){

    if (n<=1) 
        return 1;
    else       
       return (n*factorial(n-1)); 
}  
