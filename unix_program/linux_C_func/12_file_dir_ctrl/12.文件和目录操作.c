/*******************************
 *
 * 第 12 章 文件和目录操作函数
 *
**********************************/

int access(const char * pathname,int mode);
/*************************************************
 * 功能说明：   access(判断是否具有存取文件的权限)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int access(const char * pathname,int mode);
 * 函数说明： 	access（）会检查是否可以读/写某一已存在的文件。
                参数mode 有几种情况组合，R_OK，W_OK，X_OK 和F_OK。
				R_OK，W_OK与X_OK 用来检查文件是否具有读取、写入和执行的权限。
				F_OK则是用来判断该文件是否存在。
				
				由于access（）只作权限的核查，并不理会文件形态或文件内容，
				因此，如果一目录表示为“可写入”，表示可以在该目录中建立新文件等操作，
				而非意味此目录可以被当做文件处理。 
 * 返回值  ：   若所有欲查核的权限都通过了检查则返回0 值，表示成功，
                只要有一权限被禁止则返回-1。
 * 错误代码：   EACCESS 参数pathname 所指定的文件不符合所要求测试的权限。
				EROFS 欲测试写入权限的文件存在于只读文件系统内。
				EFAULT 参数pathname指针超出可存取内存空间。
				EINVAL 参数mode不正确。
				ENAMETOOLONG 参数pathname太长。
				ENOTDIR 参数pathname为一目录。
				ENOMEM 核心内存不足
				ELOOP 参数pathname有过多符号连接问题。
				EIO I/O 存取错误。
 * 附加说明：   使用access()作用户认证方面的判断要特别小心，
                例如在access()后再做open()的空文件可能会造成系统安全上的问题。
				
		if(access("xxx", F_OK) != 0)
		{
			......;
		}
**************************************************/

int alphasort(const struct dirent **a,const struct dirent **b);
/*************************************************
 * 功能说明：   alphasort(依字母顺序排序目录结构)
 * 表头文件：   #include <dirent.h>
 * 定义函数：   int alphasort(const struct dirent **a,const struct dirent **b);
 * 函数说明： 	alphasort()为scandir()最后调用qsort()函数时传给qsort()作为判断的函数 
 * 附件说明：   
				struct dirent
				{
					long d_ino;              // inode number 索引节点号
					off_t d_off;             //offset to this dirent 在目录文件中的偏移
					unsigned short d_reclen; //length of this d_name 文件名长
					unsigned char d_type;    //the type of d_name 文件类型 
					char d_name [NAME_MAX+1];//file name (null-terminated) 文件名，最长256字符
				}
**************************************************/

int scandir(const char *dir,struct dirent **namelist,int (*filter)(const void *b),
                       int ( * compare )( const struct dirent **, const struct dirent ** ) );
/*************************************************
 * 功能说明：   scandir(读取特定的目录数据)
 * 表头文件：   #include <dirent.h>
 * 定义函数：   int scandir(const char *dir,struct dirent **namelist,int (*filter)(const void *b),
                       int ( * compare )( const struct dirent **, const struct dirent ** ) );

 * 函数说明： 	函数scandir扫描dir目录下以及dir子目录下满足filter过滤模式的文件，
                返回的结果是compare函数经过排序的，并保存在 namelist中。
				
				注意namelist是通过malloc动态分配内存的,所以在使用时要注意释放内存。
				alphasort和versionsort 是使用到的两种排序的函数。 
 * 返回值  ：   当函数成功执行时返回找到匹配模式文件的个数，如果失败将返回-1。
 * 附加说明： 
**************************************************/

int chdir(const char * path);
/*************************************************
 * 功能说明：   chdir(改变当前的工作目录)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int chdir(const char * path);
 * 函数说明： 	chdir()用来将当前的工作目录改变成以参数path所指的目录。  
 * 返回值  ：   执行成功则返回0，失败返回-1，errno为错误代码。
 * 附加说明：   
				chdir("xxx");
**************************************************/

