/*******************************
 *
 * ������ �û����麯��
 *
**********************************/

void utmpname(const char * file);
/*************************************************
 * ����˵���� utmpname(����utmp�ļ�·��)
 * ��ͷ�ļ��� #include <utmp.h>
 * ���庯���� void utmpname(const char * file); 
 * ����˵���� ��������utmp �ļ���·��, ���ṩutmp ��غ����Ĵ�ȡ·��. 
			  ���û��ʹ��utmpname()��Ĭ��utmp �ļ�·��Ϊ/var/run/utmp��		  
 * ����ֵ  �� 
 * ����˵���� 
**************************************************/

struct utmp *getutent(void);
/*************************************************
 * ����˵���� getutent(��utmp�ļ���ȡ���ʺŵ�¼����)
 * ��ͷ�ļ��� #include <utmp.h>
 * ���庯���� struct utmp *getutent(void);
 * ����˵���� ��utmp �ļ�(/var/run/utmp)�ж�ȡһ���¼����, 
              ��������utmp �ṹ����. ��һ�ε���ʱ��ȡ�õ�һλ�û�����, 
              ֮��ÿ����һ�ξͻ᷵����һ������, ֱ�������κ�����ʱ����NULL��		  
 * ����ֵ  �� ���� utmp �ṹ����, �������NULL ���ʾ��������, ���д�����.
 * ����˵���� getutent()�ڵ�һ�ε���ʱ���utmp �ļ�, ��ȡ������Ϻ��ʹ��endutent()���رո�utmp�ļ�.
 * ��ؽṹ�� 
		struct utmp
		{
			short int ut_type;         //��¼����
			pid_t ut_pid;              //login ���̵�pid
			char ut_line[UT_LINESIZE]; //��¼װ����, ʡ����"/dev/"
			char ut_id[4];             //Inittab ID
			char ut_user[UT_NAMESIZE]; //��¼�˺�
			char ut_host[UT_HOSTSIZE]; //��¼�˺ŵ�Զ����������
			struxt exit_status ut_exit; //������ΪDEAD_PROCESS ʱ���̵Ľ���״̬
			long int ut_session;        //Sessioc ID
			struct timeval ut_tv;       //ʱ���¼
			int32_t ut_addr_v6[4];      //Զ�������������ַ
			char __unused[20];          //����δʹ��
		};
		
		ut_type �����¼�������:
			EMPTY����Ϊ�յļ�¼.
			RUN_LVL����¼ϵͳrun��level �ĸı�
			BOOT_TIME����¼ϵͳ����ʱ��
			NEW_TIME����¼ϵͳʱ��ı���ʱ��
			OLD_TINE����¼���ı�ϵͳʱ��ʱ��ʱ��.
			INIT_PROCESS����¼һ����init ���������Ľ���.
			LOGIN_PROCESS����¼ login ����.
			USER_PROCESS����¼һ�����.
			DEAD_PROCESS����¼һ�����Ľ���.
			ACCOUNTING��Ŀǰ��δʹ��.
			
		struct exit_status
		{
			short int e_termination; //���̽���״̬
			short int e_exit;        //�����˳�״̬
		};
		
		��س�����������:
			UT_LINESIZE 32
			UT_NAMESIZE 32
			UT_HOSTSIZE 256
 * ������ӣ�		
	#include <utmp.h>
	int main(void)
	{
		struct utmp *u;
		while((u = getutent()))
		{
			if(u->ut_type == USER_PROCESS)
			{
				printf("%d %s %s %s \n", u->ut_type, u->ut_user, u->ut_line, u->ut_host);
			}
		}
		endutent();
		
		return 0;
	}
**************************************************/

void setutent(void);
/*************************************************
 * ����˵���� setutent(��ͷ��ȡutmp/�ļ��еĵ�¼����)
 * ��ͷ�ļ��� #include <utmp.h>
 * ���庯���� void setutent(void);
 * ����˵���� setutent()������getutent()�Ķ�д��ַָ��utmp �ļ���ͷ��	  
 * ����ֵ  �� 
 * ����˵���� 
**************************************************/

void endutent(void);
/*************************************************
 * ����˵���� endutent(�ر�utmp�ļ�)
 * ��ͷ�ļ��� #include <utmp.h>
 * ���庯���� void endutent(void);
 * ����˵���� endutent()�����ر���getutent ���򿪵�utmp �ļ���  
 * ����ֵ  �� 
 * ����˵����
 * ������ӣ� 
**************************************************/

getgrent(�����ļ��ļ���ȡ���ʺŵ�����)
setgrent(��ͷ��ȡ���ļ��е�������)
endgrent(�ر����ļ�)

getpwent(�������ļ���ȡ���ʺŵ�����)
setpwent(��ͷ��ȡ�����ļ��е��ʺ�����)
endpwent(�ر������ļ�)

fgetgrent(��ָ�����ļ�����ȡ���ʽ)
fgetpwent(��ָ�����ļ�����ȡ�����ʽ)

getuid(ȡ����ʵ���û�ʶ����)
setuid(������ʵ���û�ʶ����)
setfsuid(�����ļ�ϵͳ���û�ʶ����)

seteuid(������Ч���û�ʶ����)
geteuid(ȡ����Ч���û�ʶ����)
setreuid(������ʵ����Ч���û�ʶ����)
getpwuid(�������ļ���ȡ��ָ��uid������)

getgid(ȡ����ʵ����ʶ����)
setgid(������ʵ����ʶ����)
setfsgid(�����ļ�ϵͳ����ʶ����)
setregid(������ʵ����Ч����ʶ����)

getegid(ȡ����Ч����ʶ����)
setegid(������Ч����ʶ����)
getgrgid(�����ļ���ȡ��ָ��gid������)

getgroups(ȡ�������)
setgroups(���������)

getlogin(ȡ�õ�¼���û��ʺ�����)
getpw(ȡ��ָ���û��������ļ�����)
getpwnam(�������ļ���ȡ��ָ���ʺŵ�����)

cuserid(ȡ���û��ʺ�����)
getgrnan(�����ļ���ȡ��ָ���������)
getutid(��utmp�ļ��в����ض��ļ�¼)
getutline(��utmp�ļ��в����ض��ļ�¼)
initgroups(��ʼ�����嵥)
logwtmp(��һ��¼���ݼ�¼��wtmp�ļ�)
pututline(��utmp��¼д���ļ�)
updwtmp(��һ��¼���ݼ�¼��wtmp�ļ�)







