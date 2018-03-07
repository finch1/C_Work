#if 0

#include <stdio.h>

int x = 0;
int f1()
{
	int x = 6;
	return x;
}
int f2()
{
	int x = 10;
	return x;
}


int main(void)
{
	int arr[2] = { 10, 20 };
	int *p = arr;

	int i = (5, 10);
	//f1() is called (evaluated) first followed by f2()
	int j = (f1(), f2()); //The returned value of f2() is assigned to j

	printf("i : %d, j : %d\n", i, j);

	j = i++, ++i; // i++ works
	printf("%d\n", j);

	i = 3, j;
	j = (i++, printf("i = %d\n", i), ++i, printf("i = %d\n", i), i++);
	printf("i = %d\n", i);
	++*p;
	printf("arr[0] = %d arr[1] = %d *p = %d\n", arr[0], arr[1], *p);

	arr[0] = 10;
	arr[1] = 20;
	p = arr;
	*p++;
	printf("arr[0] = %d arr[1] = %d *p = %d\n", arr[0], arr[1], *p);

	arr[0] = 10;
	arr[1] = 20;
	p = arr;
	*++p;
	printf("arr[0] = %d arr[1] = %d *p = %d\n", arr[0], arr[1], *p);

	arr[0] = 10;
	arr[1] = 20;
	p = arr;
	++*p++;
	printf("arr[0] = %d arr[1] = %d *p = %d\n", arr[0], arr[1], *p);

}
#endif
/*
Operator	Description								Associativity
()			Parentheses(function call)				left - to - right
[]			Brackets(array subscript)
.			Member selection via object name
->			Member selection via pointer
++— 		Postfix increment / decrement

++ —		Prefix increment / decrement			right - to - left
+ –			Unary plus / minus
!~          Logical negation / bitwise complement
(type)      Cast(convert value to temporary value of type)
*			Dereference
&			Address(of operand)
sizeof 	    Determine size in bytes on this implementation

* / % 		Multiplication / division / modulus 	left - to - right
+ – 		Addition / subtraction 					left - to - right
<< >>		Bitwise shift left, Bitwise shift right	left - to - right
< <=		Relational less than / less than or equal to 		left - to - right
> >=		Relational greater than / greater than or equal to 	left - to - right

== !=		Relational is equal to / is not equal to 	left - to - right
& 			Bitwise AND 							left - to - right
^ 			Bitwise exclusive OR 					left - to - right
|			Bitwise inclusive OR 					left - to - right
&& 			Logical AND 							left - to - right
| |			Logical OR 								left - to - right
? :			Ternary conditional 					right - to - left
=			Assignment								right - to - left
+= -=		Addition / subtraction assignment
*= /=		Multiplication / division assignment
%= &=		Modulus / bitwise AND assignment
^= |=		Bitwise exclusive / inclusive OR assignment
<<= >>=		Bitwise shift left / right assignment 	
,			Comma(separate expressions) 			left - to - right
*/