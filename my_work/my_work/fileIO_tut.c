/*---------------------------------------*/
// Opening a File

/* fopen_s() opens the file whose name is specified by the string filename. The
filename may contain a directory part, and must not be longer then the
maximum length specified by the value of the macro FILENAME_MAX. The first argument
is a pointer to the file pointer that will receive the pointer to the opened file.
The third argument, mode, is also a string, and specifies the access mode.
fopen_s() associates the file with a new stream.

--		errno_t fopen_s( FILE ** stream,
const char * restrict filename,
const char * restrict mode );
Modes:
"r" : opens for reading. If the file doesnt exist or cannot be found, the fopen_s call fails.
"w" : opens / creates an empty file for writing. If the file exists, its contents overwritten.
"a" : opens for writing at the end of the file (appending) without removing the EOF marker
before writing new data to the file. Creates the file if it doesn't exist.
(+) : both read and write operations are permitted. However a program must not alternate
immediately between reading and writing. After a write operation, you must call the fflush()
or positioning function; fseek(), fsetpo(), rewind()) before performing a read operation.
After a read operation, you must call a positioing function before performing a write operation.
"r+": opens for both reading and writing, start at the beginning. The file must exist.
"w+": opens / creates an empty file for both reading and writing. If the File exists, its contents are destroyed (overwrite).
"a+": opens for reading and appending. The appending operation includes the removal of the EOF marker before new data is written to the file and
the EOF marker is restored after writing is complete. Creates the file if it doesn't exist.
"b" : the new stream associated with the file is a binary stream and the file is opened in binary mode.*/



/*---------------------------------------*/
// Re-opening a File

/*freopen_s() redirects a stream. It opens the specified file in the specified mode.
However rather then creating a new stream, it associates the file with the
existing stream specified by the forth argument. The file previously associated
with that stream is closed. freopen_s() is typically used to redirect the pre-opened
files stdin, stdout and stderr to files specified by the user. The first argument is
a pointer to the file pointer to be provided by the call.

--	errno_t freopen_s(	FILE ** stream
const char * restrict filename, //restricted as in specific
const char * restrict mode,
FILE * stream);
*/



/*---------------------------------------*/
// Print to stream (mainly files). Wrtie to a text file

/*fprintf() prints formatted data to a stream. First parameter is a pointer to FILE structure.
Seccond is format control string. Third is optional. Function returns the number of bytes
written and negatice value when an output error occurs. fprintf() formatis and prints a
series of characters and values to the output stream. Each function argument(if any) is
converted and output accordingly to the corresponding format specification.


--	int fprintf(	FILE * stream,
const char *format[,argument]);
*/

/*---------------------------------------*/
// Read from a text file

/*fscanf() Reads the integer present in the file and prints it onto the screen.


--	int fscanf(	FILE * stream, escape sequence
const char *string);
*/

/*---------------------------------------*/
// Flushes a stream

/*fflush() flushes the stream. Make sure any outstanding data is actually
written to the file before the function returns.

--	int fflush(	FILE * stream);

*/

/*---------------------------------------*/
// Unformatted IO

/*fgets() reads a line from the specified stream and stores it into the string pointed
to by str. It stops when either (n -1) characters are read, the newline character is
read or the EOF is reached, whichever first.

--	  char *fgets(char *str, int n, FILE *stream);

fgetc() gets the next character (an unsigned char)
from the specified stream and advances the position for the stream.

--	  int fgetc(FILE *stream);

fputc() writes a character (an unsigned char) specified by the argument char to the specified
stream and advances the position indicator for the stream.

--	  int fputc(int char, FILE *stream);

fputs() writes a string to the specified stream up to but not including the null character

--	  int fputs(const char *str, FILE *stream);

feof() returns true once end of file is reached. This has to be
used in a loop to get to end of file.

--	  int feof(stream);

//Reading and writing to binary files

fwrite() writes data from the array pointed to by ptr to the given stream.
Returns the total number of elements successfulleu returned as a size_t object,
which is an integral data type. Same with fread().

First Parameter : pointer to the array of elements to be written.
Second Parameter: the size in bytes of each element to be written.
Third Parameter : number of elements, each one with size of (size) bytes.
Fourth Parameter: pointer to file object that specifies an output stream.

--	  size_t fwrite(const void *ptr, size_t size, size_t numbers_data, FILE *stream);
--	  size_t fread(const void *ptr, size_t size, size_t numbers_data, FILE *stream);
*/


