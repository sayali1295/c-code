#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE  *fp;
	FILE *fp_new;

	if (argc < 3)
	{
		printf("Wrong syntax!");
		printf("Correct syntax is: command_name <source_file_name> <destination_file_name>");
	}
	else
	{
		fp = fopen (argv[1], "r");

		fp_new = fopen (argv[2],"w");

		if (fp == NULL)
			printf("Error");

		if (fp_new == NULL)
			printf("Error_new");

		char ch;
//	while(ch!=EOF)

		while(ch != EOF)
		{	
			ch = getc(fp);
			putc(ch, fp_new);
		}

		return 0;
	}
}
