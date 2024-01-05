#include <stdio.h>
#include <stdlib.h>

int main (){
    int *p = (int*) malloc (sizeof(int)*5);
    int i;
    for (i=0; i<5; i++)
        p[i] = i;
    for (i=0; i<5; i++)
        printf("%i\n", p[i]); 
    free(p);
    return 0;
}