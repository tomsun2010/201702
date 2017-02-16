/*******************************
 *
 * �� 12 �� �ļ���Ŀ¼��������
 *
**********************************/

int access(const char * pathname,int mode);
/*************************************************
 * ����˵����   access(�ж��Ƿ���д�ȡ�ļ���Ȩ��)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int access(const char * pathname,int mode);
 * ����˵���� 	access���������Ƿ���Զ�/дĳһ�Ѵ��ڵ��ļ���
                ����mode �м��������ϣ�R_OK��W_OK��X_OK ��F_OK��
				R_OK��W_OK��X_OK ��������ļ��Ƿ���ж�ȡ��д���ִ�е�Ȩ�ޡ�
				F_OK���������жϸ��ļ��Ƿ���ڡ�
				
				����access����ֻ��Ȩ�޵ĺ˲飬��������ļ���̬���ļ����ݣ�
				��ˣ����һĿ¼��ʾΪ����д�롱����ʾ�����ڸ�Ŀ¼�н������ļ��Ȳ�����
				������ζ��Ŀ¼���Ա������ļ����� 
 * ����ֵ  ��   ����������˵�Ȩ�޶�ͨ���˼���򷵻�0 ֵ����ʾ�ɹ���
                ֻҪ��һȨ�ޱ���ֹ�򷵻�-1��
 * ������룺   EACCESS ����pathname ��ָ�����ļ���������Ҫ����Ե�Ȩ�ޡ�
				EROFS ������д��Ȩ�޵��ļ�������ֻ���ļ�ϵͳ�ڡ�
				EFAULT ����pathnameָ�볬���ɴ�ȡ�ڴ�ռ䡣
				EINVAL ����mode����ȷ��
				ENAMETOOLONG ����pathname̫����
				ENOTDIR ����pathnameΪһĿ¼��
				ENOMEM �����ڴ治��
				ELOOP ����pathname�й�������������⡣
				EIO I/O ��ȡ����
 * ����˵����   ʹ��access()���û���֤������ж�Ҫ�ر�С�ģ�
                ������access()������open()�Ŀ��ļ����ܻ����ϵͳ��ȫ�ϵ����⡣
				
		if(access("xxx", F_OK) != 0)
		{
			......;
		}
**************************************************/

int alphasort(const struct dirent **a,const struct dirent **b);
/*************************************************
 * ����˵����   alphasort(����ĸ˳������Ŀ¼�ṹ)
 * ��ͷ�ļ���   #include <dirent.h>
 * ���庯����   int alphasort(const struct dirent **a,const struct dirent **b);
 * ����˵���� 	alphasort()Ϊscandir()������qsort()����ʱ����qsort()��Ϊ�жϵĺ��� 
 * ����˵����   
				struct dirent
				{
					long d_ino;              // inode number �����ڵ��
					off_t d_off;             //offset to this dirent ��Ŀ¼�ļ��е�ƫ��
					unsigned short d_reclen; //length of this d_name �ļ�����
					unsigned char d_type;    //the type of d_name �ļ����� 
					char d_name [NAME_MAX+1];//file name (null-terminated) �ļ������256�ַ�
				}
**************************************************/

int scandir(const char *dir,struct dirent **namelist,int (*filter)(const void *b),
                       int ( * compare )( const struct dirent **, const struct dirent ** ) );
/*************************************************
 * ����˵����   scandir(��ȡ�ض���Ŀ¼����)
 * ��ͷ�ļ���   #include <dirent.h>
 * ���庯����   int scandir(const char *dir,struct dirent **namelist,int (*filter)(const void *b),
                       int ( * compare )( const struct dirent **, const struct dirent ** ) );

 * ����˵���� 	����scandirɨ��dirĿ¼���Լ�dir��Ŀ¼������filter����ģʽ���ļ���
                ���صĽ����compare������������ģ��������� namelist�С�
				
				ע��namelist��ͨ��malloc��̬�����ڴ��,������ʹ��ʱҪע���ͷ��ڴ档
				alphasort��versionsort ��ʹ�õ�����������ĺ����� 
 * ����ֵ  ��   �������ɹ�ִ��ʱ�����ҵ�ƥ��ģʽ�ļ��ĸ��������ʧ�ܽ�����-1��
 * ����˵���� 
**************************************************/

int chdir(const char * path);
/*************************************************
 * ����˵����   chdir(�ı䵱ǰ�Ĺ���Ŀ¼)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int chdir(const char * path);
 * ����˵���� 	chdir()��������ǰ�Ĺ���Ŀ¼�ı���Բ���path��ָ��Ŀ¼��  
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1��errnoΪ������롣
 * ����˵����   
				chdir("xxx");
**************************************************/

