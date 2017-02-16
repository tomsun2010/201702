/*******************************
 *
 * �� 16 �� socket����
 *
**********************************/

socket(����һ��socketͨ��)
bind(��socket��λ)
listen(�ȴ�����)
accept(����socket����)
connect(����socket����)

sendto(��socket��������)
recvfrom(��socket��������)

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
=========>�⼸��������ԭ���Ƕ�ȡ�ļ� /etc/protocols----(ubuntu��)
getprotoent(ȡ������Э������)
getprotobyname(������Э������ȡ��Э������)
getprotobynumber(������Э����ȡ��Э������)
setprotoent(������Э��������ļ�)
endprotoent(��������Э�����ݵĶ�ȡ)

void setprotoent (int stayopen);
/*************************************************
 * ����˵����   setprotoent(������Э��������ļ�)
 * ��ͷ�ļ���   #include <netdb.h>
 * ���庯����   void setprotoent (int stayopen);
 * ����˵����   setprotoent() ������/etc/protocols;
                �������stayopenֵΪ1�����������getprotobyname()
				��getprotobynumber()�������Զ��رմ��ļ���   
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
getservbyname(������ȡ��������������)
getservbyport(��port����ȡ��������������)
getservent(ȡ������������������)
setservent(�������������������ļ�)
endservent(��������������ݵĶ�ȡ)

void setservent(int stayopen);
/*************************************************
 * ����˵����   setservent(�������������������ļ�)
 * ��ͷ�ļ���   #include <netdb.h>
 * ���庯����   void setservent(int stayopen);
 * ����˵����   setservent () ������/etc/services;
                �������stayopen ֵΪ1�����������getservbyname()
				��getservbyport()�������Զ��ر��ļ���   
**************************************************/

gethostbyaddr(��IP��ַȡ����������)
gethostbyname(����������ȡ����������)


int getsockopt(int s, int level, int optname, void* optval, socklen_t*optlen);
/*************************************************
 * ����˵����   getsockopt(ȡ��socket״̬)
 * ��ͷ�ļ���   #include <sys/types.h>  #include <sys/socket.h>
 * ���庯����   int getsockopt(int s, int level, int optname, void* optval, socklen_t*optlen);
 * ����˵����   getsockopt�����Ὣ����s��ָ����socket״̬���ء�
				����optname������ȡ�ú���ѡ��״̬��
				����level ���������õ�����㣬һ�����SOL_SOCKET �Դ�ȡsocket ��
				����optval��ָ�������������ڴ��ַ��
				����optlen��Ϊ�ÿռ�Ĵ�С
				����optname��
					SO_DEBUG �򿪻�ر��Ŵ�ģʽ
					SO_REUSEADDR ������bind���������б��ص�ַ���ظ�ʹ��
					SO_TYPE ����socket��̬��
					SO_ERROR ����socket�ѷ����Ĵ���ԭ��
					SO_DONTROUTE �ͳ������ݰ���Ҫ����·���豸�����䡣
					SO_BROADCAST ʹ�ù㲥��ʽ����
					SO_SNDBUF �����ͳ����ݴ�����С
					SO_RCVBUF ���ý��յ��ݴ�����С
					SO_KEEPALIVE ����ȷ�������Ƿ�����ֹ
					SO_OOBINLINE �����յ�OOB����ʱ������������׼�����豸
					SO_LINGER ȷ�����ݰ�ȫ�ҿɿ��Ĵ��ͳ�ȥ

 * ����ֵ  ��   �ɹ��򷵻�0�����д����򷵻�-1������ԭ�����errno
 * ����˵����   EBADF ����s���ǺϷ���socket�������
				ENOTSOCK ����sΪһ�ļ������ʣ���socket
				ENOPROTOOPT ����optnameָ����ѡ���ȷ
				EFAULT ����optvalָ��ָ���޷���ȡ���ڴ�ռ�
 * ����˵����   
**************************************************/

