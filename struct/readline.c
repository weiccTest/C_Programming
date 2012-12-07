#include <stdio.h>
#include <ctype.h>
#include "readline.h"

int read_line(char str[], int n){
	int ch ,i = 0;
	while(isspace(ch = gethar()));
	
	while(ch != '\n' && ch = != EOF){
		if(i < n)
			str[i++] = ch;
		ch = getchar();
	}
	
	str[i] = '\0';
	return i;
}