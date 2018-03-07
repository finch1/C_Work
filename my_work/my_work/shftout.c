#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
	short int a[MAX];
	short int dist[MAX];
	short int left[MAX];
	short int right[MAX];
	unsigned short int temp = 0, temp1 = 0;

	for (int i = 0; i < MAX; i++)
	{
		a[i] = (rand() % 15) - 8;
	}

	for (int i = 0; i < MAX; i++)
	{
		dist[i] = i % 4;
		temp = a[i] << dist[i];
		temp &= 0x000F;
		left[i] = temp;

		temp1 = a[i] >> dist[i];
		temp1 &= 0x000F;
		right[i] = temp1;
	}

	FILE *stream;
	errno_t err;

	err = fopen_s(&stream, "shftout.txt", "w");
	if (err == 0) puts("File open to write");

	fputs("# shftout.txt\n", stream);
	fputs("#\n", stream);
	fputs("# 4/30/2017\n", stream);
	fputs("#\n", stream);
	fputs("# Simple ALU testbench stimulus and expected response.\n", stream);
	fputs("#\n", stream);
	fputs("# File data format = (data, distance, direction, expected)\n", stream);
	fputs("#\n", stream);

	for (int i = 0; i < MAX; i++)
	{
		fprintf_s(stream, "%d\t%d\t%d\t%d\n", a[i], dist[i], 0, left[i]);
	}
	for (int i = 0; i < MAX; i++)
	{
		fprintf_s(stream, "%d\t%d\t%d\t%d\n", a[i], dist[i], 1, right[i]);
	}
	fclose(stream);

}
#endif // 0
