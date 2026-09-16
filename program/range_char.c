#include<stdio.h>
int main()
{
#ifdef logic1   
	
   char ch = 1;
                           //o/p as -127 to 128

   for(; ch > 0; ch++)
   {
	   printf("%d\t", ch);
   };


   printf("The minimum value of character is: %d", ch);
   ch--;
   
   printf("The maximum value of character is: %d", ch);
#endif


#ifdef logic2
   
   unsigned char ch = 1;
                           //o/p as 0 to 255

   for(; ch > 0; ch++)
   {
	   printf("%d\t", ch);
   };


   printf("The minimum value of character is: %d", ch);
   ch--;
   
   printf("The maximum value of character is: %d", ch);

#endif


}




