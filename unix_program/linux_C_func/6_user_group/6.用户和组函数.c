/*******************************
 *
 * 第六章 用户和组函数
 *
**********************************/

void utmpname(const char * file);
/*************************************************
 * 功能说明： utmpname(设置utmp文件路径)
 * 表头文件： #include <utmp.h>
 * 定义函数： void utmpname(const char * file); 
 * 函数说明： 用来设置utmp 文件的路径, 以提供utmp 相关函数的存取路径. 
			  如果没有使用utmpname()则默认utmp 文件路径为/var/run/utmp。		  
 * 返回值  ： 
 * 附加说明： 
**************************************************/

struct utmp *getutent(void);
/*************************************************
 * 功能说明： getutent(从utmp文件中取得帐号登录数据)
 * 表头文件： #include <utmp.h>
 * 定义函数： struct utmp *getutent(void);
 * 函数说明： 从utmp 文件(/var/run/utmp)中读取一项登录数据, 
              该数据以utmp 结构返回. 第一次调用时会取得第一位用户数据, 
              之后每调用一次就会返回下一项数据, 直到已无任何数据时返回NULL。		  
 * 返回值  ： 返回 utmp 结构数据, 如果返回NULL 则表示已无数据, 或有错误发生.
 * 附加说明： getutent()在第一次调用时会打开utmp 文件, 读取数据完毕后可使用endutent()来关闭该utmp文件.
 * 相关结构： 
		struct utmp
		{
			short int ut_type;         //登录类型
			pid_t ut_pid;              //login 进程的pid
			char ut_line[UT_LINESIZE]; //登录装置名, 省略了"/dev/"
			char ut_id[4];             //Inittab ID
			char ut_user[UT_NAMESIZE]; //登录账号
			char ut_host[UT_HOSTSIZE]; //登录账号的远程主机名称
			struxt exit_status ut_exit; //当类型为DEAD_PROCESS 时进程的结束状态
			long int ut_session;        //Sessioc ID
			struct timeval ut_tv;       //时间记录
			int32_t ut_addr_v6[4];      //远程主机的网络地址
			char __unused[20];          //保留未使用
		};
		
		ut_type 有以下几种类型:
			EMPTY：此为空的记录.
			RUN_LVL：记录系统run－level 的改变
			BOOT_TIME：记录系统开机时间
			NEW_TIME：记录系统时间改变后的时间
			OLD_TINE：记录当改变系统时间时的时间.
			INIT_PROCESS：记录一个由init 衍生出来的进程.
			LOGIN_PROCESS：记录 login 进程.
			USER_PROCESS：记录一般进程.
			DEAD_PROCESS：记录一结束的进程.
			ACCOUNTING：目前尚未使用.
			
		struct exit_status
		{
			short int e_termination; //进程结束状态
			short int e_exit;        //进程退出状态
		};
		
		相关常数定义如下:
			UT_LINESIZE 32
			UT_NAMESIZE 32
			UT_HOSTSIZE 256
 * 相关例子：		
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
 * 功能说明： setutent(从头读取utmp/文件中的登录数据)
 * 表头文件： #include <utmp.h>
 * 定义函数： void setutent(void);
 * 函数说明： setutent()用来将getutent()的读写地址指回utmp 文件开头。	  
 * 返回值  ： 
 * 附加说明： 
**************************************************/

void endutent(void);
/*************************************************
 * 功能说明： endutent(关闭utmp文件)
 * 表头文件： #include <utmp.h>
 * 定义函数： void endutent(void);
 * 函数说明： endutent()用来关闭由getutent 所打开的utmp 文件。  
 * 返回值  ： 
 * 附加说明：
 * 相关例子： 
**************************************************/

getgrent(从组文件文件中取得帐号的数据)
setgrent(从头读取组文件中的组数据)
endgrent(关闭组文件)

getpwent(从密码文件中取得帐号的数据)
setpwent(从头读取密码文件中的帐号数据)
endpwent(关闭密码文件)

fgetgrent(从指定的文件来读取组格式)
fgetpwent(从指定的文件来读取密码格式)

getuid(取得真实的用户识别码)
setuid(设置真实的用户识别码)
setfsuid(设置文件系统的用户识别码)

seteuid(设置有效的用户识别码)
geteuid(取得有效的用户识别码)
setreuid(设置真实及有效的用户识别码)
getpwuid(从密码文件中取得指定uid的数据)

getgid(取得真实的组识别码)
setgid(设置真实的组识别码)
setfsgid(设置文件系统的组识别码)
setregid(设置真实及有效的组识别码)

getegid(取得有效的组识别码)
setegid(设置有效的组识别码)
getgrgid(从组文件中取得指定gid的数据)

getgroups(取得组代码)
setgroups(设置组代码)

getlogin(取得登录的用户帐号名称)
getpw(取得指定用户的密码文件数据)
getpwnam(从密码文件中取得指定帐号的数据)

cuserid(取得用户帐号名称)
getgrnan(从组文件中取得指定组的数据)
getutid(从utmp文件中查找特定的记录)
getutline(从utmp文件中查找特定的记录)
initgroups(初始化组清单)
logwtmp(将一登录数据记录到wtmp文件)
pututline(将utmp记录写入文件)
updwtmp(将一登录数据记录到wtmp文件)







