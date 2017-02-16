/************************************
 * File name   : mutex_base_def.h
 * Author      : SJC
 * Description : 和线程相关的的基本定义
 *             ：
 * Date        : 2016-8-16 11:58:25
 * Modification:
***************************************************/

#ifndef __MUTEX_BASE_DEF_H
#define __MUTEX_BASE_DEF_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pthread.h>

/*
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/sem.h>
#include <signal.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/syslog.h>
#include <ctype.h>
#include <sys/wait.h>
#include <linux/netlink.h>
#include <locale.h>
#include <syslog.h>
#include <dirent.h>
#include <sys/poll.h>
#include <assert.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <sys/sysinfo.h> 
#include <netinet/tcp.h> 
#include <sys/reboot.h>
#include <netdb.h>
*/

#define APP_TRUE 1
#define APP_FALSE 0

#define APP_OK 0
#define APP_FAIL -1

#ifndef MIN
   #define MIN(x,y)     ((x)<(y)?(x):(y))
#endif

#ifndef MAX
   #define MAX(x,y)     ((x)>(y)?(x):(y))
#endif


/* 
 * macro defines about pthread mutex :关于线程互斥锁的宏定义
 */
//pthread_mutex_t lock;
#define APP_CREATE_LOCK(lock)   pthread_mutex_init ((lock), NULL)   //创建
#define APP_DELETE_LOCK(lock)   pthread_mutex_destroy((lock))
#define APP_ACQUIRE_LOCK(lock)  pthread_mutex_lock ((lock))
#define APP_RELEASE_LOCK(lock)  pthread_mutex_unlock ((lock))

#endif
