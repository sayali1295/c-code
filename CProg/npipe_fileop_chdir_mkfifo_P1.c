
/* This program is performing CHILD PROCESS
 * (Here we are establishing (Process 1) child communication using NAMED pipe) but with mkfifo
 * npipe_fileop_chdir_mkfifo_P1.c */


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
#include "mknod_header.c"

int main()
{ 
//	const char *node = "P"; it is included in header file
	int pd; // pipe file descriptor for open sys call
	FILE *fp;

	char *buffer = (char *) malloc (200); // buffer to take file name
	char *reply = (char *) malloc (50); // buffer to read contents file name

	printf("Program for Two process communication using Named PIPE\n\n");
	printf("Please enter file name\n");
	scanf("%s", &buffer[0]);
	
        //CHILD PROCESS
	// -----------------CLIENT----------------
        
	printf("\n---[CHILD] process started---\n\n"); 

/* access() sys call is checking
 * if pipe exist already :  will bypass mknod() sys call
 * if pipe do not exist : run sys call mknod()
 */
	if ((access (node, F_OK)) == -1)
	{
		mkfifo(node, 0666);
	}

	pd = open (node, O_WRONLY);

	if (pd < 0)
	{
		printf("Named PIPE is not opened for Write operation\n");
		free(buffer);
		free(reply);
		return 1;
	}

	printf("[CHILD] process is writing file name: %s to Named PIPE\n\n", buffer);

        write (pd, buffer, strlen(buffer) + 1); // Writing file name to pipe(file descriptor)
        close(pd);

	pd = open (node, O_RDONLY);
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