int chmod(const char * path,mode_t mode);
/*************************************************
 * 功能说明：  chmod(改变文件的权限)
 * 表头文件：  #include <sys/types.h> #include <sys/stat.h>
 * 定义函数：  int chmod(const char * path,mode_t mode);
 * 函数说明：  chmod（）会依参数mode 权限来更改参数path 指定文件的权限。
				参数mode有下列数种组合：
					S_ISUID            04000 文件的（set user-id on execution）位
					S_ISGID            02000 文件的（set group-id on execution）位
					S_ISVTX            01000 文件的sticky位
					
					S_IRUSR（S_IREAD） 00400 文件所有者具可读取权限
					S_IWUSR（S_IWRITE）00200 文件所有者具可写入权限
					S_IXUSR（S_IEXEC） 00100 文件所有者具可执行权限
					
					S_IRGRP            00040 用户组具可读取权限
					S_IWGRP            00020 用户组具可写入权限
					S_IXGRP            00010 用户组具可执行权限
					
					S_IROTH            00004 其他用户具可读取权限
					S_IWOTH            00002 其他用户具可写入权限
					S_IXOTH            00001 其他用户具可执行权限
					
				    只有该文件的所有者或有效用户识别码为0，才可以修改该文件权
				限。基于系统安全，如果欲将数据写入一执行文件，而该执行文件
				具有S_ISUID 或S_ISGID 权限，则这两个位会被清除。如果一目
				录具有S_ISUID 位权限，表示在此目录下只有该文件的所有者或
				root可以删除该文件。					
 * 返回值  ：   权限改变成功返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EPERM   进程的有效用户识别码与欲修改权限的文件拥有者不同，而且也不具root权限。
				EACCESS 参数path所指定的文件无法存取。
				EROFS   欲写入权限的文件存在于只读文件系统内。
				EFAULT  参数path指针超出可存取内存空间。
				EINVAL  参数mode不正确
				ENAMETOOLONG 参数path太长
				ENOENT       指定的文件不存在
				ENOTDIR      参数path路径并非一目录
				ENOMEM       核心内存不足
				ELOOP        参数path有过多符号连接问题。
				EIO          I/O 存取错误
**************************************************/

int chown(const char * path, uid_t owner,gid_t group);
/*************************************************
 * 功能说明：   chown(改变文件的所有者)
 * 表头文件：   #include <sys/types.h> #include <unistd.h>
 * 定义函数：   int chown(const char * path, uid_t owner,gid_t group);
 * 函数说明： 	chown()会将参数path指定文件的所有者变更为参数owner 代表
				的用户，而将该文件的组变更为参数group 组。
				如果参数owner 或roup为-1，对应的所有者或组不会有所改变。
				root与文件所有者皆可改变文件组，但所有者必须是参数group 组的成员。当root 用
				
				chown()改变文件所有者或组时，该文件若具有S_ISUID 或
				S_ISGID 权限，则会清除此权限位，此外如果具有S_ISGID 权限但
				不具S_IXGRP位，则该文件会被强制锁定，文件模式会保留。 
 * 返回值  ：   成功则返回0，失败返回-1，错误原因存于errno。
 * 附加说明：   错误代码参考chmod()
**************************************************/

int chroot(const char * path);
/*************************************************
 * 功能说明：   chroot(改变根目录)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int chroot(const char * path);
 * 函数说明： 	chroot（）用来改变根目录为参数path 所指定的目录。
                只有超级用户才允许改变根目录，子进程将继承新的根目录。 
 * 返回值  ：   调用成功则返回0，失败则返-1，错误代码存于errno。
 * 错误代码：   EPERM  权限不足，无法改变根目录。
				EFAULT 参数path指针超出可存取内存空间。
				ENAMETOOLONG 参数path太长。
				ENOTDIR      路径中的目录存在但却非真正的目录
				EACCESS      存取目录时被拒绝
				ENOMEM       核心内存不足
				ELOOP        参数path有过多符号连接问题
				EIO          I/O 存取错误
**************************************************/

