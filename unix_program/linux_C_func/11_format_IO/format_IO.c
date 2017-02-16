/************************************
 * File name   : format_IO.c
 * Author      : SJC
 * Description : ∏Ò ΩªØIO

 * Date        : 2016-9-2 13:50:44
 * Makefile    : gcc -o xxx xxx.c

 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <stdarg.h>


int my_scanf(const char *format, ...)
{
    va_list ap;
	
    int retval = 0;
	
    va_start(ap, format);
    printf("my_scanf():");
	
    retval = vscanf(format, ap);
	
    va_end(ap);
	
    return retval;
}

int my_printf(const char *format, ...)
{
    va_list ap;
	
    int retval = 0;
	
    va_start(ap, format);
    printf("my_printf():");
	
    retval = vprintf(format, ap);
	
    va_end(ap);
	
    return retval;
}

int main(void)
{
	int i = 0;
	int j = 0;
	char s[5] = {0};
	char buf[100] = {0};
	char input[] = "10 0x1b aaaaaa bbbbbb";
	size_t count = 0;

	sscanf(input, "%d %x %s", &i, &j, s);
	printf("i=%d, j=%d, s=%s\n", i, j, s);

	sprintf(buf, ">>>%s<<<\n", s);
	printf("%s", buf);
	
	//count = snprintf(buf, 20, "%s", s);
	count = snprintf(buf, strlen(s), "%s", s);
	printf("count=%d, buf=%s\n", (int)count, buf);
	
	//my_scanf("%d, %d, %s", &i, &j, s);
	//my_printf("i=%d, j=%d, s=%s\n", i, j, s);
	
	
    

	return 0;
}