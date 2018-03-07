#if 0
#include <stdio.h>
#include <string.h>
#include <conio.h>

#define RANGE_CHECK(x)  ('0' <= x && x <= '9')
#define RANGE ('9' - '0') +1
#define TRUE 1
#define FALSE 0
#define CH '-'
#define MAX_NO 91
#define LEAP_YEAR(Year) ((Year%4==0 && Year%100 != 0)||Year%400==0) ? 29 : 28

char *months[13] = { " ", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
int month_day[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };

char getkey()
{
	while (!_kbhit()); //kbhit returns integer value whenver key is pressed. 		
	return _getch();
}

/*zeller algo used to determine the day of the week for any date in the past,
present or future, for any dates between 1582 and 4902. We're using this
function to get the weekday of the 1st day of given month*/
int getZeller(int month, int year)
{
	int day = 1, zmonth, zyear, zeller;

	if (month < 3) zmonth = month + 10;
	else zmonth = month - 2;
	if (zmonth > 10) zyear = year - 1;
	else zyear = year;
	zeller = ((int)((13 * zmonth - 1) / 5) + day + zyear % 100 +
		(int)((zyear % 100) / 4) - 2 *
		(int)(zyear / 100) +
			(int)(zyear / 400) + 77) % 7;
	return zeller;
}

void printchar(char c) //used to do some formating the output
{
	int i;
	printf("\n\t");
	for (i = 1; i < 51; i++) printf("%c", c);
	printf("\n");
}

void printfile(int m, int y, int z)
{
	int i, j;
	char filename[12];
	char stryear[5];
	FILE* stream;

	strcpy(filename, months[m - 1]); //(des, src) copy src string to des string. month name will be coppies to file name variable. month name will be used to create the text file name. 
	itoa(y, stryear, 10); //convert integer to string. convert given year to string so that it can be concatenated with the month name and from the output text file name. 
	strcat(filename, stryear); //(str1, str2) concatenate str2 with str1. initially month name was copied in filename variable. now we concatenate year with the month name to make the filename a sfollows: "JUN2014"
	strcat(filename, ".txt"); //filename will be like "june2014.txt"

	if ((stream = fopen(filename, "w")) == NULL)//write only mode
	{
		printf("\nerror cannot create file,");
		_getch(); //get char/key hit from the keyboard. 
		exit(1);
	}

	fprintf(stream, "\n\t\t\t%s %d\n\n\t", months[m - 1], y);

	for (i = 1; i <= MAX_NO; i++) fprintf(stream, "-");

	fprintf(stream, "\n\tSUN\tMON\tTUE\tWEN\tTHU\tFRI\tSAT\n\t");

	for (i = 1; i <= MAX_NO; i++) fprintf(stream, "-");

	/*setting starting position*/
	fprintf(stream, "\n");
	for (i = 1; i <= z; i++) fprintf(stream, "\t -");

	j = z;

	/*printing dates*/
	for (i = 1; i <= month_day[m - 1]; i++)
	{
		if (j++ % 7 == 0) fprintf(stream, "\n");
		fprintf(stream, "\t%2d", i);
	}

	fprintf(stream, "\n\t");
	for (i = 1; i <= MAX_NO; i++) fprintf(stream, "-");

	fprintf(stream, "\n\n\t\tCreated by: The Grings");
	fclose(stream);

}

int main(void)
{
#if 0
	/*Write a program which reads two integer values.
	If the first is less than the second, print the message up.
	If the second is less than the first, print the message down.
	If the numbers are equal, print the message equal.
	If there is an error reading the data, print a message containing the word Error and perform exit( 0 ); */



	char a, b;
	puts("Enter two numbers:");
	scanf("%c %c", &a, &b);
	if (RANGE_CHECK(a) && RANGE_CHECK())
	{
		if (a < b) puts("up");
		else if (a > b) puts("down");
		else if (a == b) puts("equal");
	}
	else puts("NAN");

#endif

#if 0
	/*Read an integer value. Assume it is the number of a month of the year; print out the name of that month. */
	char month[] = { "xxx", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
	int mon_num;
	puts("enter month in number");
	scanf("%d", &mon_num);
	printf("%s",month[mon_num]);


#endif

#if 1
	/*Given as input three integers representing a date as day, month, year, print out the number day, month and year for the following day's date.
	  Typical input: 28 2 1992 Typical output: Date following 28:02:1992 is 29:02:1992 */


	//array of strings. * is to pint at the first character of the string
	int month, year, zeller, keycode, i, j;
	
	printf("\n\t this prog shows calendar of a gicen month");
	printf("\n\t enter month-year format mm-yyyy\n");

	/*reason for infinte loop is if user inputs wrong value
	error message is displayed and try for input again*/
	while (TRUE)//infinite loop
	{
		fflush(stdin); //clears the input buffer
		printf("\n\n\t Input mm-yyyy: ");
		scanf("%d-%d", &month, &year);
		if (year < 0 || year < 1582 || year > 4902)
		{
			printf("\ninvalid year value\n");
			continue; // after every validation failure message continue; statement is written to make sure that the rest of the codes within the loop are not executed.
		}
		if (year < 100) year += 1900; //if input is 98 correct to + 1990
		if (month < 1 || month > 12)  //month input has to be valid from 1 to 12
		{
			printf("\ninvalid month value...");
			continue;
		}
		break; //has to be broken explicitly
	}

TOP:do
	{
		//calculating day of 1st date of given month
		zeller = getZeller(month, year);
		printf("\n\n\t\t\t");

		//printing the corresponding month name
		printf("%s %d\n", months[month - 1], year);

		//adjusting feb in case of leap year
		month_day[1] = LEAP_YEAR(year);

		//giving output
		printchar(CH);

		printf("\tSUN\tMON\tTUE\tWEN\tTHU\tFRI\tSAT");
		printchar(CH);

		//setting staring position
		for (i = 1; i <= zeller; i++) printf("\t -");
		j = zeller;

		//printing dates
		for (i = 1; i <= month_day[month - 1]; i++)
		{
			if (j++ % 7 == 0) printf("\n\t%2d");
			else printf("      %2d", i);
		}

		printchar(CH);
		printf("\n\n\t\t(*) USE LEFT, RIGHT, UP & DOWN ARROW");
		printf("\n\n\t\t(*) Press I for New month & year.");
		printf("\n\n\t\t(*) Press P for print to FILE.");
		printf("\n\n\t\t(*) Press ESC for EXIT.\n\n\n\t\t");

		keycode = getkey(); //getting key code
		if (keycode == 72) year++; //up arrow
		if (keycode == 80) year--; //down arrow
		if (keycode == 77) //right arrow
		{
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
		if (keycode == 75) //left arrow
		{
			month--;
			if (month < 1)
			{
				month = 12;
				year--;
			}
		}
		if (keycode == 25) printfile(month, year, zeller); //copy of p
		if (keycode == 23) goto TOP; //copy of i
	} while (keycode != 1);



#endif
}
#endif
#if 0
#include <stdio.h>
#include <math.h>
int main()
{
	int h, q, m, k, j, day, month, year;
	printf("Enter the date (dd/mm/yyyy)\n");
	scanf("%i/%i/%i", &day, &month, &year);
	if (month == 1)
	{
		month = 13;
		year--;
	}
	if (month == 2)
	{
		month = 14;
		year--;
	}
	q = day;
	m = month;
	k = year % 100;
	j = year / 100;
	h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = h % 7;
	switch (h)
	{
	case 0: printf("Saturday.\n"); break;
	case 1: printf("Sunday.\n"); break;
	case 2: printf("Monday. \n"); break;
	case 3: printf("Tuesday. \n"); break;
	case 4: printf("Wednesday. \n"); break;
	case 5: printf("Thurday. \n"); break;
	case 6: printf("Friday. \n"); break;
	}

}
#endif