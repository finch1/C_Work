#if 0
#include <stdio.h>

struct DOB
{
	int day, month, year;
};

struct Person //this is a declaration
{
	char name[30];

	char address[50];

	int age;

	struct DOB dob;
} p0; //p0 is a variable of type person. this is a global variable
	  //as it is declared outside main

int main()
{
	//instasiate a structure
	struct Person p1, p2; //these are two local variables of type person
	printf("%d\n", sizeof(p1));
	printf("enter name: "); scanf("%s", &p1.name);
	printf("enter age : "); scanf("%d", &p1.age);
	printf("enter addr: "); scanf("%s", &p1.address);
	printf("enter b'day:"); scanf("%d", &p1.dob.day);
	printf("enter b'month:"); scanf("%d", &p1.dob.month);
	printf("enter b'year:"); scanf("%d", &p1.dob.year);

	puts("\n\np1:");
	printf("%s of age %d lives @ %s\n", p1.name, p1.age, p1.address);
	printf("%s was born %d/%d/%d\n", p1.name, p1.dob.day, p1.dob.month, p1.dob.year);
	printf("%d\n", sizeof(p1));

}

#endif