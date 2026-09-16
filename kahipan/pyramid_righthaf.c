#include<stdio.h>
int main()
{

#ifdef solid
	for(int i = 0; i<=10; i++)
        {
           for(int j = i; j>0; j--)
             {
	         printf("*");
             }
        
	  printf("*\n");	  
        }
#endif



#ifdef hollow
           int i,j;
	for(i=0; i <= 10; i++)
         {
	   for(j = i; j>0; j--)
	   {
	     if((j==i) || (i==10))
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
#endif


#ifdef hollow1
	int i,j;
       
	for( i = 10; i>0; i--)
	{
	  for( j = i; j>0; j--)
	  {
	    

return 0;

}
