/* This program is a logic for converting integer to string
* PN: int_to_string.c
* Final Update Date: 21 AUG 2026
*/


#include<stdio.h>
int main()
{
	int number;
	int digit[10];
	int count = 0;
	int i = 0;

	printf("Program for converting integer to string :\n");
	printf("Please enter a number to convert :\n");
	scanf("%d", &number);
	
	int temp = number;

	while (temp > 0)
	{
		digit[i] = temp % 10;
		count++;
		i++;
		temp = temp / 10;
	}
	i++;

	printf("%d\n", digit);
return 0;

}
