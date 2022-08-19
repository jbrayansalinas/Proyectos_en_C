#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){

    char usuario[31];
    char password[31];
    printf("Ingrese su usuario: ");
    gets(usuario);
    printf("Ingrese su password: ");
    gets(password);
    if(strcmp(password,"abc123")==0){
        printf("Correcto");
    }else {
        printf("Incorrecto");
    }
    getch();
    return 0;
}

