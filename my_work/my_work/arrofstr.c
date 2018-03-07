/*had a little issue here with free(). Error: CRT detected that the application wrote to memory after end of heap buffer
solution:
Suppose one allocates a heap buffer:
	char* buffer = malloc(5);
Ok, buffer now points to five chars on the heap
Suppose one writes six characters into that buffer:
	buffer[0] = 'a';
	buffer[1] = 's';
	buffer[2] = 'd';
	buffer[3] = 'f';
	buffer[4] = 'g';
	buffer[5] = '\0';
Now the heap is corrupt. one was allowed only five chars but wrote six */

#if 0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

void safefree(void **par)
{
	free((void*)*par);
	*par = NULL;
}


int main(void)
{
	char* allstr;
	char* messages[MAX];
	int i = 0;
	int total = 1;

	for (i = 0; i < MAX; i++)
	{
		messages[i] = (char*)malloc(sizeof(char) * 10);
		printf("enter a string hombre: ");
		scanf("%s", messages[i]);
		total += strlen(messages[i]);
	}

	allstr = (char*)malloc(total + MAX);
//	memcpy(allstr, messages[0], total); //copies exact bytes specified in last parameter for me irrespective wheather the source is null terminated or not. 
	strcpy(allstr, messages[0]); //terminates when it encounters null char. 

	for (i = 1; i < MAX; i++)
	{
		strcat(allstr, " "); //this was messing everything as we were storing more than the allocated memory could handle
		strcat(allstr, messages[i]);
	}
	printf("%s\n", allstr);

	//deallocating dynamic memory
	safefree(&allstr);

	for (i = 0; i < 5; i++)
	{
		safefree(&messages[i]);
	}
}


#endif


//test program to understand pointer & arrays
#if 0
# include <stdio.h>

int main()
{
	int *ptr[10];
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

	printf("\n%p %p %p %p %d %p %u %u",ptr, &ptr[0], &ptr[1], a, a[2], &a[2], ptr[0], ptr[1]);
		//ptr, &ptr[0], a, a[2], &a[2], ptr[0], ptr[1]
	*ptr = a; //ptr[0] is assigned with address of array a

	printf("\n%p %p", ptr[0], a); //gives you same address

	printf("\n%d\n", *ptr[0]); //prints zero. if *ptr[1] is given then *(ptr + 1) i.e ptr[1] is considered which is unitialized one

	printf("\n%p %p %p %d %p %u %u\n", ptr, &ptr[0], a, a[2], &a[2], ptr[0], ptr[1]);
	return 0;
}

#endif

#if 0

#include <stdio.h>
#include <malloc.h>

#define MAX_N 5
#define OFFSET sizeof(char)

int main()
{
	int cnt = 0;
	char fill = 'a';

								 //size of pointer to a char *5
	char** names = (char**)malloc((sizeof(char*) * MAX_N));
	//what does this mean as i saw only one pointer was returned while debugging. 

	while (cnt < MAX_N)
	{
		*names = fill;
		fill++;
		cnt++;
		*names += OFFSET;
	}
	while (cnt)
	{
		printf("%c", *names - cnt);
		cnt--;
	}
	
	free(names); //correct? cause free() is waiting for a pointer.
	//which one?
	*names = NULL;	
	//or
	names = NULL;

	return 0;
}
#endif

#if 0

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

#define MAX_N 5
#define OFFSET sizeof(char)
#define NAME_LENGTH	10

int main()
{
	int cnt = 0;
	char fill = 'a';


	char** names = (char**)malloc((sizeof(char*) * MAX_N));
/*
	Yes, you only get one pointer... which is a pointer to a block of memory that is MAX_N char pointers long.
	Now we have... 
	names -> [[char*][char*][char*][char*][char*]] (0x10000000)
	|		 |      |      |				-> ?   (RandomCrap)
	|		 |		|				 -> ?          (RandomCrap)
	|		 |				  -> ?                 (RandomCrap)
	|				   -> ?                        (RandomCrap)
	            -> ?                               (RandomCrap)
	*/
	
	/* You need to make all the char* point to something useful. */
	for (cnt = 0; cnt < MAX_N; cnt++) {
		names[cnt] = (char*)malloc(NAME_LENGTH);
	}
	/*
	Now we have... (Address are meant up to show that they are not contiguous.)
	names -> [[char*][char*][char*][char*][char*]]		(0x10000000)
	|      |      |      |      -> [char * NAME_LENGTH] (0x11000000)
	|	  |	 |		-> [char * NAME_LENGTH]				(0x12000000)
	|	  |	 -> [char * NAME_LENGTH]					(0x13000000)
	|	  -> [char * NAME_LENGTH]						(0x14000000)
	-> [char * NAME_LENGTH]                             (0x15000000)
	*/

	/* This would appear to be trying to fill all the names with {fill}, so lets do that. */
	/*
	while (cnt < MAX_N)
	{
	*names = fill;
	fill++;
	cnt++;
	*names += OFFSET;
	}
	*/
	for (cnt = 0; cnt < MAX_N; cnt++) {
		memset(names[cnt], fill, NAME_LENGTH); /* Quick and Dirty way... using memset. */
		names[cnt][NAME_LENGTH - 1] = 0; // Null termimnate the name.
	}

	/* This would appear to be trying to print the names. */
	/*
	while (!cnt)
	{
	printf("%c", *names - OFFSET);
	}
	*/
	for (cnt = 0; cnt < MAX_N; cnt++) {
		printf("%s\n", names[cnt]); /* %s is print null terminated string. \n starts a new line. */
	}

	printf("\n\n"); /* Lets have two blank lines. */

					/* Lets copy some names into the array. */
	strcpy(names[0], "Gringo");
	strcpy(names[1], "Guru");
	strcpy(names[2], "Jacobo");

	for (cnt = 0; cnt < MAX_N; cnt++) {
		printf("%s\n", names[cnt]); /* %s is print null terminated string. \n starts a new line. */
	}

	/* Now to tidy up... */
	/* -- Free the names (the char*) */
	for (cnt = 0; cnt < MAX_N; cnt++) {
		free(names[cnt]);
	}
	/*
	Now we have... (Address are meant up to show that they are not contiguous. The X is because the memory is now unallocated.)
	names -> [[char*][char*][char*][char*][char*]] (0x10000000)
	|      |      |      |      -> X   (0x11000000)
	|	  |	 |		-> X          (0x12000000)
	|	  |	 -> X                 (0x13000000)
	|	  -> X                        (0x14000000)
	-> X                               (0x15000000)
	*/

	/* Now free the top-level array. */
	free(names);
	names = NULL; 

	return 0;
}

#endif