
// This program is the final implementation of unnamed pipe in networking
// pipe_final.c


#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{

	int count;
	int a[2];
	int r = pipe(a); // r is giving return value of pipe()
	
	if(r == -1)
	{
		return -1;
	}

	char buffer[count];	
	printf("Program for implementation of pipe using system calls\n");

	//In this we are giving string as an i\p to pipe thereby checking if it can be read or not using logic below

	printf("Please enter a word\n");
	scanf("%s", &buffer[0]);

	count = strlen(buffer);
	
	if (count <= 0)
	{
		printf("Invalid string size\n");
		return -1;
	}

	int write_buff = write (a[1], buffer, count); // writing to pipe

	if (write_buff > 0)
	{
		int read_buff = read (a[0], buffer, count); //reading from pipe
	
		if(read_buff > 0)
		{
			printf("PIPE INPUT READED AS: %s\n", buffer);
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


return 0;
}

