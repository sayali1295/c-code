#include<stdio.h>
int main()
{
     
#ifdef for1

	for(int i=0 ; i<=10 ; i++)
	{   
         	printf("%d\n",i);       
    	}
#endif

#ifdef for2
         
	int i = 0;
	for(; i<=10 ; i++)
	{
	  printf("%d\n", i);
	}
#endif

#ifdef for3
        
        int i = 0;
	for(; i<=10; )
	{
	   printf("%d\n", i);
	   i++;
	}
#endif

#ifdef for4

	int i = 0;
	 for(;;)
	 {
	     if(i<=10)
	       {
                 printf("%d\n", i);
	         i++;
	       }
	     else
	     {
	       break;
	     }
	 }
#endif

#ifdef for5
	 int i = 0;
	 for(; ; i++)
	 {
	   if(i<=10)
	   {
	     printf("%d\n", i);
	   }
	   else
	   {
	     break;
	   }
	 }
#endif

#ifdef forP1
         
	 for(int i = 0; i<=10 ; i++)
	 {
	     printf("-");
	 
	 }
#endif

#ifdef forP2

          for(int i = 0; i<=10 ; i++)
	  {
	    printf("|\n");
	  
	  }
#endif


#ifdef forP3
         
	  for(int i = 0; i<=10; i++)
	  {
	     
		  
		  printf("*\n");
	  }
#endif







}
