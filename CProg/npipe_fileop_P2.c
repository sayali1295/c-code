
//This program is performing fork operation (Here we are establishing PARENT communication using NAMED pipe)
//npipe_fileop_P2.c


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	const char *pipe = "P"; // Pipe 
	const char *s;	
	char er_msg[10]; 
	int pd; // pipe file descriptor for open sys call
	FILE *fp;
	char ch;


	char *buffer = (char *) malloc (200); // buffer to take file name
	char *msg = (char *) malloc (50); // buffer to write contents in file
	char *err = (char *) malloc (60); // buffer to read error

	if ((mknod(pipe , S_IFIFO | 0666 , 0)) == -1)
	{
		if (errno == EEXIST)
			unlink (pipe);
	}

	mknod(pipe, S_IFIFO | 0666, 0);

	
        //PARENT PROCESS
	//-----------------SERVER---------------
                
	printf("\n------[PARENT] process-----\n\n");
	pd = open (pipe, O_RDONLY);
	if (pd < 0)
	{
		printf("Named pipe is not opened for Reading file name\n\n");
		free(buffer);
		free(msg);
		free(err);
		return -1;
	}
		
	printf("[PARENT] is waiting for file name from [CHILD]\n\n");

	read (pd, buffer, 199);
	printf("[PARENT] is reading file name : %s from Named PIPE\n\n", buffer);
	fp = fopen (buffer, "r");
	close (pd);
	
	if(fp == NULL) // Works when file name is (NOT MATCHED)
        {
		printf("[PARENT] File not found!! Sending error back to [CHILD]\n\n");
		strcpy (err, "Dear client, mentioned file is not found");

		pd = open (pipe, O_WRONLY);
		if (pd < 0)
		{
			printf("Named pipe is not opened for Writing error\n\n");
			free (buffer);
			free(msg);
			free(err);
			return -1;
		}

		write (pd, err, strlen(err) + 1);
        }
	else // Works when file name is (MATCHED)
        {
		pd = open (pipe, O_WRONLY);
		if (pd < 0)
		{
			printf("Named pipe is not opened for Reading file name\n\n");
			free (buffer);
			free(msg);
			free(err);
			return -1;
		}
			
		printf("[PARENT] sending contents from %s to [CHILD]\n\n", buffer);
                while ((ch = getc(fp)) != EOF)
                {
			msg[0] = ch;
			write (pd, msg, 1);
		}
		printf("[PARENT] sent contents to [CHILD] successfully\n\n");
	}
	printf("---[PARENT] process Exiting---\n");
	close (pd);	
	free(msg);
	free(err);

	return 0;
}

