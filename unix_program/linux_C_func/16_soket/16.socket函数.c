/*******************************
 *
 * 第 16 章 socket函数
 *
**********************************/

socket(建立一个socket通信)
bind(对socket定位)
listen(等待连接)
accept(接受socket连线)
connect(建立socket连线)

sendto(经socket传送数据)
recvfrom(经socket接收数据)

struct protoent  
{  
	char *p_name;         // Official protocol name
	char **p_aliases;     // Alias list 
	int p_proto;          // Protocol number
};  
struct protoent *getprotoent(void);  
struct protoent *getprotobyname(const char *name);  
struct protoent *getprotobynumber(int proto);  
void setprotoent(int stayopen);  
void endprotoent(void);  
=========>这几个函数的原理是读取文件 /etc/protocols----(ubuntu下)
getprotoent(取得网络协议数据)
getprotobyname(由网络协议名称取得协议数据)
getprotobynumber(由网络协议编号取得协议数据)
setprotoent(打开网络协议的数据文件)
endprotoent(结束网络协议数据的读取)

void setprotoent (int stayopen);
/*************************************************
 * 功能说明：   setprotoent(打开网络协议的数据文件)
 * 表头文件：   #include <netdb.h>
 * 定义函数：   void setprotoent (int stayopen);
 * 函数说明：   setprotoent() 用来打开/etc/protocols;
                如果参数stayopen值为1，则接下来的getprotobyname()
				或getprotobynumber()将不会自动关闭此文件。   
**************************************************/



struct servent
{
	char *s_name;
	char **s_aliases;
	int  s_port;
	char *s_proto;
	.....
};
struct servent *getservbyname(const char *name,const char *proto);
struct servent *getservbyport(int port,const char *proto);
struct servent *getservent(void);
void setservent(int stayopen);
void endservent(void);
getservbyname(依名称取得网络服务的数据)
getservbyport(依port号码取得网络服务的数据)
getservent(取得主机网络服务的数据)
setservent(打开主机网络服务的数据文件)
endservent(结束网络服务数据的读取)

void setservent(int stayopen);
/*************************************************
 * 功能说明：   setservent(打开主机网络服务的数据文件)
 * 表头文件：   #include <netdb.h>
 * 定义函数：   void setservent(int stayopen);
 * 函数说明：   setservent () 用来打开/etc/services;
                如果参数stayopen 值为1，则接下来的getservbyname()
				或getservbyport()将补回自动关闭文件。   
**************************************************/

gethostbyaddr(由IP地址取得网络数据)
gethostbyname(由主机名称取得网络数据)


int getsockopt(int s, int level, int optname, void* optval, socklen_t*optlen);
/*************************************************
 * 功能说明：   getsockopt(取得socket状态)
 * 表头文件：   #include <sys/types.h>  #include <sys/socket.h>
 * 定义函数：   int getsockopt(int s, int level, int optname, void* optval, socklen_t*optlen);
 * 函数说明：   getsockopt（）会将参数s所指定的socket状态返回。
				参数optname代表欲取得何种选项状态，
				参数level 代表欲设置的网络层，一般设成SOL_SOCKET 以存取socket 层
				参数optval则指向欲保存结果的内存地址，
				参数optlen则为该空间的大小
				参数optname：
					SO_DEBUG 打开或关闭排错模式
					SO_REUSEADDR 允许在bind（）过程中本地地址可重复使用
					SO_TYPE 返回socket形态。
					SO_ERROR 返回socket已发生的错误原因
					SO_DONTROUTE 送出的数据包不要利用路由设备来传输。
					SO_BROADCAST 使用广播方式传送
					SO_SNDBUF 设置送出的暂存区大小
					SO_RCVBUF 设置接收的暂存区大小
					SO_KEEPALIVE 定期确定连线是否已终止
					SO_OOBINLINE 当接收到OOB数据时会马上送至标准输入设备
					SO_LINGER 确保数据安全且可靠的传送出去

 * 返回值  ：   成功则返回0，若有错误则返回-1，错误原因存于errno
 * 错误说明：   EBADF 参数s并非合法的socket处理代码
				ENOTSOCK 参数s为一文件描述词，非socket
				ENOPROTOOPT 参数optname指定的选项不正确
				EFAULT 参数optval指针指向无法存取的内存空间
 * 附加说明：   
**************************************************/

