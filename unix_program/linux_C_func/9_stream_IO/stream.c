/************************************
 * File name   : stream.c
 * Author      : SJC
 * Description : 流操作

 * Date        : 2016-9-1 11:29:08
 * Makefile    : gcc xxx.c -o xxx
     
	 FILE * fopen(const char * path,const char * mode);
	 int fclose(FILE * stream);
	 size_t fwrite(const void * ptr,size_t size,size_t nmemb,FILE * stream);
	 size_t fread(void * ptr,size_t size,size_t nmemb,FILE * stream);
	 int fflush(FILE* stream);
	 int fseek(FILE * stream,long offset,int whence);
     int fgetc(FILE * stream);
     char * fgets(char * s,int size,FILE * stream);
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
 
# include <errno.h>
 
int main(void)
{
	FILE *fp = NULL;
	char w_buf[30] = "linux sjc OK!!";
	char r_buf[30];
	int wr_count = 0;
	int rd_count = 0;
	int ret = 0;
	
	memset(r_buf, 0x0, sizeof(r_buf));
	fp = fopen("sjc.txt", "w");
	if (!fp)
	{
		perror("fopen");
		printf("fopen error, strerror = %s\n", strerror(errno));
		return -1;
	}
	
	//wr_count = fwrite(w_buf, sizeof(char), strlen(w_buf), fp);
	wr_count = fwrite(w_buf, 1, strlen(w_buf), fp);
    if (wr_count < 0)
	{
		perror("fwrite");
		printf("fwrite error, strerror = %s\n", strerror(errno));
		return -1;
	}
	//fflush(fp);
	fclose(fp);
	fp = NULL;
	
	fp = fopen("sjc.txt", "r");
	//rd_count = fread(r_buf, sizeof(char), 7, fp);
	//rd_count = fread(r_buf, 1, 7, fp);
	rd_count = fread(r_buf, 1, wr_count, fp);
	//if (rd_count < 0)
	if (rd_count != wr_count)
	{
		perror("fread");
		printf("fread error, strerror = %s\n", strerror(errno));
		return -1;
	}
	printf("read stream = %s\n", r_buf);
	fclose(fp);
	fp = NULL;
	
	memset(r_buf, 0x0, sizeof(r_buf));
	fp = fopen("sjc.txt", "r");
	fseek(fp, 8, SEEK_SET);
	rd_count = fread(r_buf, 1, wr_count, fp);
	printf("rd_count = %d, read buf = %s\n", rd_count, r_buf);
	fclose(fp);
	fp = NULL;
	
	fp = fopen("sjc.txt", "r");
	while((ret=fgetc(fp)) != EOF)
	{
		printf("read char = %c\n", ret);
	}
	fclose(fp);
	fp = NULL;
	
	memset(r_buf, 0x0, sizeof(r_buf));
	fp = fopen("sjc.txt", "r");
    fgets(r_buf, 5, fp);              //获得size-1个字符
	printf("read buf = %s\n", r_buf);
	fclose(fp);
	fp = NULL;
	
	return 0;
}