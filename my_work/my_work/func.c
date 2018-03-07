#if 0
#include <stdio.h>

//power: raise base to n-th power; n >= 0
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n) //using passed pariable
		p = p * base;
	return p;
}

int tempconv(int temp)
{
	printf("Celcius: %d \t Farenheit: %3.1f \n", temp, (1.8 * temp) + 32);
	return 0;
}

int main()
{
	int i;

	for (i = 0; i < 10; ++i)
	{
		printf("%d %5d %6d\n", i, power(2, i), power(-3, i));		
	}
		
	for (i = 0; i < 10; ++i)
	{
		tempconv(i);
	}

	return 0;
}

#endif