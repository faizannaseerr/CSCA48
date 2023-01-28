#include <stdio.h>
int main()
{
	// unsigned chars go from 0 to 255, if overflow goes back to 0
	unsigned char j = 255;
	j = j + 10;
	printf("%c \n", j);
	// signed chars go from -128 to 127
	char c = 127;
	c = c + 10;
	printf("%u \n", c);
	// u is for unsigned integers

	char mychar = 'A' + '\b';
	printf("A(65) + \\b(8) = %c(%d) \n", mychar, mychar);

	printf("char size: %lu bytes \n", sizeof(char));
	// long unsigned is lu

	//True = 1, False = 0
	int year = 3;
	if(year>=3)
		printf("oh no \n");
	if (year<=3)
	{
		printf("oh no \n");
		printf("oh no \n");
	}
	// need parenthesis for if statement with more than one line
	// logical AND - &&, logical OR - ||, logical NOT - !
	// i++ is same as i = i + 1, this is assignment then increment
	// ++i is same as i = i + 1, this is increment then assignment
	// both same in for loop

	//break & continue








	return 0;
}

