/*******************************
 *
 * 第七章 数据结构和算法
 *
**********************************/

char * crypt (const char *key,const char * salt);
/*************************************************
 * 功能说明： 将密码或数据编码
 * 表头文件： #define _XOPEN_SOURCE
              #include<unistd.h>
 * 定义函数： char * crypt (const char *key,const char * salt);
 * 函数说明： crypt（）将使用Data Encryption Standard (DES)演算法将参数key
			  所指的字符串加以编码，key 字符串长度仅取前8 个字符，超过此长度的字符没有意义。
			  参数salt为两个字符组成的字符串，由a-z、A-Z、0-9，“.”和“/”所组成，用来决定使用4096 种不同内建表格的哪一个。
			  函数执行成功后会返回指向编码过的字符串指针，参数key 所指的字符串不会有所更动。
			  编码过的字符串长度为13个字符，前两个字符为参数salt代表的字符串。		  
 * 返回值  ： 返回一个指向以NULL结尾的密码字符串。
 * 附加说明： 使用GCC编译时需加-lcrypt。
**************************************************/

void *bsearch(const void *key,const void *base,size_t nmemb,size_t
size,int (*compar) (const void*,const void*));
/*************************************************
 * 功能说明： 二元搜索
 * 表头文件： #include<stdlib.h>
 * 定义函数： void *bsearch(const void *key,const void *base,size_t nmemb,size_t
                            size,int (*compar) (const void*,const void*));
 * 函数说明： bsearch（）利用二元搜索从排序好的数组中查找数据。
              key 指向欲查找的关键数据，
			  base 指向要被搜索的数组开头地址，
			  nmemb 代表数组中的元素数量，
			  size 决定每一元素的大小
			  compar 为一函数指针，这个函数用来判断两个元素之间的大小关系，
			  若传给compar 的第一个参数所指的元素数据大于第二个参数所指的元素数据
			  则必须回传大于0的值，两个元素数据相等则回传0。
			  
 * 返回值  ： 找到关键数据则返回找到的地址，如果在数组中找不到关键数据则返回NULL。
 * 附加说明： 
**************************************************/

void *lfind (const void *key,const void *base,size_t *nmemb,size_t
size,int(* compar) (const void * ,const void *));
/*************************************************
 * 功能说明： 线性搜索
 * 表头文件： #include<stdlib.h>
 * 定义函数： void *lfind (const void *key,const void *base,size_t *nmemb,size_t
                         size,int(* compar) (const void * ,const void *));
 * 函数说明： 利用线性搜索在数组中从头至尾一项项查找数据。
              key 指向欲查找的关键数据，
			  base 指向要被搜索的数组开头地址，
			  nmemb 代表数组中的元素数量，
			  size 决定每一元素的大小
			  compar 为一函数指针，这个函数用来判断两个元素是否相同，
			  若传给compar两个元素数据相等则回传0，否则返回非0。
			  
			  lfind（）与lsearch（）不同点在于，当找不到关键数据时，
			  lfind()仅会返回NULL，而不会主动把该笔数据加入数组尾端。
			  
 * 返回值  ： 找到关键数据则返回找到的地址，如果在数组中找不到关键数据则返回NULL。
 * 附加说明： 
**************************************************/

void *lsearch(const void * key ,const void * base ,size_t *
       nmemb,size_t size, int ( * compar) (const void * ,const void *));
/*************************************************
 * 功能说明： 线性搜索
 * 表头文件： #include<stdlib.h>
 * 定义函数： void *lsearch(const void * key ,const void * base ,size_t *
                    nmemb,size_t size, int ( * compar) (const void * ,const void *));
 * 函数说明： 利用线性搜索在数组中从头至尾一项项查找数据。
              key 指向欲查找的关键数据，
			  base 指向要被搜索的数组开头地址，
			  nmemb 代表数组中的元素数量，
			  size 决定每一元素的大小
			  compar 为一函数指针，这个函数用来判断两个元素是否相同，
			  若传给compar两个元素数据相等则回传0，否则返回非0。
			  
			  如果lsearch（）找不到关键数据时会主动把该项数据加入数组里。
			  
 * 返回值  ： 找到关键数据则返回找到的该笔元素的四肢，如果在数组中找不到
              关键数据则将此关键数据加入数组，再把加入数组后的地址返回。
 * 附加说明： 如果lsearch（）找不到关键数据时会主动把该项数据加入数组里。
**************************************************/

void qsort(void * base,size_t nmemb,size_t size,
                    int ( * compar)(const void *, const void *));
/*************************************************
 * 功能说明： 利用快速排序法排列数组
 * 表头文件： #include<stdlib.h>
 * 定义函数： void qsort(void * base,size_t nmemb,size_t size,
                     int ( * compar)(const void *, const void *));
 * 函数说明： base 指向欲排序的数组开头地址
              nmemb 代表数组中的元素数量，
			  size 决定每一元素的大小
			  compar 为一函数指针，这个函数用来判断两个元素间的大小关系，
			  若传给compar 的第一个参数所指的元素数据大于第二个参数所指
			  的元素数据则必须回传大于零的值，两个元素数据相等则回传0。	  
 * 返回值  ： 
 * 附加说明： 
**************************************************/

int rand(void);
/*************************************************
 * 功能说明： 利用快速排序法排列数组
 * 表头文件： #include<stdlib.h>
 * 定义函数： int rand(void);
 * 函数说明： rand（）会返回一随机数值，范围在0 至RAND_MAX 间。在调用
			  此函数产生随机数前，必须先利用srand（）设好随机数种子，如
			  果未设随机数种子，rand（）在调用时会自动设随机数种子为1。
			  关于随机数种子请参考srand（）  
 * 返回值  ： 返回0 至RAND_MAX 之间的随机数值，RAND_MAX 定义在
              stdlib.h，其值为2147483647。
 * 附加说明： 
**************************************************/

void srand (unsigned int seed);
/*************************************************
 * 功能说明： 利用快速排序法排列数组
 * 表头文件： #include<stdlib.h>
 * 定义函数： void srand (unsigned int seed);
 * 函数说明： srand() 用来设置rand（）产生随机数时的随机数种子。参数seed
			  必须是个整数，通常可以利用geypid（）或time（0）的返回值来
			  当做seed。如果每次seed都设相同值，rand（）所产生的随机数值
			  每次就会一样.
 * 返回值  ： 
 * 附加说明：
       srand(time(NULL)) ;
**************************************************/

crypt(将密码或数据编码)
getpass(取得一密码输入)

bsearch(二元搜索)
hcreate(建立哈希表)
hdestory(删除哈希表)
hsearch(哈希表搜索)
insque(加入一项目至队列中)
lfind(线性搜索)
lsearch(线性搜索)
qsort(利用快速排序法排列数组)
rremque(从队列中删除一项目)
tdelete(从二叉树中删除数据)
tfind(搜索二叉树)
tsearch(二叉树)
twalk(走访二叉树)

drand48(产生一个正的浮点型随机数)
erand48(产生一个正的浮点型随机数)
initstate(建立随机数状态数组)
jrand48(产生一个长整型数随机数)
lcong48(设置48位运算的随机数种子)
lrand48(产生一个正的长整型随机数)
mrand48(产生一个长整型随机数)
nrand48(产生一个正的长整型随机数)
rand(产生随机数)
random(产生随机数)
seed48(设置48位运算的随机数种子)
setstate(建立随机数状态数组)
srand(设置随机数种子)
srand48(设置48位运算的随机数种子)
srandom(设置随机数种子)
