/************************************
 * File name   : strtod.c
 * Author      : SJC
 * Description : 字符串转换成浮点型数
 * Date        : 2016-8-29 11:24:27
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * 功能说明： 将字符串转换成浮点数
 * 相关函数： atoi，atol，strtod，strtol，strtoul
 * 表头文件： #include <stdlib.h>
 * 定义函数： double strtod(const char *nptr,char **endptr);
 * 函数说明： strtod()会扫描参数nptr 字符串，跳过前面的空格字符，直到遇上数
              字或正负符号才开始做转换，直到出现非数字或字符串结束时
             （’\0’）才结束转换，并将结果返回。若endptr 不为NULL，则会
              将遇到不合条件而终止的nptr 中的字符指针由endptr 传回,
			  若 endptr 为 NULL，则表示该参数无效，或不使用该参数。参数
              nptr 字符串可包含正负号、小数点或E(e)来表示指数部分。如123.456 或123e-2。
 * 返回值  ： 返回转换后的浮点型数
**************************************************/
#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 

int main(void)
{
	char a[] = "100000000";
	char b[] = "100000";
	char c[] = "ffff";
	
	printf("a = %lf\n", strtod(a, NULL));
	printf("b= %lf\n", strtod(b, NULL));
	printf("c = %lf\n", strtod(c, NULL));
 	return 0;
}
