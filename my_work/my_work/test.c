#if 0

#include <stdio.h>
//#include "somefile.h"

struct packet_struct
{
	unsigned int f1 : 1;
	unsigned int f2 : 1;
	unsigned int f3 : 1;
	unsigned int f4 : 1;
	unsigned int type : 4;
	unsigned int funny_int : 9;

}pack;

struct regrecord { char *name; short int value; };
struct regrecord regtable[] =
{ { "A",0x00 },{ "B",0x01 },{ "C",0x02 },
{ "D",0x03 },{ "E",0x04 },{ "F",0x05 },
{ "G",0x06 },{ "H",0x07 },{ "I",0x08 },
{ "J",0x09 },{ "X",0x0a },{ "Y",0x0b } };




int main()
{
	int i = 0;
	short int y = 0;
	char namebuf[] = "H\0G";
	printf("%c %c\n", namebuf[0], regtable[i].name);
	for (i = 0; i < 12; i++) {
		if (*regtable[i].name == namebuf[0])
			y = regtable[i].value;
	}
	printf("%d\n", y);
	printf("size of structure with bit field = %d\n", sizeof(pack));
	pack.f1 = 1;
	pack.f2 = 1;
	pack.f3 = 0;
	pack.f4 = 0;
	pack.type = 12;
	pack.funny_int = 200;

	printf("%x\n", pack.type);
}


	typedef struct MySecStruct pupil_details;

	struct MySecStruct
	{
		int age;
		float weight;
		pupil_details *twins;
	};

	pupil_details *personPtr, person1, person2;
	personPtr = &person1;

	printf("Enter integer age: ");
	scanf("%d", &(*personPtr).age);

	printf("Enter float weight: ");
	scanf("%f", &person1.weight);

	printf("Displaying: ");
	printf("%d  %0.1f\n", person1.age, (*personPtr).weight);

	printf("Enter float weight: ");
	scanf("%f", &personPtr->weight);

	printf("Displaying: ");
	printf("%d  %0.1f\n", person1.age, personPtr->weight);

	person2.age = 35;

	personPtr->twins = &person2;
	personPtr->twins->twins = &person1;

	printf("%d\n", person1.age);
	person1.age++;
	printf("%d\n", person1.age);

	

	return 0;



#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // for uint32_t, to get 32bit-wide rotates, regardless of the size of int.
#include <limits.h>  // for CHAR_BIT
#include <string.h>

#define MAX 10



	char *results[] = { "ADD_RESULT",
						"SUB_RESULT" };

#define RESNUM (sizeof(results) / sizeof(const char *)) 


	/*declare variables to be used by all alu functions*/
	typedef struct MyStruct myvars;

	struct MyStruct
	{
		short int var_a[MAX];
		short int var_b[MAX];
	};

	void signed_refill(myvars *alu_inputs)
	{
		myvars *test_input = alu_inputs;

		/*fill array elements*/
		for (int i = 0; i < MAX; i++)
		{
			test_input->var_a[i] = (rand() % 257) - 128;
			test_input->var_b[i] = (rand() % 257) - 128;
		}
	}



	unsigned int find_index(char *ref, char *find)
	{
		for (int i = 0; i < RESNUM; i++)
		{
			if (strcmp(ref, find)) return i;
		}
	}

	int main()
	{
		/*declare variables to work with*/
		myvars alu_inputs;

		/*fill up with values*/
		signed_refill(&alu_inputs);

		short int *alu_results[RESNUM];

		for (int i = 0; i < RESNUM; i++)
		{
			alu_results[i] = (short int*)malloc(sizeof(short int) * MAX);
		}

		for (int i = 0; i < MAX; i++)
		{
			//*alu_results[find_index][i] = alu_inputs.var_a[i] + alu_inputs.var_b[i];
		}
	}
#endif // 0