int setsockopt(int s,int level,int optname,const void * optval,socklen_toptlen);
/*************************************************
 * 功能说明：   setsockopt(设置socket状态)
 * 表头文件：   #include <sys/types.h>  #include <sys/socket.h>
 * 定义函数：   int setsockopt(int s,int level,int optname,const void * optval,socklen_toptlen);
 * 函数说明：   setsockopt（）用来设置参数s 所指定的socket 状态
 * 返回值  ：   成功则返回0，若有错误则返回-1，错误原因存于errno
 * 错误说明：   EBADF 参数s并非合法的socket处理代码
				ENOTSOCK 参数s为一文件描述词，非socket
				ENOPROTOOPT 参数optname指定的选项不正确。
				EFAULT 参数optval指针指向无法存取的内存空间
 * 附加说明：   
**************************************************/


void herror( const char *s );
/*************************************************
 * 功能说明：   herror(打印出网络错误原因信息字符串)
 * 表头文件：   #include <netdb.h>
 * 定义函数：   void herror( const char *s );
 * 函数说明：   程序的部分函数运行出错时，先打印出自定义的文字说明字符串 *s ，然后打印出相关错误代码的文字说明
 * 附加说明：
			与 perror的区别：
				perror()函数的定义包含于头文件　#include <stdio.h>　一般应与 #include <errno.h> 配合使用
				herror()函数的定义包含于头文件　#include <netdb.h> 
				一般服务于该头文件的函数，如 gethostbyname(3)　、gethostbyaddr(3) 等等。
**************************************************/
hstrerror(返回网络错误原因的描述字符串) 与strerror类似


unsigned long int inet_addr(const char *cp);
/*************************************************
 * 功能说明：   inet_addr(将网络地址转成网络二进制的数字)
 * 表头文件：   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * 定义函数：   unsigned long int inet_addr(const char *cp);
 * 函数说明：   inet_addr（）用来将参数cp所指的网络地址字符串转换成网络所使
				用的二进制数字。网络地址字符串是以数字和点组成的字符串，
				例如：“163.13.132.68”。
 * 返回值  ：   成功则返回对应的网络二进制的数字，失败返回-1。 
 * 附加说明：   例子：inet_addr("127.0.0.1");
**************************************************/

int inet_aton(const char * cp,struct in_addr *inp);
/*************************************************
 * 功能说明：   inet_aton(将网络地址转成网络二进制的数字)
 * 表头文件：   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * 定义函数：   int inet_aton(const char * cp,struct in_addr *inp);
 * 函数说明：   inet_aton（）用来将参数cp所指的网络地址字符串转换成网络使用
				的二进制的数字，然后存于参数inp所指的in_addr 结构中。
				结构in_addr 定义如下：
				struct in_addr
				{
					unsigned long int s_addr;
				};
 * 返回值  ：   成功则返回非0 值，失败则返回0。
**************************************************/

char * inet_ntoa(struct in_addr in);
/*************************************************
 * 功能说明：   inet_ntoa(将网络二进制的数字转换成网络地址)
 * 表头文件：   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * 定义函数：   char * inet_ntoa(struct in_addr in);
 * 函数说明：   inet_ntoa（）用来将参数in所指的网络二进制的数字转换成网络地
				址，然后将指向此网络地址字符串的指针返回。
 * 返回值  ：   成功则返回字符串指针，失败则返回NULL。
**************************************************/

unsigned long int htonl(unsigned long int hostlong);
/*************************************************
 * 功能说明：   htonl(将32位主机字符顺序转换成网络字符顺序)
 * 表头文件：   #include <netinet/in.h>
 * 定义函数：   unsigned long int htonl(unsigned long int hostlong);
 * 函数说明：   htonl（）用来将参数指定的32 位hostlong转换成网络字符顺序。
 * 返回值  ：   返回对应的网络字符顺序。 
**************************************************/

