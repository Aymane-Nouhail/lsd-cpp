#include "..\include\read_lines.h"
//#include "../include/read_lines.h"     uncomment this line and comment upper line if on linux.

unsigned longueurString(string L)
{
    unsigned l=0;
    if(L != NULL)
    {
        string temp=L;
        while(temp!=NULL)
        {
            l+=1;
            temp=temp->suivant;
        }
    }
    return l;
}

void printString(string L)
{
    if(L==NULL)
        printf("Empty String!");
    else
    {
        string temp=L;
        while(temp!=NULL)
        {
            if(temp->element == '\n') printf("%c%c",'/','n');
            else printf("%c",temp->element);
            temp=temp->suivant;
        }
    }
}
void ajoutDebutString(char x,string * L)
{
    letter * C=(letter *)malloc(sizeof(letter));
    C->element=x;
    C->suivant=*L;
    *L=C;
    return;
}

void ajoutFinString(char x,string * L)
{
    string C=(string)malloc(sizeof(letter));
    C->element=x;
    C->suivant=NULL;
    if(*L==NULL)
        *L=C;
    else
    {
        string temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }
    return;
}

void suppressionDebutString(string* L)
{
    if(L!=NULL)
    {
        string temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}
void freeString(string *L)
{
    while((*L)!=NULL)
    {
        string temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
}

int indexInString(char x, string L)
{
    string temp=L;
    int count=0;
    if (temp == NULL) {return (-1);}
    while(temp!=NULL)
    {
        if(temp->element==x)
            return count;
        temp=temp->suivant;
        count++;
    }
    return (-1);
}

/*
int main(){
    string T = NULL;
    ajoutFinString('w',&T);
    ajoutFinString('o',&T);
    ajoutFinString('\n',&T);
    ajoutFinString('g',&T);
    printf("%d",indexInString('x',T));
    freeString(&T);
    printString(T);
    return 0;
}
*/

