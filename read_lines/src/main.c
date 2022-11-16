#include "../include/read_lines.h"


//in order to compile, cd into read_lines, then run the following command  : gcc src/* -o read_lines.exe -D BUFFER_SIZE=10

int	main()
{
	int	fd;
	char *res;
	fd = open("test.txt", O_RDONLY);
    int n; 
    printf("how many lines do you want to show? "); scanf("%d",&n);
    for(int i=0;i<n;i++){
        res = read_lines(fd);
        printf("%s",res);
        free(res);
    }
    free(res);
    return 0;
}
