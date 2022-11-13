#include <iostream>
using namespace std;


struct cellule
{
    int element;
    struct cellule * suivant;

};

typedef struct cellule cellule;
typedef struct cellule * stack;

void stackPush(int x,stack *P)
{
    stack C=(stack)malloc(sizeof(cellule));
    C->element=x;
    C->suivant=*P;
    *P=C;
}

int stackPop(stack * P)
{
    if(*P = NULL)
    {
        int res=(*P)->element;
        stack temp=*P;
        *P=(*P)->suivant;
        free(temp);
        return res;
    }
    else
        exit(EXIT_FAILURE);
}

void printStack(stack P)
{
    stack temp=P;
    while(temp->suivant!=NULL)
    {
        printf("%d, ",temp->element);
        temp=temp->suivant;
    }
    if(temp!=NULL)
        printf("%d\n",temp->element);
}

int main() {
    stack P = NULL;
    stackPush(1,&P); printStack(P);
    stackPop(&P); printStack(P);
    return 0;
}