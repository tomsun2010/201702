#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    char *str1 = "http://see.xidian.edu.cn/cpp/u/shipin/";
    char str2[100] = "http://see.xidian.edu.cn/cpp/u/shipin_liming/";
    char str3[7] = "1234567";
	
    printf("strlen(str1)=%d, sizeof(str1)=%d\n", strlen(str1), sizeof(str1));  //38 8
    printf("strlen(str2)=%d, sizeof(str2)=%d\n", strlen(str2), sizeof(str2));  //45 100 
    printf("strlen(str3)=%d, sizeof(str3)=%d\n", strlen(str3), sizeof(str3));  //7 7
    
	return 0;
}