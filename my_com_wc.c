//This program is my comand like WC
//my_com_wc.c


#include<stdio.h>
int main(int argc, char *argv[])
{
	FILE  *fp;
	int size = 0;

	if (argc < 3)
	{
		printf("Wrong syntax!\n");
		printf("Correct syntax is: command_name <- option> <file_name>\n");
	}
	else
	{
		if (argv[1][1] == 'c')
		{
			fp = fopen (argv[2], "r");
			if (fp == NULL)
				printf("Error");

			char ch ;

			while(ch != EOF)
			{	
				ch = getc(fp);
				size++;
			}
			printf("\n%d %s", size, argv[2]);
		}
		else
			printf("\nWrong option! use correct option\n");
	}

	return 0;
}


