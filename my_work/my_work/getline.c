#if 0
#include <stdio.h>

#define MAXLINE 1000 //maximum inout line size

//read a line into s, return length
int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

//copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

//print longest input line
int main()
{
	int len; //current line length
	int max; //max length seen so far
	char line[MAXLINE]; //current input line
	char longest[MAXLINE]; //longest line saved here

	max = 0;
	while (len = getline(line, MAXLINE))
	{
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) // there was a line
		printf("%s", longest);
	return 0;

}
#endif

//same  same with external variables
#if 0
#include <stdio.h>

#define MAXLINE 1000 //maximum inout line size

int max; //max length seen so far
char line[MAXLINE]; //current input line
char longest[MAXLINE]; //longest line saved here

//read a line into s, return length
int getline()
{
	int c, i;

	for (i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n')
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

//copy 'from' into 'to'; assume to is big enough
void copy()
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}

//print longest input line
int main()
{
	int len; //current line length	
	extern int max;	
	extern char longest[]; //longest line saved here

	max = 0;
	while (len = getline())
	{
		if (len > max)
		{
			max = len;
			copy();
		}
	}

	if (max > 0) // there was a line
		printf("%s", longest);
	return 0;

}
#endif
