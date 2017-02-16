/************************************
 * File name   : mmap.c
 * Author      : SJC
 * Description : 内存映射
 * Date        : 2016-8-29 15:51:55
 * Makefile    : gcc -o xxx xxx.c
**************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//mmap需要这两个
#include <unistd.h> 
#include <sys/mman.h>

//fstat和open需要这三个
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = -1;
    void *start;
    struct stat sb;
	
    fd = open("/etc/passwd", O_RDONLY); /*打开/etc/passwd */
    fstat(fd, &sb); /* 取得文件大小 */
    start = mmap(NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if(start == MAP_FAILED) /* 判断是否映射成功 */
	{
        return -1;
	}
	
    printf("%s\n", start);
	
	munmap(start, sb.st_size); /* 解除映射 */
    close(fd);
    return 0;
}