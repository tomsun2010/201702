/************************************
 * File name   : file_dir.c
 * Author      : SJC
 * Description : 文件和目录操作函数

 * Date        : 2016-9-6 10:53:39
 * Makefile    : gcc -o xxx xxx.c
 *************************************************/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <sys/types.h>

int main(void)
{
	#if 0
		int i = 0;
		int j = 0;
		char buf[100] = {0};
		char input[] = "10 0x1b aaaaaa bbbbbb";
		size_t count = 0;
		
		struct dirent **namelist;
		int dir_num = 0;
		
		if (access("/etc/passwd", R_OK) == 0)
		{
			printf("/etc/passwd can be read\n");
		}
		
		dir_num = scandir("/", &namelist, 0, alphasort);
		if(dir_num < 0)
		{
			perror("scandir");
		}
		else
		{
			while(dir_num--)
			{
				printf("%s\n", namelist[dir_num]->d_name);
				free(namelist[dir_num]);
			}
			free(namelist);
		}
	#endif 
	
	#if 0
	    /*
		 * DIR *opendir(const char * name);
		 * struct dirent *readdir(DIR * dir);
		 * off_t telldir(DIR *dir);
		*/
		DIR *dir = NULL;
		struct dirent *ptr = NULL;
		int offset = 0;
		
		dir = opendir("/etc");
		if (dir != NULL)
		{
			while ((ptr=readdir(dir)) != NULL)
			{
				offset = telldir(dir);
				printf("d_name:%s, offset:%d\n", ptr->d_name, offset);
			}
		}
		closedir(dir);
		dir = NULL;
	
	#endif 
	
	#if 1
		char buf[100] = {0};
		
		getcwd(buf, sizeof(buf));
		printf("getcwd = %s\n", buf);
	#endif
	
	return 0;
}