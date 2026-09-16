/***
 *
 *
 *
 *
 */

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define PORT 8080

int main()
{
	int s_fd;
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	int s_address_len = sizeof(s_address);
	int c_address_len = sizeof(c_address);
	
	char * buffer = (char *) malloc (50); // buffer to receive contents from client
	char * reply = (char *) malloc (50); // msg to send contents to client

	strcpy(reply , "I am fine! from SERVER");
		
	s_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", s_fd);
	
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = INADDR_ANY;
	s_address.sin_port = htons(PORT);
	
	int b_res = bind(s_fd, (struct sockaddr *)&s_address, s_address_len); 
		if (b_res == -1) printf("Recheck bind");
	
	int l_res = listen(s_fd, 3);
		if (l_res == -1) printf("Recheck listen");

	int new_socket = accept (s_fd, (struct sockaddr *)&c_address, &c_address_len);
		if (new_socket == -1) printf("Recheck accept");

	int r_res = recv (new_socket, buffer, 50, 0);
		if (r_res == -1) printf("Recheck receive");
	
	printf("%d\n", r_res);
	printf("%s\n", buffer);

	int s_res = send (new_socket, reply, strlen(reply), 0);
		if (s_res == -1) printf("Recheck send");
	printf("Msg sent by SERVER\n");

	printf("Please hit enter key to take exit from server\n");
	getchar();

	close (new_socket);
	close (s_fd);

return 0;
}