DIR * opendir(const char * name);
/*************************************************
 * 功能说明：   opendir(打开目录)
 * 表头文件：   #include <sys/types.h> #include <dirent.h>
 * 定义函数：   DIR * opendir(const char * name);
 * 函数说明： 	opendir（）用来打开参数name 指定的目录，并返回DIR* 形态的
                目录流，和open（）类似，接下来对目录的读取和搜索都要使用此返回值   
 * 返回值  ：   成功则返回DIR* 型态的目录流，打开失败则返回NULL
 * 错误代码：   EACCESS  权限不足
				EMFILE   已达到进程可同时打开的文件数上限。
				ENFILE   已达到系统可同时打开的文件数上限。
				ENOTDIR  参数name非真正的目录
				ENOENT   参数name 指定的目录不存在，或是参数name 为一空字符串。
				ENOMEM   核心内存不足。
				
	struct __dirstream
	{
		void *__fd;
		char *__data;
		int __entry_data;
		char *__ptr;
		int __entry_ptr;
		size_t __allocation;
		size_t __size;
		__libc_lock_define (, __lock)
	};
	typedef struct __dirstream DIR;
	
	struct dirent *readdir(DIR *dp);
	void rewinddir(DIR *dp);
	int closedir(DIR *dp);
	long telldir(DIR *dp);
	void seekdir(DIR *dp,long loc);
**************************************************/

struct dirent * readdir(DIR * dir);
/*************************************************
 * 功能说明：   readdir(读取目录)
 * 表头文件：   #include <sys/types.h> #include <dirent.h>
 * 定义函数：   struct dirent * readdir(DIR * dir);
 * 函数说明： 	readdir（）返回参数dir 目录流的下个目录进入点。
 * 返回值  ：   成功则返回下个目录进入点。有错误发生或读取到目录文件尾则返回NULL。
 * 错误代码：   EBADF参数dir 为无效的目录流。	

		struct dirent
		{
			long d_ino;              //inode number 索引节点号
			off_t d_off;             //offset to this dirent 在目录文件中的偏移
			unsigned short d_reclen; //length of this d_name 文件名长
			unsigned char d_type;    //the type of d_name 文件类型 
			char d_name [NAME_MAX+1];//file name (null-terminated) 文件名，最长256字符
		}; 
**************************************************/

void seekdir(DIR * dir,off_t offset);
/*************************************************
 * 功能说明：   seekdir(设置下回读取目录的位置)
 * 表头文件：   #include <dirent.h>
 * 定义函数：   void seekdir(DIR * dir,off_t offset);
 * 函数说明： 	seekdir()用来设置参数dir 目录流目前的读取位置，在调用readdir()
                时便从此新位置开始读取。参数offset 代表距离目录文件开头的偏移量。
 * 返回值  ：   
 * 错误代码：   EBADF参数dir 为无效的目录流。	
**************************************************/

off_t telldir(DIR *dir);
/*************************************************
 * 功能说明：   telldir(取得目录流的读取位置)
 * 表头文件：   #include <dirent.h>
 * 定义函数：   off_t telldir(DIR *dir);
 * 函数说明： 	telldir（）返回参数dir 目录流目前的读取位置。
                此返回值代表距离目录文件开头的偏移量
 * 返回值  ：   返回下个读取位置，有错误发生时返回-1。
 * 错误代码：   EBADF参数dir 为无效的目录流。	
**************************************************/

void rewinddir(DIR *dir);
/*************************************************
 * 功能说明：   rewinddir(重设读取目录的位置为开头位置)
 * 表头文件：   #include <sys/types.h> #include <dirent.h>
 * 定义函数：   void rewinddir(DIR *dir);
 * 函数说明： 	rewinddir（）用来设置参数dir 目录流目前的读取位置为原来开头的读取位置。
 * 返回值  ：   
 * 错误代码：   EBADF参数dir 为无效的目录流。	
**************************************************/

int closedir(DIR *dir);
/*************************************************
 * 功能说明：   closedir(关闭目录)
 * 表头文件：   #include <sys/types.h> #include <dirent.h>
 * 定义函数：   int closedir(DIR *dir);
 * 函数说明： 	closedir（）关闭参数dir 所指的目录流。
 * 返回值  ：   关闭成功则返回0，失败返回-1，错误原因存于errno中。
 * 错误代码：   EBADF参数dir 为无效的目录流。	
**************************************************/

