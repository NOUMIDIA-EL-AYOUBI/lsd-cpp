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


int main()
{
stack P=NULL;
    
    push(2,&P);
    push(3,&P);
    push(4,&P);
    PRINT(P);
    int res=pop(&P);
    int res1= pop(&P);
    PRINT(P);
    cout<<res<<endl;
    cout<<res1<<endl;
    return 0;
    
}
