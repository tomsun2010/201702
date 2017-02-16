/************************************
 * File name   : isalnum.c
 * Author      : SJC
 * Description : 利用isalnum检查参数c是否为英文字母或阿拉伯数字，在标准c中相当于使用
                （isalpha( c )|| isdigit( c )）做测试。

 * Date        : 2016-8-29 09:57:27
 *
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * 相关函数： isalpha，isdigit，islower，isupper
 * 表头文件： #include<ctype.h>
 * 定义函数： int isalnum (int c)
 * 函数说明： 检查参数c是否为英文字母或阿拉伯数字，在标准c中相当于使用
             （isalpha( c )|| isdigit( c )）做测试。
 * 返回值  ： 若参数c为字母或数字，则返回TRUE，否则返回NULL( 0 )。
 * 附加说明： 此为宏定义，非真正函数
**************************************************/
#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 

#include<ctype.h>  //isalnum

int main(void)
{
	char str[] = "123c@#FDsP{e?";
	int i = 0;
	for (i=0; str[i]!=0; i++)
	{
		if (isalnum(str[i]))
		{
			printf("%c is an alphanumeric character\n", str[i]);
		}
	}
	return 0;
}