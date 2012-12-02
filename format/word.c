/*
	虽然word.h只有一个read_word函数的原型，但是如果需要我们可以在word.c中放置更多的函数
	添加一个小的“辅助”函数read_char ，函数read_word的编写就更容易一些了。
*/
#include <stdio.h>
#include "word.h"

/*
	读取一个字符，如果是换行符或者是制表符则将其转换为空格。
*/
int read_char(void){
	/*
		getchar 函数返回实际上是int类型而不是char类型值
		应此把ch声明为int类型并且read_char返回的也是int。
		当不能继续读入时，通常因为读到了输入文件末尾，getchar的返回之是EOF
	*/
	int ch = getchar();
	
	if(ch == '\n' || ch == '\t'){
		return ' ';
	}
	return ch;
}


/*
	read_word函数有两个循环构成。
	第一个循环跳过空格.在遇到第一个非空白字符时停止。(EOF不是空白，所以循环在到达输入文件的末尾时停止)
	第二个循环读字符直到遇到空格或者EOF时停止。
	循环体把字符存储到word函数中到达len的限制时停止，在这之后，循环继续读入字符，但是不在存储这些字符。
	read_word函数中的最后一个语句以空字符结束单词，从而构成字符串。
	如果read_word找到非空白字符前遇到EOF，pos将为０，从而使得word为空字符串
*/
void read_word(char *word, int len){
	int ch , pos = 0;
	while((ch = read_char()) == ' '){
		;
	}
	while(ch != ' ' && ch != EOF){
		if(pos < len){
			word[pos++] = ch;
		}
		ch  = read_char();
	}
	word[pos] = '\0';
}