int fchdir(int fd);
/*************************************************
 * 功能说明：   fchdir(改变当前的工作目录)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int fchdir(int fd);
 * 函数说明： 	fchdir()用来将当前的工作目录改变成以参数fd 所指的文件描述词。 
 * 返回值  ：   执行成功则返回0，失败返回-1，errno为错误代码。
**************************************************/

int fchmod(int fildes,mode_t mode);
/*************************************************
 * 功能说明：   fchmod(改变文件的权限)
 * 表头文件：   #include <sys/types.h> #include <sys/stat.h>
 * 定义函数：   int fchmod(int fildes,mode_t mode);
 * 函数说明： 	fchmod（）会依参数mode权限来更改参数fildes所指文件的权限。
				参数fildes为已打开文件的文件描述词。
				参数mode请参考chmod（）。  
 * 返回值  ：   权限改变成功则返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EBADF    参数fildes为无效的文件描述词。
				EPERM    进程的有效用户识别码与欲修改权限的文件所有者不同，而且也不具root权限。
				EROFS    欲写入权限的文件存在于只读文件系统内。
				EIO      I/O 存取错误。
**************************************************/

int fchown(int fd,uid_t owner,gid_t group);
/*************************************************
 * 功能说明：   fchown(改变文件的所有者)
 * 表头文件：   #include <sys/types.h> #include <unistd.h>
 * 定义函数：   int fchown(int fd,uid_t owner,gid_t group);
 * 函数说明： 	fchown（）会将参数fd指定文件的所有者变更为参数owner 代表的
				用户，而将该文件的组变更为参数group组。如果参数owner或group
				为-1，对映的所有者或组有所改变。
				参数fd为已打开的文件描述词。
				当root用fchown（）改变文件所有者或组时，该文件若具S_ISUID
				或S_ISGID 权限，则会清除此权限位。  
 * 返回值  ：   成功则返回0，失败则返回-1，错误原因存于errno。
 * 错误代码：   EBADF    参数fd文件描述词为无效的或该文件已关闭。
				EPERM    进程的有效用户识别码与欲修改权限的文件所有者不同，
				         而且也不具root权限，或是参数owner、group不正确。
				EROFS    欲写入的文件存在于只读文件系统内。
				ENOENT   指定的文件不存在
				EIO      I/O 存取错误
**************************************************/

