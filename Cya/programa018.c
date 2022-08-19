#include <stdio.h>
#define Pi 3.1416


int y = 5; // variable Global

int main() {
    int x = 10; // variable Local
    float Suma = 0;

    Suma = Pi + x;

    printf("La suma es %.2f", Suma);
    
    return  0; 
}