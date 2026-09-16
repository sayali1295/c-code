#include<stdio.h>
int main()
{ 
	int size =10;
	for(int i = 0; i<=10; i++, size--)
	{
		for(int j = size; j > 0; j--)
		{
			printf(" ");
		}
		printf("*\n");
	}

				
	return 0;
}
