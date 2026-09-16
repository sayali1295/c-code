
//This program is performing fork operation (Here we are establishing (Process 1) child communication using NAMED pipe)
//npipe_fileop_P1.c


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	const char *pipe = "P"; // Pipe 
	int pd; // pipe file descriptor for open sys call
	FILE *fp;

	char *buffer = (char *) malloc (200); // buffer to take file name
	char *reply = (char *) malloc (50); // buffer to read contents file name

	printf("Program for Two process communication using Named PIPE\n\n");
	printf("Please enter file name\n");
	scanf("%s", &buffer[0]);
	
        //CHILD PROCESS
	// -----------------CLIENT----------------
        
	printf("\n---[CHILD] process started---\n"); 

	pd = open (pipe, O_WRONLY);
	if (pd < 0)
	{
		printf("Named PIPE is not opened for Write operation\n");
		free(buffer);
		free(reply);
		return 1;
	}

	printf("[CHILD] process is writing file name: %s to Named PIPE\n", buffer);

        write (pd, buffer, strlen(buffer) + 1); // Writing file name to pipe(file descriptor)
        close(pd);

	pd = open (pipe, O_RDONLY);
	if (pd < 0)
	{
		printf("Named PIPE is not opened for Read operation\n");
		free(buffer);
		free(reply);
		return 1;
	}

	printf("[CHILD] process is reading contents of %s from Named PIPE as : \n\n", buffer);
        while ((read (pd, reply, 1)) > 0) // Reading contents character by character from Parent pipe
        {
		printf("%c", reply[0]);
        }
        printf("\n\n-----[CHILD] process Exiting-----\n\n");
        
	close(pd);
	free(buffer);
	free(reply); 

	return 0;
}

