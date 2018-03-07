/*EXERCISES*/
#if 0
#include <stdio.h>
#include <time.h>
#define PI 3.14159

void math(int a, int b)
{
	printf("sum : %d, average : %d, sum of squares: %d\n",
		a + b, (a + b) / 2, (a*a + b*b));
}

typedef struct _MyStruct
{	
	char name[10];
	char address[10];
	unsigned int age;
}mystruct;

int main()
{
#if 0
	int a, b;
	mystruct mydetals;

	/*Input two numbers and work out their sum, average and sum of the squares of the numbers.*/
	puts("enter two numbers: ");
	scanf("%d", &a);
	scanf("%d", &b);
	math(a, b);
#endif
#if 0
	/*Input and output your name, address and age to an appropriate structure.*/
	printf("enter name :");
	scanf("%s", mydetals.name);
	printf("enter address :");
	scanf("%s", mydetals.address);
	printf("enter age :");
	scanf("%d", mydetals.age);
#endif
# if 0
	/*Write a program that works out the largest and smallest values from a set of 10 inputted numbers.*/
	puts("enter 10 numbers");
	int numarr[10];
	int max = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", numarr + i);
		if (numarr[i] > max)
			max = numarr[i];
	}

	printf("maximum number is %d\n", max);
#endif

#if 0
	/*Write a program to read a "float" representing a number of degrees Celsius, and print as a "float" 
	the equivalent temperature in degrees Fahrenheit. Print your results in a form such as */
	float celcius;
	puts("enter temp in celcius");
	scanf("%f", &celcius);
	printf("Faren : %0.1f\n", (1.8 * celcius) + 32);
#endif

#if 0
	/*Write a program to read a positive integer at least equal to 3, and print out all possible permutations 
	of three positive integers less or equal to than this value. */
	puts("enter a number bigger then 2");
	int i;
	scanf("%d", &i);
	while (i >= 0)
		printf("%d ", i--);

	printf("\n");
#endif

#if 0
	/*Write a program to read a number of units of length (a float) and print out the area of a circle of that radius. 
	Assume that the value of pi is 3.14159 (an appropriate declaration will be given you by ceilidh - select setup).
	Print the message Error: Negative values not permitted.*/

	puts("enter radius");
	float rad;
	scanf("%f", &rad);
	if (rad <= 0)
		puts("idiota!");
	else
		printf("Radius is : %0.3f\n", PI*(rad*rad));
#endif

#if 0
	/*Given as input a floating (real) number of centimeters, print out the equivalent number of feet (integer) and inches (floating, 1 decimal), 
	with the inches given to an accuracy of one decimal place. Assume 2.54 centimeters per inch, and 12 inches per foot. */
	puts("enter a value in cm");
	float dist;
	scanf("%f", &dist);
	printf("%0.2f centi is %0.0f feet and %0.1f inches\n", dist, (dist / 2.54) / 12, dist / 2.54);
#endif

#if 0
	/*Given as input an integer number of seconds, print as output the equivalent time in hours, minutes and seconds. Recommended output format is something like */
	int timein;
	int tempo;
	int hms[3] = { 0, 0, 0 };
	puts("enter a time!:");
	scanf("%d", &timein);
	tempo = timein;
	while (timein)
	{
		if (timein >= 3600)
		{
			hms[0]++;
			timein -= 3600;
		}
		else if (timein >= 60)
		{
			hms[1]++;
			timein -= 60;
		}
		else
		{
			hms[2] = timein;
			timein = 0;
		}
	}
	printf("%d seconds is equivalent to %d hours %d minutes %d seconds\n", tempo, hms[0], hms[1], hms[2]);
#endif

#if 0
	/* Write a program to read two integers with the following significance.
	The first integer value represents a time of day on a 24 hour clock, so that 1245 represents quarter to one mid-day, for example.
	The second integer represents a time duration in a similar way, so that 345 represents three hours and 45 minutes.
	This duration is to be added to the first time, and the result printed out in the same notation, 
	in this case 1630 which is the time 3 hours and 45 minutes after 12.45.
	Typical output might be Start time is 1415. Duration is 50. End time is 1505.
	There are a few extra marks for spotting.
	Start time is 2300. Duration is 200. End time is 100. */



	return 0;

#endif

}
#endif