int chmod(const char * path,mode_t mode);
/*************************************************
 * ����˵����  chmod(�ı��ļ���Ȩ��)
 * ��ͷ�ļ���  #include <sys/types.h> #include <sys/stat.h>
 * ���庯����  int chmod(const char * path,mode_t mode);
 * ����˵����  chmod������������mode Ȩ�������Ĳ���path ָ���ļ���Ȩ�ޡ�
				����mode������������ϣ�
					S_ISUID            04000 �ļ��ģ�set user-id on execution��λ
					S_ISGID            02000 �ļ��ģ�set group-id on execution��λ
					S_ISVTX            01000 �ļ���stickyλ
					
					S_IRUSR��S_IREAD�� 00400 �ļ������߾߿ɶ�ȡȨ��
					S_IWUSR��S_IWRITE��00200 �ļ������߾߿�д��Ȩ��
					S_IXUSR��S_IEXEC�� 00100 �ļ������߾߿�ִ��Ȩ��
					
					S_IRGRP            00040 �û���߿ɶ�ȡȨ��
					S_IWGRP            00020 �û���߿�д��Ȩ��
					S_IXGRP            00010 �û���߿�ִ��Ȩ��
					
					S_IROTH            00004 �����û��߿ɶ�ȡȨ��
					S_IWOTH            00002 �����û��߿�д��Ȩ��
					S_IXOTH            00001 �����û��߿�ִ��Ȩ��
					
				    ֻ�и��ļ��������߻���Ч�û�ʶ����Ϊ0���ſ����޸ĸ��ļ�Ȩ
				�ޡ�����ϵͳ��ȫ�������������д��һִ���ļ�������ִ���ļ�
				����S_ISUID ��S_ISGID Ȩ�ޣ���������λ�ᱻ��������һĿ
				¼����S_ISUID λȨ�ޣ���ʾ�ڴ�Ŀ¼��ֻ�и��ļ��������߻�
				root����ɾ�����ļ���					
 * ����ֵ  ��   Ȩ�޸ı�ɹ�����0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EPERM   ���̵���Ч�û�ʶ���������޸�Ȩ�޵��ļ�ӵ���߲�ͬ������Ҳ����rootȨ�ޡ�
				EACCESS ����path��ָ�����ļ��޷���ȡ��
				EROFS   ��д��Ȩ�޵��ļ�������ֻ���ļ�ϵͳ�ڡ�
				EFAULT  ����pathָ�볬���ɴ�ȡ�ڴ�ռ䡣
				EINVAL  ����mode����ȷ
				ENAMETOOLONG ����path̫��
				ENOENT       ָ�����ļ�������
				ENOTDIR      ����path·������һĿ¼
				ENOMEM       �����ڴ治��
				ELOOP        ����path�й�������������⡣
				EIO          I/O ��ȡ����
**************************************************/

int chown(const char * path, uid_t owner,gid_t group);
/*************************************************
 * ����˵����   chown(�ı��ļ���������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <unistd.h>
 * ���庯����   int chown(const char * path, uid_t owner,gid_t group);
 * ����˵���� 	chown()�Ὣ����pathָ���ļ��������߱��Ϊ����owner ����
				���û����������ļ�������Ϊ����group �顣
				�������owner ��roupΪ-1����Ӧ�������߻��鲻�������ı䡣
				root���ļ������߽Կɸı��ļ��飬�������߱����ǲ���group ��ĳ�Ա����root ��
				
				chown()�ı��ļ������߻���ʱ�����ļ�������S_ISUID ��
				S_ISGID Ȩ�ޣ���������Ȩ��λ�������������S_ISGID Ȩ�޵�
				����S_IXGRPλ������ļ��ᱻǿ���������ļ�ģʽ�ᱣ���� 
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ����˵����   �������ο�chmod()
**************************************************/

int chroot(const char * path);
/*************************************************
 * ����˵����   chroot(�ı��Ŀ¼)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int chroot(const char * path);
 * ����˵���� 	chroot���������ı��Ŀ¼Ϊ����path ��ָ����Ŀ¼��
                ֻ�г����û�������ı��Ŀ¼���ӽ��̽��̳��µĸ�Ŀ¼�� 
 * ����ֵ  ��   ���óɹ��򷵻�0��ʧ����-1������������errno��
 * ������룺   EPERM  Ȩ�޲��㣬�޷��ı��Ŀ¼��
				EFAULT ����pathָ�볬���ɴ�ȡ�ڴ�ռ䡣
				ENAMETOOLONG ����path̫����
				ENOTDIR      ·���е�Ŀ¼���ڵ�ȴ��������Ŀ¼
				EACCESS      ��ȡĿ¼ʱ���ܾ�
				ENOMEM       �����ڴ治��
				ELOOP        ����path�й��������������
				EIO          I/O ��ȡ����
**************************************************/

