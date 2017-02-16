/*******************************
 *
 * 第十章 进程管理
 *
**********************************/

void abort(void);
/*************************************************
 * 功能说明：  abort(以异常方式结束进程)
 * 表头文件：  #include <stdlib.h>
 * 定义函数：  void abort(void);
 * 函数说明：  中止当前进程，返回一个错误代码。错误代码的缺省值是3。
               该函数产生SIGABRT信号并发送给自己，默认情况下导致程序
			   终止不成功的终止错误代码返回到主机环境。

			   abort()行为本身并不异常，如果用户调用了，那么进程就终止，完全是预期的行为。
			   原理上来说，abort通过给自己发送SIGABRT信号，然后kernel会杀掉自己，并coredump。
 * 附加说明：  abort()函数导致所有的流被关闭和冲洗。 
**************************************************/

void assert( int expression );
/*************************************************
 * 功能说明：  assert(若测试的条件不成立则终止进程)
 * 表头文件：  #include <assert.h>
 * 定义函数：  void assert( int expression );
 * 函数说明：  assert的作用是现计算表达式 expression ，如果其值为假（即为0），
               那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。	   
 * 附加说明：  assert是宏不是函数；
               在Windows下，使用assert之后，只需设置为debug版或者是release版，编译器就会自动忽略掉assert。
               在Linux下，必须在编译命令中加入-DNDEBUG，编译时才不会将assert编译进去。
			   不然，程序运行时有可能会被assert中断。
**************************************************/

int atexit (void (*function) (void));
/*************************************************
 * 功能说明：  atexit(设置程序正常结束前调用的函数)
 * 表头文件：  #include <stdlib.h>
 * 定义函数：  int atexit (void (*function) (void));
 * 函数说明：  atexit()用来设置一个程序正常结束前调用的函数. 
               当程序通过调用exit()或从main 中返回时, 
               参数function 所指定的函数会先被调用, 然后才真正由exit()结束程序.	  
 * 返回值  ：  如果执行成功则返回0, 否则返回-1, 失败原因存于errno 中.
**************************************************/

int on_exit(void (* function) (int void*), void *arg);
/*************************************************
 * 功能说明：  on＿exit(设置程序正常结束前调用的函数)
 * 表头文件：  #include <stdlib.h>
 * 定义函数：  int on_exit(void (* function) (int void*), void *arg);
 * 函数说明：  on_exit()用来设置一个程序正常结束前调用的函数. 
               当程序通过调用exit()或从main 中返回时, 
			   参数function 所指定的函数会先被调用, 
			   然后才真正由exit()结束程序. 
			   参数arg 指针会传给参数function函数	  
 * 返回值  ：  如果执行成功则返回0, 否则返回-1, 失败原因存于errno 中.
**************************************************/

int execl(const char * path, const char * arg, ...);
/*************************************************
 * 功能说明：  execl(执行文件)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int execl(const char * path, const char * arg, ...);
 * 函数说明：  execl()用来执行参数path 字符串所代表的文件路径, 
               接下来的参数代表执行该文件时传递过去的argv(0), argv[1], ..., 
			   最后一个参数必须用空指针(NULL)作结束.	  
 * 返回值  ：  如果执行成功则函数不会返回, 执行失败则直接返回-1, 失败原因存于errno 中.
 * 附加说明： 
            *************************************************************
exec系列函数（execl、execlp、execle、execv、execvp）
功能：
    用exec函数可以把当前进程替换为一个新进程，
	且新进程与原进程有相同的PID。
头文件: <unistd.h>
    extern char **environ; 
原型：
    int execl(const char *path, const char *arg, ...);
    int execlp(const char *file, const char *arg, ...);
    int execle(const char *path, const char *arg, ..., char * const envp[]);
    int execv(const char *path, char *const argv[]);
    int execvp(const char *file, char *const argv[]);
参数：
    path参数表示你要启动程序的名称包括路径名
    arg参数表示启动程序所带的参数，一般第一个参数为要执行命令名，不是带路径且arg必须以NULL结束
返回值:
    成功返回0,失败返回-1
上述exec系列函数底层都是通过execve系统调用实现：
#include <unistd.h>
int execve(const char *filename, char *const argv[],char *const envp[]);
1. 带 l 的exec函数：execl,execlp,execle，表示后边的参数以可变参数的形式给出且都以一个空指针结束
2. 带 p 的exec函数：execlp,execvp，表示第一个参数path不用输入完整路径，只有给出命令名即可，它会在环境变量PATH当中查找命令
***************************************************/

