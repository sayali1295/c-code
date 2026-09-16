
//This program is performing fork operation (Here we are establishing child parent communication using NAMED pipe)
//fork_trial_npipe_fileop.c


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
	char ch;

	char *buffer = (char *) malloc (200); // buffer to take file name
	char *msg = (char *) malloc (50); // buffer to write contents in file
	char *reply = (char *) malloc (50); // buffer to read contents file name
	char *err = (char *) malloc (60); // buffer to read error

	int a = mknod (pipe, S_IFIFO | 0666, 0); // creating pipe
	if (a < 0)
	{
		printf("PIPE creation failed\n");
	}

	printf("Please enter file name\n");
	scanf("%s", &buffer[0]);

	int i = fork();

 //FORK FAILED
        if(i < 0)
        {
                printf("Child process not created\n");
                return 1;
        }
	
        //CHILD PROCESS
        else if ( i == 0)
        {
		// -----------------CLIENT----------------
                printf("\n[CHILD] process started\n"); 
		
		char *read_filename = (char *) malloc (50);

		pd = open (pipe, O_WRONLY);

                write (pd, read_filename, strlen(read_filename) + 1); // Writing file name to pipe(file descriptor)
                close(pd);

                printf("\n[CHILD] process received contents as:\n\n");

		pd = open (pipe, O_RDONLY);

                while ((read (pd, reply, 1)) > 0) // Reading contents character by character from Parent pipe
                {
                        printf("%c", reply[0]);
                }
                printf("\n\n[CHILD] process Exiting\n\n");
                close(pd);         
		free(read_filename);
        }

        //PARENT PROCESS
        else
        {
		//-----------------SERVER---------------
                printf("\n[PARENT] process\n"); //server

		pd = open (pipe, O_RDONLY);

		fp = fopen (buffer, "r");
		close (pd);

                if(fp == NULL) // Works when file name is (NOT MATCHED)
                {
                        strcpy (err, "Dear client, mentioned file is not found");
			pd = open (pipe, O_WRONLY);
			write (pd, err, strlen(err) + 1);
                }
                else // Works when file name is (MATCHED)
                {
			pd = open (pipe, O_WRONLY);

                        while ((ch = getc(fp)) != EOF)
                        {
				msg[0] = ch;
				write (pd, msg, 1);
			}
		}
		close (pd);
	}
	
	free(buffer);
	free(reply);
	free(msg);
	free(err);

	return 0;
}

