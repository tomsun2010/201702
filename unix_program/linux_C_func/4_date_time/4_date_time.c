/*******************************
 *
 * 第四章 时间和日期的函数
 *
**********************************/

#include <time.h>

struct tm
{
	int tm_sec;  //代表目前秒数, 正常范围为0-59, 但允许至61 秒
	int tm_min;  //代表目前分数, 范围0-59
	int tm_hour;  //从午夜算起的时数, 范围为0-23
	int tm_mday;  //目前月份的日数, 范围01-31
	int tm_mon;  //代表目前月份, 从一月算起, 范围从0-11
	int tm_year;  //从1900 年算起至今的年数
	int tm_wday;  //一星期的日数, 从星期一算起, 范围为0-6
	int tm_yday;  //从今年1 月1 日算起至今的天数, 范围为0-365
	int tm_isdst;  //日光节约时间的旗标
};
time_t time(time_t *t);
char *ctime(const time_t *timep);

struct tm *gmtime(const time_t *timep);
struct tm *localtime(const time_t * timep);

struct tm *gmtime_r(const time_t *timep, struct tm *result);
struct tm *localtime_r(const time_t *timep, struct tm *result);

char *asctime(const struct tm * timeptr);

time_t mktime(strcut tm * timeptr);

double difftime(time_t time2, time_t time1);


time_t time(time_t *t);
/*************************************************
 * 功能说明： 获得秒数 
 * 表头文件： #include <time.h>
 * 定义函数： time_t time(time_t *t);
 * 函数说明： 此函数会返回从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数。
              如果t 并非空指针的话，此函数也会将返回值存到t 指针所指的内存。		  
 * 返回值  ： 成功则返回秒数，失败则返回((time_t)-1)值，错误原因存于errno 中。
 * 附加说明： 
**************************************************/

int settimeofday(const struct timeval *tv, const struct timezone *tz);
/*************************************************
 * 功能说明： 设置时间和时区（root用户） 
 * 表头文件： #include <sys/time.h>    #include <unistd.h>
 * 定义函数： int settimeofday(const struct timeval *tv, const struct timezone *tz);
 * 函数说明： 此函数会返回从公元 1970 年1 月1 日的UTC 时间从0 时0 分0 秒算起到现在所经过的秒数。
              如果t 并非空指针的话，此函数也会将返回值存到t 指针所指的内存。		  
 * 返回值  ： 成功则返回0，失败返回－1，错误代码存于errno。。
 * 附加说明： 
        错误代码：
			EPERM  并非由root 权限调用settimeofday()，权限不够。
			EINVAL  时区或某个数据是不正确的，无法正确设置时间。
**************************************************/

int gettimeofday (struct timeval * tv, struct timezone * tz);
/*************************************************
 * 功能说明： 设置时间和时区（root用户） 
 * 表头文件： #include <sys/time.h>    #include <unistd.h>
 * 定义函数： int gettimeofday (struct timeval * tv, struct timezone * tz);
 * 函数说明： gettimeofday()会把目前的时间有tv 所指的结构返回，当地时区的信息则放到tz 所指的结构中。		  
 * 返回值  ： 成功则返回0，失败返回－1，错误代码存于errno。。
 * 附加说明： 
        错误代码：
			EFAULT 指针tv 和tz 所指的内存空间超出存取权限。
			
		timeval 结构定义为：
		struct timeval
		{
			long tv_sec;  //秒
			long tv_usec;  //微秒
		};

		timezone 结构定义为：
		struct timezone
		{
			int tz_minuteswest;  //和Greenwich 时间差了多少分钟
			int tz_dsttime;  //日光节约时间的状态
		};
		
		tz_dsttime 所代表的状态如下
			DST_NONE  //不使用
			DST_USA  //美国
			DST_AUST  //澳洲
			DST_WET  //西欧
			DST_MET  //中欧
			DST_EET  //东欧
			DST_CAN  //加拿大
			DST_GB  //大不列颠
			DST_RUM  //罗马尼亚
			DST_TUR  //土耳其
			DST_AUSTALT  //澳洲(1986 年以后)
**************************************************/

struct tm *gmtime(const time_t *timep);
/*************************************************
 * 功能说明： 设置时间和时区（root用户） 
 * 表头文件： #include <time.h>
 * 定义函数： struct tm *gmtime(const time_t *timep);
 * 函数说明： gmtime()将参数timep 所指的time_t 结构中的信息转换成真实世界所使用的时间日期表示方法，
              然后将结果由结构tm 返回。
 * 返回值  ： 返回结构tm 代表目前UTC 时间，时间日期未经时区转换。
 * 附加说明： UTC时间的：时+8 为中国区时间
        struct tm
		{
			int tm_sec;  //代表目前秒数, 正常范围为0-59, 但允许至61 秒
			int tm_min;  //代表目前分数, 范围0-59
			int tm_hour;  //从午夜算起的时数, 范围为0-23
			int tm_mday;  //目前月份的日数, 范围01-31
			int tm_mon;  //代表目前月份, 从一月算起, 范围从0-11
			int tm_year;  //从1900 年算起至今的年数
			int tm_wday;  //一星期的日数, 从星期一算起, 范围为0-6
			int tm_yday;  //从今年1 月1 日算起至今的天数, 范围为0-365
			int tm_isdst;  //日光节约时间的旗标
        };
**************************************************/

struct tm *localtime(const time_t * timep);
/*************************************************
 * 功能说明： 设置时间和时区（root用户） 
 * 表头文件： #include <sys/time.h>    #include <unistd.h>
 * 定义函数： struct tm *localtime(const time_t * timep);
 * 函数说明： localtime()将参数timep 所指的time_t 结构中的信息转换成真实世界所使用的时间日期表示方法，
              然后将结果由结构tm 返回。
 * 返回值  ： 返回结构tm 代表目前的当地时间。
 * 附加说明： 
**************************************************/

time_t mktime(strcut tm * timeptr);
/*************************************************
 * 功能说明： 设置时间和时区（root用户） 
 * 表头文件： #include <time.h>
 * 定义函数： time_t mktime(strcut tm * timeptr);
 * 函数说明： mktime()用来将参数timeptr 所指的tm 结构数据转换成从公元1970 年1 月1 日0 时0 分0 秒
              算起至今的UTC 时间所经过的秒数。
 * 返回值  ： 返回经过的秒数
 * 附加说明： 
 
	范例：用time()取得时间 (秒数), 利用localtime() 转换成struct tm 再利用mktine()将structtm 转换成原来的秒数。
	#include <time.h>
	int main(void)
	{
		time_t timep;
		strcut tm *p = NULL;
		
		time(&timep);
		printf("time() : %d \n", timep);
		
		p = localtime(&timep);
		
		timep = mktime(p);
		printf("time()->localtime()->mktime():%d\n", timep);
		
		return 0;
	}
**************************************************/