void exit(int status);
/*************************************************
 * 功能说明：  exit(正常结束进程)
 * 表头文件：  #include <stdlib.h>
 * 定义函数：  void exit(int status);
 * 函数说明：  exit()用来正常终结目前进程的执行, 
               并把参数status 返回给父进程, 
			   而进程所有的缓冲区数据会自动写回并关闭未关闭的文件. 
**************************************************/

void _exit(int status);
/*************************************************
 * 功能说明：  _exit(立即结束进程执行)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  void _exit(int status);
 * 函数说明：  _exit()用来立刻结束目前进程的执行, 
               并把参数status 返回给父进程, 并关闭未关闭的文件. 
			   此函数调用后不会返回, 并且会传递SIGCHLD 信号给父进程, 
			   父进程可以由wait 函数取得子进程结束状态.
 * 附件说明：  _exit ()不会处理标准I/O 缓冲区, 如要更新缓冲区请使用exit ().
**************************************************/

pid_t fork(void);
/*************************************************
 * 功能说明：  fork(建立一个新的进程)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  pid_t fork(void);
 * 函数说明：  一个现有进程可以调用fork函数创建一个新进程。
               由fork创建的新进程被称为子进程（child process）。
			   fork函数被调用一次但返回两次。
			   两次返回的唯一区别是子进程中返回0值而父进程中返回子进程ID。
               
			   子进程是父进程的副本，它将获得父进程数据空间、堆、栈等资源的副本。
			   注意，子进程持有的是上述存储空间的“副本”，
			   这意味着父子进程间不共享这些存储空间。	  
 * 返回值  ：  若成功调用一次则返回两个值，子进程返回0，父进程返回子进程ID；否则，出错返回-1
**************************************************/

pid_t getpid(void);
/*************************************************
 * 功能说明：  getpid(取得当前进程识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  pid_t getpid(void);
 * 函数说明：  getpid ()用来取得目前进程的进程识别码，
               许多程序利用取到的此值来建立临时文件， 以避免临时文件相同带来的问题。
 * 返回值  ：  目前进程的进程识别码
 * 附加说明：  错误代码：ESRCH 找不到符合参数pid 指定的进程.
**************************************************/

pid_t getpgid(pid_t pid);
/*************************************************
 * 功能说明：  getpgid(取得进程组识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  pid_t getpgid(pid_t pid);
 * 函数说明：  getpgid()用来取得参数pid 指定进程所属的组识别码. 
               如果参数pid 为0, 则会取得目前进程的组识别码.	  
 * 返回值  ：  执行成功则返回组识别码, 如果有错误则返回-1, 错误原因存于errno 中.
 * 附加说明：  错误代码：ESRCH 找不到符合参数pid 指定的进程.
**************************************************/

int setpgid(pid_t pid, pid_t pgid);
/*************************************************
 * 功能说明：  setpgid(设置进程组识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int setpgid(pid_t pid, pid_t pgid);
 * 函数说明：  setpgid()将参数pid 指定进程所属的组识别码设为参数pgid 指定的组识别码. 
               如果参数pid 为0,则会用来设置目前进程的组识别码, 
			   如果参数pgid 为0, 则会以目前进程的进程识别码来取代. 
 * 返回值  ：  执行成功则返回组识别码, 如果有错误则返回-1, 错误原因存于errno 中.
 * 附加说明：  错误代码：
					1、EINVAL 参数pgid 小于0.
					2、EPERM 进程权限不足, 无法完成调用.
					3、ESRCH 找不到符合参数pid 指定的进程.
**************************************************/

