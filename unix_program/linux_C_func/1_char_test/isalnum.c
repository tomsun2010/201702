/************************************
 * File name   : isalnum.c
 * Author      : SJC
 * Description : ����isalnum������c�Ƿ�ΪӢ����ĸ���������֣��ڱ�׼c���൱��ʹ��
                ��isalpha( c )|| isdigit( c )�������ԡ�

 * Date        : 2016-8-29 09:57:27
 *
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * ��غ����� isalpha��isdigit��islower��isupper
 * ��ͷ�ļ��� #include<ctype.h>
 * ���庯���� int isalnum (int c)
 * ����˵���� ������c�Ƿ�ΪӢ����ĸ���������֣��ڱ�׼c���൱��ʹ��
             ��isalpha( c )|| isdigit( c )�������ԡ�
 * ����ֵ  �� ������cΪ��ĸ�����֣��򷵻�TRUE�����򷵻�NULL( 0 )��
 * ����˵���� ��Ϊ�궨�壬����������
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