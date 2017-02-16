/*******************************
 *
 * 第八章 文件操作---初级IO函数
 *
**********************************/

open(打开文件)
/*************************************************
 * 功能说明：   open(打开文件)
 * 表头文件：   #include<sys/types.h>  #include<sys/stat.h>  #include<fcntl.h>
 * 定义函数：   int open( const char * pathname, int flags);
				int open( const char * pathname,int flags, mode_t mode); 
 * 函数说明： 	pathname 指向欲打开的文件路径字符串。
                flags能使用的旗标：
					O_RDONLY 只读方式打开文件
					O_WRONLY 只写方式打开文件
					O_RDWR   可读写方式打开文件。
				上述三种旗标是互斥的，不可同时使用，但可与下列的旗标利用OR（|）运算符组合。
					O_CREAT 若欲打开的文件不存在则自动建立该文件。
					O_EXCL  如果O_CREAT也被设置，此指令会去检查文件是否存在。
							文件若不存在则建立该文件，否则将导致打开文件错误。
					O_NOCTTY 如果欲打开的文件为终端机设备时，则不会将该终端机当成进程控制终端机。
					O_TRUNC	 若文件存在并且以可写的方式打开时，此旗标会令文件长度清为0，而原来存于该文件的资料也会消失。
					O_APPEND 当读写文件时会从文件尾开始移动，也就是所写入的数据会以附加的方式加入到文件后面。
					O_NONBLOCK 以不可阻断的方式打开文件，也就是无论有无数据读取或等待，都会立即返回进程之中。
					O_NDELAY 同O_NONBLOCK。
					O_SYNC 以同步的方式打开文件。
					O_NOFOLLOW  如果参数pathname 所指的文件为一符号连接，则会令打开文件失败。
					O_DIRECTORY 如果参数pathname所指的文件并非为一目录，则会令打开文件失败
				mode只有在建立新文件时才会生效：
					USER GROUP OTHER
					RWX  RWX   RWX
					4210 4210  4210====>0777 0776 0775 ... 0000					
 * 返回值  ： 	若所有欲核查的权限都通过了检查则返回0值, 表示成功, 只要有一个权限被禁止则返回-1.
 * 错误代码：	EEXIST 参数pathname 所指的文件已存在，却使用了O_CREAT和O_EXCL旗标
				EACCESS 参数pathname所指的文件不符合所要求测试的权限。
				EROFS 欲测试写入权限的文件存在于只读文件系统内。
				EFAULT 参数pathname指针超出可存取内存空间。
				EINVAL 参数mode不正确。
				ENAMETOOLONG 参数pathname太长。
				ENOTDIR 参数pathname不是目录。
				ENOMEM 核心内存不足。
				ELOOP 参数pathname有过多符号连接问题。
				EIO I/O 存取错误。
				
 * 附加说明： 	使用 access()作用户认证方面的判断要特别小心, 
                例如在access()后再作open()空文件可能会造成系统安全上的问题.
 * 例    子：   fd = open("xxx", O_RDONLY);
				fd = open("xxx", O_WRONLY|O_CREAT|O_TRUNC, 0777);
**************************************************/

int creat(const char * pathname, mode_tmode);
/*************************************************
 * 功能说明：   creat(建立文件)		
 * 表头文件：   #include <sys/types.h>   #include <sys/stat.h>   #include <fcntl.h>
 * 定义函数：   int creat(const char * pathname, mode_tmode);
 * 函数说明： 	参数 pathname 指向欲建立的文件路径字符串。
				Creat()相当于使用下列的调用方式调用open()
						open(const char * pathname, (O_CREAT|O_WRONLY|O_TRUNC));	  
 * 返回值  ： 	creat()会返回新的文件描述词, 若有错误发生则会返回-1, 并把错误代码设给errno.
				EEXIST参数：pathname 所指的文件已存在.
				EACCESS参数：pathname 所指定的文件不符合所要求测试的权限
				EROFS：欲打开写入权限的文件存在于只读文件系统内
				EFAULT参数：pathname 指针超出可存取的内存空间
				EINVAL参数：mode 不正确.
				ENAMETOOLONG参数：pathname 太长.
				ENOTDIR 参数：pathname 为一目录
				ENOMEM ：核心内存不足
				ELOOP 参数：pathname 有过多符号连接问题.
				EMFILE：已达到进程可同时打开的文件数上限
				ENFILE：已达到系统可同时打开的文件数上限
 * 附加说明： 
**************************************************/

