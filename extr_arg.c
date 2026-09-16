//This program is to find argument
// extr_arg.c

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
	int i = 0;

	printf("number of arguments is: %d\n", argc);

/*	while (strcmp (argv[i], "India") == 1)
	{
		printf("argument found at : %d\n", i);
	}
	i++;

//	printf("argument found at number %d\n", argv[i]);*/

	while (i <= argc)
	{
		if (strcmp (argv[i], "India") == 1)
			printf("Argument India found at %s", argv[i]);
	}
	i++;

	return 0;
}