/*---------------------------------------*/
// Getting Data

/*fseek() seeks the cursor to the given record in the file. The first parameter is
the pointer to the file. The second parameter is the position of the recod to be
found. The third parameter specifies the location where the offset starts.

Different Whence in fseek
SEEK_SET - Starts the offset from the beginning of the file.
SEEK_END - Starts the offset from the end of the file.
SEEK_CUR - starts the offset from yhe current location of the cursor in the file.

--	int fseek(	FILE * stream,
long int offset,
int whence);
*/

// fileIO_tut.c
// 4/23/2017
// Ref : C in a nutshell, MSDN, tutorialspoint.com
// This program opens two files. It uses fclose to close the first file and
// _fcloseall to close all remaining files.

#if 0

//http://stackoverflow.com/questions/14768230/malloc-for-struct-and-pointer-in-c
//
//http://stackoverflow.com/questions/26206667/do-we-have-to-malloc-a-struct

#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <errno.h>
#include <stdbool.h>

#define BUFFSIZE(x) (unsigned)_countof(x)
#define HASHSIZE 26

#define ALPH_SIZE 26
#define CASE 'a'

/*global variables*/
char selection = 'Y';

void userselection()
{
	char c;
	printf("%c", selection);
	for (;;)
	{	// Check to see if a key has been pressed... If so getch it
		if (_kbhit())
		{
			c = (char)_getch();
			if (c == 'n' || c == 'N' || c == 'y' || c == 'Y')
			{
				selection = c;
				printf("\b");
				putc(c, stdout);

			}
			if (c == '\r')
			{
				puts("\n");
				break;
			}


		}
	}
}

typedef struct MyStruct node;
struct MyStruct
{
	int occurences;
	node *children[ALPH_SIZE];
	node *prev_char;
};

void insertnode(node *trietree, char *word)
{
	node *currentnode = trietree;

	while (*word != '\0')
	{
		if (currentnode->children[*word - CASE] == NULL)
		{
			currentnode->children[*word - CASE] = calloc(1, sizeof(node));
			currentnode->children[*word - CASE]->prev_char = currentnode;
		}

		currentnode = currentnode->children[*word - CASE];
		++word;

	}
	currentnode->occurences++;
}

node *search(node *trietree, char *word)
{
	while (*word != '\0')
	{
		if (trietree->children[*word - CASE] != NULL)
		{
			trietree = trietree->children[*word - CASE];
			++word;
		}
		else return NULL;
	}

	if (trietree->occurences != 0) return trietree;
	else return NULL;
}

void deletenode(node *trietree, char *word)
{
	node *currentnode = search(trietree, word);

	if (currentnode != NULL)
	{
		currentnode->occurences--;
		node *prev_char = NULL;
		bool isleaf = true;

		for (int i = 0; i < ALPH_SIZE; i++)
		{
			if (currentnode->children[i] != NULL)
			{
				isleaf = false;
				//free mem
				break;
			}
		}

		while (currentnode->prev_char != NULL && isleaf && currentnode->occurences == 0)
		{
			prev_char = currentnode->prev_char;
			for (int i = 0; i < ALPH_SIZE; i++)
			{
				if (prev_char->children[i] == currentnode)
				{
					prev_char->children[i] = NULL;
					free(currentnode);
					currentnode = prev_char;
				}
				else if (prev_char->children[i] != NULL)
				{
					isleaf = false;
					break;
				}
			}
		}

	}
}


FILE *stream, *stream2;

