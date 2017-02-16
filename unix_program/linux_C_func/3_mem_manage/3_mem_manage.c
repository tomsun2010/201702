/****************************
 *
 * 第三章 内存管理
 *
*****************************/

void *calloc(size_t nmemb，size_t size);
/*************************************************
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
 * 附加说明： 
**************************************************/

void free(void *ptr);
/*************************************************
 * 功能说明： 释放原先配置的内存
 * 相关函数： malloc，calloc，realloc，brk
 * 表头文件： #include <stdlib.h>
 * 定义函数： void free(void *ptr);
 * 函数说明： 参数ptr 为指向先前由malloc（）、calloc()或realloc()所返回的内存
			  指针。调用free()后ptr 所指的内存空间便会被收回。假若参数ptr
			  所指的内存空间已被收回或是未知的内存地址，则调用free()可能
			  会有无法预期的情况发生。若参数ptr 为NULL，则free()不会有任
			  何作用。			  
 * 返回值  ： 
 * 附加说明： 
**************************************************/

int getpagesize(void);
/*************************************************
 * 功能说明： 取得内存分页大小
 * 相关函数： sbrk
 * 表头文件： #include<unistd.h>
 * 定义函数： int getpagesize(void);
 * 函数说明： 返回一分页的大小，单位为字节（byte）。此为系统的分页大小，
			  不一定会和硬件分页大小相同。	  
 * 返回值  ： 内存分页大小。
 * 附加说明： 在Intel x86 上其返回值应为4096bytes
**************************************************/

void * malloc(size_t size);
/*************************************************
 * 功能说明： 配置内存空间
 * 相关函数： calloc，free，realloc，brk
 * 表头文件： #include<stdlib.h>
 * 定义函数： void * malloc(size_t size);
 * 函数说明： malloc（）用来配置内存空间，其大小由指定的size决定。	  
 * 返回值  ： 若配置成功则返回一指针，失败则返回NULL
 * 附加说明： 
**************************************************/

void *mmap(void *start,size_t length,int prot,int flags,int fd,off_t offsize);
/*************************************************
 * 功能说明： 建立内存映射
 * 相关函数： calloc，free，realloc，brk
 * 表头文件： #include <unistd.h> #include <sys/mman.h>
 * 定义函数： void *mmap(void *start,size_t length,int prot,int flags,int fd,off_t offsize);
 * 函数说明： mmap()用来将某个文件内容映射到内存中，对该内存区域的存取即是直接对该文件内容的读写。
              start 指向欲对应的内存起始地址，通常设为NULL，代表让系统自动选定地址，对应成功后该地址会返回。
	          length代表将文件中多大的部分对应到内存。
			  prot 代表映射区域的保护方式，有下列组合：
											PROT_EXEC 映射区域可被执行
											PROT_READ 映射区域可被读取
											PROT_WRITE 映射区域可被写入
											PROT_NONE 映射区域不能存取
              flags会影响映射区域的各种特性：
					MAP_FIXED 如果参数start所指的地址无法成功建立映射时，则放弃映射，不对地址做修正。通常不鼓励用此旗标。
					MAP_SHARED 对映射区域的写入数据会复制回文件内，而且允许其他映射该文件的进程共享。
					MAP_PRIVATE 对映射区域的写入操作会产生一个映射文件的复制，即私人的“写入时复制”（copy on write）
					            对此区域作的任何修改都不会写回原来的文件内容。
					MAP_ANONYMOUS建立匿名映射。此时会忽略参数fd，不涉及文件，而且映射区域无法和其他进程共享。
					MAP_DENYWRITE 只允许对映射区域的写入操作，其他对文件直接写入的操作将会被拒绝。
					MAP_LOCKED 将映射区域锁定住，这表示该区域不会被置换（swap）。
                    在调用mmap()时必须要指定MAP_SHARED 或MAP_PRIVATE。
              fd为open()返回的文件描述词，代表欲映射到内存的文件。
			  offset 为文件映射的偏移量，通常设置为0，代表从文件最前方开始对应，offset必须是分页大小的整数倍。	  
 * 返回值  ： 若映射成功则返回映射区的内存起始地址，否则返回MAP_FAILED（－1），错误原因存于errno中。
 * 错误代码： EBADF 参数fd不是有效的文件描述词
			  EACCES 存取权限有误。如果是MAP_PRIVATE 情况下文件必须可读，
			         使用MAP_SHARED 则要有PROT_WRITE 以及该文件要能写入。
			  EINVAL 参数start、length或offset有一个不合法。
			  EAGAIN 文件被锁住，或是有太多内存被锁住。
			  ENOMEM 内存不足。
 * 附加说明： 
**************************************************/

