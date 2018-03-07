#if 0
#include <stdio.h>
#include <limits.h>

#if CHAR_BIT != 8
#error char expected to have exactly 8 bits.
#endif

typedef unsigned char uint8;
typedef signed char int8;

#define FLAGS_CY_SHIFT 0
#define FLAGS_OV_SHIFT 1
#define FLAGS_CY_MASK  (1 << FLAGS_CY_SHIFT)
#define FLAGS_OV_MASK  (1 << FLAGS_OV_SHIFT)

void Adc(uint8* acc, uint8 b, uint8* flags)
{
	uint8 a = *acc;
	uint8 carryIns;
	uint8 carryOut;

	// Calculate the carry-out depending on the carry-in and addends.
	//
	// carry-in = 0: carry-out = 1 IFF (a + b > 0xFF) or,
	//   equivalently, but avoiding overflow in C: (a > 0xFF - b).
	//
	// carry-in = 1: carry-out = 1 IFF (a + b + 1 > 0xFF) or,
	//   equivalently, (a + b >= 0xFF) or,
	//   equivalently, but avoiding overflow in C: (a >= 0xFF - b).
	//
	// Also calculate the sum bits.
	if (*flags & FLAGS_CY_MASK)
	{
		carryOut = (a >= 0xFF - b);
		*acc = a + b + 1;
	}
	else
	{
		carryOut = (a > 0xFF - b);
		*acc = a + b;
	}

#if 0
	// Calculate the overflow by sign comparison.
	carryIns = ((a ^ b) ^ 0x80) & 0x80;
	if (carryIns) // if addend signs are different
	{
		// overflow if the sum sign differs from the sign of either of addends
		carryIns = ((*acc ^ a) & 0x80) != 0;
}
#else
	// Calculate all carry-ins.
	// Remembering that each bit of the sum =
	//   addend a's bit XOR addend b's bit XOR carry-in,
	// we can work out all carry-ins from a, b and their sum.
	carryIns = *acc ^ a ^ b;

	// Calculate the overflow using the carry-out and
	// most significant carry-in.
	carryIns = (carryIns >> 7) ^ carryOut;
#endif

	// Update flags.
	*flags &= ~(FLAGS_CY_MASK | FLAGS_OV_MASK);
	*flags |= (carryOut << FLAGS_CY_SHIFT) | (carryIns << FLAGS_OV_SHIFT);
}

void Sbb(uint8* acc, uint8 b, uint8* flags)
{
	// a - b - c = a + ~b + 1 - c = a + ~b + !c
	*flags ^= FLAGS_CY_MASK;
	Adc(acc, ~b, flags);
	*flags ^= FLAGS_CY_MASK;
}

const uint8 testData[] =
{
	0,
	1,
	0x7F,
	0x80,
	0x81,
	0xFF
};

int main(void)
{
	unsigned aidx, bidx, c;

	printf("ADC:\n");
	for (c = 0; c <= 1; c++)
		for (aidx = 0; aidx < sizeof(testData) / sizeof(testData[0]); aidx++)
			for (bidx = 0; bidx < sizeof(testData) / sizeof(testData[0]); bidx++)
			{
				uint8 a = testData[aidx];
				uint8 b = testData[bidx];
				uint8 flags = c << FLAGS_CY_SHIFT;
				printf("%3d(%4d) + %3d(%4d) + %u = ",
					a, (int8)a, b, (int8)b, c);
				Adc(&a, b, &flags);
				printf("%3d(%4d) CY=%d OV=%d\n",
					a, (int8)a, (flags & FLAGS_CY_MASK) != 0, (flags & FLAGS_OV_MASK) != 0);
			}

	printf("SBB:\n");
	for (c = 0; c <= 1; c++)
		for (aidx = 0; aidx < sizeof(testData) / sizeof(testData[0]); aidx++)
			for (bidx = 0; bidx < sizeof(testData) / sizeof(testData[0]); bidx++)
			{
				uint8 a = testData[aidx];
				uint8 b = testData[bidx];
				uint8 flags = c << FLAGS_CY_SHIFT;
				printf("%3d(%4d) - %3d(%4d) - %u = ",
					a, (int8)a, b, (int8)b, c);
				Sbb(&a, b, &flags);
				printf("%3d(%4d) CY=%d OV=%d\n",
					a, (int8)a, (flags & FLAGS_CY_MASK) != 0, (flags & FLAGS_OV_MASK) != 0);
			}

	return 0;
}
#endif // 0
