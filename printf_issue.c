/***
 * Program was not printing string abc , the solution is given inside
 * printf_issue.c
 */


#include<stdio.h>
#include<unistd.h>

int main()
{
	char name[] = "Apple";
	char abc[50];
	int i = 0, j = 0;

	for(; name[i] != 0; i++)
	{
		;
	}

	/* i has reached to null terminator in 1st for loop
	 * and if it is given as it is to 2nd for loop then abc[j] will store 1st character as null
	 * thereby printf can print string abc
	 * To solve this issue we must decrement i by 1 and then start the 2nd for loop
	 */

	i--; // decremented i by 1

	for (; i >= 0 ; i--)
	{
		abc[j] = name[i];
		j++;
	}

	abc[j] = '\0';
	printf("%s", abc);
//	write (1, abc, 6);

return 0;
}
