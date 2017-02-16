/*******************************
 *
 * 第 13 章 信号函数
 *
**********************************/

unsigned int alarm(unsigned int seconds);
/*************************************************
 * 功能说明：   alarm(设置信号传送闹钟)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   unsigned int alarm(unsigned int seconds);
 * 函数说明：   alarm()用来设置信号SIGALRM在经过参数seconds指定的秒数
				后传送给目前的进程。如果参数seconds 为0，则之前设置的闹钟
				会被取消，并将剩下的时间返回。
 * 附加说明：   返回之前闹钟的剩余秒数，如果之前未设闹钟则返回0。
**************************************************/

int kill(pid_t pid,int sig);
/*************************************************
 * 功能说明：   kill(传送信号给指定的进程)
 * 表头文件：   #include <sys/types.h>   #include <signal.h>
 * 定义函数：   int kill(pid_t pid,int sig);
 * 函数说明：   kill（）可以用来送参数sig指定的信号给参数pid指定的进程。
				参数pid有几种情况：
					pid>0 将信号传给进程识别码为pid的进程。
					pid=0 将信号传给和目前进程相同进程组的所有进程
					pid=-1 将信号广播传送给系统内所有的进程
					pid<0 将信号传给进程组识别码为pid绝对值的所有进程
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EINVAL 参数sig不合法
				ESRCH  参数pid所指定的进程或进程组不存在
				EPERM  权限不够无法传送信号给指定进程
**************************************************/

int raise(int sig);
/*************************************************
 * 功能说明：   raise(传送信号给目前的进程)
 * 表头文件：   #include <signal.h>  #include <sys/types.h>
 * 定义函数：   int raise(int sig);
 * 函数说明：   raise(传送信号给目前的进程)
 * 返回值  ：   成功返回0，失败返回-1
**************************************************/

int pause(void);
/*************************************************
 * 功能说明：   pause(让进程暂停直到信号出现)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int pause(void);
 * 函数说明：   pause()会令目前的进程暂停（进入睡眠状态），直到被信号（signal）所中断。
 * 返回值  ：   只返回-1
 * 错误代码：   EINTR 有信号到达中断了此函数。
 * 附加说明：   
**************************************************/

psignal(列出信号描述和指定字符串)

sigaction(查询或设置信号处理方式)
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
/*************************************************
 * 功能说明：  
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
 * 函数说明：   sigaction（）会依参数signum指定的信号编号来设置该信号的处理函数.
                参数signum可以指定SIGKILL和SIGSTOP以外的所有信号;
				参数结构sigaction定义如下：
				struct sigaction
				{
					void (*sa_handler) (int);   //新的信号处理函数
					sigset_t sa_mask;           //用来设置在处理该信号时暂时将sa_mask 指定的信号搁置.
					int sa_flags;
					void (*sa_restorer) (void); // 此参数没有使用
				}
						sa_flags 用来设置信号处理的其他相关操作:
							A_NOCLDSTOP ：如果参数signum为SIGCHLD，则当子进程暂停时并不会通知父进程
							SA_ONESHOT/SA_RESETHAND：当调用新的信号处理函数前，将此信号处理方式改为系统预设的方式。
							SA_RESTART：被信号中断的系统调用会自行重启
							SA_NOMASK/SA_NODEFER：在处理此信号未结束前不理会此信号的再次到来。
				如果参数oldact不是NULL指针，则原来的信号处理方式会由此结构sigaction返回
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EINVAL 参数signum 不合法， 或是企图拦截
				SIGKILL/SIGSTOPSIGKILL信号
				EFAULT 参数act，oldact指针地址无法存取。
				EINTR 此调用被中断
 * 附加说明：   
**************************************************/

int sigaddset(sigset_t *set,int signum);
/*************************************************
 * 功能说明：   sigaddset(增加一个信号至信号集)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigaddset(sigset_t *set,int signum);
 * 函数说明：   sigaddset()用来将参数signum代表的信号加入至参数set 信号集里。
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EFAULT 参数set指针地址无法存取
				EINVAL 参数signum非合法的信号编号 
**************************************************/

int sigdelset(sigset_t * set,int signum);
/*************************************************
 * 功能说明：   sigdelset(从信号集里删除一个信号)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigdelset(sigset_t * set,int signum);
 * 函数说明：   sigaddset()用来将参数signum代表的信号从参数set信号集里删除。
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EFAULT 参数set指针地址无法存取
				EINVAL 参数signum非合法的信号编号 
**************************************************/

