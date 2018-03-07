#if 0
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

#define MEM_BLOCK 10

void sort(int* arrptr, int mem_size)
{
	int i, j, temp_store, cnt;

	for (i = 0; i < mem_size; i++)
	{
		temp_store = arrptr[i];
		for (j = i; j < mem_size; j++)
		{
			if (temp_store >= arrptr[j])
			{
				temp_store = arrptr[j];
				cnt = j;
			}
		}
		arrptr[cnt] = arrptr[i];
		arrptr[i] = temp_store;
	}
}

int main()
{

	int i = 0, j = 0, cnt = MEM_BLOCK;
	bool stop = true;

	int* tubs = (int*)malloc(sizeof(int) *MEM_BLOCK);
	if (tubs == NULL)
	{
		puts("Memory allocation not avaialble!");
	}
	puts("enter numbers. to show result press x:");

	while (stop)
	{
		if (scanf("%d", &j)) //getchar buffer has number and caredge return so wanna skip that.
		{
			tubs[i] = 0;
			tubs[i++] = j; //convert ascii char to integer number
			cnt--;
		}
		else { stop = false; }

		if (!cnt)
		{
			cnt = MEM_BLOCK;

			tubs = (int*)realloc(tubs, sizeof(int) * MEM_BLOCK);
			if (tubs == NULL)
			{
				puts("Memory allocation not avaialble!");
			}
		}
	}

	sort(tubs, i);

	puts("numbers sorted:");

	for (j = 0; j < i; j++)
	{
		printf("%d\n", tubs[j]);
	}

	free(tubs);
	tubs = NULL;
}



#endif // 0
