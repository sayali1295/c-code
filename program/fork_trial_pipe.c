
//This program is performing fork operation (Here we are establishing child parent communication using pipe)
//fork_trial_pipe.c


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int buffer_size, msg_size;

	int c_pid, p_pid;

	int a[2];
	int b[2];
	int r = pipe(a); // child to parent pipe
	int k = pipe(b); // parent to child pipe

	int i = fork();

	char *buffer = (char *) malloc (100); // buffer for child write()
	char *bucket = (char *) malloc (100); //bucket for parent read()

	char *msg = (char *) malloc (100); // msg for parent write()
	char *reply = (char *) malloc (100); //reply for child read()

	//checking if pipe created or not
	if ((r == -1) && (k == -1))
	{
		printf("Pipe creation failed");
		return -1;
	}

	strcpy(buffer, "Hello Papa, Good Morning!"); // msg from child

	buffer_size = strlen(buffer);
	
	strcpy (msg, "Hello my child, Very Good Morning!"); //msg from parent
		
	msg_size = strlen(msg); 


	//fork failed
	if(i < 0)
	{
		printf("Child process not created\n");
		return 1;
	}

	//child execution started
	else if ( i == 0)
	{
		c_pid = getpid();

		printf("\nChild process created , pid : %d\n\n", c_pid);

		write (a[1], buffer, buffer_size);			// child writing parent

		int bytes_reply = read (b[0], reply, msg_size);		// child reading parent

		printf("Child received: %s\n", reply);	
	}

	//parent execution started
	else
	{
		p_pid = getpid();

		printf("\nParent process, pid: %d\n", p_pid);

		int bytes_bucket = read (a[0], bucket, buffer_size);	// parent reading child

		printf("Parent received: %s\n", bucket);

		write (b[1], msg, msg_size);				// parent writing child
	}
	
	free(buffer);
	free(bucket);
	free(msg);
	free(reply);
	return 0;
}

