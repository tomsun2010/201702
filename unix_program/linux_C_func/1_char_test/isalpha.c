/************************************
 * File name   : isalpha.c
 * Author      : SJC
 * Description : 检查参数c是否为英文字母，在标准c中相当于使用（isupper（c）
                 ||islower（c））做测试。

 * Date        : 2016-8-29 10:14:39
 *
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * 相关函数： isalnum，islower，isupper
 * 表头文件： #include<ctype.h>
 * 定义函数： int isalpha (int c)
 * 函数说明： 检查参数c是否为英文字母，在标准c中相当于使用（isupper（c）
              ||islower（c））做测试。
 * 返回值  ： 若参数c为英文字母，则返回TRUE，否则返回NULL( 0 )。
 * 附加说明： 此为宏定义，非真正函数
**************************************************/
#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 

#include<ctype.h>  

int main(void)
{
	char str[] = "123c@#FDsP{e?";
	int i = 0;
	for (i=0; str[i]!=0; i++)
	{
		if (isalpha(str[i]))
		{
			printf("%c is an apphabetic character\n", str[i]);
		}
	}
	return 0;
}