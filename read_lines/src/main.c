#include "..\include\read_lines.h"
//#include "../include/read_lines.h"     uncomment this line and comment upper line if on linux.


//in order to compile, cd into read_lines, then run the following command  : gcc src/* -o read_lines.exe -D BUFFER_SIZE=10

int	main()
{
	int	fd;
	char *buf;
    string T = NULL;
	fd = open("test", O_RDONLY);
    buf = read_lines(fd);
    printf("%s",buf);
    while("The sky has not fallen"){
        buf = read_lines(fd);
        if(buf == NULL) break;
        printf("%s",buf);
        free(buf);
    }
    free(buf);
    return 0;
}