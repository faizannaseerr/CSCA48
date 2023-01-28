
#include<stdio.h>
#include<stdlib.h>

int main()

{
	char f = 3;
	printf("%c\n", f);
	printf("\a");
	float number = 3.56;
	printf("%.1f\n", number);
	// rounds number
	printf("%d\n", (int)number);
	// number is truncated, no rounding
	char c = 'c';
	printf("Print ASCII number %d\n", c);
	// printing ascii number for character
	c = 67;
	printf("Print letter with ASCII number %c\n", c);
	float first = 3.45;
	// first = (int)first;
	// printf("%d\n", first);
	// for loops can iterate with numbers, char & floating point numbers
	// can use ++ for iteration by 1, or ++1.2 for iteration by a specific number
	// two questions: can you iterate (e.g. ++d) with a letter
	// and: can you permanently convert a variable into another type instead of it only converting in the printf statement
    int counter = 3;
	printf("%f\n", sqrt(4));
	return 0;


}

