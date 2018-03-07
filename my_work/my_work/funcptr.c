#if 0
#include <stdio.h>
#include <string.h>

int out; //Mr.out is a guy who knows everyone and so every one calls him.

	void myfunc(int n)	//myfunc is the address of the function call
	{
		printf("%d\n", n);
	}

		void myother(int n)
		{
			printf("%d\n", n + 2);
		}

			int *myfuncy(int *n) //myfuncy is a function returning integer function and is 
			{					//waiting for an address from the caller as  the
				*n *= 2;		//argument and will return the same address with the  
				return n;		//contents pointed to multipled by 2
			}

				int add(int m, int n) //here we have two functions that expect and return 
				{					  //the same types but change it differently	
					out = m + n;      //so we use one pointer to function for both.
					return out;
				}

				int sub(int m, int n)
				{
					return n - m;
				}

					void *add_int(void *px, void *py)//a func expecting two type void pointers //void is dangerous avoid
					{								 //returning an address to type void
						out = (*((int *)px) + *((int*)py)); //px & py are cast to integer and dereferenced
						return &out; //so the add answer will never die cause its globaly saved in the stack
					}

					//a tricky function expecting two pointers to void and one pointer 
					//to function of type void that shall return an address
					void *processing(void *pa, void*pb, void *(*op)(void*, void*))
					{
						void *res = op(pa, pb); //res is gonna point to the address of global variable
												//mr.out. 
						return res;//effectivly we shall return the address of out then derefernce it 
									//to read the actual value. 	
					}

						int strmod(char *arr)
						{
							int z = sizeof(*arr);
							static int loc_arr[26]; //static so that it initializes zero 

							for (int i = 25; i >= 0; i--)
							{
								loc_arr[i] = 0;
							}

							char alph_ref = 'a'; //compare string to start of alphabet then increment

							unsigned int i = strlen(arr);
							while (i--)
							{
								loc_arr[arr[i] - 'a']++;
							}

							return loc_arr;
						}

int main()
{
	int (*ptr); //ptr is a pointer to an integer. not used just as an example
	void (*foo)(int); //foo is a pointer to a function.
						//(int n) is the arguments this pointer to 
						//function points to

	foo = myfunc; 	//so here foo as a space in memory is assigned the
					//address of myfunc

	printf("foo : %p \t myfunc : %p \t &myfunc : %p \t foo : %x \t myfunc : %x \t &myfunc : %x \n", 
			foo,		myfunc,		   &myfunc,		   foo,		   myfunc,		  &myfunc);
//prints:A01320,	    A01320,		    A01320,		A01320,		   A01320,		   A01320

	foo(10); //calls the function automatically. a call is made automatically
			 //i think when converted to asm magic happenes. 
			 //JACOBO WILL EXPLAIN THIS. HE KNOWS EVERYTHING
			 //prints 10

		foo = &myother; //here its more obvious that foo is assigned the address of
						//the function
					
		(*foo)(10);	//same thing, calling function magically
					//prints 12
	
			int *(*boo)(int *); //getting more complex. boo is a pointer to a function
								//argument is a pointer to an integer so we send the address
								//returns a pointer to integer. so actually an address
								//to an intger will be returned. 

			int n = 16; //variable for boo argument 
			boo = myfuncy; //assigning the address
			int *ret; //a pointer to integer to hold the address that boo returns
			printf("%d\n", n);//prints 16
			ret = boo(&n);
			printf("n : %d, *ret : %d\n", n, *ret);//prints 32, 32
			//so here local n was modified in a function call through pointers. 
			//technically there wasn't any need of returning address. 

				int y = 4;
				out = 3; //modifying global variables
				int(*operation)(int, int);
				operation = add;
				printf("result : %d\n", operation(y, out)); //prints 7
				operation = sub;
				printf("result : %d\n", operation(y, out)); //prints 1

					void *(*op)(void *, void *); //pointer to function
					op = add_int; //assign pointer with address of function
					int g = 10, h = 6;
					//first we call function processing with arguments address of g and h and add_int function
					//cast the returning address to integer pointer type
					//dereference this address and print it
					int ans = *((int *)processing(&g, &h, op));
					printf("ans : %d\n", ans);

						char str[50]; 
						scanf("%s", str);
						int* loc_arr;

						loc_arr = strmod(str);
						y = 0;

						char alph_ref = 'a';
						while (y < 26)
						{
							printf("%c = %d\n", alph_ref++, loc_arr[y++]);
						}
						printf("\n\n\n");


	int a[5] = { 0,1,2,3,4 }; //this is a typical array
	int b[6], c[7];		//yet another set of typical arrays

	int *ptr_a = a;		//pointing to the initial element
	int *ptr_ua = &a;	//pointing to an array of ten elements
	int i = (sizeof(a)/sizeof(a[0]));

	printf("size a : %d, b : %d, c : %d\n", sizeof(a), sizeof(b), sizeof(c));
	//prints 20, 24, 28 // the size of the whole array.
	//Q to JACOBO : if a is a pointer to first element how come the size of the 
	//				whole array is printed? as in sizeof() returns whole array size.

	printf("size a : %d, b : %d, c : %d\n", sizeof(&a), sizeof(&b), sizeof(&c));
	//prints 4, 4, 4 //obviously the size of the actuall address. 

	printf("a = %x \t &a = %x \t ptr_a = %p \t ptr_&a = %p\n", a, &a, a, &a);
	//all of this print the address to the first element

	while (--i >= 0)
	{
		printf("_a : %d \t _ua : %x\n", *(a + i), *(&a + i));		
	}
	//prints	4	3cfc28
	//			3	3cfc14 ...and so on
	//JACOBO, why aren't the contents(elements) printed in both cases?





	return 0;
}

#endif 