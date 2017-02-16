/************************************
 * File name   : calloc.c
 * Author      : SJC
 * Description : 内存管理
 * Date        : 2016-8-29 15:22:38
 * Makefile    : gcc -o xxx xxx.c
 
 *************************************************
 * 功能说明： 动态分配内存空间（分配连续的内存空间，并初始化为0）
 * 相关函数： malloc，free，realloc，brk
 * 表头文件： #include <stdlib.h>
 * 定义函数： void *calloc(size_t nmemb，size_t size);
 * 函数说明： calloc()用来配置nmemb 个相邻的内存单位，每一单位的大小为
			  size，并返回指向第一个元素的指针。
			  这和使用下列的方式效果相同：
			      malloc(nmemb* size);不过，在利用calloc()配置内存时会将内存
			  内容初始化为0。
			  
 * 返回值  ： 若配置成功则返回一指针，失败则返回NULL
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i,n;
    int *pData;
	
    printf ("要输入的数字的数目：");
    scanf ("%d",&i);
	
    pData = (int*)calloc(i,sizeof(int));
    if (pData==NULL) 
	{
		exit(1);
	}
	
    for (n=0; n<i; n++)
    {
        printf ("请输入数字 #%d：",n+1);
        scanf ("%d",&pData[n]);
    }
	
    printf ("你输入的数字为：");
    for (n=0; n<i; n++) 
	{
		printf ("%d ",pData[n]);
	}  
	printf("\n");
	
    free (pData);
	pData = NULL;
    return 0;
}