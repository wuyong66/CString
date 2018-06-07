/********************************************************************************************************
Copyright: wuyong
Author: wuyong
Date: 2018-05-17
Description:�������ṩ��C/C++���ַ����ַ������������ �����������Լ�C/C++֮��Ļ���ת�����ַ�������ֵ֮��
            ��ת����Ϊ���Ա��Ա�����ṩ������
*********************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------
                                                   C++
----------------------------------------------------------------------------------------------------------*/
#include <iostream>  // cout cin >> <<

#include <string>    //����string��һ˳������������ز���
/*

1. ���弰��ʼ����
	string s;          //�մ�
	string s(str);     //���ƹ���
	string s(str, index)       //  ���ַ���ʼ��index���Ӵ���ʼ��s 
	string s(str, index, strlen) //  ���ַ���ʼ��index�ĳ���Ϊstrlen���Ӵ���ʼ��s
	string s(cstr)   //��c�����ַ�����ʼ��s
	string s(cstr, strlen)   //��c����ǰstrlen���ַ����Ӵ���Ϊ��ʼ����ֵ��
	string s(num, c)        //num ��c ��ʼ��s
	string s(beg, end)     //��һ�Ե�������ʼ���ַ���s
	s1.assign()    //����ֵ�� assign(str, index1, index2); assign("");assign(num, c)
	s.~string()            //���������ַ������ͷſռ�

2. �ַ������ַ�����
	const char &operator[](int n)const;     // str[num];   ���зǳ����汾
	const char &at(int n)const;             // str.at(num);  ���зǳ����汾

	const char *c_str()const;//����һ����null��ֹ��c�ַ���
	const char *data()const;//����һ����null��ֹ��c�ַ�����

3. �ַ�������������
	int size()const;        //���ص�ǰ�ַ����Ĵ�С
	int length()const;       //���ص�ǰ�ַ����ĳ���
	bool empty()const;        //��ǰ�ַ����Ƿ�Ϊ��
	int capacity()const;    //���ص�ǰ��������string�в��������ڴ漴�ɴ�ŵ�Ԫ�ظ�����
	int max_size()const;    //����string�����пɴ�ŵ�����ַ����ĳ���
	void resize(int len,char c);//���ַ�����ǰ��С��Ϊlen�������ַ�c��䲻��Ĳ���

4. string�������������
	string�����������operator>>�������룬ͬ�����������operator<<�������������
	getline(istream &in,string &s);���ڴ�������in�ж�ȡ�ַ�����s�У��Ի��з�'\n'�ֿ��� 

5. string�ĸ�ֵ��
	string &operator=(const string &s);//���ַ���s������ǰ�ַ���
	string &assign(const char *s);//��c�����ַ���s��ֵ
	string &assign(const string &s);//���ַ���s������ǰ�ַ���
	string &assign(const_iterator first,const_itertor last);//��first��last������֮��Ĳ��ָ����ַ���

6. string�����ӣ�
	string &operator+=(const string &s);//���ַ���s���ӵ���ǰ�ַ����Ľ�β
	string &append(const char *s);            //��c�����ַ���s���ӵ���ǰ�ַ�����β
	string &append(const string &s);    //ͬoperator+=()
	string &append(const_iterator first,const_iterator last);//�ѵ�����first��last֮��Ĳ������ӵ���ǰ�ַ����Ľ�β

7. string�ıȽϣ�
	bool operator==(const string &s1,const string &s2)const;//�Ƚ������ַ����Ƿ����
	�����">","<",">=","<=","!="�������������ַ����ıȽϣ�
	int compare(const string &s) const;//��Ա������ �Ƚϵ�ǰ�ַ�����s�Ĵ�С compare������>ʱ����1��<ʱ����-1��==ʱ����0  
	
8. string���Ӵ���
	string substr(int pos = 0,int n = npos) const;//����pos��ʼ��n���ַ���ɵ��ַ���

9. string�Ľ���������
	void swap(string &s2);    //������ǰ�ַ�����s2��ֵ�����зǳ�Ա�汾swap(s1, s2)

10. string�Ĳ��Һ�����
	int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
	int find(const char *s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
	int find(const char *s, int pos, int n) const;//��pos��ʼ�����ַ���s��ǰn���ַ��ڵ�ǰ���е�λ��
	int find(const string &s, int pos = 0) const;//��pos��ʼ�����ַ���s�ڵ�ǰ���е�λ��
	//���ҳɹ�ʱ��������λ�ã�ʧ�ܷ���string::npos��ֵ
	int rfind(char c, int pos = npos) const;//��pos��ʼ�Ӻ���ǰ�����ַ�c�ڵ�ǰ���е�λ��
	int rfind(const char *s, int pos = npos) const;
	int rfind(const char *s, int pos, int n = npos) const;
	int rfind(const string &s,int pos = npos) const;
	//��pos��ʼ�Ӻ���ǰ�����ַ���s��ǰn���ַ���ɵ��ַ����ڵ�ǰ���е�λ�ã��ɹ���������λ�ã�ʧ��ʱ����string::npos��ֵ
	int find_first_of(char c, int pos = 0) const;//��pos��ʼ�����ַ�c��һ�γ��ֵ�λ��
	int find_first_of(const char *s, int pos = 0) const;
	int find_first_of(const char *s, int pos, int n) const;
	int find_first_of(const string &s,int pos = 0) const;
	//��pos��ʼ���ҵ�ǰ���е�һ����s��ǰn���ַ���ɵ���������ַ���λ�á�����ʧ�ܷ���string::npos
	int find_first_not_of(char c, int pos = 0) const;
	int find_first_not_of(const char *s, int pos = 0) const;
	int find_first_not_of(const char *s, int pos,int n) const;
	int find_first_not_of(const string &s,int pos = 0) const;
	//�ӵ�ǰ���в��ҵ�һ�����ڴ�s�е��ַ����ֵ�λ�ã�ʧ�ܷ���string::npos
	int find_last_of(char c, int pos = npos) const;
	int find_last_of(const char *s, int pos = npos) const;
	int find_last_of(const char *s, int pos, int n = npos) const;
	int find_last_of(const string &s,int pos = npos) const;
	int find_last_not_of(char c, int pos = npos) const;
	int find_last_not_of(const char *s, int pos = npos) const;
	int find_last_not_of(const char *s, int pos, int n) const;
	int find_last_not_of(const string &s,int pos = npos) const;
	//find_last_of��find_last_not_of��find_first_of��find_first_not_of���ƣ�ֻ�����ǴӺ���ǰ����

11. string����滻������
	string &replace(int p0, int n0,const char *s);//ɾ����p0��ʼ��n0���ַ���Ȼ����p0�����봮s
	string &replace(int p0, int n0,const char *s, int n);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�������ַ���s��ǰn���ַ�
	string &replace(int p0, int n0,const string &s);//ɾ����p0��ʼ��n0���ַ���Ȼ����p0�����봮s
	string &replace(int p0, int n0,const string &s, int pos, int n);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0�����봮s�д�pos��ʼ��n���ַ�
	string &replace(int p0, int n0,int n, char c);//ɾ��p0��ʼ��n0���ַ���Ȼ����p0������n���ַ�c
	string &replace(iterator first0, iterator last0,const char *s);//��[first0��last0��֮��Ĳ����滻Ϊ�ַ���s
	string &replace(iterator first0, iterator last0,const char *s, int n);//��[first0��last0��֮��Ĳ����滻Ϊs��ǰn���ַ�
	string &replace(iterator first0, iterator last0,const string &s);//��[first0��last0��֮��Ĳ����滻Ϊ��s
	string &replace(iterator first0, iterator last0,int n, char c);//��[first0��last0��֮��Ĳ����滻Ϊn���ַ�c
	string &replace(iterator first0, iterator last0,const_iterator first, const_iterator last);//��[first0��last0��֮��Ĳ����滻��[first��last��֮����ַ���

12. string��Ĳ��뺯����
	string &insert(int p0, const char *s);
	string &insert(int p0, const char *s, int n);
	string &insert(int p0,const string &s);
	string &insert(int p0,const string &s, int pos, int n);
	//ǰ4��������p0λ�ò����ַ���s��pos��ʼ��ǰn���ַ�
	string &insert(int p0, int n, char c);//�˺�����p0������n���ַ�c
	iterator insert(iterator it, char c);//��it�������ַ�c�����ز�����������λ��
	void insert(iterator it, const_iterator first, const_iterator last);//��it������[first��last��֮����ַ�
	void insert(iterator it, int n, char c);//��it������n���ַ�c

13. string���ɾ������
	iterator erase(iterator first, iterator last);//ɾ��[first��last��֮��������ַ�������ɾ�����������λ��
	iterator erase(iterator it);//ɾ��itָ����ַ�������ɾ�����������λ��
	string &erase(int pos = 0, int n = npos);//ɾ��pos��ʼ��n���ַ��������޸ĺ���ַ���

14. string��ĵ���������
	string���ṩ����ǰ���������ĵ�����iterator���������ṩ�˷��ʸ����ַ����﷨��������ָ�����������������鷶Χ��
	��string::iterator��string::const_iterator����������������const_iterator������ı���������ݡ����õ����������У�
	const_iterator begin()const;
	iterator begin();                //����string����ʼλ��
	const_iterator end()const;
	iterator end();                    //����string�����һ���ַ������λ��
	const_iterator rbegin()const;
	iterator rbegin();                //����string�����һ���ַ���λ��
	const_iterator rend()const;
	iterator rend();                    //����string��һ���ַ�λ�õ�ǰ��
	rbegin��rend���ڴӺ���ǰ�ĵ������ʣ�ͨ�����õ�����string::reverse_iterator,string::const_reverse_iteratorʵ��

15. ͨ������ostringstream��istringstream����ʵ�֣�<sstream>ͷ�ļ���
	���磺
    string input("hello,this is a test");
    istringstream is(input);
    string s1,s2,s3,s4;
    is>>s1>>s2>>s3>>s4;//s1="hello,this",s2="is",s3="a",s4="test"
    ostringstream os;
    os<<s1<<s2<<s3<<s4;
    cout<<os.str();

*/
#include <cctype>    //�������ַ��ַ��ַ��ַ��������һЩ������c++��cctype ��C�е�ctype��������
/*

isxdigit()	���������ʮ�����Ƶ����֣���0��9��a~f��A~F���ú�������true

isdigit()	������������֣�0��9�����ú�������true
isalpha()	�����������ĸ���ú���������
isalnum()   �����������ĸ���֣�����ĸ�����֣��ú�������true

isblank()	��������ǿո��ˮƽ�Ʊ�����ú�������true
isspace()   ��������Ǳ�׼�հ��ַ�����ո񡢽�ֽ�����з����س���ˮƽ�Ʊ�����ߴ�ֱ�Ʊ�����ú�������true

islower()	���������Сд��ĸ���ú�������true
isupper()	��������Ǵ�д��ĸ���ú�������true

tolower()	��������Ǵ�д�ַ����򷵻���Сд�����򷵻ظò���
toupper()	���������Сд��ĸ���򷵻����д�����򷵻ظò���

*/

