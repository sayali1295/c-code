/* This program is testing use of fd_Set used in socket programming for select operation
* We are using pipe to create one more fd to test how the program behaves
* PN: socket_fdset_testpipe_write.c
* Final Update Date: 19 AUG 2026
*/

#include<stdio.h>
#include<unistd.h>

int main()
{
	int a[2];
	pipe(a); // creating pipe for checking communication with read

while(1)
{
	write(a[1], "hello", 5);
}

return 0;
}
