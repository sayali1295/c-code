#include<stdio.h>
#define SIZE 10
int main()
{
	int i,j,k,g;

	for(k=0; k<=SIZE; k++)
	{
	   printf("* ");
	}
           printf("\n");

	for(i = 0; i<=10; i++)
      	{
	    for(j = i; j >= 0; j--)
	      {
		 printf(" ");
	      }
		
	   printf("*");

                 for(g = i; g <= (SIZE-3); g++)
		 {
		    printf(" ");
		 }
           printf("*\n");

       	}

				
	return 0;

}




