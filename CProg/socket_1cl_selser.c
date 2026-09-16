/* This program is implemented using select to understand the functioning of fd_set with select
 * Here we will use all macros of fd_set - FD_ZERO, FD_SET, FD_ISSET, FD_CLR
 * Select will monitor different fds like it 1st monitor listening socket fd
 * Later it will then check listening socket is SET or not, if its SET, it is given to (accept) 
 * Later if another fd of CLIENT is found then (receive) or (send) will execute

 * All fds after listening socket fd are linked to (clients) so only S/R can work
 * PN: socket_1cl_selser.c
 * Final Update Date: 25 AUG 2026
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/select.h>

#define PORT 8080

int main()
{
	int s_fd, new_socket, max_fd;
	int r_read, s_res;
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	int s_address_len = sizeof(s_address);
	int c_address_len = sizeof(c_address);
	fd_set readfds;
	int client = 0;
	
	
	char * buffer = (char *) malloc (50); // buffer to receive contents from client
		
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", s_fd);
	
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = INADDR_ANY;
	s_address.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_address, s_address_len); 
		if (b_res == -1) printf("Recheck bind");
	
	int l_res = listen(s_fd, 3);
		if (l_res == -1) printf("Recheck listen");

	while(1)
	{
		FD_ZERO(&readfds);
		FD_SET(s_fd, &readfds);
		max_fd = s_fd;

//		Add active clients to the set and find max_sd

            	if (client > 0)
			FD_SET(client, &readfds);

           	 if (client > max_fd)
			max_fd = client;

		int act = select(max_fd + 1, &readfds, NULL, NULL, NULL);

		if(act < 0)
		{
			perror("Select error");
			break;
		}	

		if FD_ISSET (s_fd, &readfds)
		{
			c_address_len = sizeof(c_address); // each time c_address_len should be updated

			new_socket = accept (s_fd, (struct sockaddr *)&c_address, &c_address_len);
				if (new_socket == -1) printf("Recheck accept");

			if (client == 0)
			{
         		        client = new_socket;
				printf("Client connected\n");
			}
			else
			{
				close(new_socket);
			}
		}
		if ((client > 0) && (FD_ISSET (client, &readfds)))
		{
			r_read = read (client, buffer, 50);
				if (r_read == -1) printf("Recheck read");

				else if (r_read == 0)
				{
					printf("Client disconnected\n");
					close(client);
					client = 0;
				}
				else
				{
					buffer[r_read] = '\0';
					printf("Msg received by SERVER : %s\n", buffer);

					s_res = send (client, buffer, strlen(buffer) , 0); // Echo back	
						if (s_res == -1) printf("Recheck send");
					
					printf("Msg echoed by SERVER...\n");
				}
		}

	}


	printf("Please hit enter key to take exit from server\n");
	getchar();

	free(buffer);
	close (new_socket);
	close (s_fd);

return 0;
}
