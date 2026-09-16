
/* This program is the implementation of unnamed pipe in networking
 * Doing String concatenation
 * Scenario is we are asking user name and writing it to Pipe1 write end,
 * reading it from read end
 * outside pipe we have container with a 2nd string
 * cat both strings and sending it through pipe2
 * milk_pipe.c */


#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{

	int count1;
	int count2;
	int a[2];
	int b[2];

	//creating pipes
	int r = pipe(a); // r is giving return value of pipe1()
	int k = pipe(b); // k is giving return value of pipe2()		 
	
	
	if ((r == -1) && (k == -1))
	{
		printf("Pipes are not created\n");
		return -1;
	}

	char *buffer = (char *) malloc (100);
	char *bucket = (char *) malloc (100);

	printf("Program for implementation of milk pipe using system calls\n");

	//In this we are giving string as an i\p to pipe thereby checking if it can be read or not using logic below

	printf("Please enter your first name\n");
	scanf("%s", &buffer[0]);

	count1 = strlen(buffer);
	
	if (count1 <= 0)
	{
		printf("Invalid string size\n");
		return -1;
	}

	int wb1 = write (a[1], buffer, count1); // writing to pipe

	if (wb1 > 0)
	{
		int rb1 = read (a[0], buffer, count1); //reading from pipe
	
		if(rb1 > 0)
		{
			printf("PIPE 1 output read as: %s\n", buffer);
		}
		else
		{
			return -1; 
		}
	}
	else
	{
		return -1;
	}

// pipe 2 functioning starts from below

	strcpy (bucket, buffer); 
	char *my_string = (char *) malloc (100);
	strcpy (my_string, " Good Morning");
	strcat (bucket, my_string);

	count2 = strlen(bucket);

	if (count2 <= 0)
	{
		printf("Invalid string size\n");
		return -1;
	}

	int wb2 = write (b[1], bucket, count2); // writing to pipe

	if (wb2 > 0)
	{
		int rb2 = read (b[0], bucket, count2); //reading from pipe
	
		if(rb2 > 0)
		{
			printf("PIPE 2 output read as: %s\n", bucket);
		}
		else
		{
			return -1; 
		}
	}
	else
	{
		return -1;
	}
	
	free(buffer);
	free(bucket);
	free(my_string);
return 0;
}