DIR * opendir(const char * name);
/*************************************************
 * ����˵����   opendir(��Ŀ¼)
 * ��ͷ�ļ���   #include <sys/types.h> #include <dirent.h>
 * ���庯����   DIR * opendir(const char * name);
 * ����˵���� 	opendir���������򿪲���name ָ����Ŀ¼��������DIR* ��̬��
                Ŀ¼������open�������ƣ���������Ŀ¼�Ķ�ȡ��������Ҫʹ�ô˷���ֵ   
 * ����ֵ  ��   �ɹ��򷵻�DIR* ��̬��Ŀ¼������ʧ���򷵻�NULL
 * ������룺   EACCESS  Ȩ�޲���
				EMFILE   �Ѵﵽ���̿�ͬʱ�򿪵��ļ������ޡ�
				ENFILE   �Ѵﵽϵͳ��ͬʱ�򿪵��ļ������ޡ�
				ENOTDIR  ����name��������Ŀ¼
				ENOENT   ����name ָ����Ŀ¼�����ڣ����ǲ���name Ϊһ���ַ�����
				ENOMEM   �����ڴ治�㡣
				
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
 * ����˵����   readdir(��ȡĿ¼)
 * ��ͷ�ļ���   #include <sys/types.h> #include <dirent.h>
 * ���庯����   struct dirent * readdir(DIR * dir);
 * ����˵���� 	readdir�������ز���dir Ŀ¼�����¸�Ŀ¼����㡣
 * ����ֵ  ��   �ɹ��򷵻��¸�Ŀ¼����㡣�д��������ȡ��Ŀ¼�ļ�β�򷵻�NULL��
 * ������룺   EBADF����dir Ϊ��Ч��Ŀ¼����	

		struct dirent
		{
			long d_ino;              //inode number �����ڵ��
			off_t d_off;             //offset to this dirent ��Ŀ¼�ļ��е�ƫ��
			unsigned short d_reclen; //length of this d_name �ļ�����
			unsigned char d_type;    //the type of d_name �ļ����� 
			char d_name [NAME_MAX+1];//file name (null-terminated) �ļ������256�ַ�
		}; 
**************************************************/

void seekdir(DIR * dir,off_t offset);
/*************************************************
 * ����˵����   seekdir(�����»ض�ȡĿ¼��λ��)
 * ��ͷ�ļ���   #include <dirent.h>
 * ���庯����   void seekdir(DIR * dir,off_t offset);
 * ����˵���� 	seekdir()�������ò���dir Ŀ¼��Ŀǰ�Ķ�ȡλ�ã��ڵ���readdir()
                ʱ��Ӵ���λ�ÿ�ʼ��ȡ������offset �������Ŀ¼�ļ���ͷ��ƫ������
 * ����ֵ  ��   
 * ������룺   EBADF����dir Ϊ��Ч��Ŀ¼����	
**************************************************/

off_t telldir(DIR *dir);
/*************************************************
 * ����˵����   telldir(ȡ��Ŀ¼���Ķ�ȡλ��)
 * ��ͷ�ļ���   #include <dirent.h>
 * ���庯����   off_t telldir(DIR *dir);
 * ����˵���� 	telldir�������ز���dir Ŀ¼��Ŀǰ�Ķ�ȡλ�á�
                �˷���ֵ�������Ŀ¼�ļ���ͷ��ƫ����
 * ����ֵ  ��   �����¸���ȡλ�ã��д�����ʱ����-1��
 * ������룺   EBADF����dir Ϊ��Ч��Ŀ¼����	
**************************************************/

void rewinddir(DIR *dir);
/*************************************************
 * ����˵����   rewinddir(�����ȡĿ¼��λ��Ϊ��ͷλ��)
 * ��ͷ�ļ���   #include <sys/types.h> #include <dirent.h>
 * ���庯����   void rewinddir(DIR *dir);
 * ����˵���� 	rewinddir�����������ò���dir Ŀ¼��Ŀǰ�Ķ�ȡλ��Ϊԭ����ͷ�Ķ�ȡλ�á�
 * ����ֵ  ��   
 * ������룺   EBADF����dir Ϊ��Ч��Ŀ¼����	
**************************************************/

int closedir(DIR *dir);
/*************************************************
 * ����˵����   closedir(�ر�Ŀ¼)
 * ��ͷ�ļ���   #include <sys/types.h> #include <dirent.h>
 * ���庯����   int closedir(DIR *dir);
 * ����˵���� 	closedir�����رղ���dir ��ָ��Ŀ¼����
 * ����ֵ  ��   �رճɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno�С�
 * ������룺   EBADF����dir Ϊ��Ч��Ŀ¼����	
**************************************************/

