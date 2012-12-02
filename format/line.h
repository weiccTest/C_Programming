/*
	1、输出行缓冲区的内容，不进行调整
	2、检查行缓冲中还剩多少字符
	3、输出行缓冲区的内容，进行调整
	4、清除行缓冲区
	5、往行缓冲区中添加单词。
*/

#ifndef LINE_H
#define LINE_H
	
	void clear_line(void);
	
	void add_word(const char *word);
	
	int space_remaining(void);
	
	void write_line(void);
	
	void flush_line(void);
#endif
