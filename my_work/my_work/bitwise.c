#if 0

#include <stdio.h>

#define bool int
#define NUMELEMS(x) sizeof(x) / sizeof((x)[0])


//func returning the only odd occuring element
int findodd(int arr[], int n)
{
	int res = 0, i;
	for (i = 0; i < n; i++)
		res ^= arr[i];
	return res;
}

bool getparity(unsigned int n)
{
	bool parity = 0;
	while (n)
	{
		parity = !parity;
		n = n & (n - 1);
	}
	return parity;
}



int main()
{
	unsigned char a = 5, b = 9; //a = 5(00000101), b = 9(00001001)
	int arr[] = { 12, 12, 14, 90, 14, 14, 14 };
	int n = NUMELEMS(arr);

	//bitwise
	printf("%d\n", sizeof(arr));
	printf("%d\n", sizeof(arr[0]));
	printf("a = %d, b = %d\n", a, b);
	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);
	printf("~a    = %d\n", ~a);
	printf("a << 1= %d\n", a << 1);
	printf("a >> 1= %d\n", a >> 1);

	printf("Signed result %d \n", ~1);
	printf("Unsigned result %u \n", ~1);

	printf("The odd occurring element is %d\n", findodd(arr, n));

	
	int f = 2, g = 5;
	(f & g) ? puts("True ") : puts("False ");
	(f && g) ? puts("True ") : puts("False ");
	puts("enter any number");

	int var, i;

	for (i = 2; i >= 0; i--)
	{
		scanf_s("%d", &var);
		//checking if num is odd or even 
		(var & 1) ? printf("odd\n") : printf("even\n");
		//parity
		printf("parity of no %d is %s", var, (getparity(var) ? "odd\n" : "even\n"));
	}

	return 0;

}
#endif