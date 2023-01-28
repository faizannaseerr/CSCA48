
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

	unsigned char friend;
	unsigned int hello = 45;
	friend = hello;
	printf("char - %c\n", friend);


	char string[50] = "hello";
	string[3] ='y';
	printf("string: %s\n", string);
	string[3] = string[3] + 1420;
	char s = '<';
	int f = -128;
	int e = abs(f);
	if (e < 255){
		printf("less\n");
		printf("%c\n", e);
	}
	unsigned int  num = e - '0';
	printf("%d\n", num);
	s = s + '(';
	printf("%c\n", s);
	s = s - 34;
	printf("%c\n", s);
	printf("%s\n", string);

	printf("---------\n");
	char fried[10] = "help";
	char bry[10];
	strncpy(bry, &fried[0], 3);
	printf("bry: %s\n", bry);

	
	return 0;
}