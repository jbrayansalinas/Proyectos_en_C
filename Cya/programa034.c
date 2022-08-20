/* srand(time(NULL))*/

#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    FuncionAleatoria();
    return 0;
}

void FuncionAleatoria(){
    int num;
    srand(time(NULL));

    num = 1 + rand()%((10-1)-1);
    printf("%d\n", num);
}
