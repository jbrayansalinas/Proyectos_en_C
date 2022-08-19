
#include<stdio.h>
#include<conio.h>

int main(){

    char palabra[30];
    printf("Ingrese una palabra en mimusculas: ");
    gets(palabra);
    int cant=0;
    int x=0;
    while (palabra[x]!= '\0'){
        //if(palabra[x]=='a' || palabra[x]=='e' || palabra[x]=='i' || palabra[x]=='o' || palabra[x]=='u'){
          //  cant++;
        //}
        x++;
    }
    printf("La cantidad de vocales que tiene la palabra %s es %i", palabra, x);
    getch();
    return 0;
}

