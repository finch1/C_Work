#if 0

#include <stdio.h>

int test_fun(int* s)
{
	if (s == NULL)
	{
		printf("%s: received null pointer argument - file : %s @ line: %d\n", __func__, __FILE__, __LINE__);
		return -1;
	}
	else { printf("all good passed : %d\n", *s); }

	return 1;
}

int main()
{
	int a = 46;
	test_fun(&a);
	if (test_fun(NULL) < 0)
	{
		printf("sum ting wong\n");
	}
}

#endif