#include <stdio.h>
#define MAX 200 //macros

int main()
{
	int x = 5;
	int *px;
	px = &x;
	// & means address of, * means pointer variable
	// only use * when initializing, when assigning only use px (do not include *)
	// * value stored at location in pointer
	printf("printing x using a pointer %d\n", *px);
	printf("printing the pointer %p\n", px);
	int *px1 = px; // this can be done too but not assignment alone
	printf("printing x using a pointer %d\n", *px1);
	printf("printing the pointer %p\n", px1);

	px1 -= 1;
	printf("printing x using a pointer %d\n", *px1);
	printf("printing the pointer %p\n", px1); // points to junk 
	// same thing
	// doing anything to *px will change x too and vice versa
	// for a function with no parameters do we need to type in void, and then can main be void
	// can use *(p+3) and stuff like that to change values in an array
	// if p is pointer variable, p = arr points to first value
	return 0;
}