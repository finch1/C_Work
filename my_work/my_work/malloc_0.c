#if 0

#include <stdio.h>
#include <stdlib.h>

int allocate(int **a, int n)
{
	if ((*a = (int*)malloc(n * sizeof(int))) != NULL)
		return 0;
	return 1;	
}

void safefree(void **par)
{
	free((void*) *par);
	*par =  NULL;
}

int main()
{
	int len, *i, total = 0, j;
	int *par;

	printf("enter array size: "); scanf("%d", &len);

	par = (int*)malloc(sizeof(int) * len);

	for (i = par; i < (par + len); i++)
	{
		printf("Enter a number: ");
		scanf("%d", i);

	}

	for (i = par; i < (par + len); i++)
	{
		total += *i;
		//total += par[i]; //if i was just an integer
	}
	printf("%d\n", total);

	printf("before %p\n", par);
	safefree(&par);
	printf("after %p\n", par);

	int *ptr;
	if (allocate(&ptr, 10) != 1) puts("mem allocated");

	for (j = 0; j < 10; j++)
	{
		ptr[j] = j;
	}

	for (j = 9; j >= 0; --j)
	{
		printf("%d\n", ptr[j]);
	}

	safefree(&ptr);

	char *ar;
	FILE *stream;

	if (stream = (FILE*)malloc(sizeof(char) * 20) != NULL) 
		{
			for (j = 0; j < 10; j++) fwrite()

		}
			



	return 0;
}
#endif