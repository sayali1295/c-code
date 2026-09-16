/* This program is a SERVER of a multiple client demanding services from SERVER
 * Program is implemented using socket programming
 * When any client is requesting for service, SERVER identifies requesting client
 * and communnicates with the same client until client stops communicating
 * PN: socket_trial_contakcl_ser.c
 * Final update Date: 17 AUG 2026
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<arpa/inet.h>

#define PORT 8080

int main()
{
	int s_fd; // server socket fd
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	socklen_t s_address_len = sizeof(s_address);
	socklen_t c_address_len = sizeof(c_address);
	
	char * buffer = (char *) malloc (200); // buffer to receive contents from client
	char * reply = (char *) malloc (200); // buffer to reply to client
		
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", s_fd);
	
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = INADDR_ANY;
	s_address.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_address, s_address_len); 
		if (b_res == -1) printf("Recheck bind\n");
	
	int l_res = listen(s_fd, 5);
		if (l_res == -1) printf("Recheck listen\n");

	int new_socket, r_res;

	//Infinite loop for accepting multiple client requests
	while(1)
	{
		// Updating (c_address_len) each time the loop iterates
		socklen_t c_address_len = sizeof(c_address); 

		// Check for new client connection request
		new_socket = accept (s_fd, (struct sockaddr *)&c_address, &c_address_len);
			if (new_socket == -1) printf("Recheck accept\n");

			else
       			{
				printf("%d", new_socket);

				// Retrieving client information of family, port and address
				char client_ip[INET_ADDRSTRLEN];
				uint16_t client_port = ntohs(c_address.sin_port);

				// Converting network byte order address to human readable format
            			inet_ntop(AF_INET, &(c_address.sin_addr), client_ip, INET_ADDRSTRLEN);
				
				// Printing retrieved information of requesting client
            			printf("\n\nNew CLIENT knocked: \n");
				printf("Details of knocking clientis is as given below: \n");
           			printf("Client address family = %hu\n", c_address.sin_family);
            			printf("Client IP = %s\n", client_ip);
            			printf("Client port = %hu\n\n", client_port);
        		}
		while(1)
		{

			printf("\nMsg from CLIENT...\n");

			// Clear out buffer before receiving new msg
			memset(buffer, 0, 200);

			// Used 199 because server don't know how big the msg is
			r_res = recv (new_socket, buffer, 199, 0);
				if (r_res == -1) 
				{	
					printf("Recheck receive\n");
				}
				else if (r_res == 0)
				{
					printf("CLIENT Disconnected\n\n");
					break;
				}

			printf("%s\n", buffer);

			printf("\nYour turn to type: \n");
			
			// Clear out reply before sending new msg
			memset(reply, 0, 200);

			fgets(reply, 200, stdin);

			// Removing newline character (\n)
			reply[strcspn(reply, "\n")] = '\0';
			
			// Used strlen(reply) becuase server knows how big tthe msg is
			int s_res = send (new_socket, reply, strlen(reply), 0);
				if (s_res == -1) printf("Recheck send\n");

			printf("\n--Reply sent by SERVER to requested Client--\n");
			printf("\n-------------------------------\n");
//			close (new_socket);
		}
		close (new_socket);
	}

	printf("Please hit enter key to take exit from server\n");
	getchar();

	close (new_socket);
	close (s_fd);

return 0;
}