unsigned long int ntohl(unsigned long int netlong);
/*************************************************
 * 功能说明：   ntohl(将32位网络字符顺序转换成主机字符顺序)
 * 表头文件：   #include <netinet/in.h>
 * 定义函数：   unsigned long int ntohl(unsigned long int netlong);
 * 函数说明：   ntohl（）用来将参数指定的32 位netlong转换成主机字符顺序。
 * 返回值  ：   返回对应的主机字符顺序。 
**************************************************/

unsigned short int htons(unsigned short int hostshort);
/*************************************************
 * 功能说明：   htons(将16位主机字符顺序转换成网络字符顺序)
 * 表头文件：   #include <netinet/in.h>
 * 定义函数：   unsigned short int htons(unsigned short int hostshort);
 * 函数说明：   htons（）用来将参数指定的16 位hostshort转换成网络字符顺序。
 * 返回值  ：   返回对应的网络字符顺序。 
**************************************************/

unsigned short int ntohs(unsigned short int netshort);
/*************************************************
 * 功能说明：   ntohs(将16位网络字符顺序转换成主机字符顺序)
 * 表头文件：   #include <netinet/in.h>
 * 定义函数：   unsigned short int ntohs(unsigned short int netshort);
 * 函数说明：   ntohs（）用来将参数指定的16 位netshort转换成主机字符顺序。
 * 返回值  ：   返回对应的主机字符顺序。 
**************************************************/

int recv(int s,void *buf,int len,unsigned int flags);
/*************************************************
 * 功能说明：   recv(经socket接收数据)
 * 表头文件：   #include <sys/types.h> #include <sys/socket.h>
 * 定义函数：   int recv(int s,void *buf,int len,unsigned int flags);
 * 函数说明：   recv（）用来接收远端主机经指定的socket 传来的数据，并把数据
				存到由参数buf 指向的内存空间，参数len 为可接收数据的最大长度。
				参数flags一般设0。其他数值定义如下：
					MSG_OOB 接收以out-of-band送出的数据。
					MSG_PEEK 返回来的数据并不会在系统内删除，如果再调用recv()会返回相同的数据内容。
					MSG_WAITALL 强迫接收到len大小的数据后才能返回，除非有错误或信号产生。
					MSG_NOSIGNAL 此操作不愿被SIGPIPE 信号中断
 * 返回值  ：   成功则返回接收到的字符数，失败返回-1，错误原因存于errno中。
 * 错误说明：   EBADF 参数s非合法的socket处理代码
				EFAULT 参数中有一指针指向无法存取的内存空间
				ENOTSOCK 参数s为一文件描述词，非socket。
				EINTR 被信号所中断
				EAGAIN 此动作会令进程阻断，但参数s的socket为不可阻断
				ENOBUFS 系统的缓冲内存不足
				ENOMEM 核心内存不足
				EINVAL 传给系统调用的参数不正确
 * 附加说明：   
**************************************************/

int send(int s,const void * msg,int len,unsigned int falgs);
/*************************************************
 * 功能说明：   send(经socket传送数据)
 * 表头文件：   #include <sys/types.h> #include <sys/socket.h>
 * 定义函数：   int send(int s,const void * msg,int len,unsigned int falgs);
 * 函数说明：   send（）用来将数据由指定的socket 传给对方主机。参数s 为已建
				立好连接的socket。参数msg 指向欲连线的数据内容，参数len 则
				为数据长度。参数flags一般设0，其他数值定义如下：
					MSG_OOB 传送的数据以out-of-band送出
					MSG_DONTROUTE 取消路由表查询
					MSG_DONTWAIT 设置为不可阻断运作
					MSG_NOSIGNAL 此动作不愿被SIGPIPE 信号中断
 * 返回值  ：   成功则返回实际传送出去的字符数，失败返回-1。错误原因存于errno
 * 错误说明：   EBADF 参数s非合法的socket处理代码
				EFAULT 参数中有一指针指向无法存取的内存空间
				ENOTSOCK 参数s为一文件描述词，非socket。
				EINTR 被信号所中断
				EAGAIN 此动作会令进程阻断，但参数s的socket为不可阻断
				ENOBUFS 系统的缓冲内存不足
				ENOMEM 核心内存不足
				EINVAL 传给系统调用的参数不正确
 * 附加说明：   
**************************************************/

