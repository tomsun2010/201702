/*******************************
 *
 * ������ ʱ������ڵĺ���
 *
**********************************/

#include <time.h>

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

time_t mktime(strcut tm * timeptr);

double difftime(time_t time2, time_t time1);


time_t time(time_t *t);
/*************************************************
 * ����˵���� ������� 
 * ��ͷ�ļ��� #include <time.h>
 * ���庯���� time_t time(time_t *t);
 * ����˵���� �˺����᷵�شӹ�Ԫ 1970 ��1 ��1 �յ�UTC ʱ���0 ʱ0 ��0 ������������������������
              ���t ���ǿ�ָ��Ļ����˺���Ҳ�Ὣ����ֵ�浽t ָ����ָ���ڴ档		  
 * ����ֵ  �� �ɹ��򷵻�������ʧ���򷵻�((time_t)-1)ֵ������ԭ�����errno �С�
 * ����˵���� 
**************************************************/

int settimeofday(const struct timeval *tv, const struct timezone *tz);
/*************************************************
 * ����˵���� ����ʱ���ʱ����root�û��� 
 * ��ͷ�ļ��� #include <sys/time.h>    #include <unistd.h>
 * ���庯���� int settimeofday(const struct timeval *tv, const struct timezone *tz);
 * ����˵���� �˺����᷵�شӹ�Ԫ 1970 ��1 ��1 �յ�UTC ʱ���0 ʱ0 ��0 ������������������������
              ���t ���ǿ�ָ��Ļ����˺���Ҳ�Ὣ����ֵ�浽t ָ����ָ���ڴ档		  
 * ����ֵ  �� �ɹ��򷵻�0��ʧ�ܷ��أ�1������������errno����
 * ����˵���� 
        ������룺
			EPERM  ������root Ȩ�޵���settimeofday()��Ȩ�޲�����
			EINVAL  ʱ����ĳ�������ǲ���ȷ�ģ��޷���ȷ����ʱ�䡣
**************************************************/

int gettimeofday (struct timeval * tv, struct timezone * tz);
/*************************************************
 * ����˵���� ����ʱ���ʱ����root�û��� 
 * ��ͷ�ļ��� #include <sys/time.h>    #include <unistd.h>
 * ���庯���� int gettimeofday (struct timeval * tv, struct timezone * tz);
 * ����˵���� gettimeofday()���Ŀǰ��ʱ����tv ��ָ�Ľṹ���أ�����ʱ������Ϣ��ŵ�tz ��ָ�Ľṹ�С�		  
 * ����ֵ  �� �ɹ��򷵻�0��ʧ�ܷ��أ�1������������errno����
 * ����˵���� 
        ������룺
			EFAULT ָ��tv ��tz ��ָ���ڴ�ռ䳬����ȡȨ�ޡ�
			
		timeval �ṹ����Ϊ��
		struct timeval
		{
			long tv_sec;  //��
			long tv_usec;  //΢��
		};

		timezone �ṹ����Ϊ��
		struct timezone
		{
			int tz_minuteswest;  //��Greenwich ʱ����˶��ٷ���
			int tz_dsttime;  //�չ��Լʱ���״̬
		};
		
		tz_dsttime �������״̬����
			DST_NONE  //��ʹ��
			DST_USA  //����
			DST_AUST  //����
			DST_WET  //��ŷ
			DST_MET  //��ŷ
			DST_EET  //��ŷ
			DST_CAN  //���ô�
			DST_GB  //���е�
			DST_RUM  //��������
			DST_TUR  //������
			DST_AUSTALT  //����(1986 ���Ժ�)
**************************************************/

struct tm *gmtime(const time_t *timep);
/*************************************************
 * ����˵���� ����ʱ���ʱ����root�û��� 
 * ��ͷ�ļ��� #include <time.h>
 * ���庯���� struct tm *gmtime(const time_t *timep);
 * ����˵���� gmtime()������timep ��ָ��time_t �ṹ�е���Ϣת������ʵ������ʹ�õ�ʱ�����ڱ�ʾ������
              Ȼ�󽫽���ɽṹtm ���ء�
 * ����ֵ  �� ���ؽṹtm ����ĿǰUTC ʱ�䣬ʱ������δ��ʱ��ת����
 * ����˵���� UTCʱ��ģ�ʱ+8 Ϊ�й���ʱ��
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
**************************************************/

struct tm *localtime(const time_t * timep);
/*************************************************
 * ����˵���� ����ʱ���ʱ����root�û��� 
 * ��ͷ�ļ��� #include <sys/time.h>    #include <unistd.h>
 * ���庯���� struct tm *localtime(const time_t * timep);
 * ����˵���� localtime()������timep ��ָ��time_t �ṹ�е���Ϣת������ʵ������ʹ�õ�ʱ�����ڱ�ʾ������
              Ȼ�󽫽���ɽṹtm ���ء�
 * ����ֵ  �� ���ؽṹtm ����Ŀǰ�ĵ���ʱ�䡣
 * ����˵���� 
**************************************************/

time_t mktime(strcut tm * timeptr);
/*************************************************
 * ����˵���� ����ʱ���ʱ����root�û��� 
 * ��ͷ�ļ��� #include <time.h>
 * ���庯���� time_t mktime(strcut tm * timeptr);
 * ����˵���� mktime()����������timeptr ��ָ��tm �ṹ����ת���ɴӹ�Ԫ1970 ��1 ��1 ��0 ʱ0 ��0 ��
              ���������UTC ʱ����������������
 * ����ֵ  �� ���ؾ���������
 * ����˵���� 
 
	��������time()ȡ��ʱ�� (����), ����localtime() ת����struct tm ������mktine()��structtm ת����ԭ����������
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



