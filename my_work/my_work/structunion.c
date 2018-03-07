#if 0
#include <stdio.h>

typedef union 
{
	char Character;
	short Short;
	int Integer;
	float Float;
	double Double;
	char String[20];
} Value;

typedef enum
{
	CHAR, SHORT, INT, FLOAT, DOUBLE, STRING
}Type;

typedef struct 
{
	Type type;
	Value value;
}Variant;

void foo(Variant v)
{
	if( v.type == CHAR)		printf("%c\n", v.value.Character);
	else if (v.type == SHORT) printf("%d\n", v.value.Short);
	else if (v.type == INT)	printf("%d\n", v.value.Integer);
	else if (v.type == FLOAT) printf("%f\n", v.value.Float);
	else if (v.type == DOUBLE) printf("%lf\n", v.value.Double);
	else if (v.type == STRING) printf("%s\n", v.value.String);
	else puts("Not a valid input");
}

int main()
{
	Variant v1;
	v1.type = INT;
	v1.value.Integer = 100;
	foo(v1);
}

#endif