#include<stdio.h>
#define SIZE 10
int main()
{
	int i,j,k;

       for(k=0; k<=SIZE; k++)
         {
	    printf("*");
	 }
            printf("\n");

       for(i = SIZE; i >= 0 ; i--)
         {
           for(j = i; j > 0; j--)
             {
               if(j == i)
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
