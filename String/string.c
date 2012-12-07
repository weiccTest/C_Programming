#include <stdio.h>
#include <string.h>
int main(void){
	{
		char str1[] = "123456789";
		char str2[] = "def";
		
		/*
			��str2���Ƹ�str1
			strcpy�����޷����str2ָ��Ĵ�С�Ƿ���ĺ���str1��
			���str2ָ��������ַ�������ô������޷�Ԥ���ˣ���Ϊstrcpy������һֱ���Ƶ���һ�����ַ�Ϊֹ��
			�������ᳬԽstr1ָ�������ı߽��������
		*/
		strcpy(str1,str2);  
		printf("strcpy�����÷���%s\n",str1);
		
		printf("=========================\n");
	}
	
	{
		/*
			strlen����:
			���ַ������ȣ�ԭ�����£�
			size_t strlen(const char *s);
			
			strlen���������ַ���s�ĳ��ȣ�s�е�һ�����ַ�֮ǰ���ַ�����(���������ַ�)��
		*/
		int len;
		char str3[] = "adfasfasljfl";
		len = strlen(str3);
		printf("str1�ĳ�����:%d\n",len);
		printf("==========================\n");
	}
	
	{
		/*
			strcat����:�ַ���ƴ�ӣ�����ԭ�����£�
			char *strcat(char *s1, const char *s2);
			��s2׷�ӵ��ַ���s1��ĩβ�����ҷ����ַ���s1��
		*/
		char str1[]="";
		strcpy(str1,"132323");
		strcat(str1,"---asfs");
		printf("str1���Ľ��:%s\n",str1);
		printf("=====================");
	}
	
	{
		/*
			strcmp����:�ַ����Ƚϣ�����ԭ�����£�
			int strcmp(const char *s1, const char *s2);
			�Ƚ��ַ���s1���ַ���s2,Ȼ�����s1��С�ڣ����ڣ����ߴ���s2������һ��С�ڣ����ڻ��ߴ���0��ֵ��
		*/
		char str1[] = "��bc";
		char str2[] = "123";
		if(strcmp(str1,str2) == 0){
			printf("str1����str2\n");
		}else if(strcmp(str1,str2) > 0){
			printf("str1����str2\n");
		}else if(strcmp(str1,str2) < 0){
			printf("str1С��str2\n");
		}else{
			printf("error\n");
		}
	}
}