/*--------------------------------------------------------------------------------------------------------
                                              C
----------------------------------------------------------------------------------------------------------*/
#include <stdio.h>   //����һϵ�к������д�����ı�׼�������,
/*

//�����ո�ֹͣ����
scanf()     ��ʽ������ int scanf(char *format, [,argument,....])   scanf("%3d, %3.3f", &Inum, &dNum); scanf("%s", ptr);
            %d�� ʮ������    %x�� ʮ��������     %lf %f: ������     %c���ַ�     %s���ַ���     
printf()    ��ʽ������� int printf(char *format, [,argument,...]) printf("%c", c); printf("%s", ptr);
            %d�� ʮ������    %x�� ʮ��������     %d %f: ������     %c���ַ�     %s���ַ���

//vs��ȫ�汾��sscanf_s("aa", "%s", str, sizeof(str)); //Ҫ����buffer�Ĵ�С����ֹ�����
sscanf()    ��ȡ���ո��ַ�������ʽ����ȡ int sscanf(const char* str,const char* format, [,argument,...] )
            (1) sscanf("aa bb cc", "%s%s%s", ptr1, ptr2, ptr3);    //*ptr1 , *ptr2, *ptr3 = "aa", "bb", "cc" ��ȡ�ո����
			(2) sscanf("zhoue3456", "%4s", str);                   //*str = "zhou"
			(3) sscanf("654321abcdefABCDEF", "%[0-9a-z]", str);    //*str = "654321abcdef"; 
			(4) sscanf("zhou456hedf", "%[^6]", str);                //*str = "zhou45"; 
			(5) sscanf("zhou456hedf", "%[^1-9]", str);              //*str = "zhou"
			(6) sscanf("2018.05.18", "%d.%d.%d", &num1, &num2, &num3)  //num1 = 2018 num2 = 5 num3 = 18;

//vs��ȫ�汾��sprintf_s(str, "%s", [,argument,...], sizeof(str)); //Ҫ����buffer�Ĵ�С����ֹ�����
sprintf()   ����ʽ��������д���ַ�����int sprintf(char *buffer, char *format, [,argument,...])  //�����ַ�������
            (1) sprintf(str, "%d", 1024)    // *str = "1024"
			(2) sprintf(str, "0x%x", 1024)  //*str = "0x400"
			(3) sprintf(str, "%s %s", "hello", "world") // *str = "hello world"
			(4) sprintf(str, "%3d", 1024) //*str = "102"
			(5) sprintf(str, "%10.3f", 3.1415926) // *str = "3.142"  //%m.nf  m:�ܳ��ȣ� n��С����ĳ���

gets()      char *gets(char *s)  //
            (1) gets(buffer); //�����з��������������з������ڶ�ȡ�ַ���ĩβ����'\0',������ʹ��

puts()      int puts(const char * string) //
			(1) puts(buffer) //ֻ������ַ���������Զ����У��൱��printf("%s\n", str);

*/
#include <io.h>      //��Ҫ����һЩ�Ի��������ж�д������
/*

write()     //��ʱ���ܽ�,
read()      //��ʱ���ܽ�

open()      //��ʱ���ܽ�
close()     //��ʱ���ܽ�

*/
#include <stdlib.h>  //C ��׼��ͷ�ļ��� �������������ͺ�һЩ�꣬ ͨ�ù��ߺ����� 
/*
���ͣ�size_t��wchar_t��div_t��ldiv_t��lldiv_t
�꣺EXIT_FAILURE��EXIT_SUCCESS��RAND_MAX��MB_CUR_MAX��
���ú�����

malloc()         //  void *malloc(size_t size);
free()           //  void free(void *ptr);

atoi()           //  int atoi(const char *str);    �������󣬷���0
atol()           //  long atol(const char *str);   �������󣬷���0
atof()           //  float atof(const char *str);   �������󣬷���0

itoa()           //  char* itoa(int value, char* buffer, int radix);     radix ���Ʋ���

strtod()         //  double strtod(const char* str, char **endptr); //�Զ�����ǰ��Ŀհ��ַ���tab space�ȣ���
                     ֱ���������ֻ��������ſ�ʼ �������ֻ���'\0'ת������ ��endptr ���Դ��ص���ת���������ַ���null����ʾ������Ч   
strtol()         //  long int strtol(const char *nptr, char**endptr, int base)   ����һ��
strtoul()        //  uinsigned long int strtol(const char *nptr, char**endptr, int base)   ����һ��

srand()          //  srand()Ϊrand()�ṩ����,��srand(13)�Ĳ���һ������ôÿ�β����������һ�£�ͨ��
                     srand((unsigned)time(null)) ���������������
rand()           //  rand() % 100 + 1������1 - 100s֮����������

exit()           //  exit(num)  num == 0 ��ʾ�����˳��� num != 0 ��ʾ�쳣�˳��� numֵ���ᴫ�ݸ�����ϵͳ
system()         //  system("pause")  

*/
#include <string.h>  //C�����д����ַ����ĺ���
/*
strlen()         //  unsigned int strlen(char *) 
strcat()         //  char* strcat(char *dest, char *src)     //Ŀ���ַ����� srcԴ�ַ����� �����ַ��� char* strcat_s(char *dest, size_t size, char *src) ;//VS�汾
strcmp()         //  int strcmp(const char *s1, const char *s2);  //  s1 < s2 : ������ s1 > s2 : ������ s1 == s2 : 0  
strcpy()         //  char *strcpy(char *dest, const char* src); 
strchr()         //  unsigned int strchr(char *str, char c);   //�����ַ�c���ַ����е��±ꣻ

//��ȫ�汾����Щ���� ��
strnlen()       //unsigned int strnlen(const char* str, size_t size_max);
strncat()       //char* strncat(char *dest, char *src, size_t size_max);
strncmp()       //int strncmp(const char *s1, const char *s2, size_t, size_max);  //  s1 < s2 : ������ s1 > s2 : ������ s1 == s2 : 0  
strncpy()       //char* strncpy(char *dest, char *src, size_t size_max);

*/
#include <ctype.h>   //ͬcctype

