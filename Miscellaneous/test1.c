#include <stdio.h>
#include<stdlib.h>

int main()
{
	char src[50] = "Hello! My Name is Faizan";
	char *srcp=src;
	char *newpointer = srcp;
	printf("%p\n", srcp);
	printf("%p\n", newpointer);
	char dest[50] = "hi";
	char *destp = dest;
	printf("%c\n", *srcp);
	*destp = 'm';
	printf("%c\n", *destp);
	destp += 1;
	printf("%c\n", *destp);





	return 0;
}