stat(取得文件状态)
fstat(由文件描述词取得文件状态)
lstat(由文件描述词取得文件状态)
int stat(const char *file_name,struct stat *buf);
int fstat(int fildes,struct stat *buf);
int lstat (const char *file_name, struct stat * buf);
/*************************************************
 * 功能说明：   取得文件状态
 * 表头文件：   #include <sys/stat.h>  #include <unistd.h>
 * 定义函数：   int stat (const char *file_name,struct stat *buf);
				int fstat(int fildes       ,    struct stat *buf);
				int lstat(const char *file_name, struct stat * buf);
 * 函数说明： 	stat()用来将参数file_name所指的文件状态，复制到参数buf 所指的结构中；
				fstat()用来将参数fildes所指的文件状态，复制到参数buf所指的结构中。
                
				fstat()与stat()作用完全相同，不同处在于传入的参数为已打开的文件描述词。
				lstat()与stat()作用完全相同，都是取得参数file_name 所指的文件状态，
				       其差别在于，当文件为符号连接时，lstat()会返回该link本身的状态。
				
				struct stat
				{
					dev_t st_dev;      /*device     			文件的设备编号
					ino_t st_ino;      /*inode      			文件的i-node
					mode_t st_mode;    /*protection 			文件的类型和存取的权限
					nlink_t st_nlink;  /*number of hard links   连到该文件的硬连接数目，刚建立的文件值为1。
					uid_t st_uid;      /*user ID of owner       UID
					gid_t st_gid;      /*group ID of owner      GID
					dev_t st_rdev;     /*device type            若此文件为装置设备文件，则为其设备编号
					off_t st_size;     /*total size, in bytes   文件大小，以字节计算
					unsigned long st_blksize; /*blocksize for filesystem I/O   文件系统的I/O 缓冲区大小。
					unsigned long st_blocks;  /*number of blocks allocated     占用文件区块的个数，每一区块大小为512 个字节。
					time_t st_atime; /* time of lastaccess          文件最近一次被存取或被执行的时间
					time_t st_mtime; /* time of last modification   文件最后一次被修改的时间
					time_t st_ctime; /* time of last change         i-node最近一次被更改的时间
				};
				
				st_mode则定义了下列数种情况：
					S_IFMT   0170000 文件类型的位遮罩
					S_IFSOCK 0140000 scoket
					S_IFLNK  0120000 符号连接
					S_IFREG  0100000 一般文件
					S_IFBLK  0060000 区块装置
					S_IFDIR  0040000 目录
					S_IFCHR  0020000 字符装置
					S_IFIFO  0010000 先进先出
					S_ISUID  04000 文件的（set user-id on execution）位
					S_ISGID  02000 文件的（set group-id on execution）位
					S_ISVTX  01000 文件的sticky位
					S_IRUSR（S_IREAD） 00400 文件所有者具可读取权限
					S_IWUSR（S_IWRITE）00200 文件所有者具可写入权限
					S_IXUSR（S_IEXEC） 00100 文件所有者具可执行权限
					S_IRGRP 00040 用户组具可读取权限
					S_IWGRP 00020 用户组具可写入权限
					S_IXGRP 00010 用户组具可执行权限
					S_IROTH 00004 其他用户具可读取权限
					S_IWOTH 00002 其他用户具可写入权限
					S_IXOTH 00001 其他用户具可执行权限
				上述的文件类型在POSIX 中定义了检查这些类型的宏定义：
					S_ISLNK （st_mode） 判断是否为符号连接
					S_ISREG （st_mode） 是否为一般文件
					S_ISDIR （st_mode）是否为目录
					S_ISCHR （st_mode）是否为字符装置文件
					S_ISBLK （s3e） 是否为先进先出
					S_ISSOCK （st_mode） 是否为socket
 
				若一目录具有sticky 位（S_ISVTX），则表示在此目录下的文件只能
				被该文件所有者、此目录所有者或root来删除或改名。
				
 * 返回值  ：   执行成功则返回0，失败返回-1，错误代码存于errno。
 * 错误代码     ENOENT 参数file_name指定的文件不存在
				ENOTDIR 路径中的目录存在但却非真正的目录
				ELOOP 欲打开的文件有过多符号连接问题，上限为16 符号连接
				EFAULT 参数buf为无效指针，指向无法存在的内存空间
				EACCESS 存取文件时被拒绝
				ENOMEM 核心内存不足
				ENAMETOOLONG 参数file_name的路径名称太长
**************************************************/

#include <unistd.h>
char *getwd(char *buf);                  //use of getwd() is deprecated
char *get_current_dir_name(void);
char *getcwd(char * buf,size_t size);   //
/*************************************************
 * 功能说明：   getcwd(取得当前的工作目录)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   char * getcwd(char * buf,size_t size);
 * 函数说明： 	getcwd（）会将当前的工作目录绝对路径复制到参数buf 所指的内
				存空间，参数size 为buf 的空间大小。在调用此函数时，buf 所指
				的内存空间要足够大，若工作目录绝对路径的字符串长度超过参数
				size大小，则回值NULL，errno的值则为ERANGE。倘若参数buf
				为NULL，getcwd（）会依参数size的大小自动配置内存（使用malloc
				（）），如果参数size也为0，则getcwd（）会依工作目录绝对路径
				的字符串程度来决定所配置的内存大小，进程可以在使用完此字符
				串后利用free（）来释放此空间。 
 * 返回值  ：   执行成功则将结果复制到参数buf 所指的内存空间，或是返回自动
                配置的字符串指针。失败返回NULL，错误代码存于errno。
 * 附加说明： 
**************************************************/