#include <time.h>    //���������ʱ�����õ���time(null)

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
	                              C�ַ�������ֵ֮���ת��
----------------------------------------------------------------------------------------------------------*/
/*

��1�� ��ֵ------->�ַ�����
	1��ʹ��ģ�� + ostringstream:
			template<typename T> string toString(const T& t)
			{
				ostringstream oss;  //����һ����ʽ�������
				oss<<t;             //��ֵ����������
				return oss.str();   
			}
			cout<<toString(14.2)<<endl;  //ʵ��->string�����14.2

	2��ʹ�ñ�׼�⺯��std::to_string(),�ɽ���ֵ����ת��Ϊstring ͷ�ļ�<string >
			string to_string (int val);
			string to_string (long val);
			string to_string (long long val);
			string to_string (unsigned val);
			string to_string (unsigned long val);
			string to_string (unsigned long long val);
			string to_string (float val);
			string to_string (double val);
			string to_string (long double val);

��2���ַ���-------->��ֵ�͵�ת��
		1��ʹ�ú���ģ��+ istringstream����string����ת��Ϊ���õ���ֵ����
			template <class Type>  
			Type stringToNum(const string& str)
			{  
				istringstream iss(str);  
				Type num;  
				iss >> num;  
				return num;      
			}
		2��ʹ��c��׼�⣺��stringתΪchar*����ͨ����Ӧ������ת��
			string str; const char *pstr = str.c_str();  //��ʹ��c�������atoi atol atof�ȵ�	
		3��ʹ��c++��׼�⣺��<string>�У�
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
										C�ַ����ַ�������ֵ֮���ת��
----------------------------------------------------------------------------------------------------------*/
/*
��1����ֵ��------->�ַ����ַ����ͣ�
		1��������ֵ�����ַ���ת����
			int a = 1; char c = a + '0'��
		2��������ֵ���ַ�����ת����
			char *itoa(int value, char* string, int radix);   //int to array ��ת����char* ͬ*string ָ�򷵻ص��ַ�����value������ֵ��radix : ���� ������10���ƣ�16���Ƶ�
		3�������������ַ�����ת����
			char *gcvt(double number, size_t ndigits, char *buf); //char* ͬchar* bufһ������ŷ��ص��ַ�����ndigits����ʾ��ʾ��λ����

			char *ecvt(double value, int ndigitIT, int *dec, int *sign);   //��������ת��Ϊ����ΪndigitIT���ַ�����û��С���㣬����value�����ֳ��Ȳ�����

			char *fcvt(double value, int ndigitIT, int *dec, *sign);     //��������ת��Ϊ����ΪndigitIT���ַ�����û��С���㣬����value����ֵ���ȣ��Զ�����

��2���ַ����ַ�����>>>>��ֵ�ͣ�
		1���ַ�>>>>>��ֵ�ͣ�
			char c = 'a'; int num = c - '0';
		2���ַ���>>>>��ֵ�ͣ�
			atof(), atoi(), atol(), atoll();  //ͷ�ļ� ctype.h����ǰ�����н�

*/

/*--------------------------------------------------------------------------------------------------------
                                             �����������������һЩ�ܽ�
----------------------------------------------------------------------------------------------------------*/
/*

(1) scanf()       ��Space��Enter��Tab����һ�����룬�����������Ļس��������س���������ڻ������У���
(2) getchar()     ��Enter�������룬Ҳ�����������Ļس�����
(3) gets()        ��Enter�������룬���ܿո񣬻��������Ļس�����                        ......�����س���.......

(4) cin >>        ��Space��Enter��Tab����һ�����룬���������Ļس�����                  ......�����س���.......
(5) cin.get()     ��Enter�������룬Ҳ�����������Ļس�����cin.get(), cin.get(char ch), cin.get(array_name, Arsize) //char a[20]; cin.get(a, 10);
(6) cin.getline() ��Enter��������, ���������Ļس�����                                  ......�����س���.......

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