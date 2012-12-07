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
		printf("��ѡ��������Ĳ���:\n");
		printf("i--��������\n");
		printf("s--�������\n");
		printf("u--�������\n");
		printf("p--��ʾ���\n");
		printf("q--�˳�����\n");
		scanf(" %c",&code);
		
		while(getchar() != '\n'){;}
		
		switch(code){
			case 'i':insert();break;
			case 's':search();break;
			case 'u':update();break;
			case 'p':print();break;
			case 'q':return 0;
			default: printf("�������˳�!!");
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
	
	printf("������������:");
	scanf("%d",&part_number);
	
	if(find_part(part_number) >= 0){
		printf("%d������Ѿ�����.\n",part_number);
		return;
	}
	
	inventory[num_parts].number = part_number;
	printf("�������������:");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("�������������:");
	scanf("%d",&inventory[num_parts].on_hand);
	num_parts++;
}

void search(void){
	int i, number;
	
	printf("������������:");
	scanf("%d",&number);
	i = find_part(number);
	if(i >= 0){
		printf("������ƣ�%s\n",inventory[i].name);
		printf("������Ϊ��%d",inventory[i].on_hand);
	}else{
		printf("%d�����������\n",&number);
	}
}

void update(void){
	int i, number,change;
	
	printf("������������:");
	scanf("%d",&number);
	i = find_part(number);
	
	if( i >= 0){
		printf("���������Ҫ�޸ĵ�����:");
		scanf("%d",&change);
		inventory[i].on_hand += change;
	}else{
		printf("%d�����������.\n",number);
	}
}

void print(void){
	int i;
	printf("������\t�������\t�������\n");
	for(i = 0; i < num_parts; i++){
		printf("%7d		%-25s%11d",inventory[i].number,inventory[i].name,inventory[i].on_hand);
	}
}