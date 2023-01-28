#include <stdio.h>
#include <stdbool.h>

float power(float x, int p)

{
	int i;
	float result = x;
	for (i = 1; i < p; i++)
	{
		result *= x;
	}

	return result;
}


int main()

{
	float x = 1.4142;
	int i;
	for (i = 2; i < 101; i++)
	{
		int j;
		bool prime_check = true; // prime_check used as boolean variable
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				prime_check = false;
				break;
			}

		}
		if (prime_check == true)
		{
			printf("p=%d, 1.4142^%d = %f \n", i, i, power(x, i));
		}
		
	}
	

	return 0;
}

