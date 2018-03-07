#if 0

# include <stdio.h>
int main(void)
{
	const int a = 5;
	int i = 10;
	int j = 20;
	int *ptr_i = &i; //pointer to integer variable

	int k = 30;
	int l = 40;
	const int *ptr_ci = &k; //int const ptr - same same
							//const ptr cannot modify value its pointing to
	//--pointer to int
	printf("*ptr: %d\n", *ptr_i);

	ptr_i = &j; // pointer is pointing to another variable
	printf("*ptr: % d\n", *ptr_i);

	*ptr_i = 100; //we can change value stored by pointer (as in where its pointing)
	printf("*ptr: %d\n", *ptr_i);

	//--pointer to const
	printf("*ptr: %d\n", *ptr_ci);
	
	ptr_ci = &l;
	printf("*ptr: %d\n", *ptr_ci);

	return 0;
}

#endif