int sigemptyset(sigset_t *set);
/*************************************************
 * 功能说明：   sigemptyset(初始化信号集)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigemptyset(sigset_t *set);
 * 函数说明：   sigemptyset（）用来将参数set信号集初始化并清空
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EFAULT 参数set指针地址无法存取
**************************************************/

int sigfillset(sigset_t * set);
/*************************************************
 * 功能说明：   sigfillset(将所有信号加入至信号集)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigfillset(sigset_t * set);
 * 函数说明：   sigfillset()用来将参数set信号集初始化，
                然后把所有的信号加入到此信号集里。
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1。
 * 错误代码：   EFAULT 参数set指针地址无法存取
**************************************************/

int sigismember(const sigset_t *set,int signum);
/*************************************************
 * 功能说明：   sigismember(测试某个信号是否已加入至信号集里)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigismember(const sigset_t *set,int signum);
 * 函数说明：   sigismember（）用来测试参数signum 代表的信号是否已加入至参
                数set信号集里。如果信号集里已有该信号则返回1，否则返回0。
 * 返回值  ：   信号集已有该信号则返回1，没有则返回0。如果有错误则返回-1。
 * 错误代码：   EFAULT 参数set指针地址无法存取
				EINVAL 参数signum 非合法的信号编号
**************************************************/

void (*signal(int signum,void(* handler)(int)))(int);
/*************************************************
 * 功能说明：   signal(设置信号处理方式)
 * 表头文件：   #include <signal.h>
 * 定义函数：   void (*signal(int signum,void(* handler)(int)))(int);
 * 函数说明：   signal（）会依参数signum指定的信号编号来设置该信号的处理函数。
				当指定的信号到达时就会跳转到参数handler 指定的函数执行。
				如果参数handler 不是函数指针，则必须是下列两个常数之一：
					SIG_IGN 忽略参数signum指定的信号。
					SIG_DFL 将参数signum 指定的信号重设为核心预设的信号处理方式。
 * 返回值  ：   返回先前的信号处理函数指针，如果有错误则返回SIG_ERR（-1）。
 * 附件说明：   在信号发生跳转到自定的handler 处理函数执行后，系统会自动将
				此处理函数换回原来系统预设的处理方式，如果要改变此操作请改用sigaction（）。
**************************************************/

sigpause(暂停直到信号到来)

int sigpending(sigset_t *set);
/*************************************************
 * 功能说明：   sigpending(查询被搁置的信号)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigpending(sigset_t *set);
 * 函数说明：   sigpending（）会将被搁置的信号集合由参数set指针返回。
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1
 * 错误代码：   EFAULT 参数set指针地址无法存取
				EINTR 此调用被中断。
**************************************************/

int sigprocmask(int how,const sigset_t *set,sigset_t * oldset);
/*************************************************
 * 功能说明：   sigprocmask(查询或设置信号遮罩)
 * 表头文件：   #include <signal.h>
 * 定义函数：   int sigprocmask(int how,const sigset_t *set,sigset_t * oldset);
 * 函数说明：   sigprocmask()可以用来改变目前的信号遮罩，其操作依参数how来决定：
				SIG_BLOCK 新的信号遮罩由目前的信号遮罩和参数set 指定的信号遮罩作联集
				SIG_UNBLOCK 将目前的信号遮罩删除掉参数set指定的信号遮罩
				SIG_SETMASK 将目前的信号遮罩设成参数set指定的信号遮罩。
				如果参数oldset不是NULL指针，那么目前的信号遮罩会由此指针返回。
 * 返回值  ：   执行成功则返回0，如果有错误则返回-1
 * 错误代码：   EFAULT 参数set，oldset指针地址无法存取。
				EINTR 此调用被中断
**************************************************/

sigsuspend(暂停直到信号到来)


sleep(让进程暂停执行一段时间)
unsigned int sleep(unsigned int seconds);
/*************************************************
 * 功能说明：  
 * 表头文件：   #include <unistd.h>
 * 定义函数：   unsigned int sleep(unsigned int seconds);
 * 函数说明：   sleep（）会令目前的进程暂停，直到达到参数seconds 所指定的时
                间，或是被信号所中断
 * 返回值  ：   若进程暂停到参数seconds 所指定的时间则返回0，
				若有信号中断则返回剩余秒数。   
**************************************************/
