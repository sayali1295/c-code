#include<stdio.h>
int main()
{

	int i,j,x,y;
	for(i = 0; i<=10; i++)
         {
	    for(j = i; j >0; j--)
	       {
		  printf(" ");
	       }
		
		printf("*\n");
        	}

	for(x =10; x>0; x--)
	{
	  for(y=x; y>0; y--)
	  {
	  
	  printf(" ");
	  }

	  printf("*\n");
	}

return 0;

}





