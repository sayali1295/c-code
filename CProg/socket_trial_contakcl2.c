/* This program is CLIENT 2 of multiple client handling SERVER
 * In this program client is requesting service from SERVER listening on PORT 8080
 * Also this client is continuously comunicating with server back to back
 * PN : socket_trial_contakcl2.c
 * Final update Date: 17 AUG 2026
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<arpa/inet.h> // used for conversion inet_pton & inet_ntop
#define PORT 8080

int main()
{
	int c_fd;
	struct sockaddr_in  c_address;
	int c_address_len = sizeof(c_address);

	char * msg = (char *) malloc (200);
	char * buff = (char *) malloc (200);

	c_fd = socket (AF_INET, SOCK_STREAM, 0);
	printf("%d\n", c_fd);

	c_address.sin_family = AF_INET;
	c_address.sin_port = htons(PORT);

	// Converting human readable (text format) SERVER address to network byte order and store in sin_addr 
	int i_res = inet_pton (AF_INET, "127.0.0.1", &c_address.sin_addr);
		if (i_res <= 0) printf("Recheck inet_pton");


	int c_res = connect (c_fd, (struct sockaddr *)&c_address, c_address_len);
		if (c_res == -1) printf("Recheck connect\n");
	
	while(1)
	{
		printf("Your turn: Start typing.....\n");
		printf("To disconnect... Type EXIT(case sensitive)\n");

		// Clear out msg memory before reading new characters
		memset(msg, 0, 200);

		fgets(msg, 200, stdin);

		// Removing newline character (\n)
            	msg[strcspn(msg, "\n")] = '\0';

		if((strcmp(msg, "EXIT")) == 0)
		{
			printf("CLIENT 2 Disconnecting\n");
			break;
		}

		// used strlen(msg) because client knows how big the message is
		int sen = send (c_fd, msg, strlen(msg), 0);
			if(sen == -1) printf("Recheck send\n");

		printf("\n----Msg sent by CLIENT 2----\n");
		printf("___________________________________\n\n");
		
		// Clear out buff memory before receiving new characters
		memset(buff, 0, 200);
		
		printf("Reply from SERVER....\n");

		// used 199 because client don't know how big the reply is
		int rec = recv (c_fd, buff, 199, 0);
	
			if (rec == -1) printf("Recheck receive\n");

		printf("%s\n\n", buff);
	}

	printf("Please hit enter key to take exit from client 2\n");
	getchar();

	close(c_fd);
return 0;
}
