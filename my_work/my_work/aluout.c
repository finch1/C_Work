#if 1
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>  // for uint32_t, to get 32bit-wide rotates, regardless of the size of int.
#include <string.h>
#include "myfuncs.h"

int main()
{
	uint16_t cat = 0;
	/*declare variables to work with*/
	myvars alu_inputs;
	//	enum opcode_type my_opcode;

	/*fill up with values*/
	signed_refill(&alu_inputs);

	uint32_t *alu_results[18];

	for (int i = 0; i < EOR; i++)
	{
		alu_results[i] = (uint32_t*)malloc(sizeof(uint32_t) * MAX);
	}


	for (int i = 0; i < MAX; i++)
	{
		alu_results[ADD_RESULT][i] = addition(&alu_inputs, i);

		alu_results[SUB_RESULT][i] = subtraction(&alu_inputs, i);

		alu_results[LOR_RESULT][i] = logic_or(&alu_inputs, i);

		alu_results[LAND_RESULT][i] = logic_and(&alu_inputs, i);

		alu_results[LNOT_RESULT][i] = logic_not(&alu_inputs, i);

		alu_results[LXOR_RESULT][i] = logic_xor(&alu_inputs, i);

		alu_results[INC_RESULT][i] = increment(&alu_inputs, i);

		alu_results[DEC_RESULT][i] = decrement(&alu_inputs, i);

		alu_results[ALS_RESULT][i] = arith_shft_lft(&alu_inputs, i);

		alu_results[ARS_RESULT][i] = arith_shft_rit(&alu_inputs, i);

		alu_results[LLS_RESULT][i] = logic_shft_lft(&alu_inputs, i);

		alu_results[LRS_RESULT][i] = logic_shft_rit(&alu_inputs, i);
	}

	int i = 0, h = 0;

	FILE *stream;
	errno_t err;

	err = fopen_s(&stream, "C:\\altera\\13.1\\NEW\\aluout.txt", "w");
	if (err == 0) puts("File open to write");

	fputs("# aluout.txt\n", stream);
	fputs("#\n", stream);
	fputs("# 5/2/2017\n", stream);
	fputs("#\n", stream);
	fputs("# Simple ALU testbench stimulus and expected response.\n", stream);
	fputs("#\n", stream);
	fputs("# Max test input number:", stream);
	fprintf(stream, "%d\n", alu_inputs.max);
	fputs("#\n", stream);
	fputs("# Min test input number:", stream);
	fprintf(stream, "%d\n", alu_inputs.min);
	fputs("#\n", stream);
	fputs("# File data format = (cat opcode shftam input_a input_b result compout flags)\n\n", stream);


	for (i = 0; i < MAX; i++)
	{
		for (h = 0; h < EOR; h++)
		{
			switch (h)
			{
			case ADD_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case SUB_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LOR_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LAND_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LNOT_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LXOR_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case INC_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case DEC_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, h, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case ALS_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, 8, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case ARS_RESULT:
			{
				cat = 1;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, 8, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LLS_RESULT:
			{
				cat = 0;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, 9, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			case LRS_RESULT:
			{
				cat = 1;
				fprintf(stream, "%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n", cat, 9, alu_inputs.shftam[i], alu_inputs.var_a[i], alu_inputs.var_b[i], (int16_t)RESULT(alu_results[h][i]), COMPAB(alu_results[h][i]), FLAGS(alu_results[h][i]));
				break;
			}
			
			default:
				break;

			}
		}
	}

	fclose(stream);
	printf("File Closed\n");


}

#endif // 0

