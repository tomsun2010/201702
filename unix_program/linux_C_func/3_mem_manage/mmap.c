/************************************
 * File name   : mmap.c
 * Author      : SJC
 * Description : �ڴ�ӳ��
 * Date        : 2016-8-29 15:51:55
 * Makefile    : gcc -o xxx xxx.c
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//mmap��Ҫ������
#include <unistd.h> 
#include <sys/mman.h>

//fstat��open��Ҫ������
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = -1;
    void *start;
    struct stat sb;
	
    fd = open("/etc/passwd", O_RDONLY); /*��/etc/passwd */
    fstat(fd, &sb); /* ȡ���ļ���С */
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED) /* �ж��Ƿ�ӳ��ɹ� */
	{
        return -1;
	}
	
    printf("%s\n", start);
	
	munmap(start, sb.st_size); /* ���ӳ�� */
    close(fd);
    return 0;
}