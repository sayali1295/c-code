
// This program is the basic implementation of pipe in networking
// pipe_basic.c


#include<stdio.h>
#include<unistd.h>

int main()
{

	int count = 10;
	int a[2];
	int r = pipe(a);
	printf("%d\n", r);
	
	char buffer[count];

	write (a[1], "HELLO", 5);

	read (a[0], buffer, count);

	printf("%s", buffer);

return 0;
}

