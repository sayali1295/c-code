#include <stdio.h>
int main()
{
	char ch = 'a';
	char *ptr =  &ch;
	printf("%p\n", ptr);
	char **p = &ptr;
	printf("%p\n",*p);
	return 0;
}
