/********************************************************************************************************
Copyright: wuyong
Author: wuyong
Date: 2018-05-17
Description:本例程提供了C/C++的字符、字符串的输入输出 基本操作，以及C/C++之间的互相转换，字符串与数值之间
            的转换，为面试笔试编程题提供便利。
*********************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------
                                                   C++
----------------------------------------------------------------------------------------------------------*/
#include <iostream>  // cout cin >> <<

#include <string>    //定义string这一顺序容器及其相关操作
/*

1. 定义及初始化：
	string s;          //空串
	string s(str);     //复制构造
	string s(str, index)       //  将字符串始于index的子串初始化s 
	string s(str, index, strlen) //  将字符串始于index的长度为strlen的子串初始化s
	string s(cstr)   //用c风格的字符串初始化s
	string s(cstr, strlen)   //将c风格的前strlen个字符的子串作为初始化的值；
	string s(num, c)        //num 个c 初始化s
	string s(beg, end)     //用一对迭代器初始化字符串s
	s1.assign()    //赋新值， assign(str, index1, index2); assign("");assign(num, c)
	s.~string()            //销毁所有字符，并释放空间

2. 字符串的字符操作
	const char &operator[](int n)const;     // str[num];   另有非常量版本
	const char &at(int n)const;             // str.at(num);  另有非常量版本

	const char *c_str()const;//返回一个以null终止的c字符串
	const char *data()const;//返回一个非null终止的c字符数组

3. 字符串特性描述：
	int size()const;        //返回当前字符串的大小
	int length()const;       //返回当前字符串的长度
	bool empty()const;        //当前字符串是否为空
	int capacity()const;    //返回当前容量（即string中不必增加内存即可存放的元素个数）
	int max_size()const;    //返回string对象中可存放的最大字符串的长度
	void resize(int len,char c);//把字符串当前大小置为len，并用字符c填充不足的部分

4. string的输入输出操作
	string类重载运算符operator>>用于输入，同样重载运算符operator<<用于输出操作。
	getline(istream &in,string &s);用于从输入流in中读取字符串到s中，以换行符'\n'分开。 

5. string的赋值：
	string &operator=(const string &s);//把字符串s赋给当前字符串
	string &assign(const char *s);//用c类型字符串s赋值
	string &assign(const string &s);//把字符串s赋给当前字符串
	string &assign(const_iterator first,const_itertor last);//把first和last迭代器之间的部分赋给字符串

6. string的连接：
	string &operator+=(const string &s);//把字符串s连接到当前字符串的结尾
	string &append(const char *s);            //把c类型字符串s连接到当前字符串结尾
	string &append(const string &s);    //同operator+=()
	string &append(const_iterator first,const_iterator last);//把迭代器first和last之间的部分连接到当前字符串的结尾

7. string的比较：
	bool operator==(const string &s1,const string &s2)const;//比较两个字符串是否相等
	运算符">","<",">=","<=","!="均被重载用于字符串的比较；
	int compare(const string &s) const;//成员函数， 比较当前字符串和s的大小 compare函数在>时返回1，<时返回-1，==时返回0  
	
8. string的子串：
	string substr(int pos = 0,int n = npos) const;//返回pos开始的n个字符组成的字符串

9. string的交换操作：
	void swap(string &s2);    //交换当前字符串与s2的值，还有非成员版本swap(s1, s2)

10. string的查找函数：
	int find(char c, int pos = 0) const;//从pos开始查找字符c在当前字符串的位置
	int find(const char *s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
	int find(const char *s, int pos, int n) const;//从pos开始查找字符串s中前n个字符在当前串中的位置
	int find(const string &s, int pos = 0) const;//从pos开始查找字符串s在当前串中的位置
	//查找成功时返回所在位置，失败返回string::npos的值
	int rfind(char c, int pos = npos) const;//从pos开始从后向前查找字符c在当前串中的位置
	int rfind(const char *s, int pos = npos) const;
	int rfind(const char *s, int pos, int n = npos) const;
	int rfind(const string &s,int pos = npos) const;
	//从pos开始从后向前查找字符串s中前n个字符组成的字符串在当前串中的位置，成功返回所在位置，失败时返回string::npos的值
	int find_first_of(char c, int pos = 0) const;//从pos开始查找字符c第一次出现的位置
	int find_first_of(const char *s, int pos = 0) const;
	int find_first_of(const char *s, int pos, int n) const;
	int find_first_of(const string &s,int pos = 0) const;
	//从pos开始查找当前串中第一个在s的前n个字符组成的数组里的字符的位置。查找失败返回string::npos
	int find_first_not_of(char c, int pos = 0) const;
	int find_first_not_of(const char *s, int pos = 0) const;
	int find_first_not_of(const char *s, int pos,int n) const;
	int find_first_not_of(const string &s,int pos = 0) const;
	//从当前串中查找第一个不在串s中的字符出现的位置，失败返回string::npos
	int find_last_of(char c, int pos = npos) const;
	int find_last_of(const char *s, int pos = npos) const;
	int find_last_of(const char *s, int pos, int n = npos) const;
	int find_last_of(const string &s,int pos = npos) const;
	int find_last_not_of(char c, int pos = npos) const;
	int find_last_not_of(const char *s, int pos = npos) const;
	int find_last_not_of(const char *s, int pos, int n) const;
	int find_last_not_of(const string &s,int pos = npos) const;
	//find_last_of和find_last_not_of与find_first_of和find_first_not_of相似，只不过是从后向前查找

11. string类的替换函数：
	string &replace(int p0, int n0,const char *s);//删除从p0开始的n0个字符，然后在p0处插入串s
	string &replace(int p0, int n0,const char *s, int n);//删除p0开始的n0个字符，然后在p0处插入字符串s的前n个字符
	string &replace(int p0, int n0,const string &s);//删除从p0开始的n0个字符，然后在p0处插入串s
	string &replace(int p0, int n0,const string &s, int pos, int n);//删除p0开始的n0个字符，然后在p0处插入串s中从pos开始的n个字符
	string &replace(int p0, int n0,int n, char c);//删除p0开始的n0个字符，然后在p0处插入n个字符c
	string &replace(iterator first0, iterator last0,const char *s);//把[first0，last0）之间的部分替换为字符串s
	string &replace(iterator first0, iterator last0,const char *s, int n);//把[first0，last0）之间的部分替换为s的前n个字符
	string &replace(iterator first0, iterator last0,const string &s);//把[first0，last0）之间的部分替换为串s
	string &replace(iterator first0, iterator last0,int n, char c);//把[first0，last0）之间的部分替换为n个字符c
	string &replace(iterator first0, iterator last0,const_iterator first, const_iterator last);//把[first0，last0）之间的部分替换成[first，last）之间的字符串

12. string类的插入函数：
	string &insert(int p0, const char *s);
	string &insert(int p0, const char *s, int n);
	string &insert(int p0,const string &s);
	string &insert(int p0,const string &s, int pos, int n);
	//前4个函数在p0位置插入字符串s中pos开始的前n个字符
	string &insert(int p0, int n, char c);//此函数在p0处插入n个字符c
	iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置
	void insert(iterator it, const_iterator first, const_iterator last);//在it处插入[first，last）之间的字符
	void insert(iterator it, int n, char c);//在it处插入n个字符c

13. string类的删除函数
	iterator erase(iterator first, iterator last);//删除[first，last）之间的所有字符，返回删除后迭代器的位置
	iterator erase(iterator it);//删除it指向的字符，返回删除后迭代器的位置
	string &erase(int pos = 0, int n = npos);//删除pos开始的n个字符，返回修改后的字符串

14. string类的迭代器处理：
	string类提供了向前和向后遍历的迭代器iterator，迭代器提供了访问各个字符的语法，类似于指针操作，迭代器不检查范围。
	用string::iterator或string::const_iterator声明迭代器变量，const_iterator不允许改变迭代的内容。常用迭代器函数有：
	const_iterator begin()const;
	iterator begin();                //返回string的起始位置
	const_iterator end()const;
	iterator end();                    //返回string的最后一个字符后面的位置
	const_iterator rbegin()const;
	iterator rbegin();                //返回string的最后一个字符的位置
	const_iterator rend()const;
	iterator rend();                    //返回string第一个字符位置的前面
	rbegin和rend用于从后向前的迭代访问，通过设置迭代器string::reverse_iterator,string::const_reverse_iterator实现

15. 通过定义ostringstream和istringstream变量实现，<sstream>头文件中
	例如：
    string input("hello,this is a test");
    istringstream is(input);
    string s1,s2,s3,s4;
    is>>s1>>s2>>s3>>s4;//s1="hello,this",s2="is",s3="a",s4="test"
    ostringstream os;
    os<<s1<<s2<<s3<<s4;
    cout<<os.str();

*/
#include <cctype>    //定义了字符字符字符字符函数库的一些函数，c++的cctype 是C中的ctype的升级版
/*

isxdigit()	如果参数是十六进制的数字，即0～9、a~f、A~F，该函数返回true

isdigit()	如果参数是数字（0～9），该函数返回true
isalpha()	如果参数是字母，该函数返回真
isalnum()   如果参数是字母数字，即字母或数字，该函数返回true

isblank()	如果参数是空格或水平制表符，该函数返回true
isspace()   如果参数是标准空白字符，如空格、进纸、换行符、回车、水平制表符或者垂直制表符，该函数返回true

islower()	如果参数是小写字母，该函数返回true
isupper()	如果参数是大写字母，该函数返回true

tolower()	如果参数是大写字符，则返回其小写，否则返回该参数
toupper()	如果参数是小写字母，则返回其大写，否则返回该参数

*/

