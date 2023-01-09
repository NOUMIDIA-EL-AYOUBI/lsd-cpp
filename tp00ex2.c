#include<stdio.h>


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


