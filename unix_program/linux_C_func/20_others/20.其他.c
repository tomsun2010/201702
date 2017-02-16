��23��������ʽ(��ʱ��ѧ)

regcomp(����������ʽ�ַ���)
regerror(ȡ�����������Ĵ���ԭ��)
regexec(����������ʽ������)
regfree(�ͷ�������ʽʹ�õ��ڴ�)

��24�¶�̬����(��ʱ��ѧ)

dlclose(�رն�̬�������ļ�)
dlerror(��̬����������)
dlopen(�򿪶�̬�������ļ�)
dlsym(�ӹ��������������̬����)

��25����������

int getopt(int argc,char * const argv[ ],const char * optstring);
/*************************************************
 * ����˵����   getopt(���������в���)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int getopt(int argc,char * const argv[ ],const char * optstring);
 * ����˵����   getopt�����������������в�����
                ����argc��argv����main()���ݵĲ������������ݡ�
				����optstring������������ѡ���ַ�����
				�˺����᷵����argv ����һ����ѡ����ĸ������ĸ���Ӧ����
				optstring �е���ĸ�����ѡ���ַ��������ĸ�����ð�š���������
				��ʾ������صĲ�����ȫ�����optarg����ָ��˶��������
				���getopt�����Ҳ������ϵĲ������ӡ������Ϣ������ȫ�����
				optopt ��Ϊ�������ַ��������ϣ��getopt����ӡ������Ϣ����ֻ
				Ҫ��ȫ�����opterr ��Ϊ0 ���ɡ�
 * ����ֵ  ��   ����ҵ����ϵĲ����򷵻ش˲�����ĸ����������������ڲ���
                optstring��ѡ����ĸ�򷵻ء������ַ������������򷵻�-1��
**************************************************/

int isatty(int desc);
/*************************************************
 * ����˵����   isatty(�ж��ļ��������Ƿ���Ϊ�ն˻�)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int isatty(int desc);
 * ����˵����   �������desc��������ļ�������Ϊһ�ն˻��򷵻�1�����򷵻�0��
 * ����ֵ  ��   ����ļ�Ϊ�ն˻��򷵻� 1�����򷵻� 0  
**************************************************/

char * ttyname(int desc);
/*************************************************
 * ����˵����   ttyname(����һ�ն˻�����)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   char * ttyname(int desc);
 * ����˵����   �������desc��������ļ�������Ϊһ�ն˻�����Ὣ���ն˻���
                ����һ�ַ���ָ�뷵�أ����򷵻�NULL��
 * ����ֵ  ��   ����ɹ��򷵻�ָ���ն˻����Ƶ��ַ���ָ�룬
                �д����������ʱ�򷵻�NULL�� 
**************************************************/

int select(int n,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,struct timeval * timeout);
/*************************************************
 * ����˵����   select(I/O�๤����)
 * ��ͷ�ļ���   #include<sys/time.h>  #include<sys/types.h> #include <unistd.h>
 * ���庯����   int select(int n,fd_set * readfds,fd_set * writefds,fd_set *exceptfds,struct timeval * timeout);
 * ����˵����   select���������ȴ��ļ�������״̬�ĸı䡣
                ����n���������ļ������ʼ�1��
				����readfds��writefds ��exceptfds ��Ϊ�������飬�������ش��������ʵĶ���д�������״����
				���µĺ��ṩ�˴�����������������ķ�ʽ��
					FD_CLR��inr fd,fd_set* set�������������������set�����fd��λ
					FD_ISSET��int fd,fd_set *set��������������������set�����fd��λ�Ƿ�Ϊ��
					FD_SET��int fd,fd_set*set��������������������set�����fd��λ
					FD_ZERO��fd_set *set���� ���������������set��ȫ��λ
				����timeoutΪ�ṹtimeval����������select�����ĵȴ�ʱ�䣬��ṹ�������£�
					struct timeval
					{
						time_t tv_sec;
						time_t tv_usec;
					};
					�������timeout��ΪNULL���ʾselect����û��timeout��
 * ����ֵ  ��   �ɹ��򷵻��ļ�������״̬�Ѹı�ĸ�����
                ����0������������״̬�ı�ǰ�ѳ���timeoutʱ�䣻
				���󷵻�-1��
				����ԭ�����errno����ʱ����readfds��writefds��exceptfds��timeout
				��ֵ��ɲ���Ԥ�⡣
 * ����˵����   
				EBADF �ļ�������Ϊ��Ч�Ļ���ļ��ѹر�
				EINTR �˵��ñ��ź����ж�
				EINVAL ����nΪ��ֵ��
				ENOMEM �����ڴ治��  
				
 * ����˵����   �����ĳ���Ƭ��
		fs_set readset, writeset��
		FD_ZERO(&readset);
		FD_ZERO(&writeset);
		FD_SET(fd,&readset);
		FD_SET(fd,&writeset);
		select(fd+1,&readset,NULL,NULL,NULL);
		select(fd+1,&readset,&writeset,NULL,NULL);
		if(FD_ISSET(fd,&readset){����}	  //���ݿɶ�
		if(FD_ISSET(fd,&writeset){����}	  //���ݿ�д
		
**************************************************/


