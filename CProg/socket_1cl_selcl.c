/* This program is a sigle client for server implemented using select
* where only readfds is used
* The msg sent by this client is same as reveived one
* PN: socket_1cl_selcl.c
* Final Update Date: 25 AUG 2026
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<arpa/inet.h>

#define PORT 8080

int main()
{
	int c_fd;
	struct sockaddr_in  c_address;
	int c_address_len = sizeof(c_address);

	char * buff = (char *) malloc (50);
	char * msg = (char *) malloc (50);

	strcpy (msg, "Hello, Good Day");

	c_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", c_fd);

	c_address.sin_family = AF_INET;
	c_address.sin_port = htons(PORT);

	int i_res = inet_pton (AF_INET, "127.0.0.1", &c_address.sin_addr);
		if (i_res <= 0) printf("Recheck inet_pton");

	int c_res = connect (c_fd, (struct sockaddr *)&c_address, c_address_len);
		if (c_res == -1) printf("Recheck connect");

	int sen = write (c_fd, msg, strlen(msg));
		if(sen == -1) printf("Recheck send");
	printf("Msg sent by CLIENT...\n");

	int rec = recv (c_fd, buff, 49, 0);
		if (rec == -1) printf("Recheck receive");
	
	printf("Msg received by CLIENT: %s\n", buff);

	printf("Please hit enter key to take exit from client\n");
	getchar();

	free(buff);
	free(msg);
	close(c_fd);

return 0;
}
