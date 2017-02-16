/************************************
 * File name   : isattty.c
 * Author      : SJC
 * Description : 判断文件描述词是否是为终端机

 * Date        : 2016-9-12 10:58:19
 * Makefile    : gcc -o xxx xxx.c
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int main(void)
{
	int fd = -1;
	char *file = "/dev/tty";
	
	fd = open(file, O_RDONLY);
	
	if (isatty(fd))
	{
		printf("%s is a tty\n", file);
		printf("ttyname() = %s\n", ttyname(fd));
	}
    else  
	{
		printf("%s is not a tty\n", file);
	}
	
	close(fd);
	return 0;
}