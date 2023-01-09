#include<stdio.h>

void checkMsb ( int num ) 
{
    

    if ((num >> ((sizeof(int)*8))-1) & 1==1)
        printf("set\n");
    else
    printf("Nset\n");
    
}


void printBits ( unsigned char byte)
{
      for(int i= sizeof(unsigned char)*8 ;i>=0;i--)
    {
       if((byte >>i)&1==1)
            printf("1");
       else
         printf("0");
 
    }
    printf("\n");
} 


