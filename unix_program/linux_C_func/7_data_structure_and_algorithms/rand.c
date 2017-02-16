/************************************
 * File name   : rand.c
 * Author      : SJC
 * Description : 产生随机数

 * Date        : 2016-8-30 16:34:49
 * Makefile    : gcc -o xxx xxx.c

 *************************************************/
 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>
 
 # include <time.h>
 int main(void)
 {
	int tmp = 0;
	
	srand(time(NULL));
	
	tmp = rand()%7200 + 3600;
	printf("tmp = %d\n", tmp);
	
	return 0;
 }