/*--------------------------------------------------------------------------------------------------------
                                              C
----------------------------------------------------------------------------------------------------------*/
#include <stdio.h>   //定义一系列函数进行带缓冲的标准输入输出,
/*

//遇到空格停止输入
scanf()     格式化输入 int scanf(char *format, [,argument,....])   scanf("%3d, %3.3f", &Inum, &dNum); scanf("%s", ptr);
            %d： 十进制数    %x： 十六进制数     %lf %f: 浮点数     %c：字符     %s：字符串     
printf()    格式化输出， int printf(char *format, [,argument,...]) printf("%c", c); printf("%s", ptr);
            %d： 十进制数    %x： 十六进制数     %d %f: 浮点数     %c：字符     %s：字符串

//vs安全版本的sscanf_s("aa", "%s", str, sizeof(str)); //要加入buffer的大小，防止溢出；
sscanf()    提取带空格字符串，格式化提取 int sscanf(const char* str,const char* format, [,argument,...] )
            (1) sscanf("aa bb cc", "%s%s%s", ptr1, ptr2, ptr3);    //*ptr1 , *ptr2, *ptr3 = "aa", "bb", "cc" 提取空格隔开
			(2) sscanf("zhoue3456", "%4s", str);                   //*str = "zhou"
			(3) sscanf("654321abcdefABCDEF", "%[0-9a-z]", str);    //*str = "654321abcdef"; 
			(4) sscanf("zhou456hedf", "%[^6]", str);                //*str = "zhou45"; 
			(5) sscanf("zhou456hedf", "%[^1-9]", str);              //*str = "zhou"
			(6) sscanf("2018.05.18", "%d.%d.%d", &num1, &num2, &num3)  //num1 = 2018 num2 = 5 num3 = 18;

//vs安全版本的sprintf_s(str, "%s", [,argument,...], sizeof(str)); //要加入buffer的大小，防止溢出；
sprintf()   将格式化的数据写入字符串，int sprintf(char *buffer, char *format, [,argument,...])  //返回字符串长度
            (1) sprintf(str, "%d", 1024)    // *str = "1024"
			(2) sprintf(str, "0x%x", 1024)  //*str = "0x400"
			(3) sprintf(str, "%s %s", "hello", "world") // *str = "hello world"
			(4) sprintf(str, "%3d", 1024) //*str = "102"
			(5) sprintf(str, "%10.3f", 3.1415926) // *str = "3.142"  //%m.nf  m:总长度， n：小数点的长度

gets()      char *gets(char *s)  //
            (1) gets(buffer); //遇换行符结束，丢弃换行符，并在读取字符串末尾加上'\0',不建议使用

puts()      int puts(const char * string) //
			(1) puts(buffer) //只能输出字符串，输出自动换行，相当于printf("%s\n", str);

*/
#include <io.h>      //主要定义一些对缓冲区进行读写，例：
/*

write()     //暂时不总结,
read()      //暂时不总结

open()      //暂时不总结
close()     //暂时不总结

*/
#include <stdlib.h>  //C 标准库头文件， 定义了五种类型和一些宏， 通用工具函数， 
/*
类型：size_t、wchar_t、div_t、ldiv_t、lldiv_t
宏：EXIT_FAILURE、EXIT_SUCCESS、RAND_MAX、MB_CUR_MAX等
常用函数：

malloc()         //  void *malloc(size_t size);
free()           //  void free(void *ptr);

atoi()           //  int atoi(const char *str);    解析错误，返回0
atol()           //  long atol(const char *str);   解析错误，返回0
atof()           //  float atof(const char *str);   解析错误，返回0

itoa()           //  char* itoa(int value, char* buffer, int radix);     radix 进制参数

strtod()         //  double strtod(const char* str, char **endptr); //自动跳过前面的空白字符（tab space等），
                     直到遇到数字或者正负号开始 到非数字或者'\0'转换结束 ，endptr 用以传回导致转换结束的字符，null，表示参数无效   
strtol()         //  long int strtol(const char *nptr, char**endptr, int base)   与上一致
strtoul()        //  uinsigned long int strtol(const char *nptr, char**endptr, int base)   与上一致

srand()          //  srand()为rand()提供种子,若srand(13)的参数一定，那么每次产生的随机数一致，通常
                     srand((unsigned)time(null)) 种下随机数的种子
rand()           //  rand() % 100 + 1，产生1 - 100s之间的随机数；

exit()           //  exit(num)  num == 0 表示正常退出， num != 0 表示异常退出， num值将会传递给操作系统
system()         //  system("pause")  

*/
#include <string.h>  //C语言中处理字符串的函数
/*
strlen()         //  unsigned int strlen(char *) 
strcat()         //  char* strcat(char *dest, char *src)     //目的字符串， src源字符串， 连接字符串 char* strcat_s(char *dest, size_t size, char *src) ;//VS版本
strcmp()         //  int strcmp(const char *s1, const char *s2);  //  s1 < s2 : 负数， s1 > s2 : 正数， s1 == s2 : 0  
strcpy()         //  char *strcpy(char *dest, const char* src); 
strchr()         //  unsigned int strchr(char *str, char c);   //查找字符c在字符串中的下标；

//安全版本的这些函数 ：
strnlen()       //unsigned int strnlen(const char* str, size_t size_max);
strncat()       //char* strncat(char *dest, char *src, size_t size_max);
strncmp()       //int strncmp(const char *s1, const char *s2, size_t, size_max);  //  s1 < s2 : 负数， s1 > s2 : 正数， s1 == s2 : 0  
strncpy()       //char* strncpy(char *dest, char *src, size_t size_max);

*/
#include <ctype.h>   //同cctype

