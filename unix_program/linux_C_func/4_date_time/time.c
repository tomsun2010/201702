/************************************
 * File name   : time.c
 * Author      : SJC
 * Description : 日期和时间的函数

 * Date        : 2016-8-29 20:10:43
 * Makefile    : gcc -o xxx xxx.c
 * Add         :
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
 *************************************************/
 # include <stdio.h>
 # include <stdlib.h>
 # include <string.h>
 
 # include <time.h>
 # include <errno.h>
 
 int main(void)
 {
	#if 0
		time_t seconds = time(NULL);
		printf("%d\n", (int)seconds);
		printf("%s\n", ctime(&seconds));
    #endif	
	
	#if 0
	    /* 1. local= UTC + 8小时
		 * 2. gmtime和localtime调用后需要立即处理，不然会覆盖时间
		 * 3. gmtime_r和localtime_r存到用户结构体后就不会覆盖时间
		*/
	    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
		time_t timep;
		struct tm *utc_tm;
		struct tm *local_tm;
		
        time(&timep);
		
		utc_tm = gmtime(&timep);
		printf("%d/%d/%d ", (1900+utc_tm->tm_year), (1+utc_tm->tm_mon), utc_tm->tm_mday);
		printf("%s %d:%d:%d\n", wday[utc_tm->tm_wday], utc_tm->tm_hour, utc_tm->tm_min, utc_tm->tm_sec);
		
		local_tm = localtime(&timep);
		printf("%d/%d/%d ", (1900+local_tm->tm_year), (1+local_tm->tm_mon), local_tm->tm_mday);
		printf("%s %d:%d:%d\n", wday[local_tm->tm_wday], local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
		
	#endif
	
	#if 0
		/*1. 用gmtime_r和localtime_r，但是没有使用用户结构体，依然会覆盖*/
	    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
		time_t timep = time(NULL);
		if( timep < 0 )
		{
			perror("time");
			return -1;
		}
		
		struct tm tmp_tm = {0};
		struct tm *utc_tm = NULL;
		struct tm *local_tm = NULL;
		
		utc_tm = gmtime_r(&timep, &tmp_tm);
		if( NULL == utc_tm )
		{
			perror("gmtime" );
			return -1;
		}
		printf("UTC = %d/%d/%d ", (1900+utc_tm->tm_year), (1+utc_tm->tm_mon), utc_tm->tm_mday);
		printf("%s %d:%d:%d\n", wday[utc_tm->tm_wday], utc_tm->tm_hour, utc_tm->tm_min, utc_tm->tm_sec);

		local_tm = localtime_r(&timep, &tmp_tm);
		if( NULL == local_tm )
		{
			perror("localtime" );
			return -1;
		}
		printf("LOC = %d/%d/%d ", (1900+local_tm->tm_year), (1+local_tm->tm_mon), local_tm->tm_mday);
		printf("%s %d:%d:%d\n", wday[local_tm->tm_wday], local_tm->tm_hour, local_tm->tm_min, local_tm->tm_sec);
		   
	#endif
	#if 0
		/*1. 用gmtime_r和localtime_r，使用用户结构体，不会覆盖*/
		char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
		 
		time_t cur_time = time(NULL);
		if( cur_time < 0 )
		{
			perror("time");
			return -1;
		}
		
		struct tm utc_tm = {0};
		if( NULL == gmtime_r(&cur_time, &utc_tm) )
		{
			perror("gmtime" );
			return -1;
		}

		struct tm local_tm = {0};
		if( NULL == localtime_r(&cur_time, &local_tm) )
		{
			perror("localtime" );
			return -1;
		}

		printf("UTC = %s", asctime(&utc_tm) );
		printf("UTC = %d/%d/%d ", (1900+utc_tm.tm_year), (1+utc_tm.tm_mon), utc_tm.tm_mday);
		printf("%s %d:%d:%d\n", wday[utc_tm.tm_wday], utc_tm.tm_hour, utc_tm.tm_min, utc_tm.tm_sec);
		
		printf("LOC = %s", asctime(&local_tm) );
		printf("LOC = %s", ctime(&cur_time) );
	#endif 
	return 0;
 }