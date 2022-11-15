#include "../include/read_lines.h"

char* read_lines(int fd){
    char* res = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &res, 0) < 0)
		return (NULL);
    static string queue = NULL;
    int check = openString(fd,&queue,BUFFER_SIZE); //reading into queue BUFFER_SIZE bites from fd
    if(queue == NULL) return NULL;
    //general case : 
    while(check == BUFFER_SIZE && indexInString('\n',queue) == -1){ //redoing open while encountering no newlines
        openString(fd,&queue,BUFFER_SIZE);
    }
    int index_newline = indexInString('\n',queue); //getting the index of where \n was first encountered in queue
    if(index_newline == -1){ //particular case : we're in the last line.(if the document doesn't end in \n)
        index_newline = longueurString(queue)-1; //index_newline ought be changed from -1 to longueur. 
    } //we substracted one because index and size(longueur) are one-off each other.
    res = (char*) malloc(index_newline +2); //the 2 extra mallocs are for : '\n' and '\0'
    string temp = queue;
    for(int i=0;i<index_newline+1;i++){
        res[i] = temp->element; //copying everything before \n from queue into res
        temp = temp->suivant; //advancing the singly linked list by one
        suppressionDebutString(&queue); //deleting everything before /n from queue
    }
    res[index_newline+1] = '\0'; // \0 to close the char* off.
    return res;
}

//basically open but for string instead of char* in the second parameter.
int openString(int fd, string* res, int n){
    char *buf;
    int count = (int)read(fd,buf,n);
    for(int i=0;i<count;i++){
        ajoutFinString(buf[i],res);
    }
    return count;
}