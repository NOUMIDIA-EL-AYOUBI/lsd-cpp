#include<stdio.h>
#include<stdlib.h>

void checkMsb ( int num ) 
{
    

    if ((num >> ((sizeof(int)*8))-1) & 1==1)
        printf("set\n");
    else
    printf("Nset\n");
    
}



