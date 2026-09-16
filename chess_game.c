#include<stdio.h>

//This program is to print amount after 30 days challenge of doubling 5 paisa and so on 

int main()
{

#ifdef paisa

   int i, days;
   int total;
   float paisa = 0.05;

   printf("Please enter no. of days\n");
   scanf("%d", &days);
 
   for(i = 1; i <= days; i++)
   {
      total = paisa * (2 (i-1);
   

   printf("The total amount is: %d", total);

}

#endif

//This program is to print no. of rice grains after 64 days challenge

#ifdef chess

   int i, days;
   int total;
   int rgrains = 1;

   printf("Please enter no. of days\n");
   scanf("%d", &days);
 
   for(i = 1; i <= days; i++)
   {
      total = rgrains * 2 (i-1);
   
   }

   printf("The total amount is: %d", total);

#endif

}

