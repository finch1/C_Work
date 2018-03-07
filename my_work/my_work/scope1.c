#if 0
#include <stdio.h>

int main()
{
	{
		int x = 10, y = 20;
		{
			//the outer block contains declaration of x and y, so the 
			//folowing statement is valid and prints 10 and 20
			printf("x = %d, y = %d\n", x, y);
			{
				//y is declared again, so outer block y is not accessiable in this block
				int y = 40;
				x++; //changes outher block variable x
				y++; //changes this block variable y
				printf("x = %d, y = %d\n", x, y);
				{
					int z = 99;
					printf("x = %d, y = %d, z = %d\n", x, y, z);
				}
			}
			//this statement accesses only outer block variables
			printf("x = %d, y = %d\n", x, y);
		}

	}
	return 0;
}

#endif