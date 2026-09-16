/*
* This program is implementation of the UDP client
* PN: socket_udp_cl.c
* Final Update Date: 11 SEP 2026
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<arpa/inet.h>
#include<errno.h>

#define PORT 8080

int main()
{
	int c_fd;
	struct sockaddr_in  c_addr;
	int c_addr_len = sizeof(c_addr);

	char * buff = (char *) malloc (50);
	char * msg = (char *) malloc (50);

	strcpy (msg, "How are you? from CLIENT");

	c_fd = socket (AF_INET, SOCK_STREAM, 0);
	if (c_fd == -1)
	{
		perror("Socket creation failed\n");
		free(buff);
		free(msg);
		exit(EXIT_FAILURE);
	}
	printf("Client FD: %d\n", c_fd);

	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);

	int i_res = inet_pton (AF_INET, "127.0.0.1", &c_addr.sin_addr);
		if (i_res <= 0) printf("Recheck inet_pton");

	int c_res = connect (c_fd, (struct sockaddr *)&c_addr, c_addr_len);
		if (c_res == -1)
		{
			printf("Recheck connect");
			free(buff);
			free(msg);
			exit(EXIT_FAILURE);
		}

	/*int sen = send (c_fd, msg, strlen(msg), 0);
		if(sen == -1)
		{
			printf("Recheck send");
		}*/

	int sen = sendto (c_fd, msg, strlen(msg), 0, (const struct sockaddr *)&c_addr, c_addr_len);
		if(sen == -1)
		{
			printf("Recheck send");
		}

	printf("Msg sent by CLIENT\n");

	/*int rec = recv (c_fd, buff, 49, 0);
		if (rec == -1)
		{
			printf("Recheck receive");
		}*/

	int rec = recvfrom(c_fd, buff, 49, 0, (struct sockaddr *)&c_addr, &c_addr_len);
		if (rec == -1)
		{
			printf("Recheck receive");
		}
	
	printf("Response by Server: %s\n", buff);

	printf("Please hit enter key to take exit from client\n");
	getchar();

	close(c_fd);

return 0;
}
