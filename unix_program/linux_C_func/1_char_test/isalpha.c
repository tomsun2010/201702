/************************************
 * File name   : isalpha.c
 * Author      : SJC
 * Description : ������c�Ƿ�ΪӢ����ĸ���ڱ�׼c���൱��ʹ�ã�isupper��c��
                 ||islower��c���������ԡ�

 * Date        : 2016-8-29 10:14:39
 *
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * ��غ����� isalnum��islower��isupper
 * ��ͷ�ļ��� #include<ctype.h>
 * ���庯���� int isalpha (int c)
 * ����˵���� ������c�Ƿ�ΪӢ����ĸ���ڱ�׼c���൱��ʹ�ã�isupper��c��
              ||islower��c���������ԡ�
 * ����ֵ  �� ������cΪӢ����ĸ���򷵻�TRUE�����򷵻�NULL( 0 )��
 * ����˵���� ��Ϊ�궨�壬����������
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