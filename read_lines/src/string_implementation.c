#include "../include/read_lines.h"

int longueurString(string L)
{
    int l=0;
    if(L != NULL){
        while(L!=NULL){
            l+=1;
            L=L->suivant;
        }
    }
    return l;
}

void printString(string L){
    if(L==NULL)
        printf("Empty String!");
    else{
        while(L!=NULL){
            if(L->element == '\n') printf("(newline)");
            else printf("%c",L->element);
            L=L->suivant;
        }
    }
}
void ajoutDebutString(char x,string* L){
    letter* C=(letter *)malloc(sizeof(letter));
    C->element=x;
    C->suivant=*L;
    *L=C;
    return;
}

void ajoutFinString(char x,string * L){
    letter* C=(letter*)malloc(sizeof(letter));
    C->element=x;
    C->suivant=NULL;
    if(*L==NULL)
        *L=C;
    else{
        string temp=*L;
        while(temp->suivant!=NULL)
            temp=temp->suivant;
        temp->suivant=C;
    }
    return;
}

void suppressionDebutString(string* L){
    if(L!=NULL){
        string temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
    return;
}
void freeString(string *L){
    while((*L)!=NULL){
        string temp=*L;
        *L=(*L)->suivant;
        free(temp);
    }
}

int indexInString(char x, string L){
    int count=0;
    if (L == NULL) return (-1);
    while(L!=NULL){
        if(L->element==x)
            return count;
        L=L->suivant;
        count++;
    }
    return (-1);
}



/*int main(){
    string T = NULL;
    ajoutFinString('w',&T);
    ajoutFinString('o',&T);
    ajoutFinString('o',&T);
    ajoutFinString('g',&T);
    char test[5] = "hello";
    printString(T);
    return 0;
}*/


