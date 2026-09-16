#include<stdio.h>
int main()
{
   float k;

   printf("Please enter \n");
   scanf("%f", &k);

   switch((int)k)
   {
    case 3: printf("three");
	    break;
    
    case 4: printf("four");
	    break;

    default: printf("wrong");
	     break;
   }

}
