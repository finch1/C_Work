#if 0
#include <stdio.h>

int main()
{
	int c, i, j, nwhite, nother;
	int cdigit[30]; //array of 30 for holding input
	int ndigit[10]; //array of 10 integers

	nwhite = nother = j = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	for (i = 0; i < 30; i++)
	{
		cdigit[i] = getchar();
		c = cdigit[i];

		if (c >= '0' && c <= '9')
			++ndigit[c - '0']; //index - characeter value = numeric value
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else ++nother;
	}

	printf("digits =");

	for (i = 0; i < 10; i++) //arrays always start from index 0
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);

	for (i = 0; i < 10; i++)
	{
		j = 0;
		printf("num : %d  cnt : %d", i, ndigit[i]);

		while (j < ndigit[i])
		{
			printf("-"); 
			j++;
		}
		printf("\n");
			
	}

}

#endif