int ftruncate(int fd,off_t length);
/*************************************************
 * 功能说明：   ftruncate(改变文件大小)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int ftruncate(int fd,off_t length);
 * 函数说明： 	ftruncate（）会将参数fd指定的文件大小改为参数length指定的大
				小。参数fd为已打开的文件描述词，而且必须是以写入模式打开的
				文件。如果原来的文件大小比参数length大，则超过的部分会被删去。 
 * 返回值  ：   执行成功则返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EBADF 参数fd文件描述词为无效的或该文件已关闭。
                EINVAL 参数fd 为一socket 并非文件，或是该文件并非以写入模式打开。
**************************************************/

int truncate(const char *path,off_t length);
/*************************************************
 * 功能说明：   truncate(改变文件大小)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int truncate(const char *path,off_t length);
 * 函数说明： 	truncate（）会将参数path 指定的文件大小改为参数length 指定的
                大小。如果原来的文件大小比参数length大，则超过的部分会被删去。 
 * 返回值  ：   执行成功则返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EACCESS 参数path所指定的文件无法存取。
				EROFS   欲写入的文件存在于只读文件系统内
				EFAULT  参数path指针超出可存取内存空间
				EINVAL  参数path包含不合法字符
				ENAMETOOLONG 参数path太长
				ENOTDIR  参数path路径并非一目录
				EISDIR   参数path指向一目录
				ETXTBUSY 参数path所指的文件为共享程序，而且正被执行中
				ELOOP    参数path有过多符号连接问题
				EIO      I/O 存取错误。
**************************************************/

int ftw(const char *dir, int (*fn) (const *file, const struct stat *sb, int flag), int depth)
/*************************************************
 * 功能说明：   ftw(遍历目录树)
 * 表头文件：   #include <ftw.h>
 * 定义函数：   int ftw(const char *dir, int (*fn) (const *file, const struct stat *sb, int flag), int depth)
 * 函数说明： 	ftw()会从参数dir指定的 目录开始，往下一层层地递归式遍历子 目录。
                ftw()会传三个参数给fn(), 第一个参数*file指向当时所在的 目录路径，
				                         第二个参数是*sb, 为stat结构指针，
										 第三个参数为旗标，有下面几种可能值:
												FTW_F 一般文件
												FTW_D 目录
												FTW_DNR 不可读取的 目录，此 目录以下将不被遍历
												FTW_SL 符号连接
												FTW_NS 无法取得stat结构数据，有可能是 权限问题

               最后一个参数depth代表ftw（）在进行遍历 目录时同时打开的文件数。
			   
			       ftw()在遍历时每一层 目录至少需要一个文件描述词，如果遍历时用完了depth所给予的限制数目，
			   整个遍历将因不断地关文件和开文件操作而显得缓慢. 
			   
			       如果要结束ftw()的遍历，fn()只需返回一非零值即可，此值同时也会是ftw()的返回值。
			   否则ftw()会试着走完所有的 目录，然后返回0.

 * 返回值  ：  遍历中断则返回fn()函数的返回值，全部遍历则返回0，若有错误发生则返回-1
 * 附加说明： 
**************************************************/

nftw(遍历目录树)

int link (const char * oldpath,const char * newpath);
/*************************************************
 * 功能说明：   link(建立文件硬连接)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int link (const char * oldpath,const char * newpath);
 * 函数说明： 	link（）以参数newpath指定的名称来建立一个新的连接（硬连接）
				到参数oldpath所指定的已存在文件。如果参数newpath指定的名称
				为一已存在的文件则不会建立连接。 
 * 返回值  ：   成功则返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EXDEV  参数oldpath与newpath不是建立在同一文件系统。
				EPERM  参数oldpath与newpath所指的文件系统不支持硬连接
				EROFS  文件存在于只读文件系统内
				EFAULT 参数oldpath或newpath指针超出可存取内存空间。
				ENAMETOLLONG 参数oldpath或newpath太长
				ENOMEM  核心内存不足
				EEXIST  参数newpath所指的文件名已存在。
				EMLINK  参数oldpath所指的文件已达最大连接数目。
				ELOOP   参数pathname有过多符号连接问题
				ENOSPC  文件系统的剩余空间不足。
				EIO     I/O 存取错误。
 * 附加说明：   link()所建立的硬连接无法跨越不同文件系统，如果需要请改用symlink()。
**************************************************/

