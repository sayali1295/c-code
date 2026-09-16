//This program is my cat command
//my_com_cat.c

#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE  *fp;
	FILE *fp_new;

	if (argc < 2)
	{
		printf("Wrong syntax!");
		printf("Correct syntax is: command_name <source_file_name> <destination_file_name>");
	}
	else
	{
		fp = fopen (argv[1], "r");

		if (fp == NULL)
			printf("Error");

		char ch;

		while(ch != EOF)
		{	
			ch = getc(fp);
			putc(ch, stdout);
		}
		
		return 0;
	}
}

