#include<stdio.h>
#define SIZE 10
int main()
{
	int i,j,k,g;

	for(k=0; k <= SIZE+1; k++)
	{
	   printf("*");
	}
           printf("\n");

	for(i = 0; i<=10; i++)
      	{
	    for(j = i; j >= 0; j--)
	      {
		 printf(" ");
	      }
		
	   printf("*");
                   
            for(g = i; g < SIZE-1 ; g++)
	      {
	         printf(" ");
	      }   
	
    	    if(i!=SIZE)
	      {
		 printf("*\n");
              }
       	}				
	return 0;
}




