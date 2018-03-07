#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define EQZ 0
#define EQL 1
#define GRT 2
#define GRE 3
#define LSS 4
#define LSE 5
#define SGN 6

int main()
{
	short int a[MAX];
	short int b[MAX];
	unsigned short int c[MAX];
	unsigned short int temp = 0;

	for (int i = 0; i < MAX; i++)
	{
		a[i] = (rand() % 15) - 8;
		b[i] = (rand() % 15) - 8;
	}

	for (int i = 0; i < MAX; i++)
	{
		c[i] = 0;

		temp = (!(a[i])) ? 1 << EQZ : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] == b[i]) ? 1 << EQL : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] > b[i]) ? 1 << GRT : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] >= b[i]) ? 1 << GRE : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] < b[i]) ? 1 << LSS : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] <= b[i]) ? 1 << LSE : 0;
		c[i] |= temp;
		temp = 0;

		temp = (a[i] & 0x8000) ? 1 << SGN : 0;
		c[i] |= temp;
		temp = 0;

	}

	FILE *stream;
	errno_t err;

	err = fopen_s(&stream, "compout.txt", "w");
	if (err == 0) puts("File open to write");

	fputs("# compout.txt\n", stream);
	fputs("#\n", stream);
	fputs("# 4/30/2017\n", stream);
	fputs("#\n", stream);
	fputs("# Simple ALU testbench stimulus and expected response.\n", stream);
	fputs("#\n", stream);
	fputs("# File data format = (a, b, y)\n", stream);
	fputs("#\n", stream);

	for (int i = 0; i < MAX; i++)
	{
		fprintf_s(stream, "%d\t%d\t%d\n", a[i], b[i], c[i]);
	}

	fclose(stream);

}
#endif // 0
