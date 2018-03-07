#if 0


#include <stdio.h>

FILE *stream;

int main()
{
	char str[50];
	int i, n = 2;

	errno_t err;
	//open for read(will fail if file doesn't exist
	err = fopen_s(&stream, "sample.txt", "a");

	if (err)
	{
		puts("File not open");
	}
	else
	{
		puts("File open");
		for (i = 0; i < n; i++)
		{
			puts("enter a name");
			gets(str);
			fprintf(stream, "%d.%s\n", i, str);
		}
		fclose(stream);
	}



	return 0;
}
#endif