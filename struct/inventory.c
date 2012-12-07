#include <stdio.h>
#include "readline.h"

#define NAME_LEN 25
#define MAX_PARTS 100
struct part{
	int number;
	char name[NAME_LEN+1];
	int on_hand;
}inventory[MAX_PARTS];

int num_parts = 0;

int fine_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

int main(void){
	char code;
	for(;;){
		printf("请选择接下来的操作:\n");
		printf("i--添加新零件\n");
		printf("s--搜索零件\n");
		printf("u--更新零件\n");
		printf("p--显示零件\n");
		printf("q--退出程序\n");
		scanf(" %c",&code);
		
		while(getchar() != '\n'){;}
		
		switch(code){
			case 'i':insert();break;
			case 's':search();break;
			case 'u':update();break;
			case 'p':print();break;
			case 'q':return 0;
			default: printf("程序已退出!!");
		}
		printf("\n");
	}
}

int find_part(int number){
	int i;
	for(i = 0; i< number; i++){
		if(inventory[i].number == number){
			return 1;
		}
	}
	return -1;
}

void insert(void){
	int part_number;
	if(num_parts == MAX_PARTS){
		printf("Database in full;can't add more parts.\n");
		return;
	}
	
	printf("请输入零件编号:");
	scanf("%d",&part_number);
	
	if(find_part(part_number) >= 0){
		printf("%d号零件已经存在.\n",part_number);
		return;
	}
	
	inventory[num_parts].number = part_number;
	printf("请输入零件名称:");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("请输入零件数量:");
	scanf("%d",&inventory[num_parts].on_hand);
	num_parts++;
}

void search(void){
	int i, number;
	
	printf("请输入零件编号:");
	scanf("%d",&number);
	i = find_part(number);
	if(i >= 0){
		printf("零件名称：%s\n",inventory[i].name);
		printf("零件库存为：%d",inventory[i].on_hand);
	}else{
		printf("%d号零件不存在\n",&number);
	}
}

void update(void){
	int i, number,change;
	
	printf("请输入零件编号:");
	scanf("%d",&number);
	i = find_part(number);
	
	if( i >= 0){
		printf("请输入零件要修改的数量:");
		scanf("%d",&change);
		inventory[i].on_hand += change;
	}else{
		printf("%d号零件不存在.\n",number);
	}
}

void print(void){
	int i;
	printf("零件编号\t零件名称\t零件数量\n");
	for(i = 0; i < num_parts; i++){
		printf("%7d		%-25s%11d",inventory[i].number,inventory[i].name,inventory[i].on_hand);
	}
}