# if 0
//an example of changing a string constant

#include <stdio.h>
#include <string.h>

int main()
{
	char szmyname[] = "gringo san";
	char szyourname[50];

	szyourname[0] = '\0';

	//yourname is now same as my name
	strcpy_s(szyourname, 50, szmyname); 
	//strcpy_s(dest, src)

	printf("myname '%s' your name '%s' \n", szmyname, szyourname);

	//strcpy_s actually receives the add of the const "my new name"
	strcpy_s(szmyname, 50, "my new name");

	printf("myname '%s' your name '%s' \n", szmyname, szyourname);

	printf("before: myname '%s' constant '%s' \n", szmyname, szyourname);

	printf("before: myname '%s' constant '%s' \n", szmyname, "my new name");

	//strcpy actually receives the address of the constant "my new name"
	//this fails and destroys constant
	strcpy_s("my new name", 50, szyourname);

	printf("after: myname '%s' constant '%s' \n", szmyname, "my new name");
}

# endif