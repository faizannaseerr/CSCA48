#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxArray(int array[5], int length)
{
	if (length == 1){
		return array[0];
	}
	int max = maxArray(array, length - 1);
	if (array[length - 1] > max){
		return array[length - 1];
	}
	return max;
}

int isPalindrome(char *str, int count)
{
	if (*str != *(str + count - 1)) {
		return 0;
	}
	else {
		return 1;
	}
	if (str != (str + count) || (str + 1) != (str + count)) {
		return isPalindrome(str + 1, count - 1);
	}
}


int main()
{
	int array[5] = {1, 4, 5, 90, 3};
	printf("highest num: %d\n", maxArray(array, 5));
	char string[50] = "rotator";
	printf("number: %d\n", isPalindrome(&string[0], 7)); 
	// 1 means palindrome, 0 means not a palindrome
	// parameters include pointer to first character in string and count of letters
	return 0;

}