pid_t getpgrp(void);
/*************************************************
 * 功能说明：  getpgrp(取得进程组识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  pid_t getpgrp(void);
 * 函数说明：  getpgrp()用来取得目前进程所属的组识别码. 
               此函数相当于调用getpgid(0);
 * 返回值  ：  返回目前进程所属的组识别码.
 * 附加说明： 
**************************************************/

int setpgrp(void);
/*************************************************
 * 功能说明：  setpgrp(设置进程组识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int setpgrp(void);
 * 函数说明：  setpgrp()将目前进程所属的组识别码设为目前进程的进程识别码。
               此函数相当于调用setpgid(0,0)。
 * 返回值  ：  执行成功则返回组识别码，如果有错误则返回-1，错误原因存于errno 中。
 * 附加说明： 
**************************************************/

pid_t getppid(void);
/*************************************************
 * 功能说明：  getppid(取得父进程的进程识别码)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  pid_t getppid(void);
 * 函数说明：  getppid()用来取得目前进程的父进程识别码。	  
 * 返回值  ：  目前进程的父进程识别码。
**************************************************/

int getpriority(int which, int who);
/*************************************************
 * 功能说明：  getpriority(取得程序进程执行优先权)
 * 表头文件：  #include <sys/time.h>   #include <sys/resource.h>
 * 定义函数：  int getpriority(int which, int who);
 * 函数说明：  getpriority()可用来取得进程、进程组和用户的进程执行优先权。
               参数 which 有三种数值, 参数who 则依which 值有不同定义。
               which             who
               PRIO_PROCESS		 为进程识别码
               PRIO_PGRP         为进程的组识别码
               PRIO_USER         为用户识别码
			   
			   此函数返回值在-20~20之间，代表进程执行优先权, 数值越低代表有较高的优先次序, 执行会较频繁.		   
 * 返回值  ：  返回进程执行优先权, 如有错误发生返回值则为-1 且错误原因存于errno.
 * 附加说明：  错误代码：
					1、ESRCH：参数which 或who 可能有错, 而找不到符合的进程.
					2、EINVAL：参数which 值错误.
					
		由于返回值有可能是-1, 因此要同时检查errno 是否存有错误原因.
		最好在调用次函数前先清除errno变量.
**************************************************/

int setpriority(int which, int who, int prio);
/*************************************************
 * 功能说明：  setpriority(设置程序进程执行优先权)
 * 表头文件：  #include <sys/time.h>   #include <sys/resource.h>
 * 定义函数：  int setpriority(int which, int who, int prio);
 * 函数说明：  setpriority()可用来设置进程、进程组和用户的进程执行优先权。
               参数which 有三种数值, 参数who 则依which 值有不同定义。
               which             who
               PRIO_PROCESS		 为进程识别码
               PRIO_PGRP         为进程的组识别码
               PRIO_USER         为用户识别码
			   
			   参数prio在-20~20之间，代表进程执行优先权, 数值越低代表有较高的优先次序, 执行会较频繁.
               此优先权默认是0, 而只有超级用户 (root)允许降低此值.			   
 * 返回值  ：  执行成功则返回0, 如果有错误发生返回值则为-1, 
               错误原因存于errno：
					1、ESRCH：参数which 或who 可能有错, 而找不到符合的进程
					2、EINVAL：参数which 值错误.
					3、EPERM：权限不够, 无法完成设置
					4、EACCES：一般用户无法降低优先权
**************************************************/

