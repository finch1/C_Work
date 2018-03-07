#if 0
#include <stdio.h>
int main(void)
{
	const volatile int local = 10;
	int *ptr = (int*) &local;

	printf("intial value of local : %d \n", local);
	*ptr = 100;

	printf("modified value of local : %d \n", local);

	return 0;
}

#endif