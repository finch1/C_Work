# if 0

# include <stdio.h>

# define lower  0 // lower limit of temp table
# define upper  300 // upper limit of temp table
# define step   20 //step size


int main()
{
	float fahr, celsius;

	fahr = lower;

	printf("  fahr%t  celsius\n");
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%6.1f \t %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	celsius = lower;
	printf("celsius%t fahr\n");
	while (celsius <= upper)
	{
		fahr = (1.8 * celsius) + 32;
		printf("%6.1f \t %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	printf("\n\n\n");


	for (fahr = upper; fahr >= lower; fahr = fahr - step)
		printf("%5.1f \t %6.1f\n", fahr, 5 * (fahr - 32) / 9);

}


#endif