int recvmsg(int s,struct msghdr *msg,unsigned int flags);
/*************************************************
 * 功能说明：   recvmsg(经socket接收数据)
 * 表头文件：   #include <sys/types.h> #include <sys/socket.h>
 * 定义函数：   int recvmsg(int s,struct msghdr *msg,unsigned int flags);
 * 函数说明：   recvmsg（）用来接收远程主机经指定的socket传来的数据。参数s
				为已建立好连线的socket，如果利用UDP 协议则不需经过连线操
				作。参数msg指向欲连线的数据结构内容，参数flags一般设0，详
				细描述请参考send（）。关于结构msghdr 的定义请参考sendmsg（）。
 * 返回值  ：   成功则返回接收到的字符数，失败则返回-1，错误原因存于errno中。
 * 错误说明：   EBADF 参数s非合法的socket处理代码
				EFAULT 参数中有一指针指向无法存取的内存空间
				ENOTSOCK 参数s为一文件描述词，非socket。
				EINTR 被信号所中断
				EAGAIN 此动作会令进程阻断，但参数s的socket为不可阻断
				ENOBUFS 系统的缓冲内存不足
				ENOMEM 核心内存不足
				EINVAL 传给系统调用的参数不正确
 * 附加说明：   
**************************************************/

int sendmsg(int s,const strcut msghdr *msg,unsigned int flags);
/*************************************************
 * 功能说明：   sendmsg(经socket传送数据)
 * 表头文件：   #include <sys/types.h> #include <sys/socket.h>
 * 定义函数：   int sendmsg(int s,const strcut msghdr *msg,unsigned int flags);
 * 函数说明：   sendmsg（）用来将数据由指定的socket 传给对方主机。参数s 为
				已建立好连线的socket，如果利用UDP协议则不需经过连线操作。
				参数msg指向欲连线的数据结构内容，参数flags一般默认为0，详
				细描述请参考send（）。
				结构msghdr 定义如下：
				struct msghdr
				{
					void *msg_name;         //Address to send to /receive from 
					socklen_t msg_namelen;  //Length of addres data
					strcut iovec * msg_iov; //Vector of data to send/receive into
					size_t msg_iovlen;      //Number of elements in the vector
					void * msg_control;     //Ancillary dat
					size_t msg_controllen;  //Ancillary data buffer length
					int msg_flags;          //Flags on received message
				};
 * 返回值  ：   成功则返回实际传送出去的字符数，失败返回-1，错误原因存于errno
 * 错误说明：   EBADF 参数s非合法的socket处理代码
				EFAULT 参数中有一指针指向无法存取的内存空间
				ENOTSOCK 参数s为一文件描述词，非socket。
				EINTR 被信号所中断
				EAGAIN 此动作会令进程阻断，但参数s的socket为不可阻断
				ENOBUFS 系统的缓冲内存不足
				ENOMEM 核心内存不足
				EINVAL 传给系统调用的参数不正确
 * 附加说明：   
**************************************************/

int shutdown(int s,int how);
/*************************************************
 * 功能说明：   shutdown(终止socket通信)
 * 表头文件：   #include <sys/socket.h>
 * 定义函数：   int shutdown(int s,int how);
 * 函数说明：   shutdown（）用来终止参数s 所指定的socket 连线。参数s 是连线
				中的socket处理代码，参数how有下列几种情况：
					how=0 终止读取操作。
					how=1 终止传送操作
					how=2 终止读取及传送操作
 * 返回值  ：   成功则返回0，失败返回-1，错误原因存于errno。
 * 错误说明：   EBADF 参数s不是有效的socket处理代码
				ENOTSOCK 参数s为一文件描述词，非socket
				ENOTCONN 参数s指定的socket并未连线
 * 附加说明：   
**************************************************/

