#include<stdio.h>
#define SIZE 10
int main()
{
int i,j,k,g,x,y;
int d,e,s,t;
    for(i = 0; i <= SIZE-5; i++)
    {
       for(j = i ; j >= 0; j--)
       {
	 if(j>0)
	 {
           printf(" ");
	 }
	 else
	 {
	   printf("*");

	   for( s = i ; s <= SIZE; s++)
	   {
	      for(t = s; t < SIZE; t++)
	      {
	        printf(" ");
	      } 
	    //  if (t!=SIZE)
	      
	      printf("*\n");
	      
	   }

	 } 










       }
    /*   for(d = 5; d <= 0; d++)
       {
         for(e = d; e >= 0; e--)

	 {
	   printf(" ");
	 }

	 printf("*\n");
       }*/
    }







/*    for(k = SIZE; k > 0; k--)
    {
       for(g = k-1; g > 0 ; g--)
       {
         printf(" ");
       
       } 
     printf("*");

     for(x = k; x >= 0; x++)
      {
         for(y = x; y <= k; y++)
	 {
	    printf(" ");
	 }
	 printf("*\n");
      }
    }

      



*/
return 0;
}