int setsockopt(int s,int level,int optname,const void * optval,socklen_toptlen);
/*************************************************
 * ����˵����   setsockopt(����socket״̬)
 * ��ͷ�ļ���   #include <sys/types.h>  #include <sys/socket.h>
 * ���庯����   int setsockopt(int s,int level,int optname,const void * optval,socklen_toptlen);
 * ����˵����   setsockopt�����������ò���s ��ָ����socket ״̬
 * ����ֵ  ��   �ɹ��򷵻�0�����д����򷵻�-1������ԭ�����errno
 * ����˵����   EBADF ����s���ǺϷ���socket�������
				ENOTSOCK ����sΪһ�ļ������ʣ���socket
				ENOPROTOOPT ����optnameָ����ѡ���ȷ��
				EFAULT ����optvalָ��ָ���޷���ȡ���ڴ�ռ�
 * ����˵����   
**************************************************/


void herror( const char *s );
/*************************************************
 * ����˵����   herror(��ӡ���������ԭ����Ϣ�ַ���)
 * ��ͷ�ļ���   #include <netdb.h>
 * ���庯����   void herror( const char *s );
 * ����˵����   ����Ĳ��ֺ������г���ʱ���ȴ�ӡ���Զ��������˵���ַ��� *s ��Ȼ���ӡ����ش�����������˵��
 * ����˵����
			�� perror������
				perror()�����Ķ��������ͷ�ļ���#include <stdio.h>��һ��Ӧ�� #include <errno.h> ���ʹ��
				herror()�����Ķ��������ͷ�ļ���#include <netdb.h> 
				һ������ڸ�ͷ�ļ��ĺ������� gethostbyname(3)����gethostbyaddr(3) �ȵȡ�
**************************************************/
hstrerror(�����������ԭ��������ַ���) ��strerror����


unsigned long int inet_addr(const char *cp);
/*************************************************
 * ����˵����   inet_addr(�������ַת����������Ƶ�����)
 * ��ͷ�ļ���   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * ���庯����   unsigned long int inet_addr(const char *cp);
 * ����˵����   inet_addr��������������cp��ָ�������ַ�ַ���ת����������ʹ
				�õĶ��������֡������ַ�ַ����������ֺ͵���ɵ��ַ�����
				���磺��163.13.132.68����
 * ����ֵ  ��   �ɹ��򷵻ض�Ӧ����������Ƶ����֣�ʧ�ܷ���-1�� 
 * ����˵����   ���ӣ�inet_addr("127.0.0.1");
**************************************************/

int inet_aton(const char * cp,struct in_addr *inp);
/*************************************************
 * ����˵����   inet_aton(�������ַת����������Ƶ�����)
 * ��ͷ�ļ���   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * ���庯����   int inet_aton(const char * cp,struct in_addr *inp);
 * ����˵����   inet_aton��������������cp��ָ�������ַ�ַ���ת��������ʹ��
				�Ķ����Ƶ����֣�Ȼ����ڲ���inp��ָ��in_addr �ṹ�С�
				�ṹin_addr �������£�
				struct in_addr
				{
					unsigned long int s_addr;
				};
 * ����ֵ  ��   �ɹ��򷵻ط�0 ֵ��ʧ���򷵻�0��
**************************************************/

char * inet_ntoa(struct in_addr in);
/*************************************************
 * ����˵����   inet_ntoa(����������Ƶ�����ת���������ַ)
 * ��ͷ�ļ���   #include <sys/socket.h> #include <netinet/in.h> #include <arpa/inet.h>
 * ���庯����   char * inet_ntoa(struct in_addr in);
 * ����˵����   inet_ntoa��������������in��ָ����������Ƶ�����ת���������
				ַ��Ȼ��ָ��������ַ�ַ�����ָ�뷵�ء�
 * ����ֵ  ��   �ɹ��򷵻��ַ���ָ�룬ʧ���򷵻�NULL��
**************************************************/

unsigned long int htonl(unsigned long int hostlong);
/*************************************************
 * ����˵����   htonl(��32λ�����ַ�˳��ת���������ַ�˳��)
 * ��ͷ�ļ���   #include <netinet/in.h>
 * ���庯����   unsigned long int htonl(unsigned long int hostlong);
 * ����˵����   htonl��������������ָ����32 λhostlongת���������ַ�˳��
 * ����ֵ  ��   ���ض�Ӧ�������ַ�˳�� 
**************************************************/

