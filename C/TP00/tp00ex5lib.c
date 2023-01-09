#include<stdio.h>
void checkMsb(int);
void  printBits(unsigned char);

int main()
{
     printf("ex1\n");
     int n =  255;
     checkMsb(n);


     printf("\n");


     printf("ex2\n");
     int m =  255;
     printBits(m);
}


/*................ commands to create and use library.......................

    gcc -c testlib.c -o testlib.o
    ar rcs -o libtest.a testlib.o
    gcc tp00ex5lib.c -L. -ltest
    ./a.out


............................*/

    

    

