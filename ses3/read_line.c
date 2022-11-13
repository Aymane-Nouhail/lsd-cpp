#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char* read_lines(int);

char* read_lines(int fd){
    {
	static char		*s;
	char			*buffer;
	char			*temp;
	int				k;

	if (BUFFER_SIZE < 0 || fd < 0 || line == NULL)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (s == NULL)
		s = ft_strdup("");
	k = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(s, '\n') && k > 0)
	{
		buffer[k] = '\0';
		temp = s;
		s = ft_strjoinn(s, buffer);
		free(temp);
		k = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (output(line, &s, k));
}
}

int main(void) {
    int fd = open("file.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char buf[BUFSIZ+1];
    ssize_t n = 0;
    while ((n = read(fd, buf, BUFSIZ)) > 0) {
        buf[n] = '\0';
        if ((write(STDOUT_FILENO, buf, n)) == -1) {
            perror("write");
            exit(1);        
        }        
    }
    if (n == -1) {
        perror("read");
        exit(1);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(1);    
    }
    exit(0);
}