unsigned long int ntohl(unsigned long int netlong);
/*************************************************
 * ����˵����   ntohl(��32λ�����ַ�˳��ת���������ַ�˳��)
 * ��ͷ�ļ���   #include <netinet/in.h>
 * ���庯����   unsigned long int ntohl(unsigned long int netlong);
 * ����˵����   ntohl��������������ָ����32 λnetlongת���������ַ�˳��
 * ����ֵ  ��   ���ض�Ӧ�������ַ�˳�� 
**************************************************/

unsigned short int htons(unsigned short int hostshort);
/*************************************************
 * ����˵����   htons(��16λ�����ַ�˳��ת���������ַ�˳��)
 * ��ͷ�ļ���   #include <netinet/in.h>
 * ���庯����   unsigned short int htons(unsigned short int hostshort);
 * ����˵����   htons��������������ָ����16 λhostshortת���������ַ�˳��
 * ����ֵ  ��   ���ض�Ӧ�������ַ�˳�� 
**************************************************/

unsigned short int ntohs(unsigned short int netshort);
/*************************************************
 * ����˵����   ntohs(��16λ�����ַ�˳��ת���������ַ�˳��)
 * ��ͷ�ļ���   #include <netinet/in.h>
 * ���庯����   unsigned short int ntohs(unsigned short int netshort);
 * ����˵����   ntohs��������������ָ����16 λnetshortת���������ַ�˳��
 * ����ֵ  ��   ���ض�Ӧ�������ַ�˳�� 
**************************************************/

int recv(int s,void *buf,int len,unsigned int flags);
/*************************************************
 * ����˵����   recv(��socket��������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <sys/socket.h>
 * ���庯����   int recv(int s,void *buf,int len,unsigned int flags);
 * ����˵����   recv������������Զ��������ָ����socket ���������ݣ���������
				�浽�ɲ���buf ָ����ڴ�ռ䣬����len Ϊ�ɽ������ݵ���󳤶ȡ�
				����flagsһ����0��������ֵ�������£�
					MSG_OOB ������out-of-band�ͳ������ݡ�
					MSG_PEEK �����������ݲ�������ϵͳ��ɾ��������ٵ���recv()�᷵����ͬ���������ݡ�
					MSG_WAITALL ǿ�Ƚ��յ�len��С�����ݺ���ܷ��أ������д�����źŲ�����
					MSG_NOSIGNAL �˲�����Ը��SIGPIPE �ź��ж�
 * ����ֵ  ��   �ɹ��򷵻ؽ��յ����ַ�����ʧ�ܷ���-1������ԭ�����errno�С�
 * ����˵����   EBADF ����s�ǺϷ���socket�������
				EFAULT ��������һָ��ָ���޷���ȡ���ڴ�ռ�
				ENOTSOCK ����sΪһ�ļ������ʣ���socket��
				EINTR ���ź����ж�
				EAGAIN �˶������������ϣ�������s��socketΪ�������
				ENOBUFS ϵͳ�Ļ����ڴ治��
				ENOMEM �����ڴ治��
				EINVAL ����ϵͳ���õĲ�������ȷ
 * ����˵����   
**************************************************/

int send(int s,const void * msg,int len,unsigned int falgs);
/*************************************************
 * ����˵����   send(��socket��������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <sys/socket.h>
 * ���庯����   int send(int s,const void * msg,int len,unsigned int falgs);
 * ����˵����   send����������������ָ����socket �����Է�����������s Ϊ�ѽ�
				�������ӵ�socket������msg ָ�������ߵ��������ݣ�����len ��
				Ϊ���ݳ��ȡ�����flagsһ����0��������ֵ�������£�
					MSG_OOB ���͵�������out-of-band�ͳ�
					MSG_DONTROUTE ȡ��·�ɱ��ѯ
					MSG_DONTWAIT ����Ϊ�����������
					MSG_NOSIGNAL �˶�����Ը��SIGPIPE �ź��ж�
 * ����ֵ  ��   �ɹ��򷵻�ʵ�ʴ��ͳ�ȥ���ַ�����ʧ�ܷ���-1������ԭ�����errno
 * ����˵����   EBADF ����s�ǺϷ���socket�������
				EFAULT ��������һָ��ָ���޷���ȡ���ڴ�ռ�
				ENOTSOCK ����sΪһ�ļ������ʣ���socket��
				EINTR ���ź����ж�
				EAGAIN �˶������������ϣ�������s��socketΪ�������
				ENOBUFS ϵͳ�Ļ����ڴ治��
				ENOMEM �����ڴ治��
				EINVAL ����ϵͳ���õĲ�������ȷ
 * ����˵����   
**************************************************/

