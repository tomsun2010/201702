/************************************
 * File name   : strtod.c
 * Author      : SJC
 * Description : �ַ���ת���ɸ�������
 * Date        : 2016-8-29 11:24:27
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * ����˵���� ���ַ���ת���ɸ�����
 * ��غ����� atoi��atol��strtod��strtol��strtoul
 * ��ͷ�ļ��� #include <stdlib.h>
 * ���庯���� double strtod(const char *nptr,char **endptr);
 * ����˵���� strtod()��ɨ�����nptr �ַ���������ǰ��Ŀո��ַ���ֱ��������
              �ֻ��������Ųſ�ʼ��ת����ֱ�����ַ����ֻ��ַ�������ʱ
             ����\0�����Ž���ת��������������ء���endptr ��ΪNULL�����
              ������������������ֹ��nptr �е��ַ�ָ����endptr ����,
			  �� endptr Ϊ NULL�����ʾ�ò�����Ч����ʹ�øò���������
              nptr �ַ����ɰ��������š�С�����E(e)����ʾָ�����֡���123.456 ��123e-2��
 * ����ֵ  �� ����ת����ĸ�������
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