int close(int fd);
/*************************************************
 * 功能说明：  close(关闭文件)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int close(int fd);
 * 函数说明：  当使用完文件后若已不再需要则可使用 close()关闭该文件, 
               close()会让数据写回磁盘, 并释放该文件所占用的资源. 
               参数fd 为先前由open()或creat()所返回的文件描述词.	  
 * 返回值  ：  若文件顺利关闭则返回0, 发生错误时返回-1.
 * 附加说明：  虽然在进程结束时, 系统会自动关闭已打开的文件, 但仍建议自行关闭文件, 并确实检查返回值.
**************************************************/

ssize_t read(int fd, void * buf, size_t count);
/*************************************************
 * 功能说明： read(由己打开的文件读取数据)
 * 表头文件： #include <unistd.h>
 * 定义函数： ssize_t read(int fd, void * buf, size_t count);
 * 函数说明： read()会把参数fd 所指的文件传送count 个字节到buf 指针所指的内存中. 
              若参数count 为0, 则read()不会有作用并返回0. 返回值为实际读取到的字节数, 
			  如果返回0, 表示已到达文件尾或是无可读取的数据,此外文件读写位置会随读取到的字节移动.		  
 * 返回值  ： 返回0： 到达文件尾或是无数据可读； 
			  返回-1：错误；
			  其他：  读取的字节数
 * 附加说明： 如果顺利read（）会返回实际读到的字节数，最好能将返回值与参
			  数count 作比较，若返回的字节数比要求读取的字节数少，则有可
              能读到了文件尾、从管道（pipe）或终端机读取，或者是read（）
              被信号中断了读取动作。
			  当有错误发生时则返回-1，错误代码存入errno中，而文件读写位置则无法预期。
 * 错误代码： EINTR 此调用被信号所中断。
			  EAGAIN 当使用不可阻断I/O 时（O_NONBLOCK），若无数据可读取则返回此值。
              EBADF 参数fd非有效的文件描述词，或该文件已关闭。
**************************************************/

ssize_t write (int fd, const void * buf, size_t count);
/*************************************************
 * 功能说明： write(将数据写入已打开的文件内)
 * 表头文件： #include <unistd.h>
 * 定义函数： ssize_t write (int fd, const void * buf, size_t count);
 * 函数说明： write()会把参数 buf 所指的内存写入 count 个字节到参数 fd 所指的文件内. 
              当然, 文件读写位置也会随之移动.		  
 * 返回值  ： 如果顺利write()会返回实际写入的字节数. 
              当有错误发生时则返回-1, 错误代码存入errno 中.
 * 错误代码： EINTR  此调用被信号所中断.
			  EAGAIN 当使用不可阻断I/O 时 (O_NONBLOCK), 若无数据可读取则返回此值.
			  EADF   参数fd 非有效的文件描述词, 或该文件已关闭.
 * 附加说明： 
**************************************************/

off_t lseek(int fildes, off_t offset, int whence);
/*************************************************
 * 功能说明： lseek(移动文件的读写位置)
 * 表头文件： #include <sys/types.h>    #include <unistd.h>
 * 定义函数： off_t lseek(int fildes, off_t offset, int whence);
 * 函数说明： 当打开文件时通常其读写位置是指向文件开头, 若是以附加的方式打开文件(如O_APPEND), 
			  则读写位置会指向文件尾. 当read()或write()时, 读写位置会随之增加,lseek()便是用来控制该文件的读写位置. 
			  fildes 为已打开的文件描述词, 
			  offset 为根据参数whence来移动读写位置的位移数.	
			  whence 为下列其中一种:
				SEEK_SET 参数offset 即为新的读写位置.
				SEEK_CUR 以目前的读写位置往后增加offset个位移量.
				SEEK_END 将读写位置指向文件尾后再增加offset 个位移量. 
				当whence 值为SEEK_CUR 或SEEK_END 时, 参数offet 允许负值的出现.
 * 返回值  ： 当调用成功时则返回目前的读写位置, 也就是距离文件开头多少个字节. 
              若有错误则返回-1, errno 会存放错误代码.
 * 附加说明： Linux 系统不允许lseek()对tty 装置作用, 此项动作会令lseek()返回ESPIPE.

	下列是教特别的使用方式:
		1) 欲将读写位置移到文件开头时:lseek(int fildes, 0, SEEK_SET);
		2) 欲将读写位置移到文件尾时:  lseek(int fildes, 0, SEEK_END);
		3) 想要取得目前文件位置时:    lseek(int fildes, 0, SEEK_CUR);
**************************************************/

