/* This program is the updation of PN: socket_mulcl_selserup.c  where the issue of same port no. for different clients was solved
 * using new struct sockaddr_in variable used during read operation
 * Here, we are implementing a record of all clients ip,port etc in a struct
 * PN: socket_mulcl_selserstr.c
 * Final Update Date: 31 AUG 2026
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

int main()
{
	int s_fd, c_fd, new_socket, max_fd;
	int r_read, s_res;
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	int s_address_len = sizeof(s_address);
	int c_address_len = sizeof(c_address);
	fd_set readfds;
	int client[MAX_CL] = {0};
	
	
	char * buffer = (char *) malloc (200); // buffer to receive contents from client
	char * reply = (char *) malloc (200); // msg to send contents to client
	char * brdcst = (char *) malloc (200); // brdcst to broadcast same msg to all clients
	
	if (buffer == NULL || reply == NULL || brdcst == NULL)
	{
		printf("Memory Allocation failed\n");
		return -1;
	}

	// create master socket	
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	if (s_fd == -1)
		printf("Socket creation failed\n");

	printf("%d\n", s_fd);
	
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
            		c_fd = client[i];

            		if (c_fd > 0)
				FD_SET(c_fd, &readfds);

           	 	if (c_fd > max_fd)
				max_fd = c_fd;
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
				buffer[strcspn(brdcst, "\n")] = '\0';
			
				// Broadcast to all active clients
				for(int i = 0; i < MAX_CL; i++)
				{
					if (client[i] > 0)
					{
						send(client[i], brdcst, strlen(brdcst), 0);
					}
				}
			}
		}
		
		// case 2: If something happened on master socket; its an incoming client connection

		if FD_ISSET (s_fd, &readfds)
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
               	 				if (client[i] == 0)
						{
         	           				client[i] = new_socket;
							printf("Client added to list at index %d\n\n", i);
							flag = 1;
							break;
						}
					}
					if(!flag)
					{
						printf("Server is full! Rejecting Connection\n");
						close(new_socket);
					}
				}
		}

		// case 3: If something happened on an existing client socket(IO operation)
		for(int i = 0; i < MAX_CL; i++)
		{
			c_fd = client[i];

			if(c_fd > 0 && FD_ISSET (c_fd, &readfds))
			{
				memset(buffer, 0, 200);

				struct sockaddr_in currentcl_addr;
				socklen_t currentcl_addr_len = sizeof(currentcl_addr); 

				r_read = read (c_fd, buffer, 199);
					if (r_read == -1) printf("Recheck read");

					else if (r_read == 0 || strcmp(buffer, "EXIT") == 0)
					{
						if(getpeername(c_fd, (struct sockaddr *)&currentcl_addr, &currentcl_addr_len) == 0)

						printf("Client disconnected with IP: %s, PORT: %d\n", inet_ntoa(currentcl_addr.sin_addr), ntohs(currentcl_addr.sin_port));
						close(c_fd);
						client[i] = 0;
					}
					else
					{
						buffer[r_read] = '\0';

						if(getpeername(c_fd, (struct sockaddr *)&currentcl_addr, &currentcl_addr_len) == 0)

						printf("Msg from client [FD %d, Port: %d] >>\t %s\n", c_fd, ntohs(currentcl_addr.sin_port), buffer);
						printf("Server response  >>\t ");

 						memset(reply, 0, 200);
						if (fgets(reply, 200, stdin)!= NULL)
						{
							reply[strcspn(reply, "\n")] = '\0';

							s_res = send (c_fd, reply, strlen(reply), 0);	
								if (s_res == -1) printf("Recheck send");

							//printf("%s\n", reply);
							printf("\n--Response sent by Server--\n");
							printf("------------------------------\n\n");
						}
					}
			}
		}
	}

	printf("Please hit enter key to take exit from server\n");
	getchar();

	close (new_socket);
	close (s_fd);

return 0;
}
