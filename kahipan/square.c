#include<stdio.h>
int main()
{
	for (int i=0; i<=10; i++)
	{
			printf("*");

			for(int j=0; j<=10; j++)
			{
				if((i==0) || (i==10))
					printf("*");
				else
					printf(" ");
			}

			printf("*\n");

	}
	

}




