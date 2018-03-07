#if 0
#include <stdio.h>
#define INCREMENT(x) ++x
#define MULTIPLY(a, b) a * b
#define MERGE(a, b) a##b //concatenation
#define GET(a) #a // token passed converted to a string literal
#define PRINT(i, limit) while(i < limit) {printf("Geek\n"); i++;}
#define SQUARE(x) x*x //wrong output

inline int square(int x) { return x*x; }

int main(void)
{
	char *ptr = "geeksquiz";
	int x = 10;
	printf("%s  ", INCREMENT(ptr));
	printf("%d", INCREMENT(x));
	printf("\n%d\n", MULTIPLY(2 + 3, 3 + 5));
	printf("%d\n", MERGE(12, 34));
	printf("%s\n", GET(GeeksQuiz));
	x = 0;
	PRINT(x, 3);
	x = 36 / SQUARE(6);
	printf("%d\n", x);

	x = 36 / square(6);
	printf("%d\n", x);

	printf("current file: %s\n", __FILE__);


	return 0;
}
#endif