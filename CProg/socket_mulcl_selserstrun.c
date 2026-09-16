/* This program is the next step of PN: socket_mulcl_selserup.c
 * This program is the UPDATED SERVER which stores record of all connected clients in a struct
 * And it communicates with client using their username
 * PN: socket_mulcl_selserstrun.c
 * Final Update Date: 1 SEP 2026
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<arpa/inet.h>
#include<sys/select.h>

#define PORT 8080
#define MAX_CL 5

struct emp
{
	int fd;
	int port;
	char ip[INET_ADDRSTRLEN];
	char user_name[50];
};

int main()
{
	int s_fd, c_fd, new_socket, max_fd;
	int r_read, s_res;
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	int s_address_len = sizeof(s_address);
	int c_address_len = sizeof(c_address);
	fd_set readfds;
	typedef struct emp clientinfo;

	// Initialize all members in struct to 0
	clientinfo client[MAX_CL];
	
	for(int i = 0; i < MAX_CL; i++)
	{
		client[i].fd = 0;
		client[i].port = 0;
		memset(client[i].ip , 0, INET_ADDRSTRLEN);
		memset(client[i].user_name, 0, 50);	
	}	
	
	char * buffer = (char *) malloc (200); // buffer to receive contents from client
	char * reply = (char *) malloc (200); // msg to send contents to client
	char * brdcst = (char *) malloc (200); // brdcst to broadcast same msg to all clients
	
	if (buffer == NULL || reply == NULL || brdcst == NULL)
	{
		printf("Memory Allocation failed\n");
		return -1;
	}

	// Force terminal output to display immediately
	setvbuf(stdout, NULL, _IONBF, 0);	

	// create master socket	
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	if (s_fd == -1)
		printf("Socket creation failed\n");

	printf("Master Socket FD: %d\n", s_fd);
	
	//set socket options using setsockopt

	int opt = 1;
	if (setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
	{
		perror("setsockopt SO_REUSEADDR failed");
		exit(EXIT_FAILURE);	
	}

	//Bind socket to port	
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = INADDR_ANY;
	s_address.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_address, s_address_len); 
		if (b_res == -1) printf("Recheck bind");
	
	int l_res = listen(s_fd, 3);
		if (l_res == -1) printf("Recheck listen");

	printf("Server is listening on port %d - \n\n", PORT);

	while(1)
	{
		//Clear the socket set
		FD_ZERO(&readfds);

		//Add server socket to set
		FD_SET(s_fd, &readfds);
		max_fd = s_fd;

		//Add stdin (fd 0) to set so server can type and send messages
		FD_SET(STDIN_FILENO, &readfds);
			if (STDIN_FILENO > max_fd)
			{
				max_fd = STDIN_FILENO;
			}

		//Add active clients to the set and find max_sd
		for (int i = 0; i < MAX_CL; i++)
		{
            		if (client[i].fd > 0)
				FD_SET(client[i].fd, &readfds);

           	 	if (client[i].fd > max_fd)
				max_fd = client[i].fd;
        	}
		
		// Wait for an activity on one of the client socket
		int act = select(max_fd + 1, &readfds, NULL, NULL, NULL);
		if(act < 0)
		{
			perror("Select error");
			break;
		}

		// case 1: If something happened on stdin, read it and broadcast to all clients
		if (FD_ISSET (STDIN_FILENO, &readfds))
		{
			memset(brdcst, 0, 200);
			
			if (fgets(brdcst, 200, stdin) != NULL)
			{
				brdcst[strcspn(brdcst, "\n")] = '\0';
			
				// Broadcast to all active clients
				for(int i = 0; i < MAX_CL; i++)
				{
					if (client[i].fd > 0)
					{
						send(client[i].fd, brdcst, strlen(brdcst), 0);
					}
				}
			}
		}
		
		// case 2: If something happened on master socket; its an incoming client connection

		if (FD_ISSET (s_fd, &readfds))
		{
			c_address_len = sizeof(c_address); // each time c_address_len should be updated

			new_socket = accept (s_fd, (struct sockaddr *)&c_address, &c_address_len);
				if (new_socket == -1) printf("Recheck accept");
				else
				{
					printf("\nNew connection: Socket FD: %d, IP: %s, Port: %d\n",new_socket, inet_ntoa(c_address.sin_addr), ntohs(c_address.sin_port));
		

					// Add new socket to array of clients
					int flag = 0;
			
					for (int i = 0; i < MAX_CL; i++)
					{
               	 				if (client[i].fd == 0)
						{
         	           				client[i].fd = new_socket;

							// strncpy copies string of size INET_ADDRSTRLEN w/o null into struct
							strncpy(client[i].ip, inet_ntoa(c_address.sin_addr), INET_ADDRSTRLEN); 
							client[i].port = ntohs(c_address.sin_port);

							// snprintf prints string onto 
							memset(client[i].user_name, 0, 50);
						//	snprintf(client[i].user_name, sizeof(client[i].user_name), "%d", new_socket);

							printf("Client added to list at index %d\n\n", i);
							flag = 1;
							break;
						}
					}
					if(!flag)
					{
						printf("Server is full! Rejecting Connection of FD: %d\n", new_socket);
						close(new_socket);
					}
				}
		}

		// case 3: If something happened on an existing client socket(IO operation)
		for(int i = 0; i < MAX_CL; i++)
		{
			if(client[i].fd > 0 && FD_ISSET (client[i].fd, &readfds))
			{
				memset(buffer, 0, 200);

				r_read = read (client[i].fd, buffer, 199);

					if (r_read == -1) printf("Recheck read");

					else if (r_read == 0 || strcmp(buffer, "EXIT") == 0)
					{
						if(strlen(client[i].user_name) > 0)
						{
							printf("Client disconnected with FD: %d, IP: %s, PORT: %d\n\n", client[i].fd, client[i].ip, client[i].port);
						}
						else
						{
							printf("Client disconnected without entering user name: %s\n", client[i].user_name);
						}

						close(client[i].fd);
						client[i].fd = 0;
						memset(client[i].user_name, 0, 50);
					}
					else
					{
						buffer[r_read] = '\0';

						if (strlen(client[i].user_name) == 0)
						{
							// strncpy copies buffer to client[i].user_name
							strncpy (client[i].user_name, buffer, 49);

							printf("Client FD %d is registered with User Name : %s\n", client[i].fd, client[i].user_name);

							// Send confirmation back to the client

							memset(reply, 0, 200);

                        				snprintf(reply, strlen(reply), "Welcome %s! Profile saved on server.", client[i].user_name);

                        				s_res = send(client[i].fd, reply, strlen(reply), 0);
									if (s_res == -1) perror("Send Failed\n");
						}
						else
						{
							printf("\nMsg from client [FD %d, UserName: %s] >>\t %s\n", client[i].fd, client[i].user_name, buffer);
							printf("Server response  >>\t ");

 							memset(reply, 0, 200);
							if (fgets(reply, 200, stdin) != NULL)
							{
								reply[strcspn(reply, "\n")] = '\0';

								s_res = send (client[i].fd, reply, strlen(reply), 0);	
									if (s_res == -1) printf("Recheck send");

								printf("\n--Response sent by Server--\n");
								printf("------------------------------\n\n");
							}
						}
					}
			}
		}
	}

	close (s_fd);
	free (buffer);
	free (reply);
	free (brdcst);

return 0;
}