int recvmsg(int s,struct msghdr *msg,unsigned int flags);
/*************************************************
 * ����˵����   recvmsg(��socket��������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <sys/socket.h>
 * ���庯����   int recvmsg(int s,struct msghdr *msg,unsigned int flags);
 * ����˵����   recvmsg������������Զ��������ָ����socket���������ݡ�����s
				Ϊ�ѽ��������ߵ�socket���������UDP Э�����辭�����߲�
				��������msgָ�������ߵ����ݽṹ���ݣ�����flagsһ����0����
				ϸ������ο�send���������ڽṹmsghdr �Ķ�����ο�sendmsg������
 * ����ֵ  ��   �ɹ��򷵻ؽ��յ����ַ�����ʧ���򷵻�-1������ԭ�����errno�С�
 * ����˵����   EBADF ����s�ǺϷ���socket�������
				EFAULT ��������һָ��ָ���޷���ȡ���ڴ�ռ�
				ENOTSOCK ����sΪһ�ļ������ʣ���socket��
				EINTR ���ź����ж�
				EAGAIN �˶������������ϣ�������s��socketΪ�������
				ENOBUFS ϵͳ�Ļ����ڴ治��
				ENOMEM �����ڴ治��
				EINVAL ����ϵͳ���õĲ�������ȷ
 * ����˵����   
**************************************************/

int sendmsg(int s,const strcut msghdr *msg,unsigned int flags);
/*************************************************
 * ����˵����   sendmsg(��socket��������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <sys/socket.h>
 * ���庯����   int sendmsg(int s,const strcut msghdr *msg,unsigned int flags);
 * ����˵����   sendmsg����������������ָ����socket �����Է�����������s Ϊ
				�ѽ��������ߵ�socket���������UDPЭ�����辭�����߲�����
				����msgָ�������ߵ����ݽṹ���ݣ�����flagsһ��Ĭ��Ϊ0����
				ϸ������ο�send������
				�ṹmsghdr �������£�
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
 * ����ֵ  ��   �ɹ��򷵻�ʵ�ʴ��ͳ�ȥ���ַ�����ʧ�ܷ���-1������ԭ�����errno
 * ����˵����   EBADF ����s�ǺϷ���socket�������
				EFAULT ��������һָ��ָ���޷���ȡ���ڴ�ռ�
				ENOTSOCK ����sΪһ�ļ������ʣ���socket��
				EINTR ���ź����ж�
				EAGAIN �˶������������ϣ�������s��socketΪ�������
				ENOBUFS ϵͳ�Ļ����ڴ治��
				ENOMEM �����ڴ治��
				EINVAL ����ϵͳ���õĲ�������ȷ
 * ����˵����   
**************************************************/

int shutdown(int s,int how);
/*************************************************
 * ����˵����   shutdown(��ֹsocketͨ��)
 * ��ͷ�ļ���   #include <sys/socket.h>
 * ���庯����   int shutdown(int s,int how);
 * ����˵����   shutdown����������ֹ����s ��ָ����socket ���ߡ�����s ������
				�е�socket������룬����how�����м��������
					how=0 ��ֹ��ȡ������
					how=1 ��ֹ���Ͳ���
					how=2 ��ֹ��ȡ�����Ͳ���
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ����˵����   EBADF ����s������Ч��socket�������
				ENOTSOCK ����sΪһ�ļ������ʣ���socket
				ENOTCONN ����sָ����socket��δ����
 * ����˵����   
**************************************************/