int main(void)
{
	/*internal variables*/
	//struct MyStruct
	//{
	//	char filename[14];
	//	struct MyStruct *nxt_ptr;
	//} table_struct;

	int menu_sel = 10;
	int count;

	char filename[14];
	char userinput[256];
	char filesrc = 0;
	char extension[] = ".txt";
	struct MyStruct *hastable[HASHSIZE];
	char let_indx;

	FILE *stream;
	errno_t err;

	node *root;
	root = calloc(1, sizeof(node));

	//for (count = 0; count < HASHSIZE; count++)
	//{
	//	hastable[count] = (struct MyStruct*)malloc(sizeof(struct MyStruct)); //pointer to a structure		
	//	hastable[count]->filename[0] = '\0';
	//	hastable[count]->nxt_ptr = NULL;
	//}


	switch (menu_sel)
	{
	case 10:
		printf("\
			0. Create Text File\n\
			1. Write to Text File\n\
			2. Read from Text File\n\
			3. Append to Text File\n\
			4. Delete Text File\n\
			5. Exit\n");

		printf("\nSelect number: ");
		scanf_s("%d", &menu_sel);

	case 0:
		memset(filename, 0, BUFFSIZE(filename));
		printf("\n\t->Creating Text File!\n");
		printf("\nWhat do you wanna name the file?\n\tMax 10 characters: ");
		scanf_s("%10s", filename, BUFFSIZE(filename));
		printf("Do you want to create file '%s' ? ", filename);

		userselection();

		if (selection == 'Y' || selection == 'y')
		{
			insertnode(root, filename);

			strcat_s(filename, BUFFSIZE(filename), extension);

			stream = fopen(filename, "r");
			if (stream != NULL)
			{
				printf("File already exists. Please choose another file name!\n");
				fclose(stream);
				stream = NULL;
			}
			else
			{
				err = fopen_s(&stream, filename, "w");
				if (err == 0)
				{
					fprintf(stdout, "File succesfully created!\n");
				}
				else fprintf(stdout, "Error creating file!\n");

				fclose(stream);
				stream = NULL;
			}
		}
		break;

	case 1:
		memset(filename, 0, BUFFSIZE(filename));
		memset(userinput, 0, BUFFSIZE(userinput));

		printf("\nWriting To Text File!\n");
		printf("\nWhat is the name of the file you want to open?\n\tMax 10 characters: ");
		scanf_s("%10s", filename, BUFFSIZE(filename));
		printf("Do you want to open this file '%s' ? ", filename);

		userselection();

		if (selection == 'Y' || selection == 'y')
		{
			strcat_s(filename, BUFFSIZE(filename), extension);
			err = fopen_s(&stream, filename, "w");
			if (err == 0)
				fprintf(stdout, "File succesfully opened!\n");
			else fprintf(stdout, "Error opening file!\n");

		}

		printf("Start Typing:\n");

		for (count = 0; count <= 255; count++)
		{
			userinput[count] = _getche();
			if (userinput[count] == '\x1a')
				break;
		}

		userinput[count] = '\0';
		fputs(userinput, stream);

		fflush(stdout);
		fclose(stream);
		stream = NULL;
		break;

	case 2:
		//memset(filesrc, 0, BUFFSIZE(filesrc));
		printf("\nRead From Text File!\n");
		printf("\nWhat is the name of the file you want to read from?\n\tMax 10 characters: ");
		scanf_s("%10s", filename, BUFFSIZE(filename));
		printf("Do you want to open this file '%s' ? ", filename);

		userselection();

		if (selection == 'Y' || selection == 'y')
		{
			strcat_s(filename, BUFFSIZE(filename), extension);

			err = fopen_s(&stream, filename, "r");
			if (err == 0)
			{
				fprintf(stdout, "File succesfully opened!\n");
				do
				{
					putc(filesrc, stream);
				} while (filesrc != feof);

				//fscanf_s(stream, "%s", filesrc);
				printf("%s", filesrc);
			}


#endif // 0
