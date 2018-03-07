#if 0
//an example of variable scope

#include <stdio.h>
#include <string.h>

int nlife = { 5 }; //initialize to 5, defualt is 0

void displaylife()
{
	printf("displaylife(), nlife = %d\n",nlife);
}

int main()
{
	int ncounter = 0;
		do
		{
			int ncountloop = 0; //this ncounter is unique to the loop
			ncountloop += 3; //increments and prints the loop's ncounter
			nlife += ncounter;
			printf("ncountloop is = %d\n", ncountloop);

		}while (++ncounter < 10); // increments the function's n counter
	
	displaylife();
	
	printf("ended, ncounter is = %d \n", ncounter);

	return (0);
}


#endif