int symlink( const char * oldpath,const char * newpath);
/*************************************************
 * 功能说明：   symlink(建立文件符号连接)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int symlink( const char * oldpath,const char * newpath);
 * 函数说明： 	symlink（）以参数newpath指定的名称来建立一个新的连接（符号
				连接）到参数oldpath所指定的已存在文件。参数oldpath指定的文
				件不一定要存在，如果参数newpath指定的名称为一已存在的文件
				则不会建立连接。 
 * 返回值  ：   成功则返回0，失败返回-1，错误原因存于errno。
 * 错误代码：   EPERM  参数oldpath与newpath所指的文件系统不支持符号连接
				EROFS  欲测试写入权限的文件存在于只读文件系统内
				EFAULT 参数oldpath或newpath指针超出可存取内存空间。
				ENAMETOOLONG 参数oldpath或newpath太长
				ENOMEM 核心内存不足
				EEXIST 参数newpath所指的文件名已存在。
				EMLINK 参数oldpath所指的文件已达到最大连接数目
				ELOOP  参数pathname有过多符号连接问题
				ENOSPC 文件系统的剩余空间不足
				EIO    I/O 存取错误
 * 附加说明：   
**************************************************/

int readlink(const char * path ,char * buf,size_t bufsiz);
/*************************************************
 * 功能说明：   readlink(取得符号连接所指的文件)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int readlink(const char * path ,char * buf,size_t bufsiz);
 * 函数说明： 	readlink（）会将参数path的符号连接内容存到参数buf所指的内存
				空间，返回的内容不是以NULL作字符串结尾，但会将字符串的字
				符数返回。若参数bufsiz 小于符号连接的内容长度，过长的内容会被截断。  
 * 返回值  ：   执行成功则传符号连接所指的文件路径字符串，失败则返回-1，错误代码存于errno。
 * 错误代码：   EACCESS 取文件时被拒绝，权限不够
				EINVAL  参数bufsiz 为负数
				EIO     I/O 存取错误。
				ELOOP   欲打开的文件有过多符号连接问题。
				ENAMETOOLONG 参数path的路径名称太长
				ENOENT  参数path所指定的文件不存在
				ENOMEM  核心内存不足
				ENOTDIR 参数path路径中的目录存在但却非真正的目录。
**************************************************/

lchown(改变文件的所有者)

realpath(将相对目录路径转换成绝对路径)


int remove(const char * pathname);
/*************************************************
 * 功能说明：   remove(删除文件)
 * 表头文件：   #include <stdio.h>
 * 定义函数：   int remove(const char * pathname);
 * 函数说明： 	remove()会删除参数pathname 指定的文件。如果参数pathname
				为一文件，则调用unlink()处理，若参数pathname 为一目录，则
				调用rmdir()来处理。请参考unlink()与rmdir()。
 * 返回值  ：   成功则返回0，失败则返回-1，错误原因存于errno
 * 错误代码：   EROFS  欲写入的文件存在于只读文件系统内
				EFAULT 参数pathname指针超出可存取内存空间。
				ENAMETOOLONG 参数pathname太长
				ENOMEM 核心内存不足
				ELOOP  参数pathname有过多符号连接问题
				EIO    I/O 存取错误。
**************************************************/

int unlink(const char * pathname);
/*************************************************
 * 功能说明：   unlink(删除文件)
 * 表头文件：   #include <unistd.h>
 * 定义函数：   int unlink(const char * pathname);
 * 函数说明： 	unlink（）会删除参数pathname指定的文件。如果该文件名为最后
				连接点，但有其他进程打开了此文件，则在所有关于此文件的文件
				描述词皆关闭后才会删除。如果参数pathname为一符号连接，则此
				连接会被删除。
 * 返回值  ：   成功则返回0，失败则返回-1，错误原因存于errno
 * 错误代码：   EROFS  文件存在于只读文件系统内。
				EFAULT 参数pathname指针超出可存取内存空间
				ENAMETOOLONG 参数pathname太长
				ENOMEM 核心内存不足
				ELOOP  参数pathname有过多符号连接问题
				EIO    I/O 存取错误
**************************************************/

