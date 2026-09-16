
//This program is performing fork operation (Here we are creating child process, sending hello from child and also getting both of its pid)
//fork_trial2.c


#include<stdio.h>
#include<unistd.h>
int main()
{
	int i = fork();
	int c_pid;
	int p_pid;

	if(i < 0)
	{
		printf("Child process not created\n");
		return 1;
	}


	else if ( i == 0)
	{
		c_pid = getpid();
		printf("\nChild process created\n");
		printf("Hello from child!, (Child PID: %d)\n", c_pid);
	//	while(1);

	}
	else
	{
		p_pid = getpid();
		printf("\nParent process\n");
		printf("Hello from parent!, (Parent PID: %d)\n", p_pid);
	//	while(1);
	}

	return 0;
}

