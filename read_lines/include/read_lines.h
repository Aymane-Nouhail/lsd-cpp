#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

//in case the user doesn't specify BUFFER_SIZE while compiling. we take 10 by default.
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif


struct letter
{
    char element;
    struct letter * suivant;

};
typedef struct letter letter;
typedef struct letter * string;

/************** PROTOTYPES **************/

//string_implementation.c
unsigned longueurString(string); //length of a string
void printString(string); //afficher un string
void ajoutFinString(char, string*); //add a char at the end of a string
void ajoutDebutString(char, string*); //add a char at the start of a string
void suppressionDebutString(string*); //delete the first char of a string
void freeString(string*); //liberer un string
int indexInString(char, string); //returns index of a character in the string, returns -1 if it's not there.

//read_lines.c
int openString(int, string*,int); //open but takes string instead of char* as second input
char* read_lines(int); 