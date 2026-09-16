/* This program is a client of unix pathname server
* PN: socketunix_pn_trial_cl.c
* Final Update Date: 10 Sept 2026
*/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/un.h>
#include<stdlib.h>
#include<string.h> 
#include<unistd.h>
#include<errno.h>

#define PATH_NAME "/tmp/my_sock.sock"

int main()
{
	int c_fd;
	struct sockaddr_un c_addr;
	char msg[108];
	socklen_t c_addr_len = sizeof(c_addr);

	c_fd = socket (PF_UNIX, SOCK_STREAM, 0);
	if (c_fd == -1)
	{
		perror("Socket creation failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Client fd: %d\n", c_fd);
	
	/* For portability, clear the whole structure, since some 
	* implementations have additional (non standard) fields in
	* the structure
	*/

	memset(&c_addr, 0, sizeof(&c_addr));

	// Connect sockets to socket address
	c_addr.sun_family = PF_UNIX;
	strncpy(c_addr.sun_path, PATH_NAME, sizeof(c_addr.sun_path) - 1);

	int c_res = connect (c_fd, (struct sockaddr *)&c_addr, c_addr_len);
		if (c_res == -1)
		{
			perror("Recheck connect");
			close(c_fd);
			exit(EXIT_FAILURE);
		}

	printf("type >> ");
	
	memset(msg, 0, sizeof(msg));

	if (fgets(msg, sizeof(msg), stdin) != NULL)
	{
		int sen = send (c_fd, msg, strlen(msg), 0);
			if(sen == -1)
			{
				printf("Recheck send");
				exit(EXIT_FAILURE);
			}
			else
				printf("Msg sent by CLIENT\n");
	}

	char buff[50];

	memset(buff, 0, sizeof(buff));

	int rec = recv (c_fd, buff, 49, 0);
		if (rec == -1)
		{
			printf("Recheck receive");
			return -1;
		}
		else	
			printf("Client received: >> %s\n", buff);

	printf("Please hit enter key to take exit from client\n");
	getchar();

	close(c_fd);

return 0;
}
