#if 0 // very wiered code
#include <stdio.h>
#include <malloc.h> // for memory allocation


#define MAX_COMPANIES	3
#define MAX_CARS		5
#define MAX_MODELS		10

int main()
{
	int(*npointer)[MAX_MODELS];
	int i, j, k;

 	npointer = (int(*)[MAX_MODELS]) malloc(MAX_CARS * sizeof(*npointer));

	for (i = 0; i < MAX_CARS; i++)
	{
		for (j = 0; j < MAX_MODELS; j++)
		{
			npointer[i][j] = (i * 100) + j;
		}
	}

	for (i = 0; i < MAX_CARS; i++)
	{
		for (j = 0; j < MAX_MODELS; j++)
		{
			printf("npointer[%d][%d] = %4d\n",
				i, j, npointer[i][j]);
		}
	}

	free(npointer);

	return(0);
}


#endif