int fchdir(int fd);
/*************************************************
 * ����˵����   fchdir(�ı䵱ǰ�Ĺ���Ŀ¼)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int fchdir(int fd);
 * ����˵���� 	fchdir()��������ǰ�Ĺ���Ŀ¼�ı���Բ���fd ��ָ���ļ������ʡ� 
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1��errnoΪ������롣
**************************************************/

int fchmod(int fildes,mode_t mode);
/*************************************************
 * ����˵����   fchmod(�ı��ļ���Ȩ��)
 * ��ͷ�ļ���   #include <sys/types.h> #include <sys/stat.h>
 * ���庯����   int fchmod(int fildes,mode_t mode);
 * ����˵���� 	fchmod������������modeȨ�������Ĳ���fildes��ָ�ļ���Ȩ�ޡ�
				����fildesΪ�Ѵ��ļ����ļ������ʡ�
				����mode��ο�chmod������  
 * ����ֵ  ��   Ȩ�޸ı�ɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EBADF    ����fildesΪ��Ч���ļ������ʡ�
				EPERM    ���̵���Ч�û�ʶ���������޸�Ȩ�޵��ļ������߲�ͬ������Ҳ����rootȨ�ޡ�
				EROFS    ��д��Ȩ�޵��ļ�������ֻ���ļ�ϵͳ�ڡ�
				EIO      I/O ��ȡ����
**************************************************/

int fchown(int fd,uid_t owner,gid_t group);
/*************************************************
 * ����˵����   fchown(�ı��ļ���������)
 * ��ͷ�ļ���   #include <sys/types.h> #include <unistd.h>
 * ���庯����   int fchown(int fd,uid_t owner,gid_t group);
 * ����˵���� 	fchown�����Ὣ����fdָ���ļ��������߱��Ϊ����owner �����
				�û����������ļ�������Ϊ����group�顣�������owner��group
				Ϊ-1����ӳ�������߻��������ı䡣
				����fdΪ�Ѵ򿪵��ļ������ʡ�
				��root��fchown�����ı��ļ������߻���ʱ�����ļ�����S_ISUID
				��S_ISGID Ȩ�ޣ���������Ȩ��λ��  
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ���򷵻�-1������ԭ�����errno��
 * ������룺   EBADF    ����fd�ļ�������Ϊ��Ч�Ļ���ļ��ѹرա�
				EPERM    ���̵���Ч�û�ʶ���������޸�Ȩ�޵��ļ������߲�ͬ��
				         ����Ҳ����rootȨ�ޣ����ǲ���owner��group����ȷ��
				EROFS    ��д����ļ�������ֻ���ļ�ϵͳ�ڡ�
				ENOENT   ָ�����ļ�������
				EIO      I/O ��ȡ����
**************************************************/

