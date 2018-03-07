#include <stdint.h>  // for uint32_t, to get 32bit-wide rotates, regardless of the size of int.
#include <stdlib.h>

#pragma once
#ifndef myfuncs
#define myfuncs

#define EQZ 0
#define EQL 1
#define GRT 2
#define GRE 3
#define LSS 4
#define LSE 5
#define SGN 6

#define MAX 100000
#define HEXMASK 0xFFFF
#define WIDTH 16
#define FLAGSHFT 8
#define COMPSHFT 16
#define RESSHFT  8

//#define FLAGMASK 0xFF000000
//#define CARRYMASK 0x00010000

#define FLAGS(x)  (x & 0xFF000000) >> 24
#define COMPAB(x) (x & 0x00FF0000) >> 16
#define RESULT(x) (x)// & 0x0000FFFF)

char *functions[] = {	"Addition",
						"Subtraction",
						"Logic OR",
						"Logic AND",
						"Logic NOT",
						"Logic XOR",
						"Increment",
						"Decrement",
						"Arithmetic Shift Left",
						"Arithmetic Shift Right",
						"Logic Shift Left",
						"Logic Shift Right",
						"Rotate Left",
						"Rotate Right",
						"Multiplication",
						"Division",
						"Modulus",
						"Compare",
						"Flags"};

/*sizeof(functions) is something that the compiler calculates
which ends up being the number of elements * the size of the type*/
#define FUNCNUM (sizeof(functions) / sizeof(const char *)) 

enum carry_ovfl_type { ADD_T, SUB_T, MUL_T};

/*declare variables to be used by all alu functions*/
typedef struct MyStruct myvars;

struct MyStruct
{
	int16_t min, max;
	int16_t var_a[MAX];
	int16_t var_b[MAX];
	uint16_t shftam[MAX];
};

void signed_refill(myvars *alu_inputs)
{
	myvars *test_input = alu_inputs;
	test_input->min = 0;
	test_input->max = 0;

	/*fill array elements*/
	for (int i = 0; i < MAX; i++)
	{
		//test_input->var_a[i] = (rand() % 16) -8;
		//test_input->var_b[i] = (rand() % 16) -8;
		test_input->shftam[i] = (rand() % 16);
		test_input->var_a[i] = (rand() -16468) *2;
		test_input->var_b[i] = (rand() -16378) *2;


		if (test_input->max < test_input->var_a[i])
			test_input->max = test_input->var_a[i];

		if (test_input->max < test_input->var_b[i])
			test_input->max = test_input->var_b[i];

		if (test_input->min > test_input->var_a[i])
			test_input->min = test_input->var_a[i];

		if (test_input->min > test_input->var_b[i])
			test_input->min = test_input->var_b[i];
	}
}

int16_t compare(int16_t a, int16_t b)
{
	char temp1 = 0, temp2 = 0;

	temp1 = (!(a)) ? 1 << EQZ : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a == b) ? 1 << EQL : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a > b) ? 1 << GRT : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a >= b) ? 1 << GRE : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a < b) ? 1 << LSS : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a <= b) ? 1 << LSE : 0;
	temp2 |= temp1;
	temp1 = 0;

	temp1 = (a & 0x8000) ? 1 << SGN : 0;
	temp2 |= temp1;
	temp1 = 0;


	return temp2;
}

int8_t getparity(uint16_t n)
{
	int8_t parity = 0;
	while (n)
	{
		parity = !parity;
		n = n & (n - 1);
	}
	return parity;
}


int8_t carry_overflow(int16_t a, int16_t b, short int type)
{
	unsigned char cr = 0, ov = 0;
	int16_t f, g; // size is enough to calculate overflow
	uint16_t y, z; // convert to unsigned to simulate carry
	int8_t temp = 0; // 8 bits enough for flags
	int32_t ans;

	f = y = a;
	g = z = b;

	switch (type)
	{
		case ADD_T:
		{
			
			ans = y + z; // unsigned addition
			cr = (0x10000 & ans) >> 16; // logic and carry and shift
			

			ans = f + g;	//signed addition

			if (ans < -32768)
			{
				ov = 1;	 
				ans &= 0x0000FFFF; // convert overflow to positive to keep in range
			}
			else if (ans > 32767)
			{
				ov = 1;
				ans |= 0xFFFF0000; //convert overflow to negative to keep in range
			}
			break;
		}
		case SUB_T:
		{
			ans = y - z; // unsigned subtraction
			cr = (0x10000 & ans) >> 16; // logic and carry and shift


			ans = f - g;	//signed subtraction

			if (ans < -32768)
			{
				ov = 1;
				ans &= 0x0000FFFF; // convert overflow to positive to keep in range
			}
			else if (ans > 32767)
			{
				ov = 1;
				ans |= 0xFFFF0000; //convert overflow to negative to keep in range
			}
			break;
		}
		case MUL_T:
		{
			ans = y * z; // unsigned multiplication
			cr = (0x10000 & ans) >> 16; // logic and carry and shift


			ans = f * g;	//signed multiplication

			if (ans < -32768)
			{
				ov = 1;
				ans &= 0x0000FFFF; // convert overflow to positive to keep in range
			}
			else if (ans > 32767)
			{
				ov = 1;
				ans |= 0xFFFF0000; //convert overflow to negative to keep in range
			}
			break;
		}
		default :
			break;
	}

	temp = cr << 1;
	temp |= ov;

	return temp;

}


