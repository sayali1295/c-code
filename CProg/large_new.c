#include<stdio.h>
int main()
{
      printf("Program for finding the largest number");
      printf("Please enter three numbers\n");

      int a,b,c;
      scanf("%d%d%d", &a,&b,&c);

      if (a>b)
      {
        if(a>c)
	 {
	   printf("The largest number is: ", a);  
	 }
      }	
      else if (b>c)
         {
           printf("The largest number is: ", b);  
         }      
      else 
      {
           printf("The largest number is: ", c);
      }
}
