#include "../include/read_lines.h"

//the text file associated with the file descriptor has to end with an /n or else the program fails at the last line.
char* read_lines(int fd){
    char* res = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &res, 0) < 0)
		return (NULL);
    static int stop_condition = 0;
    static string queue = NULL;
    if(stop_condition == 1) return NULL;
    int check = openString(fd,&queue,BUFFER_SIZE); //reading into queue BUFFER_SIZE bites from fd
    if (check < BUFFER_SIZE){ //this means we're in the last line, we treat it separately.
        int n = longueurString(queue);
        res = (char*)malloc(n+1);
        for(int i=0;i<n;i++){
            res[i] = queue->element;
            queue = queue->suivant;
        }
        res[n] = '\0';
        stop_condition = 1; //so that the next time the function is ran we return NULL.
        return res;
    }
    //general case : 
    while(indexInString('\n',queue) == -1){ //redoing open while encountering no newlines
        openString(fd,&queue,BUFFER_SIZE);
    }
    int index_newline = indexInString('\n',queue); //getting the index of where \n was first encountered in queue
    res = (char*) malloc(index_newline +2); //the 2 extra mallocs are for : '\n' and '\0'
    string temp = queue;
    for(int i=0;i<index_newline;i++){
        res[i] = temp->element; //copying everything before \n from queue into res
        temp = temp->suivant; //advancing the singly linked list by one
        suppressionDebutString(&queue); //deleting everything before /n from queue
    }
    suppressionDebutString(&queue); //one extra delete to get rid of a trailing /n
    res[index_newline] = '\n'; //res has to end with \n
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