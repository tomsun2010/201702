/*******************************
 *
 * 第 15 章 管道相关函数
 *
**********************************/

int mkfifo(const char * pathname, mode_t mode);
/*************************************************
 * 功能说明：   mkfifo(建立具名管道)
 * 表头文件：   #include <sys/types.h>   #include <sys/stat.h>
 * 定义函数：   int mkfifo(const char * pathname, mode_t mode);
 * 函数说明：   mkfifo()会依参数pathname 建立特殊的FIFO 文件，该文件必须
				不存在，而参数mode为该文件的权限（mode%~umask），因此umask
				值也会影响到FIFO文件的权限。mkfifo()建立的FIFO 文件其他
				进程都可以用读写一般文件的方式存取。当使用open（）来打开
				FIFO 文件时，O_NONBLOCK 旗标会有影响：
				1、当使用O_NONBLOCK 旗标时，打开FIFO 文件来读取的操作
				会立刻返回，但是若还没有其他进程打开FIFO 文件来读取，则写
				入的操作会返回ENXIO 错误代码。
				2、没有使用O_NONBLOCK 旗标时，打开FIFO 来读取的操作会
				等到其他进程打开FIFO文件来写入才正常返回。同样地，打开FIFO
				文件来写入的操作会等到其他进程打开FIFO 文件来读取后才正常返回。
 * 返回值  ：   若成功则返回0，否则返回-1，错误原因存于errno中。
 * 错误说明：   EACCESS 参数pathname所指定的目录路径无可执行的权限
				EEXIST  参数pathname所指定的文件已存在。
				ENAMETOOLONG 参数pathname的路径名称太长。
				ENOENT  参数pathname包含的目录不存在
				ENOSPC  文件系统的剩余空间不足
				ENOTDIR 参数pathname路径中的目录存在但却非真正的目录。
				EROFS   参数pathname指定的文件存在于只读文件系统内。
 * 附加说明：   
**************************************************/

FILE * popen( const char * command,const char * type);
/*************************************************
 * 功能说明：   popen(建立管道I/O)
 * 表头文件：   #include <stdio.h>
 * 定义函数：   FILE * popen( const char * command,const char * type);
 * 函数说明：   popen（）会调用fork（）产生子进程，然后从子进程中调用/bin/sh
				-c来执行参数command的指令。参数type可使用“r”代表读取，
				“w”代表写入。依照此type值，popen（）会建立管道连到子进程
				的标准输出设备或标准输入设备，然后返回一个文件指针。随后进
				程便可利用此文件指针来读取子进程的输出设备或是写入到子进
				程的标准输入设备中。此外，所有使用文件指针（FILE*）操作的
				函数也都可以使用，除了fclose（）以外。
 * 返回值  ：   若成功则返回文件指针，否则返回NULL，错误原因存于errno中。
 * 错误说明：   EINVAL 参数type不合法
 * 附加说明：   在编写具SUID/SGID权限的程序时请尽量避免使用popen()，
				popen()会继承环境变量，通过环境变量可能会造成系统安全的问题。
**************************************************/

int pclose(FILE * stream);
/*************************************************
 * 功能说明：   pclose(关闭管道I／O)
 * 表头文件：   #include <stdio.h>
 * 定义函数：   int pclose(FILE * stream);
 * 函数说明：   pclose（）用来关闭由popen所建立的管道及文件指针。
				参数stream为先前由popen（）所返回的文件指针
 * 返回值  ：   返回子进程的结束状态。如果有错误则返回-1，错误原因存于errno中。
 * 错误说明：   ECHILD pclose（）无法取得子进程的结束状态
 * 附加说明：   
**************************************************/

int pipe(int filedes[2]);
/*************************************************
 * 功能说明：   pipe(建立管道)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int pipe(int filedes[2]);
 * 函数说明：   pipe（）会建立管道，并将文件描述词由参数filedes 数组返回。
				filedes[0]为管道里的读取端，filedes[1]则为管道的写入端。
 * 返回值  ：   若成功则返回零，否则返回-1，错误原因存于errno中。
 * 错误说明：   EMFILE 进程已用完文件描述词最大量
				ENFILE 系统已无文件描述词可用。
				EFAULT 参数filedes数组地址不合法。
 * 附加说明：   
**************************************************/

