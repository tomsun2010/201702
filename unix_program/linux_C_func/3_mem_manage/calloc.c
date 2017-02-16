/************************************
 * File name   : calloc.c
 * Author      : SJC
 * Description : �ڴ����
 * Date        : 2016-8-29 15:22:38
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * ����˵���� ��̬�����ڴ�ռ䣨�����������ڴ�ռ䣬����ʼ��Ϊ0��
 * ��غ����� malloc��free��realloc��brk
 * ��ͷ�ļ��� #include <stdlib.h>
 * ���庯���� void *calloc(size_t nmemb��size_t size);
 * ����˵���� calloc()��������nmemb �����ڵ��ڴ浥λ��ÿһ��λ�Ĵ�СΪ
			  size��������ָ���һ��Ԫ�ص�ָ�롣
			  ���ʹ�����еķ�ʽЧ����ͬ��
			      malloc(nmemb* size);������������calloc()�����ڴ�ʱ�Ὣ�ڴ�
			  ���ݳ�ʼ��Ϊ0��
			  
 * ����ֵ  �� �����óɹ��򷵻�һָ�룬ʧ���򷵻�NULL
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i,n;
    int *pData;
	
    printf ("Ҫ��������ֵ���Ŀ��");
    scanf ("%d",&i);
	
    pData = (int*)calloc(i,sizeof(int));
    if (pData==NULL) 
	{
		exit(1);
	}
	
    for (n=0; n<i; n++)
    {
        printf ("���������� #%d��",n+1);
        scanf ("%d",&pData[n]);
    }
	
    printf ("�����������Ϊ��");
    for (n=0; n<i; n++) 
	{
		printf ("%d ",pData[n]);
	}  
	printf("\n");
	
    free (pData);
	pData = NULL;
    return 0;
}