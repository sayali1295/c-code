//This program is to practice arguments in main function
// arg_practice.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "mystrcmp.c"

int str_compare(char *, char []);

int main(int argc, char* argv[], char* env[])
{
	
//	setenv("USER", "akash", 1);

/*	char *username;                        Line 16,17 is another way to write line no 20
	user_name = getenv("USER"); */
	
	char *user_name = getenv("USER");

	char my_name[] = "sayali";
	
	if (strcmp(user_name, my_name) != 0)
		printf("Your user name is : %s\n", user_name);

	int j = str_compare(user_name, my_name);

	if (j == 0)	
	{	
		printf("Your access to program is granted\n\n");

		int i = 0;

		while(env[i] != 0)
		{
			printf("%s\n", env[i]);
			i++;
		}
	}
	else
		printf("Access Denied\n");

		
	return 0;
}

int str_compare(char *str1, char str2[])
{
	int i = 0;

	while ((str1[i] != 0) || (str2[i] != 0))
	{
		if (str1[i] != str2[i])
		{
			return -1;
		}		
		i++;
	}
	return 0;
}