#include <time.h>    //产生随机数时，会用到，time(null)

/*--------------------------------------------------------------------------------------------------------
                                              C  <----> C++
----------------------------------------------------------------------------------------------------------*/
/*
(1) C string ------> C++ string
	string str(char *);

(2) C++ string ------> C string
	const char *ptr = str.c_str(); or char pstr[100]; strncpy(pstr, str_c_str(), sizeof(pstr));
*/

/*--------------------------------------------------------------------------------------------------------
	                              C字符串向数值之间的转换
----------------------------------------------------------------------------------------------------------*/
/*

（1） 数值------->字符串型
	1）使用模板 + ostringstream:
			template<typename T> string toString(const T& t)
			{
				ostringstream oss;  //创建一个格式化输出流
				oss<<t;             //把值传递如流中
				return oss.str();   
			}
			cout<<toString(14.2)<<endl;  //实型->string：输出14.2

	2）使用标准库函数std::to_string(),可将数值类型转换为string 头文件<string >
			string to_string (int val);
			string to_string (long val);
			string to_string (long long val);
			string to_string (unsigned val);
			string to_string (unsigned long val);
			string to_string (unsigned long long val);
			string to_string (float val);
			string to_string (double val);
			string to_string (long double val);

（2）字符串-------->数值型的转换
		1）使用函数模板+ istringstream：将string类型转换为常用的数值类型
			template <class Type>  
			Type stringToNum(const string& str)
			{  
				istringstream iss(str);  
				Type num;  
				iss >> num;  
				return num;      
			}
		2）使用c标准库：将string转为char*，再通过相应的类型转换
			string str; const char *pstr = str.c_str();  //再使用c库里面的atoi atol atof等等	
		3）使用c++标准库：在<string>中：
			int stoi (const string& str, size_t* idx = 0, int base = 10);
			int stoi (const wstring& str, size_t* idx = 0, int base = 10);
			long stol (const string& str, size_t* idx = 0, int base = 10);
			long stol (const wstring& str, size_t* idx = 0, int base = 10);
			unsigned long stoul (const string& str, size_t* idx = 0, int base = 10);
			unsigned long stoul (const wstring& str, size_t* idx = 0, int base = 10);
			long long stoll (const string& str, size_t* idx = 0, int base = 10);
			long long stoll (const wstring& str, size_t* idx = 0, int base = 10);
			unsigned long long stoull (const string& str, size_t* idx = 0, int base = 10);
			unsigned long long stoull (const wstring& str, size_t* idx = 0, int base = 10);
			float stof (const string& str, size_t* idx = 0);
			float stof (const wstring& str, size_t* idx = 0);
			double stod (const string& str, size_t* idx = 0);
			double stod (const wstring& str, size_t* idx = 0);
			long double stold (const string& str, size_t* idx = 0);
			long double stold (const wstring& str, size_t* idx = 0);

*/