int nice(int inc);
/*************************************************
 * 功能说明：  nice(改变进程优先顺序)
 * 表头文件：  #include <unistd.h>
 * 定义函数：  int nice(int inc);
 * 函数说明：  nice（）用来改变进程的进程执行优先顺序。参数inc 数值  越大则优
               先顺序排在越后面，即表示进程执行会越慢。只有超级用户才能使
               用负的inc值，代表优先顺序排在前面，进程执行会较快。	  
 * 返回值  ：  如果执行成功则返回0，否则返回-1，失败原因存于errno中。
 * 附加说明：  错误代码EPERM：一般用户企图转用负的参数inc值改变进程优先顺序。
**************************************************/

int system(const char * string);
/*************************************************
 * 功能说明：  system(执行shell命令)
 * 表头文件：  #include <stdlib.h>
 * 定义函数：  int system(const char * string);
 * 函数说明：  system()会调用fork()产生子进程, 由子进程来调用/bin/sh-c string 来执行
               参数string 字符串所代表的命令, 此命令执行完后随即返回原调用的进程. 
			   在调用system()期间SIGCHLD 信号会被暂时搁置,SIGINT 和SIGQUIT 信号则会被忽略.	  
 * 返回值  ：  返回值：
					1、如果 system()在调用/bin/sh 时失败则返回127, 其他失败原因返回-1.。
					2、若参数string 为空指针(NULL), 则返回非零值.
					3、如果system()调用成功则最后会返回执行shell 命令后的返回值, 
					   但是此返回值也有可能为system()调用/bin/sh 失败所返回的127, 
					   因此最好能再检查errno 来确认执行成功.
 * 附加说明：  在编写具有 SUID/SGID 权限的程序时请勿使用system(), 
               system()会继承环境变量, 通过环境变量可能会造成系统安全的问题.
			   
			   system("ls -al /etc/passwd /etc/shadow");
**************************************************/

pid_t wait (int * status);
/*************************************************
 * 功能说明：  wait(等待子进程中断或结束)
 * 表头文件：  #include <sys/types.h>    #include <sys/wait.h>
 * 定义函数：  pid_t wait (int * status);
 * 函数说明：  wait()会暂时停止目前进程的执行, 直到有信号来到或子进程结束. 
               如果在调用wait()时子进程已经结束, 则wait()会立即返回子进程结束状态值. 
			   子进程的结束状态值会由参数status 返回, 而子进程的进程识别码也会一快返回. 
			   如果不在意结束状态值, 则参数 status 可以设成NULL. 
			   	  
 * 返回值  ：  如果执行成功则返回子进程识别码(PID), 如果有错误发生则返回-1. 失败原因存于errno 中.
 * 附加说明：  子进程的结束状态值请参考waitpid().
**************************************************/

pid_t waitpid(pid_t pid, int * status, int options);
/*************************************************
 * 功能说明：  waitpid(等待子进程中断或结束)
 * 表头文件：  #include <sys/types.h>    #include <sys/wait.h>
 * 定义函数：  pid_t waitpid(pid_t pid, int * status, int options);
 * 函数说明：  waitpid()会暂时停止目前进程的执行, 直到有信号来到或子进程结束. 
			   如果在调用wait()时子进程已经结束, 则wait()会立即返回子进程结束状态值. 
			   子进程的结束状态值会由参数status 返回, 而子进程的进程识别码也会一快返回.
			   如果不在意结束状态值, 则参数status 可以设成NULL. 
			 
			   参数pid 为欲等待的子进程识别码, 其他数值意义如下：
					1、pid<-1 等待进程组识别码为pid 绝对值的任何子进程.
					2、pid=-1 等待任何子进程, 相当于wait().
					3、pid=0 等待进程组识别码与目前进程相同的任何子进程.
					4、pid>0 等待任何子进程识别码为pid 的子进程.
			   参数option 可以为0 或下面的OR 组合：
					WNOHANG：如果没有任何已经结束的子进程则马上返回, 不予以等待.
					WUNTRACED：如果子进程进入暂停执行情况则马上返回, 但结束状态不予以理会. 子进程的结束状态返回后存于status, 底下有几个宏可判别结束情况
					WIFEXITED(status)：如果子进程正常结束则为非0 值.
					WEXITSTATUS(status)：取得子进程exit()返回的结束代码, 一般会先用WIFEXITED 来判断是否正常结束才能使用此宏.
					WIFSIGNALED(status)：如果子进程是因为信号而结束则此宏值为真
					WTERMSIG(status)：取得子进程因信号而中止的信号代码, 一般会先用WIFSIGNALED 来判断后才使用此宏.
					WIFSTOPPED(status)：如果子进程处于暂停执行情况则此宏值为真. 一般只有使用WUNTRACED时才会有此情况.
					WSTOPSIG(status)：取得引发子进程暂停的信号代码, 一般会先用WIFSTOPPED 来判断后才使用此宏.
					
 * 返回值  ：  如果执行成功则返回子进程识别码(PID), 如果有错误发生则返回-1. 失败原因存于errno 中. 
**************************************************/

