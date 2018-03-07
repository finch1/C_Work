#if 0
#include <stdio.h>

//declare and initializeing an extern variable
extern int x = 9;

//declaring and intializing a global variable
//simply int z; would have intitialized z with
//the default value of a global variable whish is 0
int z = 10;

//using typedef to giva a hort name to a long long int
//very convenient to use now due to the short name
typedef long long int LL;

//function prints square of a no. and which has a void as 
//its return data
void callsquare(int arg)
{
	printf("the square of %d is %d\n", arg, arg*arg);
}

//here void means take no parameters
int main(void)
{
	//declaring a constant variable, its value cannot be modified
	const int a = 32;

	//declaring a char variable
	char b = 'G';

	//telling the compiler that the variable z is an external variable 
	//and has been defined elsewhere(above the main function)
	extern int z;

	LL c = 1000000;

	printf("hello gay!\n");

	//printing the above variables
	printf("this is the value of the constant variable 'a':%d\n",a);
	printf("'b' is a char variable. its value is %c\n", b);
	printf("'c' is a long long int variable. its value is %lld\n", c);
	printf("these are the values of the extern variables 'x' and 'z' resp: %d and %d\n", x, z);

	//value of extern variable x modified
	x = 2;

	//value of extern variable z modified
	z = 5;

	//printing the modified values of extern variables 'x' and 'z'
	printf("these are modified values of the extern variables"
		" 'x' and 'z' resp: %d and %d\n",x , z);

	//using a static variable
	printf("the value of a static variable 'y' is NOT intialized"
		" to 5 first iteration! See for yourself :)\n");

	while (x > 0)
	{
		static int y = 5;
		y++;
		//printing value at each iteraion
		printf("the value of y is %d\n", y);
		x--;
	}

	//print square of 5
	callsquare(5);

	printf("bye! see you soon. \n");

	return 0;
}

#endif