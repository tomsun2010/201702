/************************************
 * File name   : signal.c
 * Author      : SJC
 * Description : ÐÅºÅº¯Êý

 * Date        : 2016-9-7 14:52:24
 * Makefile    : gcc -o xxx xxx.c

 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int main(void)
{
	int i = 0;
	for (i=0; i<20; i++)
	{
		printf("error_num=%d:%s\n", i, strerror(i));
	}
	return 0;
}