stat(ȡ���ļ�״̬)
fstat(���ļ�������ȡ���ļ�״̬)
lstat(���ļ�������ȡ���ļ�״̬)
int stat(const char *file_name,struct stat *buf);
int fstat(int fildes,struct stat *buf);
int lstat (const char *file_name, struct stat * buf);
/*************************************************
 * ����˵����   ȡ���ļ�״̬
 * ��ͷ�ļ���   #include <sys/stat.h>  #include <unistd.h>
 * ���庯����   int stat (const char *file_name,struct stat *buf);
				int fstat(int fildes       ,    struct stat *buf);
				int lstat(const char *file_name, struct stat * buf);
 * ����˵���� 	stat()����������file_name��ָ���ļ�״̬�����Ƶ�����buf ��ָ�Ľṹ�У�
				fstat()����������fildes��ָ���ļ�״̬�����Ƶ�����buf��ָ�Ľṹ�С�
                
				fstat()��stat()������ȫ��ͬ����ͬ�����ڴ���Ĳ���Ϊ�Ѵ򿪵��ļ������ʡ�
				lstat()��stat()������ȫ��ͬ������ȡ�ò���file_name ��ָ���ļ�״̬��
				       �������ڣ����ļ�Ϊ��������ʱ��lstat()�᷵�ظ�link�����״̬��
				
				struct stat
				{
					dev_t st_dev;      /*device     			�ļ����豸���
					ino_t st_ino;      /*inode      			�ļ���i-node
					mode_t st_mode;    /*protection 			�ļ������ͺʹ�ȡ��Ȩ��
					nlink_t st_nlink;  /*number of hard links   �������ļ���Ӳ������Ŀ���ս������ļ�ֵΪ1��
					uid_t st_uid;      /*user ID of owner       UID
					gid_t st_gid;      /*group ID of owner      GID
					dev_t st_rdev;     /*device type            �����ļ�Ϊװ���豸�ļ�����Ϊ���豸���
					off_t st_size;     /*total size, in bytes   �ļ���С�����ֽڼ���
					unsigned long st_blksize; /*blocksize for filesystem I/O   �ļ�ϵͳ��I/O ��������С��
					unsigned long st_blocks;  /*number of blocks allocated     ռ���ļ�����ĸ�����ÿһ�����СΪ512 ���ֽڡ�
					time_t st_atime; /* time of lastaccess          �ļ����һ�α���ȡ��ִ�е�ʱ��
					time_t st_mtime; /* time of last modification   �ļ����һ�α��޸ĵ�ʱ��
					time_t st_ctime; /* time of last change         i-node���һ�α����ĵ�ʱ��
				};
				
				st_mode�������������������
					S_IFMT   0170000 �ļ����͵�λ����
					S_IFSOCK 0140000 scoket
					S_IFLNK  0120000 ��������
					S_IFREG  0100000 һ���ļ�
					S_IFBLK  0060000 ����װ��
					S_IFDIR  0040000 Ŀ¼
					S_IFCHR  0020000 �ַ�װ��
					S_IFIFO  0010000 �Ƚ��ȳ�
					S_ISUID  04000 �ļ��ģ�set user-id on execution��λ
					S_ISGID  02000 �ļ��ģ�set group-id on execution��λ
					S_ISVTX  01000 �ļ���stickyλ
					S_IRUSR��S_IREAD�� 00400 �ļ������߾߿ɶ�ȡȨ��
					S_IWUSR��S_IWRITE��00200 �ļ������߾߿�д��Ȩ��
					S_IXUSR��S_IEXEC�� 00100 �ļ������߾߿�ִ��Ȩ��
					S_IRGRP 00040 �û���߿ɶ�ȡȨ��
					S_IWGRP 00020 �û���߿�д��Ȩ��
					S_IXGRP 00010 �û���߿�ִ��Ȩ��
					S_IROTH 00004 �����û��߿ɶ�ȡȨ��
					S_IWOTH 00002 �����û��߿�д��Ȩ��
					S_IXOTH 00001 �����û��߿�ִ��Ȩ��
				�������ļ�������POSIX �ж����˼����Щ���͵ĺ궨�壺
					S_ISLNK ��st_mode�� �ж��Ƿ�Ϊ��������
					S_ISREG ��st_mode�� �Ƿ�Ϊһ���ļ�
					S_ISDIR ��st_mode���Ƿ�ΪĿ¼
					S_ISCHR ��st_mode���Ƿ�Ϊ�ַ�װ���ļ�
					S_ISBLK ��s3e�� �Ƿ�Ϊ�Ƚ��ȳ�
					S_ISSOCK ��st_mode�� �Ƿ�Ϊsocket
 
				��һĿ¼����sticky λ��S_ISVTX�������ʾ�ڴ�Ŀ¼�µ��ļ�ֻ��
				�����ļ������ߡ���Ŀ¼�����߻�root��ɾ���������
				
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������������errno��
 * �������     ENOENT ����file_nameָ�����ļ�������
				ENOTDIR ·���е�Ŀ¼���ڵ�ȴ��������Ŀ¼
				ELOOP ���򿪵��ļ��й�������������⣬����Ϊ16 ��������
				EFAULT ����bufΪ��Чָ�룬ָ���޷����ڵ��ڴ�ռ�
				EACCESS ��ȡ�ļ�ʱ���ܾ�
				ENOMEM �����ڴ治��
				ENAMETOOLONG ����file_name��·������̫��
**************************************************/

#include <unistd.h>
char *getwd(char *buf);                  //use of getwd() is deprecated
char *get_current_dir_name(void);
char *getcwd(char * buf,size_t size);   //
/*************************************************
 * ����˵����   getcwd(ȡ�õ�ǰ�Ĺ���Ŀ¼)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   char * getcwd(char * buf,size_t size);
 * ����˵���� 	getcwd�����Ὣ��ǰ�Ĺ���Ŀ¼����·�����Ƶ�����buf ��ָ����
				��ռ䣬����size Ϊbuf �Ŀռ��С���ڵ��ô˺���ʱ��buf ��ָ
				���ڴ�ռ�Ҫ�㹻��������Ŀ¼����·�����ַ������ȳ�������
				size��С�����ֵNULL��errno��ֵ��ΪERANGE����������buf
				ΪNULL��getcwd������������size�Ĵ�С�Զ������ڴ棨ʹ��malloc
				���������������sizeҲΪ0����getcwd������������Ŀ¼����·��
				���ַ����̶������������õ��ڴ��С�����̿�����ʹ������ַ�
				��������free�������ͷŴ˿ռ䡣 
 * ����ֵ  ��   ִ�гɹ��򽫽�����Ƶ�����buf ��ָ���ڴ�ռ䣬���Ƿ����Զ�
                ���õ��ַ���ָ�롣ʧ�ܷ���NULL������������errno��
 * ����˵���� 
**************************************************/

