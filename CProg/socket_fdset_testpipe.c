/* This program is testing use of fd_Set used in socket programming for select operation
* We are using pipe to create one more fd to test how the program behaves
* PN: socket_fdset_testpipe.c
* Final Update Date: 19 AUG 2026
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/select.h>

int main()
{
	char buff[100];
	char msg[100] = "HELLO";
	fd_set masterset;
	fd_set readfds;
	int a[2];
	int r = pipe(a); // creating pipe for generating second fd
	printf("%d\n", r);
	
	FD_ZERO(&masterset);

	FD_SET(0, &masterset);
	FD_SET(a[0], &masterset);

	while(1)
	{
		readfds = masterset;

		select(a[0] + 1, &readfds, NULL, NULL, NULL);
		
		if (FD_ISSET(0, &readfds))
		{
			printf("You typed something\n");
			read(0, buff, sizeof(buff));
			write(a[1], msg, strlen(msg));
		}
		else if (FD_ISSET(a[0], &readfds))
		{
			read(a[0], buff, sizeof(buff));	
			printf("%s\n", msg);
		}
		else
		{
			printf("No readfds are active\n");
		}
	}
return 0;
}

