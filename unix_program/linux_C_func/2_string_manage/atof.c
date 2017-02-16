/************************************
 * File name   : atof.c
 * Author      : SJC
 * Description : 字符串转换成浮点型数
 * Date        : 2016-8-29 10:52:57
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * 相关函数： atoi，atol，strtod，strtol，strtoul
 * 表头文件： #include <stdlib.h>
 * 定义函数： double atof(const char *nptr);
 * 函数说明： atof（）会扫描参数nptr字符串，跳过前面的空格字符，直到遇上
              数字或正负符号才开始做转换，而再遇到非数字或字符串结束时
             （’\0’）才结束转换，并将结果返回。参数nptr 字符串可包含正负
              号、小数点或E（e）来表示指数部分，如123.456 或123e-2。
			  
 * 返回值  ： 返回转换后的浮点型数。
 * 附加说明： atof()与使用strtod（nptr,(char**)NULL）；结果相同。
**************************************************/
#include <stdio.h>
#include <string.h>  
#include <stdlib.h> 


int main(void)
{
	char *a = "-100.23";
	char *b = "200e-2";
	float c = 0;
	
	c = atof(a) + atof(b);
    printf("c = %.2f\n", c);
	return 0;
}