#if 0
//To demostarate different storage classes
#include <stdio.h>
//declaring and initializing an extern variable
extern int x = 9;

//declaring and initialized a global variable z
//simply int z; would have initialized z with 
//the default value of a global variable which is 0
int z = 10;

int main()
{
	//declaring an auto variable(simply
	//writing "int a = 32 works as well)
	auto int a = 32;

	//declaring a register variable
	register char b = 'G';

	//telling the compiler that the variable z is an extern variable
	//and has been defined elsewhere(above the main function)
	extern int z; 

	printf("buddy\n");
	
	//print value of auto variable 'a'
	printf("value of auto int a: %d\n", a);

	//print the extern variables 'x' and 'z'
	printf("value of x : %d and value of z : %d\n", x, z);

	//print reg var 'b'
	printf("value of reg b : %c\n", b);

	//mod value of extern var
	x = 2;
	
	z = 5;
	//print mod extern var
	printf("values of mod extern x: %d z : %d\n", x, z);


	while (x > 0)
	{
		static int y = 5;
		y++;

		//printing value of y at each iteration
		printf("the value of y is %d\n", y);
		x--;
	}
	return 0;

}

#endif