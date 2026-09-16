#include <stdio.h>
int main()
{

        int i,j,s=0;
	for(i=20; i >= 0; i--)
        {
		for (int j = i ; j >= 0; j--)
		{
			printf(" ");
		}
		printf("*");

		for (int k = s*2; (k) >= 0 ; k--)
		{
			printf(" ");
		}
		printf("*\n");
		s++;

	}
	for(int i = 0; i <= 20*2 ; i++)
		printf("*");
}