int ptrace(int request, int pid, int addr, int data);
/*************************************************
 * 功能说明：  ptrace(进程追踪)
 * 表头文件：  #include <sys/ptrace.h>
 * 定义函数：  int ptrace(int request, int pid, int addr, int data);
 * 函数说明：  Ptrace 提供了一种父进程可以控制子进程运行，并可以检查和改变它的核心image。
               它主要用于实现断点调试。一个被跟踪的进程运行中，直到发生一个信号，
			   则进程被中止，并且通知其父进程。在进程中止的状态下，进程的内存空间可以被读写。
			   父进程还可以使子进程继续执行，并选择是否是否忽略引起中止的信号。	
			   
			   Request参数决定了系统调用的功能：
					PTRACE_TRACEME  本进程被其父进程所跟踪。其父进程应该希望跟踪子进程。
					PTRACE_PEEKTEXT, PTRACE_PEEKDATA 从内存地址中读取一个字节，内存地址由addr给出。
					PTRACE_PEEKUSR  从USER区域中读取一个字节，偏移量为addr。
					PTRACE_POKETEXT, PTRACE_POKEDATA  往内存地址中写入一个字节。内存地址由addr给出。
					PTRACE_POKEUSR              往USER区域中写入一个字节。偏移量为addr。
					PTRACE_SYSCALL, PTRACE_CONT 重新运行。
					PTRACE_KILL                 杀掉子进程，使它退出。
					PTRACE_SINGLESTEP           设置单步执行标志
					PTRACE_ATTACH               跟踪指定pid 进程。
					PTRACE_DETACH               结束跟踪
 * 返回值  ：  成功返回0。错误返回-1。errno被设置。
 * 错误代码：  EPERM  特殊进程不可以被跟踪或进程已经被跟踪。
               ESRCH  指定的进程不存在
               EIO    请求非法
			   		   
功能详细描述：
1)  PTRACE_TRACEME
    形式：ptrace(PTRACE_TRACEME,0 ,0 ,0)
    描述：本进程被其父进程所跟踪。其父进程应该希望跟踪子进程。
 
2)  PTRACE_PEEKTEXT, PTRACE_PEEKDATA
    形式：ptrace(PTRACE_PEEKTEXT, pid, addr, data)
          ptrace(PTRACE_PEEKDATA, pid, addr, data)
    描述：从内存地址中读取一个字节，
	      pid表示被跟踪的子进程，
	      内存地址由addr给出，
		  data为用户变量地址用于返回读到的数据。
		  
3)  PTRACE_POKETEXT, PTRACE_POKEDATA
    形式：ptrace(PTRACE_POKETEXT, pid, addr, data)
          ptrace(PTRACE_POKEDATA, pid, addr, data)
    描述：往内存地址中写入一个字节。
	      pid表示被跟踪的子进程，内存地址由addr给出，data为所要写入的数据。
 
4)  TRACE_PEEKUSR
    形式：ptrace(PTRACE_PEEKUSR, pid, addr, data)
    描述：从USER区域中读取一个字节，
	pid表示被跟踪的子进程，USER区域地址由addr给出，data为用户变量地址用于返回读到的数据。USER结构为core文件的前面一部分，它描述了进程中止时的一些状态，如：寄存器值，代码、数据段大小，代码、数据段开始地址等。在Linux（i386）中通过PTRACE_PEEKUSER和PTRACE_POKEUSR可以访问USER结构的数据有寄存器和调试寄存器。
 
5)  PTRACE_POKEUSR
    形式：ptrace(PTRACE_POKEUSR, pid, addr, data)
    描述：往USER区域中写入一个字节，pid表示被跟踪的子进程，
	      USER区域地址由addr给出，data为需写入的数据。
 
6)   PTRACE_CONT
     形式：ptrace(PTRACE_CONT, pid, 0, signal)
     描述：继续执行。pid表示被跟踪的子进程，signal为0则忽略引起调试进程中止的信号，
	       若不为0则继续处理信号signal。
		   
7)  PTRACE_SYSCALL
    形式：ptrace(PTRACE_SYS, pid, 0, signal)
    描述：继续执行。pid表示被跟踪的子进程，signal为0则忽略引起调试进程中止的信号，
	      若不为0则继续处理信号signal。
		  与PTRACE_CONT不同的是进行系统调用跟踪。
		  在被跟踪进程继续运行直到调用系统调用开始或结束时，被跟踪进程被中止，并通知父进程。
 
8)  PTRACE_KILL
    形式：ptrace(PTRACE_KILL,pid)
    描述：杀掉子进程，使它退出。pid表示被跟踪的子进程。
 
9)  PTRACE_SINGLESTEP
    形式：ptrace(PTRACE_KILL, pid, 0, signle)
    描述：设置单步执行标志，单步执行一条指令。pid表示被跟踪的子进程。
	      signal为0则忽略引起调试进程中止的信号，若不为0则继续处理信号signal。
		  当被跟踪进程单步执行完一个指令后，被跟踪进程被中止，并通知父进程。
 
10) PTRACE_ATTACH
    形式：ptrace(PTRACE_ATTACH,pid)
    描述：跟踪指定pid 进程。pid表示被跟踪进程。被跟踪进程将成为当前进程的子进程，并进入中止状态。
 
11) PTRACE_DETACH
    形式：ptrace(PTRACE_DETACH,pid)
    描述：结束跟踪。 pid表示被跟踪的子进程。结束跟踪后被跟踪进程将继续执行。
 
12) PTRACE_GETREGS
    形式：ptrace(PTRACE_GETREGS, pid, 0, data)
    描述：读取寄存器值，pid表示被跟踪的子进程，data为用户变量地址用于返回读到的数据。
	      此功能将读取所有17个基本寄存器的值。
 
13) PTRACE_SETREGS
    形式：ptrace(PTRACE_SETREGS, pid, 0, data)
    描述：设置寄存器值，pid表示被跟踪的子进程，data为用户数据地址。
	      此功能将设置所有17个基本寄存器的值。
 
14) PTRACE_GETFPREGS
    形式：ptrace(PTRACE_GETFPREGS, pid, 0, data)
    描述：读取浮点寄存器值，pid表示被跟踪的子进程，data为用户变量地址用于返回读到的数据。此功能将读取所有浮点协处理器387的所有寄存器的值。
 
15) PTRACE_SETFPREGS
    形式：ptrace(PTRACE_SETREGS, pid, 0, data)
	描述：设置浮点寄存器值，pid表示被跟踪的子进程，data为用户数据地址。
	      此功能将设置所有浮点协处理器387的所有寄存器的值。
**************************************************/

setjmp(保存目前堆栈环境)
longjmp(跳转到原先setjmp保存的堆栈环境)
sigsetjmp(保存目前堆栈环境)
siglongjmp(跳转到原先sigsetjmp保存的堆栈环境)
/*************************************************
 * 功能说明： 
 * 表头文件：  #include <unistd.h>
 * 定义函数： 
 * 函数说明： 		  
 * 返回值  ： 
 * 附加说明： 
**************************************************/
