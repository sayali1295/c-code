
//This program is performing fork operation (Here we are establishing child parent communication using pipe)
//fork_trial_pipe_fileop.c


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int buffer_size;

	char ch, ch_e;

	int a[2];
	int b[2];
	int r = pipe(a); // child to parent pipe
	int k = pipe(b); // parent to child pipe
	
	FILE *fp;
//	int i = fork();

	char *buffer = (char *) malloc (100); // buffer for child write()
	char *bucket = (char *) malloc (100); //bucket for parent read()

	char *msg = (char *) malloc (100); // msg for parent write()
	char *reply = (char *) malloc (100); //reply for child read()
	
	//buffer for file not found operation
        char *error = (char *) malloc (50);
        char *arr = (char *) malloc (50);


	//checking if pipe created or not
	if ((r == -1) && (k == -1))
	{
		printf("Pipe creation failed");
		return -1;
	}
	
	printf("Please enter file name\n");
	scanf("%s", &buffer[0]);

	buffer_size = strlen(buffer) + 1;
	
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
		printf("\n[CHILD] process started\n"); //client

		close(a[0]);
		close(b[1]);

		write (a[1], buffer, buffer_size); // Writing file name to pipe
		close(a[1]);

		printf("\n[CHILD] process received contents as:\n\n");
		close (a[1]);
		
		while ((read (b[0], reply, 1)) > 0) // Reading contents character by character from Parent pipe	
		{
			printf("%c", reply[0]);	
		}
		printf("\n\n[CHILD] process Exiting\n\n");
		close(b[0]);
		while(1);
	}

	//PARENT PROCESS
	else
	{
		printf("\n[PARENT] process\n");//server
		
	
		close (a[1]);
		close (b[0]);

		read (a[0], bucket, buffer_size); // Reading file name sent by Child
		close(a[0]);
		
		fp = fopen (bucket, "r");

		if(fp == NULL) // Works when file name is (NOT MATCHED)
		{
			strcpy (error, "Dear client, mentioned file is not found");
			char ch_e;
                        int i = 0;

			write (b[1], error, strlen(error));

                       /* while(error[i] != 0)  extra logic 
                        {
                                arr[i] = error[i];
                                write (b[1], arr+i, 1);
                                i++;
                        }*/
			close(b[1]);
		}
		else // Works when file name is (MATCHED)
		{
			while ((ch = getc(fp)) != EOF)
			{
				msg[0] = ch;	

				write (b[1], msg, 1);
			}
			close(b[1]);
			while(1);
		}
	}	
	free(buffer);
	free(bucket);
	free(msg);
	free(reply);
	free(error);
	free(arr);
	return 0;
}

