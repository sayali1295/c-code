#include<stdio.h>
#define SIZE 5
int main()
{
           int i,j;
	for(i=0; i <= SIZE ; i++)
         {
	   for(j = i; j>0; j--)
	   {
	     if((j==i) || (i==SIZE))
	      {
	       printf("*");
	      }
	     else
	      {
	       printf(" ");
	      }
	   }
	  printf("*\n");
	}

return 0;

}
