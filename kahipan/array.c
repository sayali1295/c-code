#include <stdio.h>
#include <string.h>
int main()
{

	int mystrlen(char []);//declaration
	char array[]="Sayli";
	//	{'S','a','l','i', '\0'};
	int i=0;
	while(array[i] != '\0')
	{
		printf("%c", array[i]);
		i++;
	}

	printf("\nnew : %s",array);

	printf("\nLength of str is %ld\n", strlen(array));
	return 0;
}


int mystrlen(char arr[])
{

	int i=0;
	
	while(arr[i] != '\0')
	{
		i++;
	}
	return i;
}