int dup (int oldfd);
/*************************************************
 * 功能说明： dup(复制文件描述词)
 * 表头文件： #include <unistd.h>
 * 定义函数： int dup (int oldfd);
 * 函数说明： dup()用来复制参数oldfd 所指的文件描述词, 并将它返回. 
              此新的文件描述词和参数oldfd 指的是同一个文件, 共享所有的锁定、读写位置和各项权限或旗标. 
			  例如, 当利用lseek()对某个文件描述词作用时, 另一个文件描述词的读写位置也会随着改变. 
			  不过, 文件描述词之间并不共享close-on-exec 旗标.
			  
 * 返回值  ： 当复制成功时, 则返回最小及尚未使用的文件描述词. 
              若有错误则返回-1, errno 会存放错误代码.
 * 错误代码： EBADF 参数fd 非有效的文件描述词, 或该文件已关闭.
 * 附加说明： 
**************************************************/

int dup2(int odlfd, int newfd);
/*************************************************
 * 功能说明： dup2(复制文件描述词)
 * 表头文件： #include <unistd.h>
 * 定义函数： int dup2(int odlfd, int newfd);
 * 函数说明： dup2()用来复制参数oldfd 所指的文件描述词, 并将它拷贝至参数newfd 后一块返回. 
              若参数newfd为一已打开的文件描述词, 则newfd 所指的文件会先被关闭. 
			  dup2()所复制的文件描述词, 与原来的文件描述词共享各种文件状态, 详情可参考dup().
			  
 * 返回值  ： 当复制成功时, 则返回最小及尚未使用的文件描述词. 
              若有错误则返回-1, errno 会存放错误代码.
 * 错误代码： EBADF 参数fd 非有效的文件描述词, 或该文件已关闭
 * 附加说明： dup2()相当于调用fcntl(oldfd, F_DUPFD, newfd); 请参考fcntl().
**************************************************/

int fcntl(int fd, int cmd, long arg);  //fcntl(文件描述词操作)
/*************************************************
 * 功能说明： fcntl()用来操作文件描述词的一些特性
 * 表头文件： #include <unistd.h>    #include <fcntl.h>
 * 定义函数： int fcntl(int fd, int cmd);
			  int fcntl(int fd, int cmd, long arg);
              int fcntl(int fd, int cmd, struct flock * lock);
 * 函数说明： fd 代表欲设置的文件描述词
			  cmd 代表欲操作的指令：
				  F_DUPFD 用来查找大于或等于参数arg 的最小且仍未使用的文件描述词, 并且复制参数fd 的文件描述词. 执行成功则返回新复制的文件描述词.
				  F_SETFD 设置close-on-exec 旗标. 该旗标以参数arg 的FD_CLOEXEC 位决定.
				  F_GETFL 取得文件描述词状态旗标, 此旗标为open()的参数flags.
				  F_SETFL 设置文件描述词状态旗标, 参数arg 为新旗标, 
				          但只允许O_APPEND、O_NONBLOCK 和O_ASYNC 位的改变, 其他位的改变将不受影响.
				  F_GETLK 取得文件锁定的状态.
				  F_SETLK 设置文件锁定的状态. 此时flcok 结构的l_type 值必须是F_RDLCK、F_WRLCK 或
                          F_UNLCK. 如果无法建立锁定, 则返回-1, 错误代码为EACCES 或EAGAIN.
				  F_SETLKW 同F_SETLK 作用相同, 但是无法建立锁定时, 此调用会一直等到锁定动作成功为止. 
				           若在等待锁定的过程中被信号中断时, 会立即返回-1, 错误代码为EINTR. 
			参数lock 指针为flock 结构指针		   
		        struct flcok
				{
					short int l_type; //锁定的状态
					short int l_whence; //决定l_start 位置
					off_t l_start; //锁定区域的开头位置
					off_t l_len; //锁定区域的大小
					pid_t l_pid; //锁定动作的进程
				};
			l_type 有三种状态:
				F_RDLCK 建立一个供读取用的锁定
				F_WRLCK 建立一个供写入用的锁定
				F_UNLCK 删除之前建立的锁定

			l_whence 也有三种方式:
				SEEK_SET 以文件开头为锁定的起始位置.
				SEEK_CUR 以目前文件读写位置为锁定的起始位置
				SEEK_END 以文件结尾为锁定的起始位置.

 * 返回值  ： 成功则返回0, 若有错误则返回-1, 错误原因存于errno.
 * 附加说明： 
			使用例子：
				int flags = fcntl(fd, F_GETFL, 0);
				fcntl(fd, F_SETFL, 0);
				
**************************************************/

