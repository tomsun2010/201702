/************************************
 * File name   : getopt.c
 * Author      : SJC
 * Description : 分析命令行参数

 * Date        : 2016-9-12 10:26:50
 * Makefile    : gcc -o xxx xxx.c
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>

int main(int argc, char **argv)
{
	#if 0
		int ch = 0;

		while((ch=getopt(argc, argv, "a:bcde")) != -1)
		switch(ch)
		{
			case 'a':
				printf("option a:'%s'\n", optarg);   //./xxx -axx
				break;
			case 'b':
				printf("option b:b\n");              //./xxx -b
				break;
			default:
				printf("other option:%c\n", ch);    //./xxx -a
		}
	#endif 
	
	#if 1
		int opt = 0;
        int wdog_flag = 0;
		while((opt=getopt(argc, argv, "w")) != -1)
		switch(opt)
		{
			case 'w':
			{
				wdog_flag = 1;   //./xxx -w
				printf("wdog_flag = %d\n", wdog_flag);
				break;
			}
			default:
			{
				break;
			}
		}
	#endif 
	return 0;
}