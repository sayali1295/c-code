/* This program is testing use of fd_Set used in socket programming for select operation
* PN: socket_fdset_test.c
* Final Update Date: 18 AUG 2026
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

int main()
{
	fd_set masterset;
	fd_set readfds;
	
	FD_ZERO(&masterset);

	FD_SET(0, &masterset);

	while(1)
	{
		readfds = masterset;
		select(1, &readfds, NULL, NULL, NULL);
		if (FD_ISSET(0, &readfds))
		{
			printf("You typed something\n");
			char buff[100];
			read(0, buff, sizeof(buff));

		}


	}
return 0;
}

