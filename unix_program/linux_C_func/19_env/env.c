/************************************
 * File name   : env.c
 * Author      : SJC
 * Description : 环境变量函数

 * Date        : 2016-9-9 15:08:42
 * Makefile    : gcc -o xxx xxx.c

	char * getenv(const char *name);
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
	char *p = NULL;
	
	p = getenv("USER");
	if (NULL != p)
	{
		printf("USER = %s\n", p);
	}
	
	putenv("SJC=laoda");
	printf("SJC = %s\n", getenv("SJC"));
	
	
	setenv("SJC", "123", 1);
	printf("SJC = %s\n", getenv("SJC"));
	
	unsetenv("SJC");
	printf("SJC = %s\n", getenv("SJC"));
	
	return 0;
}