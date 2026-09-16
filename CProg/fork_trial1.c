#include<stdio.h>
#include<unistd.h>
int main()
{
	int i = fork();
	if ( i == 0)
	{
		int cpid = getpid();
		printf("\nChild process created: ppid = %d\n", cpid);
		while(1);

	}
	else
	{
		int pid = getpid();
		printf("\nParent process: pid = %d\n", pid);
		while(1);
	}

	return 0;
}

