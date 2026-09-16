//This program is to perform sum of 4 digit numbwe and reversal of it
// digits_sum.c

#include<stdio.h>
int main()
{
    // printf("Program for sum of digits\n");
     printf("Program for reversal of digits\n");
     printf("Please enter a 4 digit number: ");
     int num;
     scanf("%d", &num);

     int a = num % 10;
     num = (num - a) / 10; 


     
     int b = num % 10;
     num = (num - b) / 10;

     int c = num % 10;
     num = (num - c) /10;

     int d = num % 10;

     int sum = a + b + c + d;

     printf("The sum of digits of a number is: %d", sum);
     
    // int reverse = a * 1000 + b * 100 + c * 10 + d * 1;

 //    printf("The reverse of a number is: %d", reverse);



}













