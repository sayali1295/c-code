
/* This program is performing PARENT PROCESS 
 * (Here we are establishing PARENT communication using NAMED pipe)
 * npipe_fileop_chdir_P2.c */


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
//	const char *node = "P";
	const char *s;	
	char er_msg[10]; 
	int pd; // pipe file descriptor for open sys call
	FILE *fp;
	char ch;


	char *buffer = (char *) malloc (200); // buffer to take file name
	char *msg = (char *) malloc (50); // buffer to write contents in file
	char *err = (char *) malloc (60); // buffer to read error


/* Above comment is failed in the scene when Server started first and then 
 * Client. This is because Server have no knowledge about whether pipe
 * is present or not so it flags error as : 'Named pipe is not open for
 * read operation'
 * To tackle this we are using access() sys call.
 */

/*	if ((mknod(node , S_IFIFO | 0666 , 0)) == -1)
	{
		if (errno == EEXIST);
			unlink (node);
	}

	mknod(node, S_IFIFO | 0666, 0);*/

/* access() sys call is checking
 * if pipe exist already : will bypass mknod() sys call
 * if ooe do not exist : run sys call mknod()
 */

	if ((access (node, F_OK)) == -1)
	{
		mknod(node, S_IFIFO | 0666, 0);
	}

        //PARENT PROCESS
	//-----------------SERVER---------------
                
	printf("\n------[PARENT] process-----\n\n");
	pd = open (node, O_RDONLY);
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
	close(pd);

	fp = fopen (buffer, "r");
	
	pd = open (node, O_WRONLY);
	if (pd < 0)
	{
		printf("Named pipe is not opened for Write operation\n\n");
		free (buffer);
		free(msg);
		free(err);
		return -1;
	}

	if (fp == NULL)
	{
		printf("[PARENT] File not found in current directory! Wait while I check in /home/sayali\n\n");
	
		if (chdir("/home/sayali") == 0) // Change in diretory is successful
		{
			fp = fopen (buffer, "r");
		}
		else
		{
			fprintf(stderr, "%s", strerror(errno));
		}
	}

	if (fp == NULL) // Works when file name is (NOT MATCHED) in CWD
        {
		printf("[PARENT] File not found anywhere!! Sending error back to [CHILD]\n\n");
		strcpy (err, "Dear client, mentioned file is not found anywhere");

		write (pd, err, strlen(err) + 1);
        }

	else // Works when file name is (MATCHED)
        {
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
	unlink(node);

	return 0;
}

