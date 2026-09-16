/* This program is a logic for identifying a number is perfect square or not
* For this we are checking sum of all numbers in a perfect sq no.
* if sum is among 1,4,7,9 then it is definately a perfect sq no.
* PN: is_perfect_sq.c
* Final Update Date: 21 AUG 2026
*/


#include<stdio.h>
int main()
{
	int number;
	int digit[10];
	int count = 0;
	int i = 0;
	int rec = 0;

	printf("Program for checking no. is perfect square or not :\n");
	printf("Please enter a number to check :\n");
	scanf("%d", &number);
	
	int temp = number;

	while (temp > 0)
	{
		digit[i] = temp % 10;
		count++;
		i++;
		temp = temp / 10;
	}

	printf("no. of digits seperated: %d\n", count);
	
	for(i = 0; i <= count; i++)
	{
		rec = rec + digit[i];
	}
	printf("The sum of digits : %d\n", rec);


	if ((rec == 1) || (rec == 4) || (rec == 7) || (rec == 9))
	{
		printf("Congrats! The number is a perfect square number\n");
	}
	else
	{
		printf("Sorry! The number is NOT a perfect square number\n");
	}	



return 0;

}
