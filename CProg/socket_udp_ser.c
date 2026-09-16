/***
 * This program is implmentation of the UDP server 
 * PN: socket_udp_ser.c
 * Final Update Date: 11 SEP 2026
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#define PORT 8080

int main()
{
	int s_fd;
	struct sockaddr_in s_addr;
	struct sockaddr_in p_addr;
	int s_addr_len = sizeof(s_addr);
	int p_addr_len = sizeof(p_addr);
	
	char * buffer = (char *) malloc (50); // buffer to receive contents from client
	char * reply = (char *) malloc (50); // msg to send contents to client

	strcpy(reply , "I am fine! from SERVER");
		
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	if (s_fd == -1)
	{  
		perror("socket creation failed\n");
		free(buffer);
		free(reply);
		exit(EXIT_FAILURE);
	}

	printf("Server FD :%d\n", s_fd);
	
	s_addr.sin_family = PF_INET;
	s_addr.sin_addr.s_addr = INADDR_ANY;
	s_addr.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_addr, s_addr_len); 
		if (b_res == -1)
		{
			printf("Recheck bind");
			free(buffer);
			free(reply);
			exit(EXIT_FAILURE);
		}
	
	int l_res = listen(s_fd, 3);
		if (l_res == -1)
		{	
			printf("Recheck listen");
			free(buffer);
			free(reply);
			exit(EXIT_FAILURE);
		}

	int new_socket = accept (s_fd, (struct sockaddr *)&p_addr, &p_addr_len);
		if (new_socket == -1)
		{
			printf("Recheck accept");
		}
/*	int r_res = recv (new_socket, buffer, 50, 0);
		if (r_res == -1)
		{
			printf("Recheck receive");
		}*/

	int r_res = recvfrom(new_socket, buffer, 50, 0, (struct sockaddr *)&p_addr, &p_addr_len);
		if (r_res == -1)
		{
			printf("Recheck receive");
		}
		
	printf("Received bytes: %d\n", r_res);
	printf("Response by client: %s\n", buffer);

/*	int s_res = send (new_socket, reply, strlen(reply), 0);
		if (s_res == -1)
		{
			printf("Recheck send");
		}*/

	int s_res = sendto (new_socket, reply, strlen(reply), 0, (const struct sockaddr *)&p_addr, p_addr_len);
		if (s_res == -1)
		{
			printf("Recheck send");
		}

	printf("Msg sent by SERVER\n");

	printf("Please hit enter key to take exit from server\n");
	getchar();

	close (new_socket);
	close (s_fd);

return 0;
}