int ftruncate(int fd,off_t length);
/*************************************************
 * ����˵����   ftruncate(�ı��ļ���С)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int ftruncate(int fd,off_t length);
 * ����˵���� 	ftruncate�����Ὣ����fdָ�����ļ���С��Ϊ����lengthָ���Ĵ�
				С������fdΪ�Ѵ򿪵��ļ������ʣ����ұ�������д��ģʽ�򿪵�
				�ļ������ԭ�����ļ���С�Ȳ���length���򳬹��Ĳ��ֻᱻɾȥ�� 
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EBADF ����fd�ļ�������Ϊ��Ч�Ļ���ļ��ѹرա�
                EINVAL ����fd Ϊһsocket �����ļ������Ǹ��ļ�������д��ģʽ�򿪡�
**************************************************/

int truncate(const char *path,off_t length);
/*************************************************
 * ����˵����   truncate(�ı��ļ���С)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int truncate(const char *path,off_t length);
 * ����˵���� 	truncate�����Ὣ����path ָ�����ļ���С��Ϊ����length ָ����
                ��С�����ԭ�����ļ���С�Ȳ���length���򳬹��Ĳ��ֻᱻɾȥ�� 
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EACCESS ����path��ָ�����ļ��޷���ȡ��
				EROFS   ��д����ļ�������ֻ���ļ�ϵͳ��
				EFAULT  ����pathָ�볬���ɴ�ȡ�ڴ�ռ�
				EINVAL  ����path�������Ϸ��ַ�
				ENAMETOOLONG ����path̫��
				ENOTDIR  ����path·������һĿ¼
				EISDIR   ����pathָ��һĿ¼
				ETXTBUSY ����path��ָ���ļ�Ϊ������򣬶�������ִ����
				ELOOP    ����path�й��������������
				EIO      I/O ��ȡ����
**************************************************/

int ftw(const char *dir, int (*fn) (const *file, const struct stat *sb, int flag), int depth)
/*************************************************
 * ����˵����   ftw(����Ŀ¼��)
 * ��ͷ�ļ���   #include <ftw.h>
 * ���庯����   int ftw(const char *dir, int (*fn) (const *file, const struct stat *sb, int flag), int depth)
 * ����˵���� 	ftw()��Ӳ���dirָ���� Ŀ¼��ʼ������һ���صݹ�ʽ������ Ŀ¼��
                ftw()�ᴫ����������fn(), ��һ������*fileָ��ʱ���ڵ� Ŀ¼·����
				                         �ڶ���������*sb, Ϊstat�ṹָ�룬
										 ����������Ϊ��꣬�����漸�ֿ���ֵ:
												FTW_F һ���ļ�
												FTW_D Ŀ¼
												FTW_DNR ���ɶ�ȡ�� Ŀ¼���� Ŀ¼���½���������
												FTW_SL ��������
												FTW_NS �޷�ȡ��stat�ṹ���ݣ��п����� Ȩ������

               ���һ������depth����ftw�����ڽ��б��� Ŀ¼ʱͬʱ�򿪵��ļ�����
			   
			       ftw()�ڱ���ʱÿһ�� Ŀ¼������Ҫһ���ļ������ʣ��������ʱ������depth�������������Ŀ��
			   �����������򲻶ϵع��ļ��Ϳ��ļ��������Եû���. 
			   
			       ���Ҫ����ftw()�ı�����fn()ֻ�践��һ����ֵ���ɣ���ֵͬʱҲ����ftw()�ķ���ֵ��
			   ����ftw()�������������е� Ŀ¼��Ȼ�󷵻�0.

 * ����ֵ  ��  �����ж��򷵻�fn()�����ķ���ֵ��ȫ�������򷵻�0�����д������򷵻�-1
 * ����˵���� 
**************************************************/

nftw(����Ŀ¼��)

int link (const char * oldpath,const char * newpath);
/*************************************************
 * ����˵����   link(�����ļ�Ӳ����)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int link (const char * oldpath,const char * newpath);
 * ����˵���� 	link�����Բ���newpathָ��������������һ���µ����ӣ�Ӳ���ӣ�
				������oldpath��ָ�����Ѵ����ļ����������newpathָ��������
				Ϊһ�Ѵ��ڵ��ļ��򲻻Ὠ�����ӡ� 
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EXDEV  ����oldpath��newpath���ǽ�����ͬһ�ļ�ϵͳ��
				EPERM  ����oldpath��newpath��ָ���ļ�ϵͳ��֧��Ӳ����
				EROFS  �ļ�������ֻ���ļ�ϵͳ��
				EFAULT ����oldpath��newpathָ�볬���ɴ�ȡ�ڴ�ռ䡣
				ENAMETOLLONG ����oldpath��newpath̫��
				ENOMEM  �����ڴ治��
				EEXIST  ����newpath��ָ���ļ����Ѵ��ڡ�
				EMLINK  ����oldpath��ָ���ļ��Ѵ����������Ŀ��
				ELOOP   ����pathname�й��������������
				ENOSPC  �ļ�ϵͳ��ʣ��ռ䲻�㡣
				EIO     I/O ��ȡ����
 * ����˵����   link()��������Ӳ�����޷���Խ��ͬ�ļ�ϵͳ�������Ҫ�����symlink()��
**************************************************/

