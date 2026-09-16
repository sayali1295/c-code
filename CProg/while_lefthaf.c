#include <stdio.h>
int main()
{

        int i = 10,j,s=0;

	while(i >= 0)
        {
		j = i;
		while (j >= 0)
		{
			printf(" ");
			j--;
		}
		printf("*");
		
		int k = s;

		while (k >= 0)
		{
			printf(" ");
			k--;
		}
		printf("*\n");
		s++;
		i--;

	}

	int b = 0;

	while(b <= 10)
	{
	    printf("*");
	    b++;
	}
}

