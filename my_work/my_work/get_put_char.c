#if 0
#include <stdio.h>

#define in 1 //inside a word
#define out 0 //outside a word


int main()
{
	int c, nl, nw, nc, state;

	state = out;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state = out;
		else if (state == out)
		{
			state = in; ++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
#endif 