int symlink( const char * oldpath,const char * newpath);
/*************************************************
 * ����˵����   symlink(�����ļ���������)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int symlink( const char * oldpath,const char * newpath);
 * ����˵���� 	symlink�����Բ���newpathָ��������������һ���µ����ӣ�����
				���ӣ�������oldpath��ָ�����Ѵ����ļ�������oldpathָ������
				����һ��Ҫ���ڣ��������newpathָ��������Ϊһ�Ѵ��ڵ��ļ�
				�򲻻Ὠ�����ӡ� 
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno��
 * ������룺   EPERM  ����oldpath��newpath��ָ���ļ�ϵͳ��֧�ַ�������
				EROFS  ������д��Ȩ�޵��ļ�������ֻ���ļ�ϵͳ��
				EFAULT ����oldpath��newpathָ�볬���ɴ�ȡ�ڴ�ռ䡣
				ENAMETOOLONG ����oldpath��newpath̫��
				ENOMEM �����ڴ治��
				EEXIST ����newpath��ָ���ļ����Ѵ��ڡ�
				EMLINK ����oldpath��ָ���ļ��Ѵﵽ���������Ŀ
				ELOOP  ����pathname�й��������������
				ENOSPC �ļ�ϵͳ��ʣ��ռ䲻��
				EIO    I/O ��ȡ����
 * ����˵����   
**************************************************/

int readlink(const char * path ,char * buf,size_t bufsiz);
/*************************************************
 * ����˵����   readlink(ȡ�÷���������ָ���ļ�)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int readlink(const char * path ,char * buf,size_t bufsiz);
 * ����˵���� 	readlink�����Ὣ����path�ķ����������ݴ浽����buf��ָ���ڴ�
				�ռ䣬���ص����ݲ�����NULL���ַ�����β�����Ὣ�ַ�������
				�������ء�������bufsiz С�ڷ������ӵ����ݳ��ȣ����������ݻᱻ�ضϡ�  
 * ����ֵ  ��   ִ�гɹ��򴫷���������ָ���ļ�·���ַ�����ʧ���򷵻�-1������������errno��
 * ������룺   EACCESS ȡ�ļ�ʱ���ܾ���Ȩ�޲���
				EINVAL  ����bufsiz Ϊ����
				EIO     I/O ��ȡ����
				ELOOP   ���򿪵��ļ��й�������������⡣
				ENAMETOOLONG ����path��·������̫��
				ENOENT  ����path��ָ�����ļ�������
				ENOMEM  �����ڴ治��
				ENOTDIR ����path·���е�Ŀ¼���ڵ�ȴ��������Ŀ¼��
**************************************************/

lchown(�ı��ļ���������)

realpath(�����Ŀ¼·��ת���ɾ���·��)


int remove(const char * pathname);
/*************************************************
 * ����˵����   remove(ɾ���ļ�)
 * ��ͷ�ļ���   #include <stdio.h>
 * ���庯����   int remove(const char * pathname);
 * ����˵���� 	remove()��ɾ������pathname ָ�����ļ����������pathname
				Ϊһ�ļ��������unlink()����������pathname ΪһĿ¼����
				����rmdir()��������ο�unlink()��rmdir()��
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ���򷵻�-1������ԭ�����errno
 * ������룺   EROFS  ��д����ļ�������ֻ���ļ�ϵͳ��
				EFAULT ����pathnameָ�볬���ɴ�ȡ�ڴ�ռ䡣
				ENAMETOOLONG ����pathname̫��
				ENOMEM �����ڴ治��
				ELOOP  ����pathname�й��������������
				EIO    I/O ��ȡ����
**************************************************/

int unlink(const char * pathname);
/*************************************************
 * ����˵����   unlink(ɾ���ļ�)
 * ��ͷ�ļ���   #include <unistd.h>
 * ���庯����   int unlink(const char * pathname);
 * ����˵���� 	unlink������ɾ������pathnameָ�����ļ���������ļ���Ϊ���
				���ӵ㣬�����������̴��˴��ļ����������й��ڴ��ļ����ļ�
				�����ʽԹرպ�Ż�ɾ�����������pathnameΪһ�������ӣ����
				���ӻᱻɾ����
 * ����ֵ  ��   �ɹ��򷵻�0��ʧ���򷵻�-1������ԭ�����errno
 * ������룺   EROFS  �ļ�������ֻ���ļ�ϵͳ�ڡ�
				EFAULT ����pathnameָ�볬���ɴ�ȡ�ڴ�ռ�
				ENAMETOOLONG ����pathname̫��
				ENOMEM �����ڴ治��
				ELOOP  ����pathname�й��������������
				EIO    I/O ��ȡ����
**************************************************/

