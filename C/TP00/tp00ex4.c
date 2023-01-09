#include<stdio.h>


void printnthByte ( int m , int n)
{
      for(int i= n*8 ;i>=(n-1)*8;i--)
    {
       if((m >>i)&1==1)
            printf("1");
       else
         printf("0");
 
    }
    printf("\n");
} 

int main()
{
   

    int n=2;
    int m =  17161;
    printnthByte(m,n);
}
