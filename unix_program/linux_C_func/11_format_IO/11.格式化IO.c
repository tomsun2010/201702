/*******************************
 *
 * 第 11 章 格式化IO
 *
**********************************/

printf(格式化输出数据)
scanf(格式化字符串输入)

int fprintf(FILE * stream, const char * format,.......);
/*************************************************
 * 功能说明： fprintf(格式化输出数据至文件)
 * 表头文件： # include <stdio.h>
 * 定义函数： int fprintf(FILE * stream, const char * format,.......);
 * 函数说明： fprintf（）会根据参数format 字符串来转换并格式化数据，
              然后将结果输出到参数stream 指定的文件中，
			  直到出现字符串结束（‘\0‘）为止。		  
 * 返回值  ： 成功则返回实际输出的字符数，失败则返回-1，错误原因存于errno中。
 * 附加说明： 
**************************************************/

int fscanf(FILE * stream ,const char *format,....);
/*************************************************
 * 功能说明： fscanf(格式化字符串输入)
 * 表头文件： # include <stdio.h>
 * 定义函数： int fscanf(FILE * stream ,const char *format,....);
 * 函数说明： fscanf（）会自参数stream的文件流中读取字符串，
              再根据参数format字符串来转换并格式化数据。	  
 * 返回值  ： 成功则返回参数数目，失败则返回-1，错误原因存于errno中。
 * 附加说明： 
**************************************************/

int sprintf( char *str,const char * format,.........);
/*************************************************
 * 功能说明： sprintf(格式化字符串复制)
 * 表头文件： # include <stdio.h>
 * 定义函数： int sprintf( char *str,const char * format,.........);
 * 函数说明： sprintf（）会根据参数format 字符串来转换并格式化数据，
              然后将结果复制到参数str 所指的字符串数组,
			  直到出现字符串结束（’\0’）为止。
 * 返回值  ： 成功则返回参数str 字符串长度，失败则返回-1，
              错误原因存于errno中。
 * 附加说明： 使用此函数得留意堆栈溢出，或改用snprintf（）。
**************************************************/

int sscanf (const char *str,const char * format,........);
/*************************************************
 * 功能说明： sscanf(格式化字符串输入)
 * 表头文件： # include <stdio.h>
 * 定义函数： int sscanf (const char *str,const char * format,........);
 * 函数说明： sscanf（）会将参数str 的字符串根据参数format字符串来转换并格
              式化数据。格式转换形式请参考scanf（）。
			  转换后的结果存于对应的参数内。
 * 返回值  ： 成功则返回参数数目，失败则返回-1，错误原因存于errno中。
**************************************************/


int vprintf(const char * format,va_list ap);
/*************************************************
 * 功能说明： vprintf(格式化输出数据)
 * 表头文件： #include <stdio.h>  #include <stdarg.h>
 * 定义函数： int vprintf(const char * format,va_list ap);
 * 函数说明： vprintf（）作用和printf（）相同，参数format格式也相同。
              va_list为不定个数的参数列
			  
 * 返回值  ： 成功则返回实际输出的字符数，失败则返回-1，
              错误原因存于errno中。
			  
			va_list ap;
			va_start(ap, format);
			vprintf(format, ap);
			va_end(ap);
**************************************************/

int vscanf(const char * format, va_list ap);
/*************************************************
 * 功能说明： vscanf(格式化字符串输入)
 * 表头文件： #include <stdio.h>  #include <stdarg.h>
 * 定义函数： int vscanf(const char * format, va_list ap);
 * 函数说明： vscanf()会将输入的数据根据参数format 字符串来转换并格式化数据. 
              转换后的结果存于对应的参数内
			  
 * 返回值  ： 成功则返回参数数目, 失败则返回-1, 错误原因存于errno 中。
			  
			va_list ap;
			va_start(ap, format);
			vscanf(format, ap);
			va_end(ap);
**************************************************/