/********************************
mkdir�������ڴ���Ŀ¼��
��ʽ���£�
	#include<sys/types.h>
	#include<sys/stat.h>
	#include<unistd.h>
	int mkdir(const char *pathname,mode_t mode);
rmdir()����ɾ��һ����Ŀ¼�����ĸ�ʽ���£�
	#include<unistd.h>
	int rmdir(const char *pathname);
ʹ��rmdir����ʱ��Ŀ¼����Ϊ�գ��������ʧ�ܣ���������-1���ɹ�ʱ����������0.

��������remove֮�����Ͽ����ļ���ɾ�����������ж��Ƿ�ռ�á�����ʹ��system("rm -rf filename").
****************************************/

int rename(const char *oldpath,const char *newpath);
/*************************************************
 * ����˵����   rename(�����ļ����ƻ�λ��)
 * ��ͷ�ļ���   #include <stdio.h>
 * ���庯����   int rename(const char * oldpath,const char * newpath);
 * ����˵���� 	rename()�Ὣ����oldpath ��ָ�����ļ����Ƹ�Ϊ����newpath
                ��ָ���ļ����ơ���newpath��ָ�����ļ��Ѵ��ڣ���ᱻɾ���� 
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������ԭ�����errno
**************************************************/

mode_t umask(mode_t mask);
/*************************************************
 * ����˵����   umask(���ý������ļ�ʱ��Ȩ������)
 * ��ͷ�ļ���   #include <sys/types.h>  #include <sys/stat.h>
 * ���庯����   mode_t umask(mode_t mask);
 * ����˵���� 	umask()�Ὣϵͳumaskֵ��ɲ���mask&0777 ���ֵ��Ȼ��
				��ǰ��umaskֵ���ء���ʹ��open()�������ļ�ʱ���ò���mode
				�������������ļ���Ȩ�ޣ����ǣ�mode&~umask����Ȩ��ֵ�����磬
				�ڽ����ļ�ʱָ���ļ�Ȩ��Ϊ0666��ͨ��umaskֵĬ��Ϊ022����
				���ļ�������Ȩ����Ϊ0666&��022��0644��Ҳ����rw-r--r-- 
 * ����ֵ  ��   �˵��ò����д���ֵ���ء�����ֵΪԭ��ϵͳ��umaskֵ��
 * ����˵���� 
**************************************************/

int utime(const char * filename,struct utimbuf * buf);
/*************************************************
 * ����˵����   utime(�޸��ļ��Ĵ�ȡʱ��͸���ʱ��)
 * ��ͷ�ļ���   #include <sys/types.h>  #include <utime.h>
 * ���庯����   int utime(const char * filename,struct utimbuf * buf);
 * ����˵���� 	utime���������޸Ĳ���filename�ļ�������inode��ȡʱ�䡣�ṹ
				utimbuf�������£�
				struct utimbuf{
					time_t actime;
					time_t modtime;
				};
                �������bufΪ��ָ�루NULL��������ļ��Ĵ�ȡʱ��͸���ʱ��ȫ������ΪĿǰʱ��  
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������������errno��
 * ������룺   EACCESS ��ȡ�ļ�ʱ���ܾ���Ȩ�޲���
				ENOENT ָ�����ļ������ڡ�
**************************************************/

int utimes(char * filename.struct timeval *tvp);
/*************************************************
 * ����˵����   utimes(�޸��ļ��Ĵ�ȡʱ��͸���ʱ��)
 * ��ͷ�ļ���   #include <sys/types.h>  #include <utime.h>
 * ���庯����   int utimes(char * filename.struct timeval *tvp);
 * ����˵���� 	utimes���������޸Ĳ���filename�ļ�������inode��ȡʱ����޸�
				ʱ�䣬�ṹtimeval�������£�
				struct timeval {
					long tv_sec;
					long tv_usec; //΢��
				};
				����tvp ָ������timeval �ṹ�ռ䣬��utime����ʹ�õ�utimebuf
				�ṹ�Ƚϣ�tvp[0].tc_sec ��Ϊutimbuf.actime��tvp]1].tv_sec Ϊutimbuf.modtime�� 
 * ����ֵ  ��   ִ�гɹ��򷵻�0��ʧ�ܷ���-1������������errno��
 * ������룺   EACCESS ��ȡ�ļ�ʱ���ܾ���Ȩ�޲���
				ENOENT ָ�����ļ�������
**************************************************/