int munmap(void *start,size_t length);
/*************************************************
 * 功能说明： 解除内存映射
 * 相关函数： mmap
 * 表头文件： #include<unistd.h>    #include<sys/mman.h>
 * 定义函数： int munmap(void *start,size_t length);
 * 函数说明： munmap()用来取消参数start所指的映射内存起始地址，参数length
			  则是欲取消的内存大小。当进程结束或利用exec相关函数来执行其
			  他程序时，映射内存会自动解除，但关闭对应的文件描述词时不会解除映射。  
 * 返回值  ： 如果解除映射成功则返回0，否则返回－1，错误原因存于errno中
 * 错误代码： EINVAL 参数start或length不合法。
 * 附加说明： 
**************************************************/

void * memset( void * ptr, int value, size_t num );
/*************************************************
 * 功能说明： 指定内存的前num个字节设置为特定的值
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： void * memset( void * ptr, int value, size_t num );
 * 函数说明： memset() 会将 ptr 所指的内存区域的前 num 个字节的值都设置为 value，然后返回指向 ptr 的指针
              memset() 可以将一段内存空间全部设置为特定的值，所以经常用来初始化字符数组
			  ptr 为要操作的内存的指针
			  value 为要设置的值：虽声明为 int，但必须是 unsigned char，所以范围在0到255之间
			  num 为 ptr 的前 num 个字节，size_t 就是unsigned int
 * 返回值  ： 返回指向 ptr 的指针
**************************************************/

void * memmove(void *dest, const void *src, size_t num);
/*************************************************
 * 功能说明： memmove() 用来复制内存内容
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： void * memmove(void *dest, const void *src, size_t num);
 * 函数说明： memmove() 与 memcpy() 类似都是用来复制 src 所指的内存内容
              前 num 个字节到 dest 所指的地址上。
			  不同的是，memmove() 更为灵活，当src 和 dest 所指的内存区域重叠时，
			  memmove() 仍然可以正确的处理，不过执行效率上会比使用 memcpy() 略慢些。
 * 返回值  ： 
 * 附件说明： 
			#include <stdio.h>
			#include <stdlib.h>
			#include <string.h>
			int main (void)
			{
				char str[] = "memmove can be very useful......";
				memmove (str+20,str+15,11);
				puts (str);
				return 0;
			}
**************************************************/

void * memcpy ( void * dest, const void * src, size_t num );
/*************************************************
 * 功能说明： 复制内存内容
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： void * memcpy ( void * dest, const void * src, size_t num );
 * 函数说明： 复制 src 所指的内存内容的前 num 个字节到 dest 所指的内存地址上。
			  memcpy() 并不关心被复制的数据类型，只是逐字节地进行复制，
			  这给函数的使用带来了很大的灵活性，可以面向任何数据类型进行复制。
			  
			  与 strcpy() 不同的是，memcpy() 会完整的复制 num 个字节，不会因为遇到“\0”而结束。
			  
 * 返回值  ： 返回指向 dest 的指针。注意返回的指针类型是 void，使用时一般要进行强制类型转换。
 * 附件说明： 
		需要注意的是：
            dest 指针要分配足够的空间，也即大于等于 num 字节的空间。如果没有分配空间，会出现段错误。
            dest 和 src 所指的内存空间不能重叠（如果发生了重叠，使用 memmove() 会更加安全）。
**************************************************/

int memcmp (const void *s1, const void *s2, size_t n);
/*************************************************
 * 功能说明： 比较内存的内容
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： int memcmp (const void *s1, const void *s2, size_t n);
 * 函数说明： memcmp()用来比较s1 和s2 所指的内存区间前n个字符。
			  字符串大小的比较是以ASCII 码表上的顺序来决定，次顺序亦为字符的值。
			  memcmp()首先将s1 第一个字符值 减去 s2第一个字符的值，若差为0则再继续比较下个字符，
			  若差值不为0则将差值返回。
			  
 * 返回值  ： 若参数s1 和s2 所指的内存内容都完全相同，则返回0值。
              s1 若大于s2 则返回大于0 的值。
			  s1 若小于s2 则返回小于0 的值。
 * 附件说明： 
**************************************************/

void * memchr(const void *s, char c, size_t n);
/*************************************************
 * 功能说明： 比较内存的内容
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： void * memchr(const void *s, char c, size_t n);
 * 函数说明： memchr()从头开始搜寻s 所指的内存内容前n 个字节，直到发现第一个值为c 的字节，则返回指向该字节的指针。
			  
 * 返回值  ： 如果找到指定的字节则返回该字节的指针，否则返回0。
 * 附件说明： 
**************************************************/

void * memccpy(void *dest, const void * src, int c, size_t n);
/*************************************************
 * 功能说明： 比较内存的内容
 * 相关函数： 
 * 表头文件： #include <string.h>
 * 定义函数： void * memccpy(void *dest, const void * src, int c, size_t n);
 * 函数说明： memccpy()用来拷贝src 所指的内存内容前n 个字节到dest 所指的地址上。
			  与memcpy()不同的是，memccpy()会在复制时检查参数c 是否出现，
			  若是则返回dest 中值为c 的下一个字节地址。
			  
 * 返回值  ： 返回指向dest 中值为c 的下一个字节指针。
              返回值为0 表示在src 所指内存前n 个字节中没有值为c的字节。
 * 附件说明： 
**************************************************/



