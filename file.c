#include<stdio.h>
int main(char *argv[])
{
	FILE  *fp;
	fp = fopen (argv[1], "r");
	if (fp == NULL)
		printf("Error");

	char ch;
//	while(ch!=EOF)
	while(1)
	{	
		if(ch==EOF)
			break;
		{
			ch = getc(fp);
			printf("%c", ch);
		//	putc(ch, stdout);

		}
	
	}
	return 0;
}
