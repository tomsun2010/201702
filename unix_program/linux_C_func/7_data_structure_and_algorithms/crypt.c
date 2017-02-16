/************************************
 * File name   : crypt.c
 * Author      : SJC
 * Description : 加密

 * Date        : 2016-8-30 14:57:43
 * Makefile    : gcc -o xxx xxx.c -lcrypt
 
	char * crypt (const char *key,const char * salt);
	char * getpass(char *prompt);
 *************************************************/
 #if 0
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include <unistd.h>

#define _XOPEN_SOURCE
int main(void)
{
	char *key = "test";
	char *passwd;
	char salt[2];
	
	salt[0] = key[1];
	salt[1] = key[2];
	
	passwd = crypt(key, salt);
	printf("salt[0] = %c, salt[1] = %c\n", salt[0], salt[1]);
	printf("after crypt, passwd = %s\n", passwd);
	
	return 0;
}
#endif 

#include <stdio.h>  
#include <stdlib.h>
# include <string.h>

#include <unistd.h>  
#define _XOPEN_SOURCE  
  
int main(void)  
{  
		/*salt: cat /etc/shadow
		    $6$             3FcxipHV$cVMR3K/3MjABmcROTyW7zKzME4O2jcb1mDaN9o.GXm9hm7qRYOaie
		    $6$开头才有效	
		*/
        char *passwd;  
        char key[] = "123456";  
        //passwd = crypt(key, "$6$y9cP0qlm");  
		//passwd = crypt(key, "$6$y9cP0"); 
		//passwd = crypt(key, "$6$y");
        passwd = crypt(key, "$6$123456");		
        printf("password: %s\n", passwd);  
        return 0;  
}