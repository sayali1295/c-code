/* This program is a SERVER of a multiple client demanding services from SERVER
 * Program is implemented using socket programming
 * When client 1 is requesting for service, SERVER identifies requesting client
 * and send it back its information i.e. PORT, ADDRESS, Family
 * PN: socket_trial_mulcl_ser.c
 * Final update Date: 13 AUG 2026
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
	
	char * buffer = (char *) malloc (50); // buffer to receive contents from client
		
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", s_fd);
	
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = INADDR_ANY;
	s_address.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_address, s_address_len); 
		if (b_res == -1) printf("Recheck bind");
	
	int l_res = listen(s_fd, 5);
		if (l_res == -1) printf("Recheck listen");

	int new_socket, r_res;

	//Infinite loop for accepting multiple client requests
	while(1)
	{
		// Updating (c_address_len) each time the loop iterates
		socklen_t c_address_len = sizeof(c_address); 

		// Check for new client connection request
		new_socket = accept (s_fd, (struct sockaddr *)&c_address, &c_address_len);
			if (new_socket == -1) printf("Recheck accept");

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
           			printf("Client address family = %hu\n", c_address.sin_family);
            			printf("Client IP = %s\n", client_ip);
            			printf("Client port = %hu\n\n", client_port);
        		}
	
		 r_res = recv (new_socket, buffer, 50, 0);
			if (r_res == -1) printf("Recheck receive");

		printf("%s\n", buffer);
		
		// sending struct c_address directly to client
		int s_res = send (new_socket, &c_address, sizeof(c_address), 0);
			if (s_res == -1) printf("Recheck send");

		printf("\n--Reply sent by SERVER to requested Client--\n");
		printf("\n-------------------------------\n");
		close (new_socket);
	}

	printf("Please hit enter key to take exit from server\n");
	getchar();

	close (new_socket);
	close (s_fd);

return 0;
}
