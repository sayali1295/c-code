
#include<stdio.h>
int main()
{
    printf("Reversing the digits of a number \n");
    printf("Please enter a 4 digit number: ");
    int num;
    scanf("%d", &num);

    int new_num = 0;

    while(num>0){

    int digit = num % 10;
    new_num = new_num * 10 + digit;
    num = num / 10; 
    }
    printf("The number after reversal is: %d", new_num);
   
}
