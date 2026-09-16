// This program is printing o/p as 
// 1   2
// 2   1
// out_1221.c

#include<stdio.h>
int main()
{
   for(int i = 1; i <= 2; i++)
   {
      for(int j = 1; j <=2; j++)
      {
	      if(i==j)
		      continue;
         	printf("%d\t%d\n", i , j);
      
      }
   
   
   
   }


}