/********************************
mkdir函数用于创建目录。
格式如下：
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<unistd.h>
	int mkdir(const char *pathname,mode_t mode);
rmdir()函数删除一个空目录，它的格式如下：
	#include<unistd.h>
	int rmdir(const char *pathname);
使用rmdir函数时，目录必须为空，否则调用失败，函数返回-1，成功时，函数返回0.

如果想调用remove之后马上看到文件被删除，建议你判断是否被占用。或者使用system("rm -rf filename").
****************************************/

int rename(const char *oldpath,const char *newpath);
/*************************************************
 * 功能说明：   rename(更改文件名称或位置)
 * 表头文件：   #include <stdio.h>
 * 定义函数：   int rename(const char * oldpath,const char * newpath);
 * 函数说明： 	rename()会将参数oldpath 所指定的文件名称改为参数newpath
                所指的文件名称。若newpath所指定的文件已存在，则会被删除。 
 * 返回值  ：   执行成功则返回0，失败返回-1，错误原因存于errno
**************************************************/

mode_t umask(mode_t mask);
/*************************************************
 * 功能说明：   umask(设置建立新文件时的权限遮罩)
 * 表头文件：   #include <sys/types.h>  #include <sys/stat.h>
 * 定义函数：   mode_t umask(mode_t mask);
 * 函数说明： 	umask()会将系统umask值设成参数mask&0777 后的值，然后将
				先前的umask值返回。在使用open()建立新文件时，该参数mode
				并非真正建立文件的权限，而是（mode&~umask）的权限值。例如，
				在建立文件时指定文件权限为0666，通常umask值默认为022，则
				该文件的真正权限则为0666&～022＝0644，也就是rw-r--r-- 
 * 返回值  ：   此调用不会有错误值返回。返回值为原先系统的umask值。
 * 附加说明： 
**************************************************/

int utime(const char * filename,struct utimbuf * buf);
/*************************************************
 * 功能说明：   utime(修改文件的存取时间和更改时间)
 * 表头文件：   #include <sys/types.h>  #include <utime.h>
 * 定义函数：   int utime(const char * filename,struct utimbuf * buf);
 * 函数说明： 	utime（）用来修改参数filename文件所属的inode存取时间。结构
				utimbuf定义如下：
				struct utimbuf{
					time_t actime;
					time_t modtime;
				};
                如果参数buf为空指针（NULL），则该文件的存取时间和更改时间全部会设为目前时间  
 * 返回值  ：   执行成功则返回0，失败返回-1，错误代码存于errno。
 * 错误代码：   EACCESS 存取文件时被拒绝，权限不足
				ENOENT 指定的文件不存在。
**************************************************/

int utimes(char * filename.struct timeval *tvp);
/*************************************************
 * 功能说明：   utimes(修改文件的存取时间和更改时间)
 * 表头文件：   #include <sys/types.h>  #include <utime.h>
 * 定义函数：   int utimes(char * filename.struct timeval *tvp);
 * 函数说明： 	utimes（）用来修改参数filename文件所属的inode存取时间和修改
				时间，结构timeval定义如下：
				struct timeval {
					long tv_sec;
					long tv_usec; //微妙
				};
				参数tvp 指向两个timeval 结构空间，和utime（）使用的utimebuf
				结构比较，tvp[0].tc_sec 则为utimbuf.actime，tvp]1].tv_sec 为utimbuf.modtime。 
 * 返回值  ：   执行成功则返回0。失败返回-1，错误代码存于errno。
 * 错误代码：   EACCESS 存取文件时被拒绝，权限不足
				ENOENT 指定的文件不存在
**************************************************/




