/************************************
 * File name   : atof.c
 * Author      : SJC
 * Description : �ַ���ת���ɸ�������
 * Date        : 2016-8-29 10:52:57
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * ��غ����� atoi��atol��strtod��strtol��strtoul
 * ��ͷ�ļ��� #include <stdlib.h>
 * ���庯���� double atof(const char *nptr);
 * ����˵���� atof������ɨ�����nptr�ַ���������ǰ��Ŀո��ַ���ֱ������
              ���ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ
             ����\0�����Ž���ת��������������ء�����nptr �ַ����ɰ�������
              �š�С�����E��e������ʾָ�����֣���123.456 ��123e-2��
			  
 * ����ֵ  �� ����ת����ĸ���������
 * ����˵���� atof()��ʹ��strtod��nptr,(char**)NULL���������ͬ��
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