int flock(int fd,int operation);
/*************************************************
 * 功能说明：   flock(锁定文件或解除锁定)
 * 表头文件：   #include <sys/file.h>
 * 定义函数：   int flock(int fd,int operation);
 * 函数说明：   flock（）会依参数operation 所指定的方式对参数fd 所指的文件做
                各种锁定或解除锁定的动作。此函数只能锁定整个文件，无法锁定文件的某一区域。
				operation有下列四种情况：
					LOCK_SH 建立共享锁定。多个进程可同时对同一个文件作共享锁定。
					LOCK_EX 建立互斥锁定。一个文件同时只有一个互斥锁定。
					LOCK_UN 解除文件锁定状态。
					LOCK_NB 无法建立锁定时，此操作可不被阻断，马上返回进程。
					        通常与LOCK_SH 或LOCK_EX 做OR（|）组合。
					        单一文件无法同时建立共享锁定和互斥锁定，而当使用dup或
                            fork（）时文件描述词不会继承此种锁定。
 * 返回值  ：   返回0 表示成功，若有错误则返回-1，错误代码存于errno。
 * 附加说明： 
**************************************************/

int sync(void);
/*************************************************
 * 功能说明：  sync(将缓冲区数据写回磁盘)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int sync(void);
 * 函数说明：  sync（）负责将系统缓冲区数据写回磁盘，以确保数据同步。	  
 * 返回值  ：  返回 0
 * 附加说明： 
**************************************************/

int fsync(int fd);
/*************************************************
 * 功能说明：  fsync(将缓冲区数据写回磁盘)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int fsync(int fd);
 * 函数说明：  fsync（）负责将参数fd所指的文件数据，由系统缓冲区写回磁盘，以确保数据同步。	  
 * 返回值  ：  成功则返回0，失败返回-1，errno为错误代码
 * 附加说明： 
**************************************************/

int mkstemp(char * template);
/*************************************************
 * 功能说明：  mkstemp(建立唯一的临时文件)
 * 表头文件：  #include<stdlib.h>
 * 定义函数：  int mkstemp(char * template);
 * 函数说明：  mkstemp（）用来建立唯一的临时文件。
               template 所指的文件名称字符串中最后六个字符必须是XXXXXX。
			   mkstemp（）会以可读写模式和0600 权限来打开该文件，如果该文件不存在则会建立
			   该文件。打开该文件后其文件描述词会返回。
			   	  
 * 返回值  ：  文件顺利打开后返回可读写的文件描述词。若果文件打开失败则返
			   回NULL，并把错误代码存在errno中。
 * 错误代码：  EINVAL 参数template字符串最后六个字符非XXXXXX。
			   EEXIST 无法建立临时文件。
 * 附加说明：  参数template所指的文件名称字符串必须声明为数组，如：
			   char template[ ] =”template-XXXXXX”;
			   千万不可以使用下列的表达方式
			   char *template = “template-XXXXXX”;
**************************************************/


