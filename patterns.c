#include<stdio.h>
int main()
{

#ifdef Horz  

	for(int i =0; i<=10, i++)
	{
	   printf("*");
	}
#endif


#ifdef Vert

	for(int i = 0; i<= 10; i++)
	{
	  printf("*\n");
	}
#endif

#ifdef slantL

	for(int i = 5; ;)
	{
	  if (i>0)
	  {
	     printf("*");
	     i--;
	  }
	  else
	  {
	     break;
	  }
           printf(" ");
	}
#endif

#ifdef slantR

    int n = 5; // Size of the line
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
	{
            if (i == j) 
	    {
                printf("*");
            }
	    else 
	    {
                printf(" ");
            }
        }
        printf("\n");
    }
#endif	

}
