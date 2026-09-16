#include<stdio.h>
int main()
{
   int n;
   int num1, num2;
   char input;
   
   printf("Welcome to Mini Calculator\n");

   printf("Please enter A for Addition, S for Subtraction, M for Multiplication & D for Division\n");
   scanf("%c", &input);
   

   printf("Enter two numbers\n");
   scanf("%d%d", &num1, &num2);

   if((input == 'A') || (input == 'a'))
   {
	  int a = num1 + num2;
	  printf("The result is: %d", a);
   }
   else if((input == 83) || (input == 115))
   {
	  int s = num1 - num2;
	  printf("The result is: %d", s);
   }
   else if((input == 77) || (input ==109))
   {
          int m = num1 * num2;
	  printf("The result is: %d", m);
   }
   else if((input == 68) || (input == 100))
   {
	  int d = num1 / num2;
	  printf("The result is: %d", d);
   }
   else
   {
          printf("Wrong input");
   }

/*printf("Please enter on how many numbers operation is to be performed");
scanf("%d", &n);

for(int i = 0; i <= n-1; i++)
{
  scanf("%d", &)
}*/





return 0;



}
