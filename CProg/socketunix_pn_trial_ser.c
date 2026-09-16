/**
 * This program is the implementation of UNIX socket
 * PN: socketunix_pn_trial_ser.c 
 * Final Update Date: 10 SEP 2026
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/un.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#define PATH_NAME "/tmp/my_sock.sock"

int main()
{
	int s_fd;
	struct sockaddr_un s_addr;
	char buffer[108];
	socklen_t s_addr_len = sizeof(s_addr);
	
	// clean up old socket file
	unlink(PATH_NAME);
	
	s_fd = socket (PF_UNIX, SOCK_STREAM, 0);
	if (s_fd == -1)
	{
		perror("socket creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("server fd: %d\n", s_fd);
	
	/* For portability clear the whole structure, since some
	* implementations have additional (non standard) fields in the
	* structure.
	*/

	memset(&s_addr, 0, sizeof(s_addr));
	
	// Bind the socket

	s_addr.sun_family = PF_UNIX; 
	strncpy(s_addr.sun_path, PATH_NAME, sizeof(s_addr.sun_path) - 1);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_addr, s_addr_len); 
		if (b_res == -1)
		{
			perror("Recheck bind");
			close(s_fd);
			exit(EXIT_FAILURE);
		}
	
	int l_res = listen(s_fd, 3);
		if (l_res == -1)
		{
			perror("Recheck listen");
			unlink(PATH_NAME);
			close(s_fd);
			exit(EXIT_FAILURE);
		}

		printf("Server listening on %s...\n", PATH_NAME);
int new_socket;
	// main loop for handeling connections
	for(;;)
	{
		 new_socket = accept (s_fd, NULL, NULL);
			if (new_socket == -1)
			{
				perror("Recheck accept");
				return -1;
			}
		memset(buffer, 0, sizeof(buffer));

		int r_res = recv (new_socket, buffer, sizeof(buffer) - 1, 0);
			if (r_res == -1)
			{	
				perror("Recheck receive");
				continue;
			}
	
		printf("Bytes received: %d\n", r_res);
		printf("received from client: %s", buffer);
		
		char reply[50];
		printf("\nServer response: >> ");

		if (fgets(reply, 50, stdin) != NULL)
		{
			int s_res = send (new_socket, reply, strlen(reply), 0);
			if (s_res == -1)
			{
				perror("Recheck send");
			}
			else
				printf("Msg sent by SERVER\n");
		}
		else
		close (new_socket);
//	}
		close(new_socket);
		printf("Please hit enter key to take exit from server\n");
		getchar();
		//close(new_socket);
		close (s_fd);
	}
return 0;
}
