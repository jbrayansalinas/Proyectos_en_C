#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[5] = {1,2,3,4,5};

    int *apuntadorArray = &array[0];

    while (*apuntadorArray != NULL)
    {
        printf("\n %d", *apuntadorArray);
        
    }
    apuntadorArray++;


    return 0;
}
