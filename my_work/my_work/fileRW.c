#if 0

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 30



int main()
{
	FILE *stream;
	errno_t err;
	int ch_i;
	char ch;


	stream = fopen("demo.txt", "r");

	if (!stream)
	{
		puts("File not open dude!!");
	}

	while ((ch_i = fgetc(stream)) != EOF)
	{
		printf("%c", ch_i);
	}

	printf("\n now right some stuff\n");

	stream = fopen("demo.txt", "a+");

	while ((ch = getchar()) != EOF)
	{
		putc(ch, stream);
	}



	fclose(stream);
	return 0;
}
#endif