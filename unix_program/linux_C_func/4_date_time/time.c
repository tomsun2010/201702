/************************************
 * File name   : time.c
 * Author      : SJC
 * Description : ���ں�ʱ��ĺ���

 * Date        : 2016-8-29 20:10:43
 * Makefile    : gcc -o xxx xxx.c
 * Add         :
	    struct tm
		{
			int tm_sec;  //����Ŀǰ����, ������ΧΪ0-59, ��������61 ��
			int tm_min;  //����Ŀǰ����, ��Χ0-59
			int tm_hour;  //����ҹ�����ʱ��, ��ΧΪ0-23
			int tm_mday;  //Ŀǰ�·ݵ�����, ��Χ01-31
			int tm_mon;  //����Ŀǰ�·�, ��һ������, ��Χ��0-11
			int tm_year;  //��1900 ���������������
			int tm_wday;  //һ���ڵ�����, ������һ����, ��ΧΪ0-6
			int tm_yday;  //�ӽ���1 ��1 ���������������, ��ΧΪ0-365
			int tm_isdst;  //�չ��Լʱ������
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
	    /* 1. local= UTC + 8Сʱ
		 * 2. gmtime��localtime���ú���Ҫ����������Ȼ�Ḳ��ʱ��
		 * 3. gmtime_r��localtime_r�浽�û��ṹ���Ͳ��Ḳ��ʱ��
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
		/*1. ��gmtime_r��localtime_r������û��ʹ���û��ṹ�壬��Ȼ�Ḳ��*/
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
		/*1. ��gmtime_r��localtime_r��ʹ���û��ṹ�壬���Ḳ��*/
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