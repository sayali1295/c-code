#include <stdio.h>
int main()

{
   printf("Program for sum of digits\n");
   printf("Please enter a 3 digit number: \n");
   int a;
   scanf("%d", &a);

   int b = a / 100;
   int c = a % 100;
   int d = c / 10;
   int e = c / 10;

   int f = b + e + d;

   printf("THE SUM OF DIGITS OF A NUMBER: %d %d is", a, f);





}

