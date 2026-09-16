#include<stdio.h>
int main()
{
   printf("Multiplication Table \n");

    int i, j;
    for (i = 1; i <= 10; i++) 
    {
        for (j = 2; j <= 10; j++) 
	{
	    int k = i*j;
	     
            printf("%d ", k);
        }
	printf("\n");
    }

    return 0;
}



