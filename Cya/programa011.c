#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){

    char nombre1[31];
    char nombre2[31];
    char nombreLargo[31];
    printf("Ingrese primer nombre: ");
    gets(nombre1);
    printf("Ingrese segundo nombre: ");
    gets(nombre2);
    if (strlen(nombre1)>strlen(nombre2)){
        strcpy(nombreLargo, nombre1);
    }else {
        strcpy(nombreLargo, nombre2);
    }
    printf("El nombre %s tiene mas caracteres",nombreLargo);
    getch();
    return 0;
}

