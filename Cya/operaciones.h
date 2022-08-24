#include <stdio.h>
#include <string.h>

int resta(int *uno, int *dos){
    return (*uno-*dos);
}
int suma(int *p_a, int *p_b){
    return (*p_a + *p_b);
}
int multiplicacion(int *p_a, int *p_b){
    return ((*p_a) * (*p_b));
}
int division(int *p_a, int *p_b){
    return ((*p_a) / (*p_b));
}