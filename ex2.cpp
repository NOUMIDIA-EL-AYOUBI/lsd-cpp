#include <iostream>
//#include <algorithm>
using namespace std;
struct node
{
    int element;
    struct node * next;
};
typedef struct node node;
typedef node * stack;




void push(int x,stack * P)
{
    stack C=(stack)malloc(sizeof(node));
    C->element=x;
    C->next=*P;
    *P=C;
    return;
}

int pop(stack * P)
{
    if(*P!=NULL)
    {
        int res=(*P)->element;
        stack temp=*P;
        *P=(*P)->next;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}


void PRINT(stack P)
{
    stack temp=P;
    while(temp->next!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->next;
    }
    if(temp!=NULL)
        printf("%d\n",temp->element);
}


stack add(stack A , stack B)
{
    stack tempa = A;
    stack temp=NULL;
    if(A==NULL)
        return B;
    while(tempa!=NULL)
    {
        int res1 = pop(&tempa);
        push(res1,&temp); 
    }
    while(temp!=NULL)
    {
        int res1 = pop(&temp);
        push(res1,&B); 
    }
    return B;
}

int len(stack P)
{
	int n =0;
	stack temp =P;
	while(temp!=NULL)
	{
		n++;
		temp=temp->next;
	}
	return n;
}


stack reverseS(stack P,int k)
{
    stack temp = NULL;
    stack result = NULL;
    stack tmp=P ;
    int n=len(P);
	int r=n%k;
    int c=0;
    while(tmp!=NULL)
    {
        if(c<n/k)
        {
          for (int i =0; i < k; i++) 
          {
             int res1 = pop(&tmp);
             push(res1,&temp);
          }
          result = add(result,temp);
          temp=NULL;
          c+=1;
       }
       else
       {
            for (int i =0; i < r; i++) 
          {
             int res1 = pop(&tmp);
             push(res1,&temp);
          }
          result = add(result,temp);
       }
    
    }
    
    
    return result;
    
}





int main()
{
    stack P=NULL;
    stack R=NULL;
    stack K=NULL;
    push(2,&P);
    push(3,&P);
    push(4,&P);
    push(8,&P);
    push(9,&P);
    push(5,&P);
    push(0,&P);
    push(6,&P);
    PRINT(P);
    R=reverseS(P ,3);
    PRINT(R);
    return 0;
    
}