/*--------------------------------------------------------------------------------------------------------
										C字符、字符串向数值之间的转换
----------------------------------------------------------------------------------------------------------*/
/*
（1）数值型------->字符、字符串型：
		1）整型数值型向字符型转换：
			int a = 1; char c = a + '0'；
		2）整型数值向字符串型转换：
			char *itoa(int value, char* string, int radix);   //int to array 的转换，char* 同*string 指向返回的字符串，value整型数值，radix : 进制 ，比如10进制，16进制等
		3）浮点数型向字符串型转换：
			char *gcvt(double number, size_t ndigits, char *buf); //char* 同char* buf一样，存放返回的字符串，ndigits：表示显示的位数；

			char *ecvt(double value, int ndigitIT, int *dec, int *sign);   //将浮点数转换为长度为ndigitIT的字符串，没有小数点，超过value的数字长度不补零

			char *fcvt(double value, int ndigitIT, int *dec, *sign);     //将浮点数转换为长度为ndigitIT的字符串，没有小数点，超过value的数值长度，自动补零

（2）字符、字符串型>>>>数值型：
		1）字符>>>>>数值型：
			char c = 'a'; int num = c - '0';
		2）字符串>>>>数值型：
			atof(), atoi(), atol(), atoll();  //头文件 ctype.h，在前文中有讲

*/

/*--------------------------------------------------------------------------------------------------------
                                             关于输入输出函数的一些总结
----------------------------------------------------------------------------------------------------------*/
/*

(1) scanf()       以Space、Enter、Tab结束一次输入，不会舍弃最后的回车符（即回车符会残留在缓冲区中）；
(2) getchar()     以Enter结束输入，也不会舍弃最后的回车符；
(3) gets()        以Enter结束输入，接受空格，会舍弃最后的回车符！                        ......舍弃回车符.......

(4) cin >>        以Space、Enter、Tab结束一次输入，会舍弃最后的回车符！                  ......舍弃回车符.......
(5) cin.get()     以Enter结束输入，也不会舍弃最后的回车符；cin.get(), cin.get(char ch), cin.get(array_name, Arsize) //char a[20]; cin.get(a, 10);
(6) cin.getline() 以Enter结束输入, 会舍弃最后的回车符！                                  ......舍弃回车符.......

*/

int main()
{
	std::string str1("2018-05-19");
	char str2[100] = "powered by wuyong";
	std::cout << str1 << std::endl;
	printf("%s\n", str2);

	system("pause");
	return 0;
}