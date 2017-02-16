/************************************
 * File name   : protoent.c
 * Author      : SJC
 * Description : 

 * Date        : 2016-9-8 20:21:59
 * Modification:
 * Makefile    : gcc xxx.c -o xxx
 
	struct protoent  
	{  
		char *p_name;          
		char **p_aliases;     
		int p_proto;          
	};
*****************************************************/
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>

#include <netdb.h>  
  
static void printproto(struct protoent *proto)  
{  
    char **p = NULL;  
      
    printf("protocol: %s\n", proto->p_name);  
      
    for(p=proto->p_aliases; *p; p++)  
    {  
        printf("alias: %s\n", *p);  
    }  
      
    printf("protocol: %d\n", proto->p_proto);  
}   
  
int main(void)  
{  
    struct protoent *proto = NULL;  
    setprotoent(1);  
	
    while( (proto=getprotoent()) != NULL )  
    {  
        printproto(proto);  
        printf("\n");  
    }  
    endprotoent(); 
	
    return 0;  
}  
