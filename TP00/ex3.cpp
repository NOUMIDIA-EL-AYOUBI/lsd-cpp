#include <iostream>
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


stack reverse(stack P)
{
    int n= len(P);
    stack R= NULL;
    for (int i=0;i<n;i++)
    {
        int res= pop(&P);
        push(res,&R);
    }
     return R;
}


int notIn(int x, stack P)
{
    stack temp= P;
    while(temp != NULL)
    {
        if (temp->element == x)
            return 1;
        temp=temp->next;
    }
    return 0;
}


stack elemin_double(stack* P)
{
    int n=len(*P);
    stack temp= NULL;
    for(int i=0;i<n ; i++)
    {
        int res = pop(P);
        if (notIn(res,temp)==0)
            push(res,&temp);
    }
    return reverse(temp);
}





int main()
{
    stack P=NULL;
    stack R=NULL;
    push(2,&P);
    push(3,&P);
    push(4,&P);
    push(4,&P);
    push(9,&P);
    push(3,&P);
    push(0,&P);
    push(2,&P);
    PRINT(P);
    R=elemin_double(&P);
    PRINT(R);
    return 0;
    
}
