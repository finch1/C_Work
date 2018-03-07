#if 0
#include <stdio.h>

int main()
{
	float x = 0.3;
	if (x == 0.3) printf("IF\n");
	else if (x == 0.3f) printf("ELSE IF\n");
	else printf("ELSE\n");

	printf("%d %d %d\n", sizeof(x), sizeof(0.3), sizeof(0.3f));

	{
		float x = 0.5;
		if (x == 0.5) printf("IF\n");
		else if (x == 0.5f) printf("ELSE IF\n");
		else printf("ELSE\n");

		printf("%d %d %d\n", sizeof(x), sizeof(0.5), sizeof(0.5f));
	}
	float f = 0.25; //double converted to float
	double d1 = 0.25; //double kept as double
	double d2 = f; //float converted back to double

	printf("float            :%0.6f\n", f);
	printf("double           :%0.6f\n", d1);
	printf("double from float:%0.6f\n", d2);


	return 0;
}
#endif