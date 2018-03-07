#if 0
//demostration of multidimentional arrays

#include <stdio.h>

#define MAX_COMPANIES	3
#define MAX_CARS		5
#define MAX_MODELS		7

int main()
{
	//this is a 10 element array
	int narray1[MAX_CARS];

	//this is a 10-by-5 array
	int narray2[MAX_CARS][MAX_MODELS];

	//this is a 10-by-5-by-3 array
	int narray3[MAX_CARS][MAX_MODELS][MAX_COMPANIES];

	int i, j, k;

	for (i = 0; i < MAX_CARS; i++)
	{
		narray1[i] = i;
		for (j = 0; j < MAX_MODELS; j++)
		{
			narray2[i][j] = (j * 10) + i;
			for (k = 0; k < MAX_COMPANIES; k++)
			{
				narray3[i][j][k] = (i * 100) + (j * 10) + k;
			}
		}
	}

	for (i = 0; i < MAX_CARS; i++)
	{
		//printf("%d ", *(narray1 + i));
		printf("%d ", narray1[i]);
	}
	printf("\n");

	//one for loop to go through 2D array
	for (i = 0; i < MAX_CARS * MAX_MODELS; i++) 
	{
		if (!(i % MAX_MODELS))
		{
			printf("\n");
		}
		printf("%d ", *(*(narray2) + i)); // min flok nuzaw zewg for loops
	}
	printf("\n");

	for (i = 0; i < (MAX_COMPANIES * MAX_CARS * MAX_MODELS); i++)
	{
		if ((i % MAX_COMPANIES) == 0)
		{
			printf("\n");
		}
		printf("%d ", *(*(*(narray3)) + i));
	}

	printf("\n");
	//notice that string concatenation makes the printf format
	//string more readable. also the blank line between the 
	//format string and the other arguments to printf.

}

#endif