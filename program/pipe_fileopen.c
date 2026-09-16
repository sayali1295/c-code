
// This program is the implementation of unnamed pipe (by giving file name thereby demanding its contents from pipe) in networking
// fileopen_pipe.c


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int count1;
	int a[2];
	int b[2];

	//creating pipes
	int r = pipe(a); // r is giving return value of pipe1()
	int k = pipe(b); // k is giving return value of pipe2()		 
	
	//checking pipes created or not
	if ((r == -1) && (k == -1))
	{
		printf("Pipes are not created\n");
		return -1;
	}

	//buffers pipe1
	char *buffer1 = (char *) malloc (100);
	char *bucket1 = (char *) malloc (100);

	//buffers for file not found operation
	char *error = (char *) malloc (50);
	char *arr = (char *) malloc (50);

	//buffers for pipe2
	char *buffer2 = (char *) malloc (100); 
	char *bucket2 = (char *) malloc (100);

	printf("Program for implementation of file opening using pipe & system calls\n");

	//In this we are giving <file name> as an i\p to pipe thereby checking if it can be read or not using logic below

	printf("Please enter your file name\n");
	scanf("%s", &buffer1[0]);

	count1 = strlen(buffer1);
	
	if (count1 <= 0)
	{
		printf("Invalid string size\n");
		return -1;
	}

	int wb1 = write (a[1], buffer1, count1); // writing to pipe

	if (wb1 > 0)
	{
		int rb1 = read (a[0], bucket1, count1); //reading from pipe
	
		if(rb1 > 0)
		{
			printf("PIPE 1 output read as: %s\n", bucket1);
		}
		else
		{
			return -1;
		        free(buffer1);
			free(bucket1);	
		}
	}
	else
	{
		return -1;
		free(buffer1);	
		free(bucket1);
	}

// pipe 2 functioning starts from below

	fp = fopen (bucket1, "r"); //opening file

	if (fp == NULL) // logic for file not found
	{
	//	printf("Error in opening file occured\n");
		strcpy (error, "Dear client, mentioned file is not found");
		char ch_e;
		int i = 0;

		while(error[i] != 0)
		{
			arr[i] = error[i];
			write (b[1], arr, 1);
			read (b[0], arr, 1);
			i++;
		}
			printf("%s", arr);
			free(error);
			free(arr);
	}

	else // logic for file found and sending its contents
	{
		char ch;

		printf("PIPE 2 output read as:\n\n");

		while((ch = getc(fp)) != EOF)
		{
			buffer2[0] = ch;

			int wb2 = write (b[1], buffer2, 1); // writing to pipe

			if (wb2 > 0)
			{
				int rb2 = read (b[0], bucket2, 1); //reading from pipe
				
				if(rb2 > 0)
				{
			        	printf(	"%c", bucket2[0]);
				}
				else
				{
					return -1; 
		        		free(buffer2);
					free(bucket2);	
				}
			}
			else
			{
				return -1;
		        	free(buffer2);
				free(bucket2);	
			}
	
		}
	}	

return 0;
}

