/************************************
 * File name   : process.c
 * Author      : SJC
 * Description : 进程管理

 * Date        : 2016-9-5 10:23:58
 * Makefile    : gcc -o xxx xxx.c

 *************************************************/
 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>
 
 # include <unistd.h>
 void my_atexit(void)
 {
	 printf("before exit()!!\n");
 }
 
 void my_on_exit(int status, void *arg)
 {
	 printf("before exit()!!\n");
	 //printf("arg = %d\n", (int *)arg);
 }
 int main(void)
 {
	int tmp = 0;
	
	srand(time(NULL));
	
	tmp = rand()%7200 + 3600;
	printf("tmp = %d\n", tmp);
	
	//execl("/bin/ls", "ls", "-al", NULL);
	
	printf("getpid = %d\n", getpid());
	printf("getpgrp = %d\n", getpgrp());
	printf("getpgid = %d\n", getpgid(0));
	printf("getppid = %d\n", getppid());
	
	system("ls -al /etc/passwd /etc/shadow");
	
	//atexit(my_atexit);
	//on_exit(my_on_exit, (void *)(tmp));
	//exit(0);
	return 0;
 }