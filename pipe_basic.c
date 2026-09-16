
/* This program is the basic implementation of unnamed pipe in networking
 * Here we are writing "HELLO" to pipe thereby reading it from
 * "buffer at read end"
 * pipe_basic.c */


#include<stdio.h>
#include<unistd.h>

int main()
{

	int count = 10;
	int a[2];
	int r = pipe(a);
	
	char buffer[count];

	write (a[1], "HELLO", 5);

	read (a[0], buffer, count);

	printf("%s", buffer);

return 0;
}

