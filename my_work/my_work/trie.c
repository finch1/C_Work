#if 0
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#define ALPH_SIZE 3
#define CASE 'a'

/*
typedef   struct MyStruct   node    node_a ;
| 			     | |     | |      |
typedef         int		    MyInt      i   ;
MyInt is a new type of int.
*/

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

int main()
{
	node *root;
	root = calloc(1, sizeof(node));

	char string[10] = { "a" };
	insertnode(root, string);
	memset(string, 0, (unsigned)_countof(string));

	strcpy(string, "ab");
	insertnode(root, string);
	memset(string, 0, (unsigned)_countof(string));

	strcpy(string, "abc");
	insertnode(root, string);
	memset(string, 0, (unsigned)_countof(string));

	strcpy(string, "ca");
	insertnode(root, string);
	memset(string, 0, (unsigned)_countof(string));

	strcpy(string, "cab");
	insertnode(root, string);
	memset(string, 0, (unsigned)_countof(string));

	search(root, "cab");
	deletenode(root, "cab")

		return 0;
}
#endif // 0
