#if 0

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 30

struct student
{
	char name[MAXLINE];
	float marks;
};

FILE *stream;

int main()
{
	errno_t err;
	char ch;

	struct student s1, s2;
	err = fopen_s(&stream, "student.dat", "w+b");
	if (err) puts("file not open!!");

	while (1)
	{
		printf("enter name: ");  scanf_s("%s", s1.name, (unsigned)_countof(s1.name));

		printf("enter marks: "); scanf_s("%f", &s1.marks);

		fwrite(&s1, sizeof(s1), 1, stream);

		printf("continue y/n"); ch = getch(); printf(" %c\n", ch);
		if (ch == 'N' || ch == 'n') break;
	}


	fseek(stream, 0, 0);
	while (1)
	{
		int n = fread(&s1, sizeof(s1), 1, stream);
		if (!n) break;
		printf("%s %.0f\n", s1.name, s1.marks);
	}



	fclose(stream);

	return 0;
}
#endif