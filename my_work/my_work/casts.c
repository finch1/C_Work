#if 0
//using casts to change a data type
#include <stdio.h>
#include <string.h>

int main()
{
	float fvalue = 123.0;
	double dvalue = 987.0;
	long double ddvalue = 123123123123.0;

	int ninteger = 12345;
	int nintegeragain = 12345;
	long llong = 987;
	unsigned long ulong = 987;
	char cchar = 'a';

	printf(" value %f \n dvalue %f \n ddvalue %lf \n"
		" ninteger %d \n llong %ld \n ulong %lu \n cchar %c\n",
		fvalue, dvalue, ddvalue, ninteger, llong, ulong, cchar);
	
	//these assignment statements generate a warning message about type conv
	ninteger = dvalue;
	llong = ddvalue;
	ulong = ddvalue;
	cchar = nintegeragain;

	printf("\n fvalue %f \n dvalue %lf \n ddvalue %lf \n"
		" ninteger %d \n llong %ld \n ulong %lu \n cchar %c\n",
		fvalue, dvalue, ddvalue, ninteger, llong, ulong, cchar);

	//with cast there is no warning however the conversion is the same

	ninteger = (int)dvalue;
	llong = (long)ddvalue;
	ulong = (unsigned long)ddvalue;
	cchar = (char)nintegeragain;

	printf("\n fvalue %f \n dvalue %lf \n ddvalue %lf \n"
		" ninteger %d \n llong %ld \n ulong %lu \n cchar %c\n",
		fvalue, dvalue, ddvalue, ninteger, llong, ulong, cchar);


	printf("\n notice that 'llong' and 'ulong' both have wrong value \n");

	{
		float f = 3.24;
		printf("int : %d, dec : %0.2f", (int)f, f - (int)f);
	}

	return(0);
}

#endif