int8_t getflags(int16_t a, int16_t b, int16_t type)
{
	int8_t temp = 0;

	temp = carry_overflow(a, b, type);
	temp = temp << 2;
	return temp;
}

// returns unsigned and need to be parsed 
uint32_t addition(myvars *alu_inputs, int a)
{

	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], test_input->var_b[a], ADD_T) << FLAGSHFT;			
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] + test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}


uint32_t subtraction(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], test_input->var_b[a], SUB_T) << FLAGSHFT;			
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] - test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x1000000;

	return temp;
}

uint32_t logic_or(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;			
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] | test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
	temp ^= 0x10000000;
	
	return temp;
}

uint32_t logic_and(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] & test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;
	
	return temp;
}

uint32_t logic_not(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t) (~test_input->var_a[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x1000000;
	
	return temp;
}

uint32_t logic_xor(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] ^ test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;
	
	return temp;
}

uint32_t increment(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], 1, ADD_T) << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)test_input->var_a[a] +1;			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;
	
	return temp;
}

uint32_t decrement(myvars *alu_inputs, int a)
{
	uint32_t temp;
	unsigned short banana;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], 1, SUB_T) << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	banana = test_input->var_a[a] - 1;
	temp |= (unsigned short)banana;			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x1000000;

	return temp;
}

uint32_t arith_shft_lft(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] << test_input->shftam[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

uint32_t arith_shft_rit(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] >> test_input->shftam[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

uint32_t logic_shft_lft(myvars *alu_inputs, int a)
{
	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)(test_input->var_a[a] << test_input->shftam[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

uint32_t logic_shft_rit(myvars *alu_inputs, int a)
{
	uint32_t temp;
	unsigned short apple;
	myvars *test_input = alu_inputs;
	temp = 0 << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	apple = (unsigned short)test_input->var_a[a];
	temp |= (uint16_t)(apple >> test_input->shftam[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

//uint32_t rotl32(myvars *alu_inputs, int a)
//{
//	uint32_t temp;
//	unsigned int first_half = 0, second_half = 0;
//
//	myvars *test_input = alu_inputs;
//	temp = 0 << FLAGSHFT;
//	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
//	
//	first_half = test_input->var_a[a] << test_input->shftam[a];
//	second_half = test_input->var_a[a] >> WIDTH;
//	first_half |= second_half;
//	temp |= (uint16_t)first_half;			//first OR result with current value then shift
//
//	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
//		temp ^= 0x10000000;
//
//	return temp;
//}
//
//
//uint32_t rotr32(myvars *alu_inputs, int a)
//{
//	uint32_t temp;
//	uint16_t first_half = 0, second_half = 0;
//
//	myvars *test_input = alu_inputs;
//	temp = 0 << FLAGSHFT;
//	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
//
//	first_half = test_input->var_a[a] >> test_input->shftam[a];
//	second_half = test_input->var_a[a] << (WIDTH - test_input->shftam[a]);
//	first_half |= second_half;
//	temp |= (uint16_t)first_half;			//first OR result with current value then shift
//
//	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
//		temp ^= 0x10000000;
//
//	return temp;
//}
uint32_t multiplication(myvars *alu_inputs, int a)
{

	uint32_t temp;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], test_input->var_b[a], MUL_T) << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	temp |= (uint16_t)((test_input->var_a[a]) * (test_input->var_b[a]));			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

uint32_t division(myvars *alu_inputs, int a)
{

	uint32_t temp = 0;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], test_input->var_b[a], MUL_T) << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	if(test_input->var_b[a])
		temp |= (uint16_t)(test_input->var_a[a] / test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}


uint32_t modulus(myvars *alu_inputs, int a)
{

	uint32_t temp = 0;
	myvars *test_input = alu_inputs;
	temp = (uint32_t)getflags(test_input->var_a[a], test_input->var_b[a], MUL_T) << FLAGSHFT;
	temp = (temp | (uint32_t)compare(test_input->var_a[a], test_input->var_b[a])) << COMPSHFT;	//first OR return with current value then shift
	if (test_input->var_b[a])
		temp |= (uint16_t)(test_input->var_a[a] % test_input->var_b[a]);			//first OR result with current value then shift

	if (!(temp & 0x0000FFFF))	// check if answer is zero flag
		temp ^= 0x10000000;

	return temp;
}

//void print_to_file()
//{
//	fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat,
//																h,
//																alu_inputs.shftam[i],
//																alu_inputs.var_a[i],
//																alu_inputs.var_b[i],
//																(int16_t)RESULT(alu_results[h][i]),
//																COMPAB(alu_results[h][i]),
//																FLAGS(alu_results[h][i]));
//}

enum opcode_type {	ADD,
					SUB,
					L_OR,
					L_AND,
					L_NOT,
					L_XOR,
					INC,
					DEC,
					ASHF,
					LSHF,
					//RSHF,
					//MUL,
					//DIV,
					//MOD,
					//BCD_ADD,
					//BCD_SUB,
					EOI};

enum result_type {	ADD_RESULT,
					SUB_RESULT,
					LOR_RESULT,
					LAND_RESULT,
					LNOT_RESULT,
					LXOR_RESULT,
					INC_RESULT,
					DEC_RESULT,
					ALS_RESULT,
					ARS_RESULT,
					LLS_RESULT,
					LRS_RESULT,
					//RLS_RESULT,
					//RRS_RESULT,
					//MUL_RESULT,
					//DIV_RESULT,
					//MOD_RESULT,
					//COMP_RESULT,
					EOR};

#endif // !myfuncs