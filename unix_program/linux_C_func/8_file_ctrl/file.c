/************************************
 * File name   : file.c
 * Author      : SJC
 * Description : ÎÄ¼þ²Ù×÷

 * Date        : 2016-8-30 16:58:11
 * Makefile    : sudo gcc xxx.c -o xxx
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
# include <sys/types.h>   
# include <sys/stat.h>   
# include <fcntl.h>
# include <unistd.h>

# include <errno.h>
 
int main(void)
{
	int fd = -1;
	char s[] = "linux c func file!!!!";
	char buf[30];
	int wr_count = 0;
	int rd_count = 0;
	int offset = 0;
	int ret = 0; 
	int flags = 0;
	
	
	memset(buf, 0x0, sizeof(buf));
	
	//fd = open("sjc.txt", O_WRONLY|O_CREAT, 0777);
	fd = open("sjc.txt", O_WRONLY|O_CREAT);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	
	flags = fcntl(fd, F_GETFL, 0);
	printf("flags = %d\n", flags);
	
	wr_count = write(fd, s, sizeof(s));
	printf("wr_count = %d\n", wr_count);
	
	close(fd);
	
	fd = open("sjc.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return -1;
	}
	
	ret = lseek(fd, 2, SEEK_SET);
	printf("offset = %d\n", ret);
	
	rd_count = read(fd, buf, sizeof(buf));
	printf("rd_count = %d\n", rd_count);
	close(fd);
	printf("%s\n", buf);
	
	return 0;
}