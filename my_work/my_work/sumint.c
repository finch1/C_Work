#if def 0

//declare the variables that will be shared between these functions
long int sum; //using int is optional
long int count;

void sumint(int nitem)
{
	sum += (long)nitem;
	++count;
}

void subint(int nitem)
{
	sum -= (long)nitem;
	--count;
}

int average()
{
	int nreturn = 0;
	nreturn = (int)(sum / count);

	return nreturn;
}


#endif