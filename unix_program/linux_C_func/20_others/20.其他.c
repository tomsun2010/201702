第23章正则表达式(暂时不学)

regcomp(编译正则表达式字符串)
regerror(取得正则搜索的错误原因)
regexec(进行正则表达式的搜索)
regfree(释放正则表达式使用的内存)

第24章动态函数(暂时不学)

dlclose(关闭动态函数库文件)
dlerror(动态函数错误处理)
dlopen(打开动态函数库文件)
dlsym(从共享对象中搜索动态函数)

第25章其他函数

int getopt(int argc,char * const argv[ ],const char * optstring);
/*************************************************
 * 功能说明：   getopt(分析命令行参数)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int getopt(int argc,char * const argv[ ],const char * optstring);
 * 函数说明：   getopt（）用来分析命令行参数。
                参数argc和argv是由main()传递的参数个数和内容。
				参数optstring则代表欲处理的选项字符串。
				此函数会返回在argv 中下一个的选项字母，此字母会对应参数
				optstring 中的字母。如果选项字符串里的字母后接着冒号“：”，则
				表示还有相关的参数，全域变量optarg即会指向此额外参数。
				如果getopt（）找不到符合的参数则会印出错信息，并将全域变量
				optopt 设为“？”字符，如果不希望getopt（）印出错信息，则只
				要将全域变量opterr 设为0 即可。
 * 返回值  ：   如果找到符合的参数则返回此参数字母，如果参数不包含在参数
                optstring的选项字母则返回“？”字符，分析结束则返回-1。
**************************************************/

int isatty(int desc);
/*************************************************
 * 功能说明：   isatty(判断文件描述词是否是为终端机)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int isatty(int desc);
 * 函数说明：   如果参数desc所代表的文件描述词为一终端机则返回1，否则返回0。
 * 返回值  ：   如果文件为终端机则返回 1，否则返回 0  
**************************************************/

char * ttyname(int desc);
/*************************************************
 * 功能说明：   ttyname(返回一终端机名称)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   char * ttyname(int desc);
 * 函数说明：   如果参数desc所代表的文件描述词为一终端机，则会将此终端机名
                称由一字符串指针返回，否则返回NULL。
 * 返回值  ：   如果成功则返回指向终端机名称的字符串指针，
                有错误情况发生时则返回NULL。 
**************************************************/

int select(int n,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,struct timeval * timeout);
/*************************************************
 * 功能说明：   select(I/O多工机制)
 * 表头文件：   #include<sys/time.h>  #include<sys/types.h> #include <unistd.h>
 * 定义函数：   int select(int n,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,struct timeval * timeout);
 * 函数说明：   select（）用来等待文件描述词状态的改变。
                参数n代表最大的文件描述词加1，
				参数readfds、writefds 和exceptfds 称为描述词组，是用来回传该描述词的读，写或例外的状况。
				底下的宏提供了处理这三种描述词组的方式：
					FD_CLR（inr fd,fd_set* set）；用来清除描述词组set中相关fd的位
					FD_ISSET（int fd,fd_set *set）；用来测试描述词组set中相关fd的位是否为真
					FD_SET（int fd,fd_set*set）；用来设置描述词组set中相关fd的位
					FD_ZERO（fd_set *set）； 用来清除描述词组set的全部位
				参数timeout为结构timeval，用来设置select（）的等待时间，其结构定义如下：
					struct timeval
					{
						time_t tv_sec;
						time_t tv_usec;
					};
					如果参数timeout设为NULL则表示select（）没有timeout。
 * 返回值  ：   成功则返回文件描述词状态已改变的个数；
                返回0代表在描述词状态改变前已超过timeout时间；
				错误返回-1；
				错误原因存于errno，此时参数readfds，writefds，exceptfds和timeout
				的值变成不可预测。
 * 错误说明：   
				EBADF 文件描述词为无效的或该文件已关闭
				EINTR 此调用被信号所中断
				EINVAL 参数n为负值。
				ENOMEM 核心内存不足  
				
 * 附件说明：   常见的程序片段
		fs_set readset, writeset；
		FD_ZERO(&readset);
		FD_ZERO(&writeset);
		FD_SET(fd,&readset);
		FD_SET(fd,&writeset);
		select(fd+1,&readset,NULL,NULL,NULL);
		select(fd+1,&readset,&writeset,NULL,NULL);
		if(FD_ISSET(fd,&readset){……}	  //数据可读
		if(FD_ISSET(fd,&writeset){……}	  //数据可写
		
**************************************************/


