#include <stdio.h>

int	main(){

    int a = 1; // 2 bytes  -32768 -> 32767
    char b= 'z'; // 1 byte 0 -> 255
    float c = 1.5; // 4 bytes
    double d = 1.5555555555; // 8 bytes
    short v=2; // 2 bytes -128 -> 127
    unsigned int g = 123; // 2 bytes 0 -> 65535 solo admite positivos
    long e = 12.3; // 4 bytes

    printf("El valor del entero es de %i\n",a);
    printf("El valor del char es de %c\n",b);
    printf("El valor del float es de %f\n",c);
    printf("El valor del double es de %f\n",d);
    printf("El valor del short es de %i\n",v);
    printf("El valor del unsigned int es de %i\n",g);
    printf("El valor del long es de %li\n",e);
    
    return 0;
}
