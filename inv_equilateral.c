#include<stdio.h>
#define SIZE 20
int main()
{
   int i,j,k,y,z = 0;

    for(i = 0; i <= SIZE*2; i++// top line)
     {
       printf("*");
     }
    printf("\n");
     
    for(j = 0; j <= SIZE-1; j++)
    {
        for(k = j; k >= 0; k--)
         {
            printf(" ");
         }
	    printf("*");

	if(j < SIZE-1)
	 {
	        
	for(y = z; y <= (2*SIZE-4); y++)
          {
	      printf(" ");
          } 
	      printf("*\n");
	      z=z+2;
         }
     } 

return 0;
}