int vfprintf(FILE *stream,const char * format,va_list ap);
/*************************************************
 * 功能说明： vfprintf(格式化输出数据至文件)
 * 表头文件： #include <stdio.h>  #include <stdarg.h>
 * 定义函数： int vfprintf(FILE *stream,const char * format,va_list ap);
 * 函数说明： vfprintf（）会根据参数format字符串来转换并格式化数据，然后将
              结果输出到参数stream指定的文件中，直到出现字符串结束（’\0’）为止。
			  
 * 返回值  ： 成功则返回实际输出的字符数，失败则返回-1，错误原因存于errno中。
**************************************************/

int vfscanf(FILE * stream,const char * format ,va_list ap);
/*************************************************
 * 功能说明： vfscanf(格式化字符串输入)
 * 表头文件： #include <stdio.h>  #include <stdarg.h>
 * 定义函数： int vfscanf(FILE * stream,const char * format ,va_list ap);
 * 函数说明： vfscanf（）会自参数stream 的文件流中读取字符串，再根据参数
			  format字符串来转换并格式化数据。格式转换形式请参考scanf（）。
			  转换后的结果存于对应的参数内.  
 * 返回值  ： 成功则返回参数数目，失败则返回-1，错误原因存于errno中。
**************************************************/

int vsprintf(char * str, const char * format, va_list ap);
/*************************************************
 * 功能说明： vsprintf(格式化字符串复制)
 * 表头文件： #include <stdio.h>
 * 定义函数： int vsprintf( char * str,const char * format,va_list ap);
 * 函数说明： vsprintf（）会根据参数format字符串来转换并格式化数据，然后将
              结果复制到参数str 所指的字符串数组，直到出现字符串结束（’\0’）为止。 
 * 返回值  ： 成功则返回参数str 字符串长度，失败则返回-1，错误原因存于errno中。
**************************************************/

int vsscanf(const char * str,const char * format,va_list ap);
/*************************************************
 * 功能说明： vsscanf(格式化字符串输入)
 * 表头文件： #include <stdio.h>
 * 定义函数： int vsscanf(const char * str,const char * format,va_list ap);
 * 函数说明： vsscanf（）会将参数str 的字符串根据参数format 字符串来转换并格式化数据.
 * 返回值  ： 成功则返回参数数目，失败则返回-1，错误原因存于errno中。
**************************************************/

int snprintf(char *str, size_t size, const char *format, ...)
/*************************************************
 * 功能说明： snprintf(格式化字符串复制)
 * 表头文件： #include <stdio.h> 
 * 定义函数： int snprintf(char *str, size_t size, const char *format, ...);
 * 函数说明： 将可变个参数(...)按照format格式化成字符串，然后将其复制到str中
			  (1) 如果格式化后的字符串长度 < size，则将此字符串全部复制到str中，
			      并给其后添加一个字符串结束符('\0')；
			  (2) 如果格式化后的字符串长度 >= size，则只将其中的(size-1)个字符复制到str中，
			      并给其后添加一个字符串结束符('\0')，返回值为欲写入的字符串长度。
 * 返回值  ： 若成功则返回欲写入的字符串长度，若出错则返回负值。
 * 补充说明： strcpy()  sprintf()  strcat() 存在安全隐患， 
              其对应的安全版为：
              strncpy() snprintf() strncat()
**************************************************/

int _vsnprintf(char* str, size_t size, const char* format, va_list ap);
/*************************************************
 * 功能说明： vsnprintf(格式化字符串复制)
 * 表头文件： # include <stdio.h> # include <stdarg.h>
 * 定义函数： int _vsnprintf(char* str, size_t size, const char* format, va_list ap);
 * 函数说明： 将可变参数格式化输出到一个字符数组。
			  char *str [out],把生成的格式化的字符串存放在这里.
			  size_t size [in], str可接受的最大字符数[1]  (非字节数，UNICODE一个字符两个字节),防止产生数组越界.
			  const char *format [in], 指定输出格式的字符串，它决定了你需要提供的可变参数的类型、个数和顺序。
			  va_list ap [in], va_list变量. va:variable-argument:可变参数		  
 * 返回值  ： 执行成功，返回写入到字符数组str中的字符个数（不包含终止符），
              最大不超过size；执行失败，返回负值，并置errno.
**************************************************/
