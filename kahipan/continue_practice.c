#include<stdio.h>
int main()
{
   int i = 0;

   while(i <= 6)
   {
      if(i == 3)
      {
        i++;
	continue;
      }
    printf("%d", i);
    i++;
   
   }

}
