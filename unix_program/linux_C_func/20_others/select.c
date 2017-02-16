/************************************
 * File name   : select.c
 * Author      : SJC
 * Description : I/O多工机制

 * Date        : 2016-9-12 11:04:51
 * Makefile    : gcc -o xxx xxx.c
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>
# include <sys/types.h>
 #include<sys/time.h>
 
void my_delay(int sec, int usec)
{
	struct timeval tval = {};
	tval.tv_sec = sec;
	tval.tv_usec = usec;
	select(0, NULL, NULL, NULL, &tval);
}

int main(void)
{
	
	#if 0
	    /*用select作延时*/
		static int count = 0;
		while (1)
		{
			printf("count=%d\n", count);
			//sleep(1);
			my_delay(1, 0);
			count++;
			if (10 == count)
			{
				count = 0;
			}
		}
	#endif 
	return 0;
}