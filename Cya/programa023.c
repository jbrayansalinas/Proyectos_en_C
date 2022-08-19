/* Ver si un alumno va a pasar de año o no.
un alumno solo tiene derecho a reprobar 3 materias para poder pasar de año
si reprueba 4 materias no puede pasar de año y recursa */

#include <stdio.h>

int main()
{
    int materiasR;

    printf("Cuantas materias has reprobado?\n");
    scanf("%i", &materiasR);

    if (materiasR > 3)
    printf("Estas reprobado, tienes que repetir\n");
    else
    printf("Felicidades puedes pasar, pero debes %i materias\n", materiasR); 


    return 0;
}
