#include <stdio.h>
#include <string.h>
int main(void){
	{
		char str1[] = "123456789";
		char str2[] = "def";
		
		/*
			将str2复制给str1
			strcpy函数无法检查str2指向的大小是否真的合适str1。
			如果str2指向更长的字符串，那么结果就无法预料了，因为strcpy函数会一直复制到第一个空字符为止，
			所以他会超越str1指向的数组的边界继续复制
		*/
		strcpy(str1,str2);  
		printf("strcpy复制用法：%s\n",str1);
		
		printf("=========================\n");
	}
	
	{
		/*
			strlen函数:
			求字符串长度，原型如下：
			size_t strlen(const char *s);
			
			strlen函数返回字符串s的长度：s中第一个空字符之前的字符个数(不包含空字符)。
		*/
		int len;
		char str3[] = "adfasfasljfl";
		len = strlen(str3);
		printf("str1的长度是:%d\n",len);
		printf("==========================\n");
	}
	
	{
		/*
			strcat函数:字符串拼接，函数原型如下：
			char *strcat(char *s1, const char *s2);
			把s2追加到字符串s1的末尾，并且返回字符串s1；
		*/
		char str1[]="";
		strcpy(str1,"132323");
		strcat(str1,"---asfs");
		printf("str1最后的结果:%s\n",str1);
		printf("=====================");
	}
	
	{
		/*
			strcmp函数:字符串比较，函数原型如下：
			int strcmp(const char *s1, const char *s2);
			比较字符串s1和字符串s2,然后根据s1是小于，等于，或者大于s2，返回一个小于，等于或者大于0的值。
		*/
		char str1[] = "你bc";
		char str2[] = "123";
		if(strcmp(str1,str2) == 0){
			printf("str1等于str2\n");
		}else if(strcmp(str1,str2) > 0){
			printf("str1大于str2\n");
		}else if(strcmp(str1,str2) < 0){
			printf("str1小于str2\n");
		}else{
			printf("error\n");
		}
	}
}